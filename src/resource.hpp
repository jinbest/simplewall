#ifndef __RESOURCE_H__
#define __RESOURCE_H__

#ifndef IDC_STATIC
#define IDC_STATIC (-1)
#endif

// Acceleration
#define IDA_MAIN 100

// Menu Id
#define IDM_MAIN 100
#define IDM_TRAY 101
#define IDM_LISTVIEW 102
#define IDM_EDITOR 103

// Dialogs
#define IDD_MAIN 100
#define IDD_EDITOR 101
#define IDD_SETTINGS 102
#define IDD_SETTINGS_GENERAL 103
#define IDD_SETTINGS_INTERFACE 104
#define IDD_SETTINGS_FILTERS 105
#define IDD_SETTINGS_RULES_BLOCKLIST 106
#define IDD_SETTINGS_RULES_SYSTEM 107
#define IDD_SETTINGS_RULES_CUSTOM 108
#define IDD_SETTINGS_LOG 109

// Main Dlg
#define IDC_LISTVIEW 1000
#define IDC_START_BTN 1001
#define IDC_SETTINGS_BTN 1002
#define IDC_EXIT_BTN 1003
#define IDC_STATUSBAR 1004

// Notification Dlg
#define IDC_TITLE_ID 1100
#define IDC_CLOSE_BTN 1101
#define IDC_ICON_ID 1102
#define IDC_FILE_ID 1103
#define IDC_ADDRESS_ID 1104
#define IDC_FILTER_ID 1105
#define IDC_DATE_ID 1106
#define IDC_CREATERULE_ADDR_ID 1107
#define IDC_CREATERULE_PORT_ID 1108
#define IDC_DISABLENOTIFY_ID 1109
#define IDC_NEXT_ID 1110
#define IDC_PREV_ID 1111
#define IDC_IDX_ID 1112
#define IDC_ALLOW_BTN 1113
#define IDC_BLOCK_BTN 1114

// Editor Dlg
#define IDC_NAME 2000
#define IDC_NAME_EDIT 2001
#define IDC_PORTVERSION 2002
#define IDC_PORTVERSION_EDIT 2003
#define IDC_PROTOCOL 2004
#define IDC_PROTOCOL_EDIT 2005
#define IDC_DIRECTION 2006
#define IDC_DIRECTION_EDIT 2007
#define IDC_ACTION 2008
#define IDC_ACTION_EDIT 2009
#define IDC_RULES 2010
#define IDC_RULES_EDIT 2011
#define IDC_FILES 2012
#define IDC_FILES_LV 2013
#define IDC_RULES_WIKI 2014
#define IDC_ENABLED_CHK 2015

// Settings Dlg
#define IDC_NAV 1000
#define IDC_SAVE 1001
#define IDC_CLOSE 1002

#define IDC_TITLE_GENERAL 1003
#define IDC_TITLE_LANGUAGE 1004
#define IDC_TITLE_CONFIRMATIONS 1005
#define IDC_TITLE_HIGHLIGHTING 1006
#define IDC_TITLE_EXPERTS 1007
#define IDC_TITLE_NOTIFICATIONS 1008
#define IDC_TITLE_ADVANCED 1009

#define IDC_ALWAYSONTOP_CHK 100
#define IDC_LOADONSTARTUP_CHK 101
#define IDC_SKIPUACWARNING_CHK 102
#define IDC_CHECKUPDATES_CHK 103

#define IDC_LANGUAGE_HINT 104
#define IDC_LANGUAGE 105

#define IDC_RULE_ALLOWINBOUND 106
#define IDC_RULE_ALLOWLISTEN 107
#define IDC_RULE_ALLOWLOOPBACK 108

#define IDC_USEFULLBLOCKLIST_CHK 109
#define IDC_USESTEALTHMODE_CHK 110
#define IDC_INSTALLBOOTTIMEFILTERS_CHK 111
#define IDC_PROXYSUPPORT_CHK 112

#define IDC_USEHOSTS_CHK 113

#define IDC_CONFIRMEXIT_CHK 114
#define IDC_CONFIRMDELETE_CHK 115
#define IDC_CONFIRMLOGCLEAR_CHK 116

#define IDC_COLORS_HINT 117

#define IDC_ENABLELOG_CHK 118
#define IDC_LOGPATH 119
#define IDC_LOGPATH_BTN 120

#define IDC_LOGSIZELIMIT_HINT 121
#define IDC_LOGSIZELIMIT_CTRL 122
#define IDC_LOGSIZELIMIT 123

#define IDC_LOGBACKUP_CHK 124

#define IDC_ENABLENOTIFICATIONS_CHK 125
#define IDC_NOTIFICATIONSILENT_CHK 126
#define IDC_NOTIFICATIONDISPLAYTIMEOUT_HINT 127
#define IDC_NOTIFICATIONDISPLAYTIMEOUT_CTRL 128
#define IDC_NOTIFICATIONDISPLAYTIMEOUT 129
#define IDC_NOTIFICATIONTIMEOUT_HINT 130
#define IDC_NOTIFICATIONTIMEOUT_CTRL 131
#define IDC_NOTIFICATIONTIMEOUT 132
#define IDC_NOTIFICATIONNOBLOCKLIST_CHK 133

#define IDC_RULES_BLOCKLIST_HINT 140
#define IDC_RULES_SYSTEM_HINT 141
#define IDC_RULES_CUSTOM_HINT 142

#define IDC_COLORS 200
#define IDC_EDITOR 201

// Main Menu
#define IDM_SETTINGS 2000
#define IDM_EXIT 2001
#define IDM_PURGEN 2002
#define IDM_FIND 2003
#define IDM_FINDNEXT 2004
#define IDM_REFRESH 2005
#define IDM_ALWAYSONTOP_CHK 2006
#define IDM_SHOWFILENAMESONLY_CHK 2007
#define IDM_AUTOSIZECOLUMNS_CHK 2008
#define IDM_ICONSSMALL 2009
#define IDM_ICONSLARGE 2010
#define IDM_ICONSISHIDDEN 2011
#define IDM_FONT 2012
#define IDM_ENABLELOG_CHK 2013
#define IDM_ENABLENOTIFICATIONS_CHK 2014
#define IDM_LOGSHOW 2015
#define IDM_LOGCLEAR 2016
#define IDM_WEBSITE 2017
#define IDM_DONATE 2018
#define IDM_CHECKUPDATES 2019
#define IDM_ABOUT 2020

// Tray Menu
#define IDM_TRAY_SHOW 3000
#define IDM_TRAY_START 3001
#define IDM_TRAY_MODEWHITELIST 3002
#define IDM_TRAY_MODEBLACKLIST 3003
#define IDM_TRAY_ENABLELOG_CHK 3004
#define IDM_TRAY_ENABLENOTIFICATIONS_CHK 3005
#define IDM_TRAY_LOGSHOW 3006
#define IDM_TRAY_LOGCLEAR 3007
#define IDM_TRAY_LOGSHOW_ERR 3008
#define IDM_TRAY_LOGCLEAR_ERR 3009
#define IDM_TRAY_SETTINGS 3010
#define IDM_TRAY_WEBSITE 3011
#define IDM_TRAY_ABOUT 3012
#define IDM_TRAY_EXIT 3013

// Listview Menu
#define IDM_ADD_FILE 4000
#define IDM_ALL_PROCESSES 4001
#define IDM_ALL_PACKAGES 4002
#define IDM_REFRESH2 4003
#define IDM_DISABLENOTIFICATIONS 4004
#define IDM_OPENRULESEDITOR 4005
#define IDM_EXPLORE 4006
#define IDM_COPY 4007
#define IDM_CHECKALL 4008
#define IDM_UNCHECKALL 4009
#define IDM_CHECK 4010
#define IDM_UNCHECK 4011

#define IDM_ADD 4012
#define IDM_EDIT 4013
#define IDM_DELETE 4014

#define IDM_EXPORT_APPS 4015
#define IDM_EXPORT_RULES 4016

#define IDM_IMPORT_APPS 4017
#define IDM_IMPORT_RULES 4018

#define IDM_SELECT_ALL 4020
#define IDM_ZOOM 4021

#define IDM_PROCESS 5000
#define IDM_PACKAGE 5100
#define IDM_LANGUAGE 5200
#define IDM_RULES_SPECIAL 5300

// Strings
#define IDS_UPDATE_NO 1001
#define IDS_UPDATE_YES 1002

#define IDS_DONATE 1003
#define IDS_DONATE_TEXT 1004
#define IDS_SHOWATSTARTUP_CHK 1005

#define IDS_FILE 1006
#define IDS_SETTINGS 1007
#define IDS_EXIT 1008
#define IDS_EDIT 1009
#define IDS_PURGEN 1010
#define IDS_FIND 1011
#define IDS_FINDNEXT 1012
#define IDS_REFRESH 1013
#define IDS_VIEW 1014
#define IDS_ICONS 1015
#define IDS_ICONSSMALL 1016
#define IDS_ICONSLARGE 1017
#define IDS_ICONSISHIDDEN 1018
#define IDS_LANGUAGE 1019
#define IDS_FONT 1020
#define IDS_HELP 1021
#define IDS_WEBSITE 1022
#define IDS_CHECKUPDATES 1023
#define IDS_ABOUT 1024

#define IDS_TRAY_SHOW 2000
#define IDS_TRAY_START 2001
#define IDS_TRAY_STOP 2002
#define IDS_TRAY_MODE 2003
#define IDS_TRAY_FILTERS 2004
#define IDS_TRAY_BLOCKLIST_RULES 2005
#define IDS_TRAY_SYSTEM_RULES 2006
#define IDS_TRAY_CUSTOM_RULES 2007
#define IDS_TRAY_LOG 2008
#define IDS_TRAY_LOGERR 2009

#define IDS_ADD_FILE 3000
#define IDS_ADD_PROCESS 3001
#define IDS_ADD_PACKAGE 3002
#define IDS_ALL 3003
#define IDS_DISABLENOTIFICATIONS 3004
#define IDS_OPENRULESEDITOR 3005
#define IDS_EXPLORE 3006
#define IDS_COPY 3007
#define IDS_CHECKALL 3008
#define IDS_UNCHECKALL 3009
#define IDS_CHECK 3010
#define IDS_UNCHECK 3011

#define IDS_ADD 3012
#define IDS_EDIT2 3013
#define IDS_DELETE 3014
#define IDS_EXPORT 3015
#define IDS_IMPORT 3016

#define IDS_EXPORT_APPS 3017
#define IDS_EXPORT_RULES 3018

#define IDS_IMPORT_APPS 3019
#define IDS_IMPORT_RULES 3020

#define IDS_MODE_WHITELIST 4000
#define IDS_MODE_BLACKLIST 4001

#define IDS_RULE_ALLOWINBOUND 5000
#define IDS_RULE_ALLOWLISTEN 5001
#define IDS_RULE_ALLOWLOOPBACK 5002

#define IDS_HIGHLIGHT_INVALID 6000
#define IDS_HIGHLIGHT_NETWORK 6001
#define IDS_HIGHLIGHT_PACKAGE 6002
#define IDS_HIGHLIGHT_PICO 6003
#define IDS_HIGHLIGHT_SIGNED 6004
#define IDS_HIGHLIGHT_SILENT 6005
#define IDS_HIGHLIGHT_SPECIAL 6006
#define IDS_HIGHLIGHT_SYSTEM 6007

#define IDS_EDITOR 7000

#define IDS_NAME 7001
#define IDS_RULE 7002
#define IDS_PORTVERSION 7003
#define IDS_PROTOCOL 7004
#define IDS_DIRECTION 7005
#define IDS_ACTION 7006
#define IDS_DATE 7007
#define IDS_FILEPATH 7008
#define IDS_SIGNATURE 7009
#define IDS_ADDRESS 7010
#define IDS_FILTER 7011
#define IDS_NOTES 7012
#define IDS_ADDED 7013
#define IDS_APPLYTO 7033

#define IDS_SIGN_SIGNED 7014
#define IDS_SIGN_UNSIGNED 7015

#define IDS_GROUP_ALLOWED 7016
#define IDS_GROUP_BLOCKED 7017

#define IDS_GROUP_GLOBAL 7018
#define IDS_GROUP_SPECIAL 7019
#define IDS_GROUP_DISABLED 7020

#define IDS_DIRECTION_1 7021
#define IDS_DIRECTION_2 7022
#define IDS_DIRECTION_3 7023

#define IDS_ACTION_1 7024
#define IDS_ACTION_2 7025
#define IDS_ACTION_3 7026

#define IDS_RULE_TITLE_1 7027
#define IDS_RULE_TITLE_2 7028

#define IDS_RULES_WIKI 7029

#define IDS_ENABLERULE_CHK 7030

#define IDS_SETTINGS_1 8000
#define IDS_SETTINGS_3 8001

#define IDS_SAVE 8002
#define IDS_CLOSE 8003

#define IDS_TITLE_GENERAL 8004
#define IDS_TITLE_LANGUAGE 8005
#define IDS_TITLE_CONFIRMATIONS 8006
#define IDS_TITLE_HIGHLIGHTING 8007
#define IDS_TITLE_EXPERTS 8008
#define IDS_TITLE_NOTIFICATIONS 8009
#define IDS_TITLE_ADVANCED 8010

#define IDS_ALWAYSONTOP_CHK 9000
#define IDS_LOADONSTARTUP_CHK 9001
#define IDS_SHOWFILENAMESONLY_CHK 9002
#define IDS_AUTOSIZECOLUMNS_CHK 9003
#define IDS_SKIPUACWARNING_CHK 9004
#define IDS_CHECKUPDATES_CHK 9005

#define IDS_LANGUAGE_HINT 9006

#define IDS_USEFULLBLOCKLIST_CHK 9007
#define IDS_USEFULLBLOCKLIST_HINT 9008
#define IDS_USESTEALTHMODE_CHK 9009
#define IDS_USESTEALTHMODE_HINT 9010
#define IDS_INSTALLBOOTTIMEFILTERS_CHK 9011
#define IDS_INSTALLBOOTTIMEFILTERS_HINT 9012
#define IDS_PROXYSUPPORT_CHK 9013
#define IDS_PROXYSUPPORT_HINT 9014

#define IDS_USEHOSTS_CHK 9044

#define IDS_DISABLEWINDOWSFIREWALL_CHK 9015
#define IDS_ENABLEWINDOWSFIREWALL_CHK 9016

#define IDS_CONFIRMEXIT_CHK 9017
#define IDS_CONFIRMDELETE_CHK 9018
#define IDS_CONFIRMLOGCLEAR_CHK 9019

#define IDS_COLORS_HINT 9020

#define IDS_ENABLELOG_CHK 9021
#define IDS_LOGSHOW 9022
#define IDS_LOGCLEAR 9023

#define IDS_LOGSIZELIMIT_HINT 9024
#define IDS_LOGBACKUP_CHK 9025

#define IDS_ENABLENOTIFICATIONS_CHK 9026
#define IDS_NOTIFICATIONSILENT_CHK 9027
#define IDS_NOTIFICATIONDISPLAYTIMEOUT_HINT 9028
#define IDS_NOTIFICATIONTIMEOUT_HINT 9029
#define IDS_NOTIFICATIONNOBLOCKLIST_CHK 9030

#define IDS_RULES_BLOCKLIST_HINT 9031
#define IDS_RULES_SYSTEM_HINT 9032
#define IDS_RULES_CUSTOM_HINT 9033

#define IDS_NOTIFY_CREATERULE_ADDRESS 9034
#define IDS_NOTIFY_CREATERULE_PORT 9035
#define IDS_NOTIFY_DISABLENOTIFICATIONS 9036
#define IDS_NOTIFY_TOOLTIP 9037

#define IDS_QUESTION 10000
#define IDS_QUESTION_DELETE 10001
#define IDS_QUESTION_START 10002
#define IDS_QUESTION_STOP 10003
#define IDS_QUESTION_EXIT 10004
#define IDS_QUESTION_LISTEN 10005
#define IDS_QUESTION_EXPERT 10006
#define IDS_QUESTION_FLAG_CHK 10007

#define IDS_STATUS_TOTAL 10008
#define IDS_STATUS_SELECTED 10009

#define IDS_STATUS_EMPTY 10010

#define IDS_STATUS_ERROR 10011
#define IDS_STATUS_SYNTAX_ERROR 10012

// RC data
#define IDR_RULES_BLOCKLIST 1
#define IDR_RULES_SYSTEM 2

// Icons
#define IDI_MAIN 100
#define IDI_ACTIVE IDI_MAIN
#define IDI_INACTIVE 101
#define IDI_ALLOW 102
#define IDI_BLOCK 103
#define IDI_CLOSE 104

#endif // __RESOURCE_H__
