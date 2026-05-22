/* DWM config.h — Catppuccin Mocha + JetBrains Mono Nerd Font
 * Tags: kanji numerals  |  Mod: Super key
 * Generated for Void Linux / X11
 */

/* ── Appearance ─────────────────────────────────────────────────────────── */
static const unsigned int borderpx       = 2;   /* border pixel of windows */
static const unsigned int snap           = 32;  /* snap pixel */
static const unsigned int gappih         = 8;   /* inner horiz gap */
static const unsigned int gappiv         = 8;   /* inner vert  gap */
static const unsigned int gappoh         = 10;  /* outer horiz gap */
static const unsigned int gappov         = 10;  /* outer vert  gap */
static const int smartgaps               = 1;   /* no outer gap when single window */
static const int showbar                 = 1;
static const int topbar                  = 1;
static const char *fonts[]               = {
    "JetBrainsMono Nerd Font:size=10:antialias=true:autohint=true",
    "Noto Color Emoji:size=10"
};
static const char dmenufont[]            = "JetBrainsMono Nerd Font:size=10";

/* ── Catppuccin Mocha palette ───────────────────────────────────────────── */
#define BASE    "#1e1e2e"
#define MANTLE  "#181825"
#define CRUST   "#11111b"
#define SURFACE0 "#313244"
#define SURFACE1 "#45475a"
#define SURFACE2 "#585b70"
#define OVERLAY0 "#6c7086"
#define OVERLAY1 "#7f849c"
#define OVERLAY2 "#9399b2"
#define TEXT    "#cdd6f4"
#define SUBTEXT0 "#a6adc8"
#define SUBTEXT1 "#bac2de"
#define LAVENDER "#b4befe"
#define BLUE    "#89b4fa"
#define SAPPHIRE "#74c7ec"
#define SKY     "#89dceb"
#define TEAL    "#94e2d5"
#define GREEN   "#a6e3a1"
#define YELLOW  "#f9e2af"
#define PEACH   "#fab387"
#define MAROON  "#eba0ac"
#define RED     "#f38ba8"
#define MAUVE   "#cba6f7"
#define PINK    "#f5c2e7"
#define FLAMINGO "#f2cdcd"
#define ROSEWATER "#f5e0dc"

/*                    fg         bg        border   */
static const char *colors[][3] = {
    [SchemeNorm]  = { TEXT,    BASE,    SURFACE0 },
    [SchemeSel]   = { BASE,    MAUVE,   MAUVE    },
    [SchemeTitle] = { TEXT,    MANTLE,  SURFACE0 },
};

/* ── Tags (kanji numerals) ──────────────────────────────────────────────── */
static const char *tags[] = { "一", "二", "三", "四", "五", "六", "七", "八", "九" };

/* ── Window rules ───────────────────────────────────────────────────────── */
static const Rule rules[] = {
    /* class              instance  title   tags mask  isfloating  monitor */
    { "Gimp",             NULL,     NULL,   0,         1,          -1 },
    { "Firefox",          NULL,     NULL,   1 << 1,    0,          -1 },
    { "steam",            NULL,     NULL,   1 << 3,    0,          -1 },
    { "Steam",            NULL,     NULL,   1 << 3,    0,          -1 },
    { "discord",          NULL,     NULL,   1 << 4,    0,          -1 },
    { "mpv",              NULL,     NULL,   1 << 5,    0,          -1 },
};

/* ── Layouts ────────────────────────────────────────────────────────────── */
static const float mfact        = 0.55;  /* master area size [0.05..0.95] */
static const int   nmaster      = 1;
static const int   resizehints  = 0;     /* respect size hints in tiled mode */
static const int   lockfullscreen = 1;

#include "vanitygaps.c"  /* patch: requires vanitygaps.c in src dir */

static const Layout layouts[] = {
    /* symbol  arrange function */
    { "󰙀 ",   tile           },   /* []=  tiling   — default */
    { " ",   NULL           },   /* [><] floating */
    { " ",   monocle        },   /* [M]  monocle  */
    { "󰘣 ",   centeredmaster },   /* |M|  centered master (vanitygaps) */
    { "󱢈 ",   centeredfloatingmaster }, /* >M< floating centered */
};

/* ── Key definitions ────────────────────────────────────────────────────── */
#define MODKEY Mod4Mask   /* Super */
#define TAGKEYS(KEY, TAG) \
    { MODKEY,                       KEY, view,       {.ui = 1 << TAG} }, \
    { MODKEY|ControlMask,           KEY, toggleview, {.ui = 1 << TAG} }, \
    { MODKEY|ShiftMask,             KEY, tag,        {.ui = 1 << TAG} }, \
    { MODKEY|ControlMask|ShiftMask, KEY, toggletag,  {.ui = 1 << TAG} },

/* ── Commands ───────────────────────────────────────────────────────────── */
static char dmenumon[2]    = "0";
static const char *dmenucmd[]  = {
    "dmenu_run", "-m", dmenumon, "-fn", dmenufont,
    "-nb", BASE, "-nf", TEXT, "-sb", MAUVE, "-sf", BASE,
    NULL
};
static const char *termcmd[]   = { "st", NULL };          /* swap for alacritty/foot */
static const char *browsercmd[]= { "firefox", NULL };
static const char *roficmd[]   = { "rofi", "-show", "drun", NULL };
static const char *sscmd[]     = { "scrot", "-s", NULL }; /* region screenshot */
static const char *lockcmd[]   = { "slock", NULL };

/* volume / brightness (requires pamixer / brightnessctl) */
static const char *volup[]    = { "pamixer", "-i", "5",    NULL };
static const char *voldown[]  = { "pamixer", "-d", "5",    NULL };
static const char *voltoggle[]= { "pamixer", "-t",         NULL };
static const char *brtup[]    = { "brightnessctl", "set", "5%+", NULL };
static const char *brtdown[]  = { "brightnessctl", "set", "5%-", NULL };

/* ── Key bindings ───────────────────────────────────────────────────────── */
static const Key keys[] = {
    /* modifier                key          function        argument */

    /* ── launchers ── */
    { MODKEY,                  XK_p,        spawn,          {.v = dmenucmd  } },
    { MODKEY,                  XK_space,    spawn,          {.v = roficmd   } },
    { MODKEY|ShiftMask,        XK_Return,   spawn,          {.v = termcmd   } },
    { MODKEY,                  XK_b,        spawn,          {.v = browsercmd} },
    { 0,                       XK_Print,    spawn,          {.v = sscmd     } },
    { MODKEY|ShiftMask,        XK_l,        spawn,          {.v = lockcmd   } },

    /* ── media / brightness ── */
    { 0,         XF86XK_AudioRaiseVolume,   spawn,          {.v = volup     } },
    { 0,         XF86XK_AudioLowerVolume,   spawn,          {.v = voldown   } },
    { 0,         XF86XK_AudioMute,          spawn,          {.v = voltoggle } },
    { 0,         XF86XK_MonBrightnessUp,    spawn,          {.v = brtup     } },
    { 0,         XF86XK_MonBrightnessDown,  spawn,          {.v = brtdown   } },

    /* ── bar ── */
    { MODKEY,                  XK_F12,      togglebar,      {0}             },

    /* ── focus / swap ── */
    { MODKEY,                  XK_j,        focusstack,     {.i = +1}       },
    { MODKEY,                  XK_k,        focusstack,     {.i = -1}       },
    { MODKEY,                  XK_Return,   zoom,           {0}             },
    { MODKEY,                  XK_Tab,      view,           {0}             },
    { MODKEY|ShiftMask,        XK_c,        killclient,     {0}             },
    { MODKEY,                  XK_q,        killclient,     {0}             },

    /* ── master size ── */
    { MODKEY,                  XK_h,        setmfact,       {.f = -0.05}    },
    { MODKEY,                  XK_l,        setmfact,       {.f = +0.05}    },
    { MODKEY,                  XK_i,        incnmaster,     {.i = +1}       },
    { MODKEY,                  XK_d,        incnmaster,     {.i = -1}       },

    /* ── gaps (vanitygaps) ── */
    { MODKEY|ShiftMask,        XK_equal,    incrgaps,       {.i = +2}       },
    { MODKEY|ShiftMask,        XK_minus,    incrgaps,       {.i = -2}       },
    { MODKEY|ShiftMask,        XK_g,        togglegaps,     {0}             },
    { MODKEY|ShiftMask,        XK_0,        defaultgaps,    {0}             },

    /* ── layouts ── */
    { MODKEY,                  XK_t,        setlayout,      {.v = &layouts[0]} }, /* tile    */
    { MODKEY,                  XK_f,        setlayout,      {.v = &layouts[1]} }, /* float   */
    { MODKEY,                  XK_m,        setlayout,      {.v = &layouts[2]} }, /* monocle */
    { MODKEY,                  XK_u,        setlayout,      {.v = &layouts[3]} }, /* centred */
    { MODKEY|ShiftMask,        XK_space,    togglefloating, {0}             },
    { MODKEY,                  XK_0,        view,           {.ui = ~0}      },
    { MODKEY|ShiftMask,        XK_0,        tag,            {.ui = ~0}      },

    /* ── multi-monitor ── */
    { MODKEY,                  XK_comma,    focusmon,       {.i = -1}       },
    { MODKEY,                  XK_period,   focusmon,       {.i = +1}       },
    { MODKEY|ShiftMask,        XK_comma,    tagmon,         {.i = -1}       },
    { MODKEY|ShiftMask,        XK_period,   tagmon,         {.i = +1}       },

    /* ── tags ── */
    TAGKEYS(XK_1, 0) TAGKEYS(XK_2, 1) TAGKEYS(XK_3, 2)
    TAGKEYS(XK_4, 3) TAGKEYS(XK_5, 4) TAGKEYS(XK_6, 5)
    TAGKEYS(XK_7, 6) TAGKEYS(XK_8, 7) TAGKEYS(XK_9, 8)

    /* ── quit / restart ── */
    { MODKEY|ShiftMask,        XK_q,        quit,           {0}             },
    { MODKEY|ControlMask,      XK_r,        quit,           {1}             }, /* restart (restart patch) */
};

/* ── Mouse bindings ─────────────────────────────────────────────────────── */
static const Button buttons[] = {
    /* click              event mask   button    function        argument */
    { ClkTagBar,          0,           Button1,  view,           {0}          },
    { ClkTagBar,          0,           Button3,  toggleview,     {0}          },
    { ClkTagBar,          MODKEY,      Button1,  tag,            {0}          },
    { ClkTagBar,          MODKEY,      Button3,  toggletag,      {0}          },
    { ClkWinTitle,        0,           Button2,  zoom,           {0}          },
    { ClkStatusText,      0,           Button2,  spawn,          {.v = termcmd} },
    { ClkClientWin,       MODKEY,      Button1,  movemouse,      {0}          },
    { ClkClientWin,       MODKEY,      Button2,  togglefloating, {0}          },
    { ClkClientWin,       MODKEY,      Button3,  resizemouse,    {0}          },
    { ClkRootWin,         0,           Button2,  spawn,          {.v = roficmd} },
};
