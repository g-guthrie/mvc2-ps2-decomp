/* Player settings: one key/value store shared by every front end.
 *
 * Every option is a string value under a dotted key ("video.scale",
 * "audio.music", "input.p1.pad.lp", "arcade.frame_data" ...).  Typed options
 * are *described* (SetDesc: label, section, type, range, choices, apply
 * callback), so the in-game menu (port/host/fe/fe_ui.c) and the web page's
 * settings panel (port/web/shell.html, through settings_json()) are both
 * generated from the same table, and an option registered by any module
 * shows up in both without touching either UI.
 *
 * Persistence (per device):
 *   native: a plain "key = value" file (settings_load_file / _save_file;
 *           the app uses SDL_GetPrefPath("mvc2-port", "mvc2")/settings.ini,
 *           or --config PATH).
 *   web:    localStorage["mvc2-settings"] (settings_load_web / automatic save).
 * Command-line "--set key=value" (and the legacy flags such as --no-unlock)
 * are session overrides: they apply now but are not written back unless the
 * player changes that option afterwards.
 *
 * EXTENSION POINT (arcade-accuracy toggles and anything else):
 *   static const char *const kOnOff[] = { "Off", "On", NULL };
 *   static void on_frames(int v) { ... }
 *   static const SetDesc d = { "arcade.frame_data", "NAOMI frame data",
 *       SET_SECTION_ARCADE, SET_BOOL, 0, 0, 1, NULL, NULL, on_frames,
 *       SET_RESTART, "Use the arcade frame and hitbox tables" };
 *   settings_register(&d);            (before settings_apply_all(), or any time)
 *   ... settings_get_int("arcade.frame_data") ...
 * The value comes from the store (persisted per device); the callback runs
 * from settings_apply_all() (the app calls it once its subsystems are up),
 * right away when registered after that, and on every change.  See
 * port/docs/USER_GUIDE.md "For developers".
 */
#ifndef PORT_SETTINGS_H
#define PORT_SETTINGS_H

typedef enum { SET_BOOL, SET_ENUM, SET_INT, SET_ACTION } SetType;

/* Sections, in menu order.  Free-form strings are accepted too. */
#define SET_SECTION_VIDEO  "Video"
#define SET_SECTION_AUDIO  "Audio"
#define SET_SECTION_INPUT  "Input"
#define SET_SECTION_GAME   "Game"
#define SET_SECTION_ARCADE "Arcade accuracy"

enum {
    SET_RESTART = 1,     /* takes effect on the next start (shown as such) */
    SET_NATIVE_ONLY = 2, /* hidden on the web */
    SET_WEB_ONLY = 4,    /* hidden natively */
    SET_HIDDEN = 8,      /* stored, not shown */
};

typedef struct SetDesc {
    const char *key;
    const char *label;
    const char *section;
    SetType type;
    int def, min, max;            /* SET_ENUM: index range [0, n-1]; SET_INT: range */
    const char *const *choices;   /* SET_ENUM: labels (NULL-terminated) */
    const char *const *values;    /* SET_ENUM: stored strings (NULL: = labels, lower-case) */
    void (*apply)(int value);     /* on change (and once at settings_apply_all) */
    int flags;
    const char *help;
    int step;                     /* SET_INT: menu step (0 = 1) */
} SetDesc;

/* ---- typed options ---- */
int settings_register(const SetDesc *d);         /* 0 = ok (copied by pointer: keep d alive) */
int settings_count(void);
const SetDesc *settings_desc(int i);
const SetDesc *settings_find(const char *key);
int settings_get_int(const char *key);           /* typed value (desc default if unset) */
void settings_set_int(const char *key, int v);   /* clamps, stores, persists, applies */
void settings_apply_all(void);                   /* every described option's callback once */
const char *settings_value_label(const SetDesc *d, int v); /* "Fit", "On", "80 %" ... */

/* ---- raw strings (bindings etc.) ---- */
const char *settings_get(const char *key);       /* NULL if unset */
void settings_set(const char *key, const char *value);      /* persists; NULL value = unset */
void settings_override(const char *key, const char *value); /* session only (command line) */
int settings_parse_assignment(const char *kv, int override);/* "key=value" */
void settings_reset_prefix(const char *prefix);  /* unset keys starting with prefix (persists) */
/* Iterate stored raw entries: returns key or NULL past the end. */
const char *settings_entry(int i, const char **value);

/* ---- change notification (UI refresh) ---- */
typedef void (*SettingsListener)(const char *key);
void settings_add_listener(SettingsListener fn);   /* up to 8 */

/* ---- persistence ---- */
int settings_load_file(const char *path);        /* 0 = read; the path is kept for saves */
int settings_save(void);                         /* native: the loaded path; web: localStorage */
void settings_load_web(void);                    /* web: localStorage (no-op natively) */
void settings_set_autosave(int on);              /* save after every change (default on) */

/* ---- web panel ---- JSON: {"options":[{key,label,section,type,value,def,min,max,step,
 * choices:[...],flags,help},...],"raw":{key:value,...}} */
const char *settings_json(void);

#endif
