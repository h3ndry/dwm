/* See LICENSE file for copyright and license details. */

#include <X11/XF86keysym.h>

/* appearance */
static const unsigned int borderpx  = 2;        /* border pixel of windows */
static const unsigned int fborderpx = 0;        /* border pixel of floating windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const int viewontag          = 1;     /* Switch view on tag switch */
static const int lockfullscreen     = 0; /* 1 will force focus on the fullscreen window */
static const char *fonts[]          = { "JetBrainsMono-Regular:size=11" };
static const char dmenufont[]       = "JetBrainsMono-Regular:size=11";
static const char col_gray1[]       = "#21262d"; //"#1f1f1f";
static const char col_gray2[]       = "#21262d"; //"#1f1f1f";"#1f1f1f";
static const char col_gray3[]       = "#a9b1d6";
static const char col_gray4[]       = "#c0caf5";
static const char col_cyan[]        = "#005577"; // static const char col_cyan[]        = "#164846";
static const char col_cyan1[]        = "#005577"; //7ee686 static 42cba5 const char col_cyan[]        = "#164846";
static const char col_urgborder[]   = "#ff9e64";
static const unsigned int baralpha = 0xd0;
static const unsigned int borderalpha = OPAQUE;
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
	[SchemeSel]  = { col_gray4, col_cyan,  col_cyan1  },
	[SchemeTitle]  = { col_gray4, col_gray1,  col_cyan  },
	[SchemeUrg]  = { col_gray4, col_cyan,  col_urgborder  },
};

static const unsigned int alphas[][3]      = {
	/*               fg      bg        border     */
	[SchemeNorm] = { OPAQUE, baralpha, borderalpha },
	[SchemeSel]  = { OPAQUE, baralpha, borderalpha },
};

static const XPoint stickyicon[]    = { {0,0}, {4,0}, {4,8}, {2,6}, {0,8}, {0,0} }; /* represents the icon as an array of vertices */
static const XPoint stickyiconbb    = {4,8};	/* defines the bottom right corner of the polygon's bounding box (speeds up scaling) */

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

/* initial layouts */ 
static const int  initlayouts[] = { 0, 0, 1, 0, 1, 0, 1, 2, 2, 3 };


static const char *upvol[]   = { "/usr/bin/pactl", "set-sink-volume", "0", "+5%",     NULL };
static const char *downvol[] = { "/usr/bin/pactl", "set-sink-volume", "0", "-5%",     NULL };
static const char *mutevol[] = { "/usr/bin/pactl", "set-sink-mute",   "0", "toggle",  NULL };
static const char *mic[] = { "/usr/bin/pactl", "set-source-mute ",   "0", "toggle",  NULL };
static const char *light_up[] = {"/usr/bin/brightnessctl", "set", "+5%", NULL};
static const char *light_down[] = {"/usr/bin/brightnessctl", "set", "5%-", NULL};

 // pactl 1 toggle


static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
     *	"bluemail", "BlueMail
     *	
     *	WM_CLASS(STRING) = "Toolkit", "firefox"
WM_ICON_NAME(STRING) = "Picture-in-Picture"
_NET_WM_ICON_NAME(UTF8_STRING) = "Picture-in-Picture"
WM_NAME(STRING) = "Picture-in-Picture"
_NET_WM_NAME(UTF8_STRING) = "Picture-in-Picture"

     *   CLASS(STRING) = "Toolkit", "firefox"
	 */
	/* class                            instance    title       tags mask      iscentered  switchtotag  isfloating  issticky  cantfocus ispermanent monitor */ 
	{ "Org.gnome.Nautilus",             NULL,       NULL,       1 << 2,        0,          1,          0,          0,         0,        0,         -1 },
	{ "speedcrunch",         	        NULL,       NULL,            0,        1,          0,          1,          1,         0,        0,         -1 },
	{ "SpeedCrunch",         	        NULL,       NULL,            0,        1,          0,          1,          1,         0,        0,         -1 },
	{ "Gimp",                           NULL,       NULL,       1 << 3,        0,          1,          1,          0,         0,        0,         -1 },
	{ "jetbrains-pycharm",              NULL,       NULL,       1 << 1,        0,          1,          0,          0,         0,        0,         -1 },
	{ "Insomnia",                       NULL,       NULL,       1 << 1,        0,          1,          0,          0,         0,        0,         -1 },
	{ "Inkscape",                       NULL,       NULL,       1 << 3,        0,          1,          0,          0,         0,        0,         -1 },
	{ "firefox",                        NULL,       NULL,       1 << 8,        0,          1,          0,          0,         0,        0,         -1 },
	{ "firefox",                        "Toolkit",  NULL,            0,        0,          0,          1,          1,         1,        1,         -1 },
	{ "brave-browser-nightly",          NULL,       NULL,       1 << 8,        0,          1,          0,          0,         0,        0,         -1 },
	{ "Brave-browser-nightly",          NULL,       NULL,       1 << 8,        0,          1,          0,          0,         0,        0,         -1 },
	{ "Microsoft-edge-beta",            NULL,       NULL,       1 << 8,        0,          1,          0,          0,         0,        0,         -1 },
	{ "microsoft-edge-beta",            NULL,       NULL,       1 << 8,        0,          1,          0,          0,         0,        0,         -1 },
	{ "Microsoft-edge",                 NULL,       NULL,       1 << 8,        0,          1,          0,          0,         0,        0,         -1 },
	{ "microsoft-edge",                 NULL,       NULL,       1 << 8,        0,          1,          0,          0,         0,        0,         -1 },
	{ "Slack",                          NULL,       NULL,       1 << 7,        0,          1,          0,          0,         0,        0,         -1 },
	{ "whatsapp-nativefier-d40211",     NULL,       NULL,       1 << 7,        0,          1,          0,          0,         0,        0,         -1 },
	{ "obs",                            NULL,       NULL,       1 << 7,        0,          1,          0,          0,         0,        0,         -1 },
	{ "kdenlive",                       NULL,       NULL,       1 << 7,        0,          1,          0,          0,         0,        0,         -1 },
	{ "discord",                        NULL,       NULL,       1 << 7,        1,          1,          0,          0,         0,        0,         -1 },
	{ "Zoom",                           NULL,       NULL,       1 << 7,        0,          0,          0,          0,         0,        0,         -1 },
	{ "DBeaver",                        NULL,       NULL,       1 << 7,        0,          1,          0,          0,         0,        0,         -1 },
	{ "Thunderbird",                    NULL,       NULL,       1 << 6,        0,          1,          0,          0,         0,        0,         -1 },
	{ "Evolution",                      NULL,       NULL,       1 << 6,        0,          1,          0,          0,         0,        0,         -1 },
	{ "BlueMail",                       NULL,       NULL,       1 << 6,        0,          1,          0,          0,         0,        0,         -1 },
	{ "st",                             NULL,       NULL,       1 << 0,        0,          1,          0,          0,         0,        0,         -1 },
	{ "Notes",                          NULL,       "Notes",         0,        1,          0,          1,          1,         0,        0,         -1 },
	{ "NIDE",                           NULL,       NULL,  SCRATCHPAD_MASK,     1,         0,          0,          0,         0,        0,         -1 },
};

/* window swallowing */
static const int swaldecay = 3;
static const int swalretroactive = 1;
static const char swalsymbol[] = "???/???";

/* layout(s) */
static const float mfact     = 0.60; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
	{ "###",      grid },
	{ "TTT",      bstack },
	{ "===",      bstackhoriz },
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
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", NULL  };
static const char *termcmd[]  = { "st", NULL };
static const char *lockcmd[]  = { "slock", NULL };
/*First arg only serves to match against key in rules*/
static const char *scratchpadcmd[] = {"s", "st", "-t", "scratchpad", NULL}; 


static Key keys[] = {
	/* modifier                     key            function        argument */
	{ MODKEY,                       XK_p,          spawn,          {.v = dmenucmd } },
	{ MODKEY,                       XK_Return,     spawn,          {.v = termcmd } },
	{ MODKEY|ShiftMask,             XK_e,          spawn,          {.v = lockcmd } },
	{ MODKEY,                       XK_e,      focusurgent,         {0} },
	{ MODKEY,                       XK_b,          togglebar,      {0} },
	{ MODKEY,                       XK_j,          focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,          focusstack,     {.i = -1 } },
	/* { MODKEY|ShiftMask,             XK_h,          inplacerotate,  {.i = +1} }, */
	/* { MODKEY|ShiftMask,             XK_l,          inplacerotate,  {.i = -1} }, */
	{ MODKEY|ShiftMask,             XK_j,           inplacerotate,  {.i = +2} },
	{ MODKEY|ShiftMask,             XK_k,           inplacerotate,  {.i = -2} },
	{ MODKEY,                       XK_y,           incnmaster,     {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_y,          incnmaster,     {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_h,          setmfact,       {.f = -0.05} },
	{ MODKEY|ShiftMask,             XK_l,          setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_h,          shiftview,      {.i = -1 } },
	{ MODKEY,                       XK_l,          shiftview,      {.i = +1 } },
	{ MODKEY,                       XK_space,      zoom,           {0} },
	{ MODKEY,                       XK_Tab,        view,           {0} },
	{ MODKEY|ShiftMask,             XK_Tab,        view,           {.ui = ~0 } },
	{ MODKEY,                       XK_q,          killclient,     {0} },
	{ MODKEY|ShiftMask,             XK_q,          quit,           {0} },
	{ MODKEY|ShiftMask,             XK_w,          killunsel,      {0} },
	{ MODKEY,                       XK_t,          setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,          setlayout,      {.v = &layouts[1]} },
	// { MODKEY|ShiftMask,             XK_f,          togglefloating, {0} },
    { MODKEY|ShiftMask,             XK_f,          unfloatvisible, {.v = &layouts[0]} },
	{ MODKEY,                       XK_m,          setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_g,          setlayout,      {.v = &layouts[3]} },
	{ MODKEY,                       XK_u,          setlayout,      {.v = &layouts[4]} },
	{ MODKEY|ShiftMask,             XK_u,          setlayout,      {.v = &layouts[5]} },
	{ MODKEY|ShiftMask,             XK_space,      setlayout,      {0} },
	{ MODKEY,                       XK_0,          view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,          tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_s,          togglesticky,   {0} },
	/* { MODKEY,                       XK_s,          focusmon,       {.i = -1 } }, */
	/* { MODKEY|ShiftMask,             XK_s,          focusmon,       {.i = +1 } }, */
	{ MODKEY,                       XK_v,          winview,        {0} },
	// { MODKEY,                       XK_a,          tagmon,         {.i = -1 } },
	// { MODKEY|ShiftMask,             XK_a,          togglescratch,         {0} },
	{ MODKEY,                       XK_comma,       focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period,      focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,       tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period,      tagmon,         {.i = +1 } },
	{ MODKEY,                       XK_z,           togglecanfocusfloating,    {0} },
	// { MODKEY,                       XK_6,          swapfocus,    {0} },
	{ MODKEY,                       XK_Left,        viewtoleft,         {0} },
	{ MODKEY,                       XK_Right,       viewtoright,        {0} },
	// { MODKEY|ShiftMask,             XK_h,          tagtoleft,               {0} },
	// { MODKEY|ShiftMask,             XK_l,          tagtoright,               {0} },
	{ MODKEY,                       XK_grave,           scratchpad_show,          {0} },
	{ MODKEY|ShiftMask,             XK_grave,           scratchpad_hide,          {0} },
	{ MODKEY|ShiftMask,             XK_r,           scratchpad_remove,        {0} },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ 0,    XF86XK_AudioLowerVolume,	 spawn,		    {.v = downvol } },
	{ 0,	XF86XK_AudioMute,		     spawn,		    {.v = mutevol } },
	{ 0,	XF86XK_AudioRaiseVolume,	 spawn,		    {.v = upvol   } },
	{ 0,	XF86XK_AudioMicMute,	     spawn,		    {.v = mic   } },
    { 0,	XF86XK_MonBrightnessUp,		spawn,	        {.v = light_up} },
	{ 0,	XF86XK_MonBrightnessDown,	spawn,	        {.v = light_down} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	/* { ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} }, */
	{ ClkClientWin,         MODKEY,         Button2,        resizemouse,    {0} },
	{ ClkClientWin,         MODKEY,         Button3,        swalmouse,      {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};
