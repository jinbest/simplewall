// simplewall
// Copyright (c) 2016-2020 Henry++

#include "global.hpp"

VOID _app_settab_id (HWND hwnd, INT page_id)
{
	if (!page_id || ((INT)_r_tab_getlparam (hwnd, IDC_TAB, INVALID_INT) == page_id && IsWindowVisible (GetDlgItem (hwnd, page_id))))
		return;

	for (INT i = 0; i < (INT)SendDlgItemMessage (hwnd, IDC_TAB, TCM_GETITEMCOUNT, 0, 0); i++)
	{
		INT listview_id = (INT)_r_tab_getlparam (hwnd, IDC_TAB, i);

		if (listview_id == page_id)
		{
			_r_tab_selectitem (hwnd, IDC_TAB, i);
			return;
		}
	}

	_app_settab_id (hwnd, IDC_APPS_PROFILE);
}

UINT _app_getinterfacestatelocale (ENUM_INSTALL_TYPE install_type)
{
	if (install_type == InstallEnabled)
		return IDS_STATUS_FILTERS_ACTIVE;

	else if (install_type == InstallEnabledTemporary)
		return IDS_STATUS_FILTERS_ACTIVE_TEMP;

	// InstallDisabled
	return IDS_STATUS_FILTERS_INACTIVE;
}

BOOLEAN _app_initinterfacestate (HWND hwnd, BOOLEAN is_forced)
{
	if (!hwnd)
		return FALSE;

	if (is_forced || !!SendDlgItemMessage (config.hrebar, IDC_TOOLBAR, TB_ISBUTTONENABLED, IDM_TRAY_START, 0))
	{
		SendDlgItemMessage (config.hrebar, IDC_TOOLBAR, TB_ENABLEBUTTON, IDM_TRAY_START, MAKELPARAM (FALSE, 0));
		SendDlgItemMessage (config.hrebar, IDC_TOOLBAR, TB_ENABLEBUTTON, IDM_REFRESH, MAKELPARAM (FALSE, 0));

		_r_status_settext (hwnd, IDC_STATUSBAR, 0, app.LocaleString (IDS_STATUS_FILTERS_PROCESSING, L"..."));

		return TRUE;
	}

	return FALSE;
}

VOID _app_restoreinterfacestate (HWND hwnd, BOOLEAN is_enabled)
{
	if (!is_enabled)
		return;

	SendDlgItemMessage (config.hrebar, IDC_TOOLBAR, TB_ENABLEBUTTON, IDM_TRAY_START, MAKELPARAM (TRUE, 0));
	SendDlgItemMessage (config.hrebar, IDC_TOOLBAR, TB_ENABLEBUTTON, IDM_REFRESH, MAKELPARAM (TRUE, 0));

	ENUM_INSTALL_TYPE install_type = _wfp_isfiltersinstalled ();

	_r_status_settext (hwnd, IDC_STATUSBAR, 0, app.LocaleString (_app_getinterfacestatelocale (install_type), NULL));
}

VOID _app_setinterfacestate (HWND hwnd)
{
	ENUM_INSTALL_TYPE install_type = _wfp_isfiltersinstalled ();

	BOOLEAN is_filtersinstalled = (install_type != InstallDisabled);
	INT icon_id = is_filtersinstalled ? IDI_ACTIVE : IDI_INACTIVE;
	UINT string_id = is_filtersinstalled ? IDS_TRAY_STOP : IDS_TRAY_START;

	HICON hico_sm = app.GetSharedImage (app.GetHINSTANCE (), icon_id, _r_dc_getsystemmetrics (hwnd, SM_CXSMICON));
	HICON hico_big = app.GetSharedImage (app.GetHINSTANCE (), icon_id, _r_dc_getsystemmetrics (hwnd, SM_CXICON));

	SendMessage (hwnd, WM_SETICON, ICON_SMALL, (LPARAM)hico_sm);
	SendMessage (hwnd, WM_SETICON, ICON_BIG, (LPARAM)hico_big);

	//SendDlgItemMessage (hwnd, IDC_STATUSBAR, SB_SETICON, 0, (LPARAM)hico_sm);

	if (!_wfp_isfiltersapplying ())
		_r_status_settext (hwnd, IDC_STATUSBAR, 0, app.LocaleString (_app_getinterfacestatelocale (install_type), NULL));

	_r_toolbar_setbutton (config.hrebar, IDC_TOOLBAR, IDM_TRAY_START, app.LocaleString (string_id, NULL), BTNS_BUTTON | BTNS_AUTOSIZE | BTNS_SHOWTEXT, 0, is_filtersinstalled ? 1 : 0);

	_r_tray_setinfo (hwnd, UID, hico_sm, APP_NAME);
}

VOID _app_listviewresize (HWND hwnd, INT listview_id, BOOLEAN is_forced)
{
	if (!listview_id || (!is_forced && !app.ConfigGetBoolean (L"AutoSizeColumns", TRUE)))
		return;

	INT column_count = _r_listview_getcolumncount (hwnd, listview_id);

	if (!column_count)
		return;

	HWND hlistview = GetDlgItem (hwnd, listview_id);
	HWND hheader = (HWND)SendMessage (hlistview, LVM_GETHEADER, 0, 0);

	RECT rc_client = {0};
	GetClientRect (hlistview, &rc_client);

	// get device context and fix font set
	HDC hdc_listview = GetDC (hlistview);
	HDC hdc_header = GetDC (hheader);

	if (hdc_listview)
		SelectObject (hdc_listview, (HFONT)SendMessage (hlistview, WM_GETFONT, 0, 0)); // fix

	if (hdc_header)
		SelectObject (hdc_header, (HFONT)SendMessage (hheader, WM_GETFONT, 0, 0)); // fix

	INT calculated_width = 0;

	// set general column id
	INT column_general_id = 0;

	BOOLEAN is_tableview = ((INT)SendMessage (hlistview, LVM_GETVIEW, 0, 0) == LV_VIEW_DETAILS);

	INT total_width = _r_calc_rectwidth (INT, &rc_client);

	INT max_width = _r_dc_getdpi (hwnd, 158);
	INT spacing = _r_dc_getsystemmetrics (hwnd, SM_CXSMICON);

	for (INT i = 0; i < column_count; i++)
	{
		if (i == column_general_id)
			continue;

		// get column text width
		rstring column_text = _r_listview_getcolumntext (hwnd, listview_id, i);
		INT column_width = _r_dc_fontwidth (hdc_header, column_text, column_text.GetLength ()) + spacing;

		if (column_width >= max_width)
		{
			column_width = max_width;
		}
		else
		{
			// calculate max width of listview subitems (only for details view)
			if (is_tableview)
			{
				for (INT j = 0; j < _r_listview_getitemcount (hwnd, listview_id, FALSE); j++)
				{
					rstring item_text = _r_listview_getitemtext (hwnd, listview_id, j, i);
					INT text_width = _r_dc_fontwidth (hdc_listview, item_text, item_text.GetLength ()) + spacing;

					// do not continue reaching higher and higher values for performance reason!
					if (text_width >= max_width)
					{
						column_width = max_width;
						break;
					}

					if (text_width > column_width)
						column_width = text_width;
				}
			}
		}

		_r_listview_setcolumn (hwnd, listview_id, i, NULL, column_width);

		calculated_width += column_width;
	}

	// set general column width
	_r_listview_setcolumn (hwnd, listview_id, column_general_id, NULL, max (total_width - calculated_width, max_width));

	if (hdc_listview)
		ReleaseDC (hlistview, hdc_listview);

	if (hdc_header)
		ReleaseDC (hheader, hdc_header);
}

VOID _app_listviewsetview (HWND hwnd, INT listview_id)
{
	BOOLEAN is_mainview = (listview_id >= IDC_APPS_PROFILE) && (listview_id <= IDC_RULES_CUSTOM);
	INT view_type = is_mainview ? _r_calc_clamp (INT, app.ConfigGetInteger (L"ViewType", LV_VIEW_DETAILS), LV_VIEW_ICON, LV_VIEW_MAX) : LV_VIEW_DETAILS;

	INT icons_size = (is_mainview || listview_id == IDC_NETWORK) ? _r_calc_clamp (INT, app.ConfigGetInteger (L"IconSize", SHIL_SYSSMALL), SHIL_LARGE, SHIL_LAST) : SHIL_SYSSMALL;
	HIMAGELIST himg = NULL;

	if (listview_id >= IDC_RULES_BLOCKLIST && listview_id <= IDC_RULES_CUSTOM)
	{
		if (icons_size == SHIL_SMALL || icons_size == SHIL_SYSSMALL)
			himg = config.himg_rules_small;

		else
			himg = config.himg_rules_large;
	}
	else
	{
		SHGetImageList (icons_size, IID_IImageList2, (LPVOID*)&himg);
	}

	if (himg)
	{
		SendDlgItemMessage (hwnd, listview_id, LVM_SETIMAGELIST, LVSIL_NORMAL, (LPARAM)himg);
		SendDlgItemMessage (hwnd, listview_id, LVM_SETIMAGELIST, LVSIL_SMALL, (LPARAM)himg);
	}

	SendDlgItemMessage (hwnd, listview_id, LVM_SETVIEW, (WPARAM)view_type, 0);
	SendDlgItemMessage (hwnd, listview_id, LVM_SCROLL, 0, (LPARAM)GetScrollPos (GetDlgItem (hwnd, listview_id), SB_VERT)); // HACK!!!
}

VOID _app_listviewinitfont (HWND hwnd, PLOGFONT plf)
{
	rstring buffer = app.ConfigGetString (L"Font", UI_FONT_DEFAULT);

	if (!buffer.IsEmpty ())
	{
		rstringvec rvc;
		_r_str_split (buffer, buffer.GetLength (), L';', rvc);

		if (!rvc.empty ())
		{
			_r_str_copy (plf->lfFaceName, LF_FACESIZE, rvc.at (0)); // face name

			if (rvc.size () >= 2)
			{
				plf->lfHeight = _r_dc_fontsizetoheight (hwnd, _r_str_tointeger (rvc.at (1))); // size

				if (rvc.size () >= 3)
					plf->lfWeight = _r_str_tointeger (rvc.at (2)); // weight
			}
		}
	}

	// fill missed font values
	{
		NONCLIENTMETRICS ncm = {0};
		ncm.cbSize = sizeof (ncm);

		if (SystemParametersInfo (SPI_GETNONCLIENTMETRICS, ncm.cbSize, &ncm, 0))
		{
			PLOGFONT pdeflf = &ncm.lfMessageFont;

			if (_r_str_isempty (plf->lfFaceName))
				_r_str_copy (plf->lfFaceName, LF_FACESIZE, pdeflf->lfFaceName);

			if (!plf->lfHeight)
				plf->lfHeight = pdeflf->lfHeight;

			if (!plf->lfWeight)
				plf->lfWeight = pdeflf->lfWeight;

			// set default values
			plf->lfCharSet = pdeflf->lfCharSet;
			plf->lfQuality = pdeflf->lfQuality;
		}
	}
}

VOID _app_listviewsetfont (HWND hwnd, INT listview_id, BOOLEAN is_redraw)
{
	LOGFONT lf = {0};

	if (is_redraw || !config.hfont)
	{
		SAFE_DELETE_OBJECT (config.hfont);

		_app_listviewinitfont (hwnd, &lf);

		config.hfont = CreateFontIndirect (&lf);
	}

	if (config.hfont)
		SendDlgItemMessage (hwnd, listview_id, WM_SETFONT, (WPARAM)config.hfont, TRUE);
}

INT CALLBACK _app_listviewcompare_callback (LPARAM lparam1, LPARAM lparam2, LPARAM lparam)
{
	HWND hlistview = (HWND)lparam;
	HWND hparent = GetParent (hlistview);
	INT listview_id = GetDlgCtrlID (hlistview);

	INT item1 = _app_getposition (hparent, listview_id, lparam1);
	INT item2 = _app_getposition (hparent, listview_id, lparam2);

	if (item1 == INVALID_INT || item2 == INVALID_INT)
		return 0;

	rstring cfg_name = _r_fmt (L"listview\\%04" TEXT (PRIX32), listview_id);

	INT column_id = app.ConfigGetInteger (L"SortColumn", 0, cfg_name);
	BOOLEAN is_descend = app.ConfigGetBoolean (L"SortIsDescending", FALSE, cfg_name);

	INT result = 0;

	if ((SendMessage (hlistview, LVM_GETEXTENDEDLISTVIEWSTYLE, 0, 0) & LVS_EX_CHECKBOXES) != 0)
	{
		BOOLEAN is_checked1 = _r_listview_isitemchecked (hparent, listview_id, item1);
		BOOLEAN is_checked2 = _r_listview_isitemchecked (hparent, listview_id, item2);

		if (is_checked1 != is_checked2)
		{
			if (is_checked1 && !is_checked2)
				result = is_descend ? 1 : -1;

			else if (!is_checked1 && is_checked2)
				result = is_descend ? -1 : 1;
		}
	}

	if (!result)
	{
		// timestamp sorting
		if ((listview_id >= IDC_APPS_PROFILE && listview_id <= IDC_APPS_UWP) && column_id == 1)
		{
			time_t* timestamp1 = (time_t*)_app_getappinfo (lparam1, InfoTimestampPtr);
			time_t* timestamp2 = (time_t*)_app_getappinfo (lparam2, InfoTimestampPtr);

			if (timestamp1 && timestamp2)
			{
				if ((*timestamp1) < (*timestamp2))
					result = -1;

				else if ((*timestamp1) > (*timestamp2))
					result = 1;
			}
		}
	}

	if (!result)
	{
		result = _r_str_compare_logical (
			_r_listview_getitemtext (hparent, listview_id, item1, column_id),
			_r_listview_getitemtext (hparent, listview_id, item2, column_id)
		);
	}

	return is_descend ? -result : result;
}

VOID _app_listviewsort (HWND hwnd, INT listview_id, INT column_id, BOOLEAN is_notifycode)
{
	HWND hlistview = GetDlgItem (hwnd, listview_id);

	if (!hlistview)
		return;

	if ((GetWindowLongPtr (hlistview, GWL_STYLE) & (LVS_NOSORTHEADER | LVS_OWNERDATA)) != 0)
		return;

	INT column_count = _r_listview_getcolumncount (hwnd, listview_id);

	if (!column_count)
		return;

	rstring cfg_name = _r_fmt (L"listview\\%04" TEXT (PRIX32), listview_id);
	BOOLEAN is_descend = app.ConfigGetBoolean (L"SortIsDescending", FALSE, cfg_name);

	if (is_notifycode)
		is_descend = !is_descend;

	if (column_id == INVALID_INT)
		column_id = app.ConfigGetInteger (L"SortColumn", 0, cfg_name);

	column_id = _r_calc_clamp (INT, column_id, 0, column_count - 1); // set range

	if (is_notifycode)
	{
		app.ConfigSetBoolean (L"SortIsDescending", is_descend, cfg_name);
		app.ConfigSetInteger (L"SortColumn", column_id, cfg_name);
	}

	for (INT i = 0; i < column_count; i++)
		_r_listview_setcolumnsortindex (hwnd, listview_id, i, 0);

	_r_listview_setcolumnsortindex (hwnd, listview_id, column_id, is_descend ? -1 : 1);

	SendMessage (hlistview, LVM_SORTITEMS, (WPARAM)hlistview, (LPARAM)&_app_listviewcompare_callback);
}

VOID _app_refreshgroups (HWND hwnd, INT listview_id)
{
	UINT group1_title;
	UINT group2_title;
	UINT group3_title;

	if (!SendDlgItemMessage (hwnd, listview_id, LVM_ISGROUPVIEWENABLED, 0, 0))
		return;

	if (listview_id >= IDC_APPS_PROFILE && listview_id <= IDC_APPS_UWP)
	{
		group1_title = IDS_GROUP_ALLOWED;
		group2_title = IDS_GROUP_SPECIAL_APPS;
		group3_title = IDS_GROUP_BLOCKED;
	}
	else if (listview_id >= IDC_RULES_BLOCKLIST && listview_id <= IDC_RULES_CUSTOM)
	{
		group1_title = IDS_GROUP_ENABLED;
		group2_title = IDS_GROUP_SPECIAL;
		group3_title = IDS_GROUP_DISABLED;
	}
	else if (listview_id == IDC_RULE_APPS_ID)
	{
		group1_title = IDS_TAB_APPS;
		group2_title = IDS_TAB_SERVICES;
		group3_title = IDS_TAB_PACKAGES;
	}
	else
	{
		return;
	}

	INT total_count = _r_listview_getitemcount (hwnd, listview_id, FALSE);

	INT group1_count = 0;
	INT group2_count = 0;
	INT group3_count = 0;

	for (INT i = 0; i < total_count; i++)
	{
		if (listview_id == IDC_RULE_APPS_ID)
		{
			if (_r_listview_isitemchecked (hwnd, listview_id, i))
			{
				group1_count = group2_count = group3_count += 1;
			}
		}
		else
		{
			LVITEM lvi = {0};

			lvi.mask = LVIF_GROUPID;
			lvi.iItem = i;

			if (SendDlgItemMessage (hwnd, listview_id, LVM_GETITEM, 0, (LPARAM)&lvi))
			{
				if (lvi.iGroupId == 2)
					group3_count += 1;

				else if (lvi.iGroupId == 1)
					group2_count += 1;

				else
					group1_count += 1;
			}
		}
	}

	_r_listview_setgroup (hwnd, listview_id, 0, app.LocaleString (group1_title, total_count ? _r_fmt (L" (%d/%d)", group1_count, total_count).GetString () : NULL), 0, 0);
	_r_listview_setgroup (hwnd, listview_id, 1, app.LocaleString (group2_title, total_count ? _r_fmt (L" (%d/%d)", group2_count, total_count).GetString () : NULL), 0, 0);
	_r_listview_setgroup (hwnd, listview_id, 2, app.LocaleString (group3_title, total_count ? _r_fmt (L" (%d/%d)", group3_count, total_count).GetString () : NULL), 0, 0);
}

VOID _app_refreshstatus (HWND hwnd, INT listview_id)
{
	PITEM_STATUS pstatus = (PITEM_STATUS)_r_mem_allocatezero (sizeof (ITEM_STATUS));
	_app_getcount (pstatus);

	HWND hstatus = GetDlgItem (hwnd, IDC_STATUSBAR);
	HDC hdc = GetDC (hstatus);

	// item count
	if (hdc)
	{
		SelectObject (hdc, (HFONT)SendMessage (hstatus, WM_GETFONT, 0, 0)); // fix

		const INT parts_count = 3;
		INT spacing = _r_dc_getdpi (hwnd, 12);

		rstring text[parts_count];
		INT parts[parts_count] = {0};
		LONG size[parts_count] = {0};
		LONG lay = 0;

		for (INT i = 0; i < parts_count; i++)
		{
			switch (i)
			{
				case 1:
				{
					if (pstatus)
						text[i].Format (L"%s: %" TEXT (PR_SIZE_T), app.LocaleString (IDS_STATUS_UNUSED_APPS, NULL).GetString (), pstatus->apps_unused_count);

					break;
				}

				case 2:
				{
					if (pstatus)
						text[i].Format (L"%s: %" TEXT (PR_SIZE_T), app.LocaleString (IDS_STATUS_TIMER_APPS, NULL).GetString (), pstatus->apps_timer_count);

					break;
				}
			}

			if (i)
			{
				size[i] = _r_dc_fontwidth (hdc, text[i], text[i].GetLength ()) + spacing;
				lay += size[i];
			}
		}

		RECT rc_client = {0};
		GetClientRect (hstatus, &rc_client);

		parts[0] = _r_calc_rectwidth (INT, &rc_client) - lay - _r_dc_getsystemmetrics (hwnd, SM_CXVSCROLL) - (_r_dc_getsystemmetrics (hwnd, SM_CXBORDER) * 2);
		parts[1] = parts[0] + size[1];
		parts[2] = parts[1] + size[2];

		SendMessage (hstatus, SB_SETPARTS, parts_count, (LPARAM)parts);

		for (INT i = 1; i < parts_count; i++)
			_r_status_settext (hwnd, IDC_STATUSBAR, i, text[i]);

		ReleaseDC (hstatus, hdc);
	}

	// group information
	if (listview_id)
	{
		if (listview_id == INVALID_INT)
			listview_id = (INT)_r_tab_getlparam (hwnd, IDC_TAB, INVALID_INT);

		_app_refreshgroups (hwnd, listview_id);
	}

	if (pstatus)
		_r_mem_free (pstatus);
}

INT _app_getposition (HWND hwnd, INT listview_id, LPARAM lparam)
{
	LVFINDINFO lvfi = {0};

	lvfi.flags = LVFI_PARAM;
	lvfi.lParam = lparam;

	return (INT)SendDlgItemMessage (hwnd, listview_id, LVM_FINDITEM, (WPARAM)INVALID_INT, (LPARAM)&lvfi);
}

VOID _app_showitem (HWND hwnd, INT listview_id, INT item, INT scroll_pos)
{
	HWND hlistview = GetDlgItem (hwnd, listview_id);

	if (!hlistview)
		return;

	_app_settab_id (hwnd, listview_id);

	INT total_count = _r_listview_getitemcount (hwnd, listview_id, FALSE);

	if (!total_count)
		return;

	if (item != INVALID_INT)
	{
		item = _r_calc_clamp (INT, item, 0, total_count - 1);

		PostMessage (hlistview, LVM_ENSUREVISIBLE, (WPARAM)item, TRUE); // ensure item visible

		ListView_SetItemState (hlistview, INVALID_INT, 0, LVIS_SELECTED | LVIS_FOCUSED); // deselect all
		ListView_SetItemState (hlistview, (WPARAM)item, LVIS_SELECTED | LVIS_FOCUSED, LVIS_SELECTED | LVIS_FOCUSED); // select item
	}

	if (scroll_pos > 0)
		PostMessage (hlistview, LVM_SCROLL, 0, (LPARAM)scroll_pos); // restore scroll position
}

LONG_PTR _app_nmcustdraw_listview (LPNMLVCUSTOMDRAW lpnmlv)
{
	if (!app.ConfigGetBoolean (L"IsEnableHighlighting", TRUE))
		return CDRF_DODEFAULT;

	switch (lpnmlv->nmcd.dwDrawStage)
	{
		case CDDS_PREPAINT:
		{
			return CDRF_NOTIFYITEMDRAW;
		}

		case CDDS_ITEMPREPAINT:
		{
			INT view_type = (INT)SendMessage (lpnmlv->nmcd.hdr.hwndFrom, LVM_GETVIEW, 0, 0);
			BOOLEAN is_tableview = (view_type == LV_VIEW_DETAILS || view_type == LV_VIEW_SMALLICON || view_type == LV_VIEW_TILE);

			INT listview_id = PtrToInt ((LPVOID)lpnmlv->nmcd.hdr.idFrom);

			if ((listview_id >= IDC_APPS_PROFILE && listview_id <= IDC_APPS_UWP) || listview_id == IDC_RULE_APPS_ID || listview_id == IDC_NETWORK || listview_id == IDC_LOG)
			{
				SIZE_T app_hash;

				if (listview_id == IDC_NETWORK)
				{
					app_hash = _app_getnetworkapp (lpnmlv->nmcd.lItemlParam); // initialize
				}
				else if (listview_id == IDC_LOG)
				{
					app_hash = _app_getlogapp (lpnmlv->nmcd.lItemlParam); // initialize
				}
				else
				{
					app_hash = lpnmlv->nmcd.lItemlParam;
				}

				if (app_hash)
				{
					COLORREF new_clr = _app_getappcolor (listview_id, app_hash);

					if (new_clr)
					{
						lpnmlv->clrText = _r_dc_getcolorbrightness (new_clr);
						lpnmlv->clrTextBk = new_clr;

						if (is_tableview)
							_r_dc_fillrect (lpnmlv->nmcd.hdc, &lpnmlv->nmcd.rc, new_clr);

						return CDRF_NEWFONT;
					}
				}
			}
			else if (listview_id >= IDC_RULES_BLOCKLIST && listview_id <= IDC_RULES_CUSTOM)
			{
				SIZE_T rule_idx = lpnmlv->nmcd.lItemlParam;

				COLORREF new_clr = _app_getrulecolor (listview_id, rule_idx);

				if (new_clr)
				{
					lpnmlv->clrText = _r_dc_getcolorbrightness (new_clr);
					lpnmlv->clrTextBk = new_clr;

					if (is_tableview)
						_r_dc_fillrect (lpnmlv->nmcd.hdc, &lpnmlv->nmcd.rc, new_clr);

					return CDRF_NEWFONT;
				}

			}
			else if (listview_id == IDC_COLORS)
			{
				PITEM_COLOR ptr_clr = (PITEM_COLOR)lpnmlv->nmcd.lItemlParam;

				if (ptr_clr)
				{
					COLORREF new_clr = ptr_clr->new_clr ? ptr_clr->new_clr : ptr_clr->default_clr;

					if (new_clr)
					{
						lpnmlv->clrText = _r_dc_getcolorbrightness (new_clr);
						lpnmlv->clrTextBk = new_clr;

						if (is_tableview)
							_r_dc_fillrect (lpnmlv->nmcd.hdc, &lpnmlv->nmcd.rc, lpnmlv->clrTextBk);

						return CDRF_NEWFONT;
					}
				}
			}

			break;
		}
	}

	return CDRF_DODEFAULT;
}

LONG_PTR _app_nmcustdraw_toolbar (LPNMLVCUSTOMDRAW lpnmlv)
{
	switch (lpnmlv->nmcd.dwDrawStage)
	{
		case CDDS_PREPAINT:
		{
			return CDRF_NOTIFYITEMDRAW | CDRF_NOTIFYPOSTPAINT;
		}

		case CDDS_ITEMPREPAINT:
		{
			TBBUTTONINFO tbi = {0};

			tbi.cbSize = sizeof (tbi);
			tbi.dwMask = TBIF_STYLE | TBIF_STATE | TBIF_IMAGE;

			if ((INT)SendMessage (lpnmlv->nmcd.hdr.hwndFrom, TB_GETBUTTONINFO, (WPARAM)lpnmlv->nmcd.dwItemSpec, (LPARAM)&tbi) == INVALID_INT)
				break;

			if ((tbi.fsState & TBSTATE_ENABLED) == 0)
			{
				INT icon_size_x = 0;
				INT icon_size_y = 0;

				SelectObject (lpnmlv->nmcd.hdc, (HFONT)SendMessage (lpnmlv->nmcd.hdr.hwndFrom, WM_GETFONT, 0, 0)); // fix

				SetBkMode (lpnmlv->nmcd.hdc, TRANSPARENT);
				SetTextColor (lpnmlv->nmcd.hdc, GetSysColor (COLOR_GRAYTEXT));

				if (tbi.iImage != I_IMAGENONE)
				{
					HIMAGELIST himglist = (HIMAGELIST)SendMessage (lpnmlv->nmcd.hdr.hwndFrom, TB_GETIMAGELIST, 0, 0);

					if (himglist)
					{
						DWORD padding = (DWORD)SendMessage (lpnmlv->nmcd.hdr.hwndFrom, TB_GETPADDING, 0, 0);
						UINT rebar_height = (UINT)SendMessage (GetParent (lpnmlv->nmcd.hdr.hwndFrom), RB_GETBARHEIGHT, 0, 0);

						ImageList_GetIconSize (himglist, &icon_size_x, &icon_size_y);

						IMAGELISTDRAWPARAMS ildp = {0};

						ildp.cbSize = sizeof (ildp);
						ildp.himl = himglist;
						ildp.hdcDst = lpnmlv->nmcd.hdc;
						ildp.i = tbi.iImage;
						ildp.x = lpnmlv->nmcd.rc.left + (LOWORD (padding) / 2);
						ildp.y = (rebar_height / 2) - (icon_size_y / 2);
						ildp.fState = ILS_SATURATE; // grayscale
						ildp.fStyle = ILD_NORMAL | ILD_ASYNC;

						ImageList_DrawIndirect (&ildp);
					}
				}

				if ((tbi.fsStyle & BTNS_SHOWTEXT) == BTNS_SHOWTEXT)
				{
					WCHAR text[MAX_PATH] = {0};
					SendMessage (lpnmlv->nmcd.hdr.hwndFrom, TB_GETBUTTONTEXT, (WPARAM)lpnmlv->nmcd.dwItemSpec, (LPARAM)text);

					if (tbi.iImage != I_IMAGENONE)
						lpnmlv->nmcd.rc.left += icon_size_x;

					DrawTextEx (lpnmlv->nmcd.hdc, text, (INT)_r_str_length (text), &lpnmlv->nmcd.rc, DT_CENTER | DT_VCENTER | DT_SINGLELINE | DT_HIDEPREFIX, NULL);
				}

				return CDRF_SKIPDEFAULT;
			}

			break;
		}
	}

	return CDRF_DODEFAULT;
}
