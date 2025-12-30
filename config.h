//Appearance!
//-----------
static const unsigned int borderpx  = 0;        // Border px of windows. set to 0 for no px
static const unsigned int snap      = 32;       // Snap px
static const int showbar            = 0;        // Set to 0 if u dont want a bar
static const int topbar             = 1;        // Set to 0 if u want the bar to be at the bottom
static const char *fonts[]          = { "monospace:size=10" }; // Font here!
static const char dmenufont[]       = "monospace:size=10"; // Font here asw!
static const char col_gray1[]       = "#222222";
static const char col_gray2[]       = "#444444";
static const char col_gray3[]       = "#bbbbbb";
static const char col_gray4[]       = "#eeeeee";
static const char col_cyan[]        = "#005577";
static const char *colors[][3]      = {
        /*               fg         bg         border   */
        [SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
        [SchemeSel]  = { col_gray4, col_cyan,  col_cyan  },
};

// GAPS PATCH (fullgaps)
static const int gappx = 25;


// Tagging
// Leave it stock for now if u dont know what ur doing
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
        /* xprop(1):
         *      WM_CLASS(STRING) = instance, class
         *      WM_NAME(STRING) = title
         */
	/* class      instance    title       tags mask     isfloating   monitor */
        { "Gimp",     NULL,	  NULL,       0,            1,           -1 },
        { "Firefox",  NULL,	  NULL,       1 << 8,       0,           -1 },
};

// Layout
// Change refreshrate to yours
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */
static const int refreshrate = 120;  /* refresh rate (per second) for client move/resize */

// Layout symbols. U can change them but u dont have to :3
static const Layout layouts[] = {
        /* symbol     arrange function */
        { ":3",      tile },    /* first entry is default */
        { "OwO",      NULL },    /* no layout function means floating behavior */
        { "[M]",      monocle },
};
//-------------------------
// IMPORTANT STUFF HERE!!!!
//_________________________
#define MODKEY Mod4Mask // Mod4 =  Win key, Mod1 = Alt
#define TAGKEYS(KEY,TAG) \
        { MODKEY,                       KEY,	  view,           {.ui = 1 << TAG} }, \
        { MODKEY|ControlMask,           KEY,	  toggleview,     {.ui = 1 << TAG} }, \
        { MODKEY|ShiftMask,             KEY,	  tag,            {.ui = 1 << TAG} }, \
        { MODKEY|ControlMask|ShiftMask, KEY,	  toggletag,	  {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* __________________ */
/*      CMD Conf      */
/* ------------------ */
// Add the shortcuts here if a program has to be run from terminal

// static const char *namehere[] = { "commandhere", NULL };
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4, NULL };

static const char *termcmd[]  = { "alacritty", NULL };
static const char *firecmd[]  = { "firefox", NULL};
static const char *roficmd[]  = { "rofi", "-show", "drun", NULL};

/* ________________________ */
/*      Keybinds here!      */
/* ------------------------ */
static const Key keys[] = {
        /* modifier                     key        function        argument */  { MODKEY,                       XK_p,	   spawn,	   {.v = dmenucmd } },
       { MODKEY,                       XK_Return, spawn,          {.v = termcmd } },
        { MODKEY|ShiftMask,             XK_q,   killclient,     {0} },
        { MODKEY,                       XK_f,   spawn,          {.v = firecmd} },
        { MODKEY,                       XK_d,   spawn,          {.v = roficmd} },
        TAGKEYS(                        XK_1,                      0)
        TAGKEYS(                        XK_2,                      1)
        TAGKEYS(                        XK_3,                      2)
        TAGKEYS(                        XK_4,                      3)
        TAGKEYS(                        XK_5,                      4)
        TAGKEYS(                        XK_6,                      5)
        TAGKEYS(                        XK_7,                      6)
        TAGKEYS(                        XK_8,                      7)
        TAGKEYS(                        XK_9,                      8)
        { MODKEY|ShiftMask,             XK_e,	   quit,           {0} },
};
