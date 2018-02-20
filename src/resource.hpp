#ifndef __RESOURCE_H__
#define __RESOURCE_H__

#ifndef IDC_STATIC
#define IDC_STATIC (-1)
#endif

// Acceleration
#define IDA_MAIN 1

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
#define IDD_SETTINGS_HIGHLIGHTING 105
#define IDD_SETTINGS_RULES 106
#define IDD_SETTINGS_RULES_BLOCKLIST 107
#define IDD_SETTINGS_RULES_SYSTEM 108
#define IDD_SETTINGS_RULES_CUSTOM 109
#define IDD_SETTINGS_LOG 110

// Main Dlg
#define IDC_LISTVIEW 104
#define IDC_START_BTN 105
#define IDC_SETTINGS_BTN 106
#define IDC_EXIT_BTN 107
#define IDC_STATUSBAR 108

// Notification Dlg
#define IDC_ICON_ID 109
#define IDC_TITLE_ID 110
#define IDC_MUTE_BTN 111
#define IDC_CLOSE_BTN 112
#define IDC_FILE_ID 113
#define IDC_ADDRESS_REMOTE_ID 114
#define IDC_ADDRESS_LOCAL_ID 115
#define IDC_FILTER_ID 116
#define IDC_DATE_ID 117
#define IDC_CREATERULE_ADDR_ID 118
#define IDC_CREATERULE_PORT_ID 119
#define IDC_TIMER_CB 120
#define IDC_ALLOW_BTN 121
#define IDC_BLOCK_BTN 122
#define IDC_IGNORE_BTN 123

// Editor Dlg
#define IDC_NAME 124
#define IDC_NAME_EDIT 125
#define IDC_PORTVERSION 126
#define IDC_PORTVERSION_EDIT 127
#define IDC_PROTOCOL 128
#define IDC_PROTOCOL_EDIT 129
#define IDC_DIRECTION 130
#define IDC_DIRECTION_EDIT 131
#define IDC_ACTION 132
#define IDC_ACTION_EDIT 133
#define IDC_RULES 134
#define IDC_RULES_EDIT 135
#define IDC_REGION 136
#define IDC_DISABLE_CHK 137
#define IDC_ENABLE_CHK 138
#define IDC_ENABLEFORAPPS_CHK 139
#define IDC_APPS_LV 140

// Settings Dlg
#define IDC_NAV 141
#define IDC_SAVE 142
#define IDC_CLOSE 143
#define IDC_WIKI 144

#define IDC_TITLE_GENERAL 145
#define IDC_TITLE_LANGUAGE 146
#define IDC_TITLE_CONFIRMATIONS 147
#define IDC_TITLE_HIGHLIGHTING 148
#define IDC_TITLE_EXPERTS 149
#define IDC_TITLE_NOTIFICATIONS 150
#define IDC_TITLE_LOGGING 151
#define IDC_TITLE_ADVANCED 152

#define IDC_ALWAYSONTOP_CHK 153
#define IDC_LOADONSTARTUP_CHK 154
#define IDC_STARTMINIMIZED_CHK 155
#define IDC_SKIPUACWARNING_CHK 156
#define IDC_CHECKUPDATES_CHK 157

#define IDC_LANGUAGE_HINT 158
#define IDC_LANGUAGE 159

#define IDC_CONFIRMEXIT_CHK 160
#define IDC_CONFIRMEXITTIMER_CHK 161
#define IDC_CONFIRMDELETE_CHK 162
#define IDC_CONFIRMLOGCLEAR_CHK 163

#define IDC_COLORS_HINT 164

#define IDC_RULE_ALLOWINBOUND 165
#define IDC_RULE_ALLOWLISTEN 166
#define IDC_RULE_ALLOWLOOPBACK 167

#define IDC_USEFULLBLOCKLIST_CHK 168
#define IDC_USESTEALTHMODE_CHK 169
#define IDC_INSTALLBOOTTIMEFILTERS_CHK 170
#define IDC_PROXYSUPPORT_CHK 171

#define IDC_USEHOSTS_CHK 172
#define IDC_USECERTIFICATES_CHK 173
#define IDC_USENETWORKRESOLUTION_CHK 174

#define IDC_ENABLELOG_CHK 175
#define IDC_LOGPATH 176
#define IDC_LOGPATH_BTN 177

#define IDC_LOGSIZELIMIT_HINT 178
#define IDC_LOGSIZELIMIT_CTRL 179
#define IDC_LOGSIZELIMIT 180

#define IDC_ENABLENOTIFICATIONS_CHK 181
#define IDC_NOTIFICATIONSOUND_CHK 182
#define IDC_NOTIFICATIONDISPLAYTIMEOUT_HINT 183
#define IDC_NOTIFICATIONDISPLAYTIMEOUT_CTRL 184
#define IDC_NOTIFICATIONDISPLAYTIMEOUT 185
#define IDC_NOTIFICATIONTIMEOUT_HINT 186
#define IDC_NOTIFICATIONTIMEOUT_CTRL 187
#define IDC_NOTIFICATIONTIMEOUT 188
#define IDC_NOTIFICATIONNOBLOCKLIST_CHK 189

#define IDC_RULES_BLOCKLIST_HINT 190
#define IDC_RULES_SYSTEM_HINT 191
#define IDC_RULES_CUSTOM_HINT 192

#define IDC_COLORS 193
#define IDC_EDITOR 194

// Main Menu
#define IDM_SETTINGS 195
#define IDM_EXIT 196
#define IDM_PURGE_UNUSED 197
#define IDM_PURGE_ERRORS 198
#define IDM_PURGE_TIMERS 199
#define IDM_FIND 200
#define IDM_FINDNEXT 201
#define IDM_REFRESH 202
#define IDM_ALWAYSONTOP_CHK 203
#define IDM_SHOWFILENAMESONLY_CHK 204
#define IDM_AUTOSIZECOLUMNS_CHK 205
#define IDM_ICONSSMALL 206
#define IDM_ICONSLARGE 207
#define IDM_ICONSISHIDDEN 208
#define IDM_FONT 209
#define IDM_ENABLELOG_CHK 210
#define IDM_ENABLENOTIFICATIONS_CHK 211
#define IDM_LOGSHOW 212
#define IDM_LOGCLEAR 213
#define IDM_WEBSITE 214
#define IDM_CHECKUPDATES 215
#define IDM_ABOUT 216

// Tray Menu
#define IDM_TRAY_SHOW 217
#define IDM_TRAY_START 218
#define IDM_TRAY_MODEWHITELIST 219
#define IDM_TRAY_MODEBLACKLIST 220
#define IDM_TRAY_ENABLELOG_CHK 221
#define IDM_TRAY_ENABLENOTIFICATIONS_CHK 222
#define IDM_TRAY_LOGSHOW 223
#define IDM_TRAY_LOGCLEAR 224
#define IDM_TRAY_LOGSHOW_ERR 225
#define IDM_TRAY_LOGCLEAR_ERR 226
#define IDM_TRAY_SETTINGS 227
#define IDM_TRAY_WEBSITE 228
#define IDM_TRAY_ABOUT 229
#define IDM_TRAY_EXIT 230

// Listview Menu
#define IDM_ADD_FILE 231
#define IDM_ALL_PROCESSES 232
#define IDM_ALL_PACKAGES 233
#define IDM_ALL_SERVICES 234
#define IDM_REFRESH2 235
#define IDM_DISABLENOTIFICATIONS 236
#define IDM_OPENRULESEDITOR 237
#define IDM_EXPLORE 238
#define IDM_COPY 239
#define IDM_CHECK 240
#define IDM_UNCHECK 241
#define IDM_DISABLETIMER 242

#define IDM_ADD 243
#define IDM_EDIT 244
#define IDM_DELETE 245

#define IDM_EXPORT_APPS 246
#define IDM_EXPORT_RULES 247
#define IDM_IMPORT_APPS 248
#define IDM_IMPORT_RULES 249

#define IDM_SELECT_ALL 250
#define IDM_ZOOM 251

#define IDX_PROCESS 1000
#define IDX_PACKAGE 2000
#define IDX_SERVICE 3000
#define IDX_LANGUAGE 4000
#define IDX_RULES_SPECIAL 5000
#define IDX_TIMER 6000

// Strings
#define IDS_UPDATE_NO 1
#define IDS_UPDATE_YES 2
#define IDS_FILE 3
#define IDS_SETTINGS 4
#define IDS_EXIT 5
#define IDS_EDIT 6
#define IDS_PURGE_ERRORS 7
#define IDS_PURGE_UNUSED 8
#define IDS_PURGE_TIMERS 9
#define IDS_FIND 10
#define IDS_FINDNEXT 11
#define IDS_REFRESH 12
#define IDS_VIEW 13
#define IDS_ICONS 14
#define IDS_ICONSSMALL 15
#define IDS_ICONSLARGE 16
#define IDS_ICONSISHIDDEN 17
#define IDS_LANGUAGE 18
#define IDS_FONT 19
#define IDS_HELP 20
#define IDS_WEBSITE 21
#define IDS_CHECKUPDATES 22
#define IDS_DONATE 23
#define IDS_ABOUT 24
#define IDS_TRAY_SHOW 25
#define IDS_TRAY_START 26
#define IDS_TRAY_STOP 27
#define IDS_TRAY_MODE 28
#define IDS_TRAY_RULES 29
#define IDS_TRAY_BLOCKLIST_RULES 30
#define IDS_TRAY_SYSTEM_RULES 31
#define IDS_TRAY_USER_RULES 32
#define IDS_TRAY_LOG 33
#define IDS_TRAY_LOGERR 34
#define IDS_TRAY_SYSTEM 35
#define IDS_ADD_FILE 36
#define IDS_ADD_PROCESS 37
#define IDS_ADD_PACKAGE 38
#define IDS_ADD_SERVICE 39
#define IDS_ALL 40
#define IDS_DISABLENOTIFICATIONS 41
#define IDS_OPENRULESEDITOR 42
#define IDS_TIMER 43
#define IDS_NOTIMER 44
#define IDS_DISABLETIMER 45
#define IDS_EXPLORE 46
#define IDS_COPY 47
#define IDS_SELECT_ALL 48
#define IDS_CHECK 49
#define IDS_UNCHECK 50
#define IDS_ADD 51
#define IDS_EDIT2 52
#define IDS_DELETE 53
#define IDS_EXPORT 54
#define IDS_IMPORT 55
#define IDS_MODE_WHITELIST 56
#define IDS_MODE_BLACKLIST 57
#define IDS_RULE_ALLOWINBOUND 58
#define IDS_RULE_ALLOWLISTEN 59
#define IDS_RULE_ALLOWLOOPBACK 60
#define IDS_HIGHLIGHT_INVALID 61
#define IDS_HIGHLIGHT_NETWORK 62
#define IDS_HIGHLIGHT_PACKAGE 63
#define IDS_HIGHLIGHT_PICO 64
#define IDS_HIGHLIGHT_SERVICE 65
#define IDS_HIGHLIGHT_SIGNED 66
#define IDS_HIGHLIGHT_SILENT 67
#define IDS_HIGHLIGHT_SPECIAL 68
#define IDS_HIGHLIGHT_SYSTEM 69
#define IDS_HIGHLIGHT_TIMER 70
#define IDS_EDITOR 71
#define IDS_NAME 72
#define IDS_RULE 73
#define IDS_PORTVERSION 74
#define IDS_PROTOCOL 75
#define IDS_DIRECTION 76
#define IDS_ACTION 77
#define IDS_DATE 78
#define IDS_FILEPATH 79
#define IDS_SIGNATURE 80
#define IDS_ADDRESS 81
#define IDS_FILTER 82
#define IDS_NOTES 83
#define IDS_ADDED 84
#define IDS_REGION 85
#define IDS_TIMELEFT 86
#define IDS_SIGN_SIGNED 87
#define IDS_SIGN_UNSIGNED 88
#define IDS_GROUP_ALLOWED 89
#define IDS_GROUP_BLOCKED 90
#define IDS_GROUP_ENABLED 91
#define IDS_GROUP_SPECIAL 92
#define IDS_GROUP_DISABLED 93
#define IDS_DIRECTION_1 94
#define IDS_DIRECTION_2 95
#define IDS_DIRECTION_3 96
#define IDS_ACTION_ALLOW 97
#define IDS_ACTION_BLOCK 98
#define IDS_ACTION_IGNORE 99
#define IDS_RULE_APPLY 100
#define IDS_DISABLE_CHK 101
#define IDS_ENABLE_CHK 102
#define IDS_ENABLEFORAPPS_CHK 103
#define IDS_WIKI 104
#define IDS_SAVE 105
#define IDS_CLOSE 106
#define IDS_SETTINGS_GENERAL 107
#define IDS_TITLE_GENERAL 108
#define IDS_TITLE_LANGUAGE 109
#define IDS_TITLE_CONFIRMATIONS 110
#define IDS_TITLE_INTERFACE 111
#define IDS_TITLE_HIGHLIGHTING 112
#define IDS_TITLE_EXPERTS 113
#define IDS_TITLE_LOGGING 114
#define IDS_TITLE_NOTIFICATIONS 115
#define IDS_TITLE_ADVANCED 116
#define IDS_ALWAYSONTOP_CHK 117
#define IDS_LOADONSTARTUP_CHK 118
#define IDS_STARTMINIMIZED_CHK 119
#define IDS_SHOWFILENAMESONLY_CHK 120
#define IDS_AUTOSIZECOLUMNS_CHK 121
#define IDS_SKIPUACWARNING_CHK 122
#define IDS_CHECKUPDATES_CHK 123
#define IDS_LANGUAGE_HINT 124
#define IDS_USEFULLBLOCKLIST_CHK 125
#define IDS_USEFULLBLOCKLIST_HINT 126
#define IDS_USESTEALTHMODE_CHK 127
#define IDS_USESTEALTHMODE_HINT 128
#define IDS_INSTALLBOOTTIMEFILTERS_CHK 129
#define IDS_INSTALLBOOTTIMEFILTERS_HINT 130
#define IDS_PROXYSUPPORT_CHK 131
#define IDS_PROXYSUPPORT_HINT 132
#define IDS_USEHOSTS_CHK 133
#define IDS_USECERTIFICATES_CHK 134
#define IDS_USENETWORKRESOLUTION_CHK 135
#define IDS_DISABLEWINDOWSFIREWALL_CHK 136
#define IDS_ENABLEWINDOWSFIREWALL_CHK 137
#define IDS_CONFIRMEXIT_CHK 138
#define IDS_CONFIRMEXITTIMER_CHK 139
#define IDS_CONFIRMDELETE_CHK 140
#define IDS_CONFIRMLOGCLEAR_CHK 141
#define IDS_COLORS_HINT 142
#define IDS_ENABLELOG_CHK 143
#define IDS_LOGSHOW 144
#define IDS_LOGCLEAR 145
#define IDS_LOGSIZELIMIT_HINT 146
#define IDS_ENABLENOTIFICATIONS_CHK 147
#define IDS_NOTIFICATIONSOUND_CHK 148
#define IDS_NOTIFICATIONNOBLOCKLIST_CHK 149
#define IDS_NOTIFICATIONDISPLAYTIMEOUT_HINT 150
#define IDS_NOTIFICATIONTIMEOUT_HINT 151
#define IDS_RULES_BLOCKLIST_HINT 152
#define IDS_RULES_SYSTEM_HINT 153
#define IDS_RULES_USER_HINT 154
#define IDS_NOTIFY_CREATERULE_ADDRESS 155
#define IDS_NOTIFY_CREATERULE_PORT 156
#define IDS_NOTIFY_DISABLENOTIFICATIONS 157
#define IDS_NOTIFY_TOOLTIP 158
#define IDS_QUESTION 159
#define IDS_QUESTION_DELETE 160
#define IDS_QUESTION_START 161
#define IDS_QUESTION_STOP 162
#define IDS_QUESTION_MODE 163
#define IDS_QUESTION_EXIT 164
#define IDS_QUESTION_LISTEN 165
#define IDS_QUESTION_EXPERT 166
#define IDS_QUESTION_TIMER 167
#define IDS_QUESTION_TIMERS 168
#define IDS_QUESTION_FLAG_CHK 169
#define IDS_STATUS_TOTAL 170
#define IDS_STATUS_SELECTED 171
#define IDS_STATUS_EMPTY 172
#define IDS_STATUS_ERROR 173
#define IDS_STATUS_SYNTAX_ERROR 174

// RC data
#define IDR_RULES_BLOCKLIST 1
#define IDR_RULES_SYSTEM 2

// Icons
#define IDI_MAIN 100
#define IDI_ACTIVE IDI_MAIN
#define IDI_INACTIVE 101
#define IDI_ALLOW 102
#define IDI_BLOCK 103
#define IDI_MUTE 104
#define IDI_CLOSE 105

#endif // __RESOURCE_H__
