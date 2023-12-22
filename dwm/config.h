/* settings */
static const unsigned int borderpx  = 2;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const unsigned int gappx     = 0;
static const char *fonts[]          = { "JetBrainsMono Nerd Font:size=10" };
/* color */
static const char col_gray1[]       = "#1d2021";
static const char col_gray2[]       = "#B16286";
static const char col_gray3[]       = "#a89984";
static const char col_gray4[]       = "#1d2021";
static const char col_cyan[]        = "#83a598";
/*color status */
static const char col_green[]       = "#bcb18e";
static const char col_text[]        = "#2e2d2c";
static const char col_blue[]        = "#458588";
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_gray1, col_blue, col_gray2 },
	[SchemeSel]  = { col_gray4, col_cyan,  col_cyan  },
  [SchemeStatus] = { col_text, col_green },
  [SchemeTagsSel]  = { col_gray4, col_cyan },
  [SchemeTagsNorm]  = { col_gray4, col_blue },
};

/* workspace */
static const char *tags[] = { "一", "二", "三", "四", "五", "六", "七", "八" };

static const Rule rules[] = {
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Gimp",             NULL,       NULL,       0,            1,           -1 },
	{ "librewolf-bin",    NULL,       NULL,       1 << 1,       0,           -1 },
	{ "qutebrowser",      NULL,       NULL,       1 << 1,       0,           -1 },
	{ "Pcmanfm",          NULL,       NULL,       1 << 2,       0,           -1 },
	{ "TelegramDesktop",  NULL,       NULL,       1 << 3,       0,           -1 },
	{ "Popcorn-Time",     NULL,       NULL,       1 << 4,       0,           -1 },
	{ "steam",     	      NULL,       NULL,       1 << 7,       0,           -1 },
  { "Gcolor3",          NULL,       NULL,       0,            1,           -1 },
  { "Lxappearance",     NULL,       NULL,       0,            1,           -1 },
  { "Viewnior",         NULL,       NULL,       0,            1,           -1 },
  { "Nitrogen",         NULL,       NULL,       0,            1,           -1 },

};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
	{ "十",      tile },
	{ "百",      NULL },   
	{ "千",      monocle },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static const char *dmenucmd[]   = { "dmenu_run", NULL };
static const char *termcmd[]    = { "st", NULL };
static const char *webcmd[]     = { "qutebrowser", NULL };
static const char *filcmd[]     = { "pcmanfm", NULL };
static const char *upvol[]      = { "amixer",  "set", "Master", "5%+", NULL };
static const char *downvol[]    = { "amixer",  "set", "Master", "5%-", NULL };
static const char *mutevol[]    = { "amixer", "set", "Master", "toggle", NULL };
static const char *brupcmd[]    = { "brightnessctl", "set", "10%+", NULL };
static const char *brdowncmd[]  = { "brightnessctl", "set", "10%-", NULL };
static const char *redshiftcmd[]  = { "redshift", "-P", "-O" "4600", NULL };
static const char *cmdprint[]   = { "scrot", "-d1", "/home/aquaverso/%Y-%m-%d-%s_$wx$h.png", NULL };
static const char *powermcmd[]  = { "/home/aquaverso/.config/rofi/powerm/powermenu.sh", NULL };


static const Key keys[] = {
  { MODKEY,                  XK_x,       spawn,          { .v = powermcmd } },
  { MODKEY,                  XK_F10,     spawn,          { .v = redshiftcmd } },
  { MODKEY,                  XK_F3,      spawn,          { .v = brupcmd } },
  { 0,                       XK_F12,     spawn,          { .v = cmdprint } },
  { 0,                       XK_F2,      spawn,          { .v = webcmd } },
  { 0,                       XK_F3,      spawn,          { .v = filcmd } },
  { MODKEY,                       XK_F3,      spawn,          { .v = brupcmd } },
  { MODKEY,                       XK_F2,      spawn,          { .v = brdowncmd } },
  { MODKEY,                       XK_F8,      spawn,          { .v = upvol } },
  { MODKEY,                       XK_F7,      spawn,          { .v = downvol } },
  { MODKEY,                       XK_F6,      spawn,          { .v = mutevol } },
	/* modifier                     key        function        argument */
  { MODKEY,                       XK_p,      spawn,          { .v = dmenucmd } },
	{ MODKEY,                       XK_Return, spawn,          { .v = termcmd } },
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY|ShiftMask,             XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY|ShiftMask,             XK_q,      killclient,     {0} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	{ MODKEY,                       XK_minus,  setgaps,        {.i = -1 } },
	{ MODKEY,                       XK_equal,  setgaps,        {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_equal,  setgaps,        {.i = 0  } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
/*	{ MODKEY|ShiftMask,             XK_x,      quit,           {0} },*/
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};
