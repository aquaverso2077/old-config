static int topbar = 1;
static int centered = 1;
static int min_width = 700;
static const char *fonts[] = {
	"JetBrainsMono Nerd Font:size=10"
};
static const char *prompt      = NULL;
static const char *colors[SchemeLast][2] = {
	/*     fg         bg       */
	[SchemeNorm] = { "#ebdbb2", "#1d2021" },
	[SchemeSel] = { "#1d2021", "#689d6a" },
	[SchemeOut] = { "#1d2021", "#00ffff" },
};
static unsigned int lines          = 0;
static const char worddelimiters[] = " ";
static unsigned int border_width   = 1;
