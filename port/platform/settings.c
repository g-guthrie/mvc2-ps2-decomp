#include "settings.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#endif

#define MAX_DESC 160

typedef struct Entry {
    char *key, *val;
    char *saved;    /* value to write while overridden (NULL: unset in the file) */
    int ov;         /* session override */
} Entry;

static struct {
    const SetDesc *desc[MAX_DESC];
    int ndesc;
    Entry *e;
    int n, cap;
    char *path;
    int autosave_off, loading, dirty, applied;
    SettingsListener listener[8];
    int nlisten;
    char *json;
    size_t json_len, json_cap;
} S;

static char *dupstr(const char *s)
{
    size_t n = strlen(s) + 1;
    char *d = (char *)malloc(n);
    memcpy(d, s, n);
    return d;
}

static int find_entry(const char *key)
{
    for (int i = 0; i < S.n; i++)
        if (!strcmp(S.e[i].key, key)) return i;
    return -1;
}

const SetDesc *settings_find(const char *key)
{
    for (int i = 0; i < S.ndesc; i++)
        if (!strcmp(S.desc[i]->key, key)) return S.desc[i];
    return NULL;
}

int settings_count(void) { return S.ndesc; }
const SetDesc *settings_desc(int i) { return i >= 0 && i < S.ndesc ? S.desc[i] : NULL; }
void settings_add_listener(SettingsListener fn) { if (S.nlisten < 8) S.listener[S.nlisten++] = fn; }
static void notify(const char *key) { for (int i = 0; i < S.nlisten; i++) S.listener[i](key); }
void settings_set_autosave(int on) { S.autosave_off = !on; }

const char *settings_get(const char *key)
{
    int i = find_entry(key);
    return i < 0 ? NULL : S.e[i].val;
}

const char *settings_entry(int i, const char **value)
{
    if (i < 0 || i >= S.n) return NULL;
    if (value) *value = S.e[i].val;
    return S.e[i].key;
}

static int ieq(const char *a, const char *b)
{
    while (*a && *b && tolower((unsigned char)*a) == tolower((unsigned char)*b)) a++, b++;
    return *a == 0 && *b == 0;
}

static int enum_count(const SetDesc *d)
{
    int n = 0;
    while (d->choices && d->choices[n]) n++;
    return n;
}

/* stored string for enum index v */
static void enum_value(const SetDesc *d, int v, char *out, size_t cap)
{
    const char *s = d->values ? d->values[v] : d->choices[v];
    size_t i = 0;
    for (; s[i] && i + 1 < cap; i++) out[i] = d->values ? s[i] : (char)tolower((unsigned char)s[i]);
    out[i] = 0;
}

static int clampv(const SetDesc *d, int v)
{
    int lo = d->min, hi = d->max;
    if (d->type == SET_BOOL) { lo = 0; hi = 1; }
    if (d->type == SET_ENUM) { lo = 0; hi = enum_count(d) - 1; }
    return v < lo ? lo : v > hi ? hi : v;
}

static int parse_typed(const SetDesc *d, const char *s, int *out)
{
    char tmp[64];
    if (!s) return 0;
    switch (d->type) {
    case SET_BOOL:
        if (ieq(s, "1") || ieq(s, "on") || ieq(s, "true") || ieq(s, "yes")) { *out = 1; return 1; }
        if (ieq(s, "0") || ieq(s, "off") || ieq(s, "false") || ieq(s, "no")) { *out = 0; return 1; }
        return 0;
    case SET_ENUM:
        for (int i = 0, n = enum_count(d); i < n; i++) {
            enum_value(d, i, tmp, sizeof tmp);
            if (ieq(s, tmp) || ieq(s, d->choices[i])) { *out = i; return 1; }
        }
        return 0;
    case SET_INT:
    case SET_ACTION: {
        char *end;
        long v = strtol(s, &end, 10);
        if (end == s) return 0;
        *out = clampv(d, (int)v);
        return 1;
    }
    }
    return 0;
}

int settings_get_int(const char *key)
{
    const SetDesc *d = settings_find(key);
    const char *s = settings_get(key);
    int v;
    if (!d) return s ? atoi(s) : 0;
    if (parse_typed(d, s, &v)) return v;
    return d->def;
}

const char *settings_value_label(const SetDesc *d, int v)
{
    static char buf[48];
    switch (d->type) {
    case SET_BOOL: return v ? "On" : "Off";
    case SET_ENUM: v = clampv(d, v); return d->choices[v];
    case SET_INT:
        snprintf(buf, sizeof buf, "%d%s", v, d->min >= 0 && (d->max == 100 || !strncmp(d->key, "touch.", 6) ||
                 strstr(d->key, "deadzone")) ? " %" : "");
        return buf;
    case SET_ACTION: return "";
    }
    return "";
}

#ifdef __EMSCRIPTEN__
EM_JS(void, web_store_write, (const char *text), {
    try { localStorage.setItem('mvc2-settings', UTF8ToString(text)); } catch (e) {}
});
EM_JS(int, web_store_len, (void), {
    try { var s = localStorage.getItem('mvc2-settings'); return s ? lengthBytesUTF8(s) + 1 : 0; }
    catch (e) { return 0; }
});
EM_JS(void, web_store_copy, (char *buf, int n), {
    try { stringToUTF8(localStorage.getItem('mvc2-settings') || "", buf, n); } catch (e) {}
});
EM_JS(void, web_notify, (const char *key), {
    if (Module['onSettingChanged']) { try { Module['onSettingChanged'](UTF8ToString(key)); } catch (e) {} }
});
#endif

static void changed(const char *key)
{
    S.dirty = 1;
    if (!S.loading && !S.autosave_off) settings_save();
    notify(key);
#ifdef __EMSCRIPTEN__
    if (!S.loading) web_notify(key);
#endif
}

static void store(const char *key, const char *value, int override)
{
    int i = find_entry(key);
    if (!value) {
        if (i < 0) return;
        if (override) {               /* override to "unset" keeps the persisted value */
            if (!S.e[i].ov) { S.e[i].saved = S.e[i].val; S.e[i].ov = 1; S.e[i].val = dupstr(""); }
            return;
        }
        free(S.e[i].key); free(S.e[i].val); free(S.e[i].saved);
        S.e[i] = S.e[--S.n];
        return;
    }
    if (i < 0) {
        if (S.n == S.cap) {
            S.cap = S.cap ? S.cap * 2 : 64;
            S.e = (Entry *)realloc(S.e, sizeof(Entry) * (size_t)S.cap);
        }
        i = S.n++;
        S.e[i].key = dupstr(key);
        S.e[i].val = NULL;
        S.e[i].saved = NULL;
        S.e[i].ov = 0;
        if (override) S.e[i].ov = 1; /* saved = NULL: not in the file */
    } else if (override && !S.e[i].ov) {
        S.e[i].saved = S.e[i].val;   /* keep the persisted value */
        S.e[i].val = NULL;
        S.e[i].ov = 1;
    } else if (!override && S.e[i].ov) {
        free(S.e[i].saved);
        S.e[i].saved = NULL;
        S.e[i].ov = 0;
    }
    free(S.e[i].val);
    S.e[i].val = dupstr(value);
}

static void apply(const char *key)
{
    const SetDesc *d = settings_find(key);
    if (d && d->apply && d->type != SET_ACTION) d->apply(settings_get_int(key));
}

void settings_set(const char *key, const char *value)
{
    const char *old = settings_get(key);
    if (old && value && !strcmp(old, value)) {
        int i = find_entry(key);
        if (!S.e[i].ov) return;
    }
    store(key, value, 0);
    apply(key);
    changed(key);
}

void settings_override(const char *key, const char *value)
{
    store(key, value, 1);
    apply(key);
    notify(key);
}

void settings_set_int(const char *key, int v)
{
    const SetDesc *d = settings_find(key);
    char buf[64];
    if (d) {
        v = clampv(d, v);
        if (d->type == SET_ENUM) enum_value(d, v, buf, sizeof buf);
        else snprintf(buf, sizeof buf, "%d", v);
    } else {
        snprintf(buf, sizeof buf, "%d", v);
    }
    settings_set(key, buf);
}

int settings_parse_assignment(const char *kv, int override)
{
    char key[128];
    const char *eq = strchr(kv, '=');
    if (!eq || eq == kv || (size_t)(eq - kv) >= sizeof key) return -1;
    size_t n = (size_t)(eq - kv);
    memcpy(key, kv, n);
    while (n && isspace((unsigned char)key[n - 1])) n--;
    key[n] = 0;
    const char *v = eq + 1;
    while (isspace((unsigned char)*v)) v++;
    if (override) settings_override(key, v);
    else if (S.loading) { store(key, v, 0); notify(key); } /* callbacks run at settings_apply_all */
    else { store(key, v, 0); apply(key); changed(key); }
    return 0;
}

void settings_reset_prefix(const char *prefix)
{
    size_t pl = strlen(prefix);
    int any = 0;
    for (int i = S.n - 1; i >= 0; i--)
        if (!strncmp(S.e[i].key, prefix, pl)) {
            char *k = dupstr(S.e[i].key);
            store(k, NULL, 0);
            apply(k);
            notify(k);
#ifdef __EMSCRIPTEN__
            web_notify(k);
#endif
            free(k);
            any = 1;
        }
    if (any) changed(prefix);
}

int settings_register(const SetDesc *d)
{
    if (!d || !d->key || S.ndesc >= MAX_DESC) return -1;
    for (int i = 0; i < S.ndesc; i++)
        if (!strcmp(S.desc[i]->key, d->key)) { S.desc[i] = d; return 0; }
    S.desc[S.ndesc++] = d;
    if (S.applied && d->apply && d->type != SET_ACTION) d->apply(settings_get_int(d->key)); /* late registration */
    return 0;
}

void settings_apply_all(void)
{
    S.applied = 1;
    for (int i = 0; i < S.ndesc; i++)
        if (S.desc[i]->apply && S.desc[i]->type != SET_ACTION) S.desc[i]->apply(settings_get_int(S.desc[i]->key));
}

/* ---- persistence ---- */
static void parse_text(const char *text)
{
    S.loading = 1;
    while (*text) {
        const char *nl = strchr(text, '\n');
        size_t n = nl ? (size_t)(nl - text) : strlen(text);
        char line[512];
        if (n >= sizeof line) n = sizeof line - 1;
        memcpy(line, text, n);
        line[n] = 0;
        while (n && (line[n - 1] == '\r' || isspace((unsigned char)line[n - 1]))) line[--n] = 0;
        char *p = line;
        while (isspace((unsigned char)*p)) p++;
        if (*p && *p != '#' && *p != ';' && *p != '[') settings_parse_assignment(p, 0);
        if (!nl) break;
        text = nl + 1;
    }
    S.loading = 0;
}

static char *serialize(void)
{
    size_t cap = 256, len = 0;
    char *out = (char *)malloc(cap);
    const char *hdr = "# mvc2 port settings (key = value); see port/docs/USER_GUIDE.md\n";
    len = strlen(hdr);
    memcpy(out, hdr, len + 1);
    for (int i = 0; i < S.n; i++) {
        const char *v = S.e[i].ov ? S.e[i].saved : S.e[i].val;
        if (!v) continue;
        size_t need = strlen(S.e[i].key) + strlen(v) + 5;
        while (len + need + 1 > cap) { cap *= 2; out = (char *)realloc(out, cap); }
        len += (size_t)sprintf(out + len, "%s = %s\n", S.e[i].key, v);
    }
    return out;
}

int settings_load_file(const char *path)
{
    free(S.path);
    S.path = path ? dupstr(path) : NULL;
    if (!path) return -1;
    FILE *f = fopen(path, "rb");
    if (!f) return -1;
    fseek(f, 0, SEEK_END);
    long n = ftell(f);
    fseek(f, 0, SEEK_SET);
    if (n < 0 || n > (1 << 20)) { fclose(f); return -1; }
    char *buf = (char *)malloc((size_t)n + 1);
    size_t got = fread(buf, 1, (size_t)n, f);
    buf[got] = 0;
    fclose(f);
    parse_text(buf);
    free(buf);
    return 0;
}

void settings_load_web(void)
{
#ifdef __EMSCRIPTEN__
    int n = web_store_len();
    if (n <= 0) return;
    char *buf = (char *)malloc((size_t)n + 1);
    buf[0] = 0;
    web_store_copy(buf, n + 1);
    parse_text(buf);
    free(buf);
#endif
}

int settings_save(void)
{
    char *text = serialize();
    int r = 0;
    S.dirty = 0;
#ifdef __EMSCRIPTEN__
    web_store_write(text);
#else
    if (S.path) {
        char tmp[1024];
        snprintf(tmp, sizeof tmp, "%s.tmp", S.path);
        FILE *f = fopen(tmp, "wb");
        if (f) {
            fputs(text, f);
            fclose(f);
            if (rename(tmp, S.path) != 0) r = -1;
        } else {
            r = -1;
        }
    }
#endif
    free(text);
    return r;
}

/* ---- JSON for the web panel ---- */
static void jput(const char *s)
{
    size_t n = strlen(s);
    if (S.json_len + n + 1 > S.json_cap) {
        while (S.json_len + n + 1 > S.json_cap) S.json_cap = S.json_cap ? S.json_cap * 2 : 4096;
        S.json = (char *)realloc(S.json, S.json_cap);
    }
    memcpy(S.json + S.json_len, s, n + 1);
    S.json_len += n;
}

static void jstr(const char *s)
{
    char b[8];
    jput("\"");
    for (; s && *s; s++) {
        unsigned char c = (unsigned char)*s;
        if (c == '"' || c == '\\') { b[0] = '\\'; b[1] = (char)c; b[2] = 0; jput(b); }
        else if (c < 0x20) { snprintf(b, sizeof b, "\\u%04x", c); jput(b); }
        else { b[0] = (char)c; b[1] = 0; jput(b); }
    }
    jput("\"");
}

static void jint(const char *name, int v)
{
    char b[64];
    snprintf(b, sizeof b, ",\"%s\":%d", name, v);
    jput(b);
}

const char *settings_json(void)
{
    static const char *types[] = { "bool", "enum", "int", "action" };
    S.json_len = 0;
    jput("{\"options\":[");
    for (int i = 0; i < S.ndesc; i++) {
        const SetDesc *d = S.desc[i];
        if (i) jput(",");
        jput("{\"key\":"); jstr(d->key);
        jput(",\"label\":"); jstr(d->label);
        jput(",\"section\":"); jstr(d->section);
        jput(",\"type\":"); jstr(types[d->type]);
        jint("value", settings_get_int(d->key));
        jint("def", d->def); jint("min", d->min); jint("max", d->max);
        jint("step", d->step ? d->step : 1); jint("flags", d->flags);
        jput(",\"help\":"); jstr(d->help ? d->help : "");
        jput(",\"choices\":[");
        for (int k = 0; d->type == SET_ENUM && d->choices[k]; k++) { if (k) jput(","); jstr(d->choices[k]); }
        jput("]}");
    }
    jput("],\"raw\":{");
    for (int i = 0; i < S.n; i++) {
        if (i) jput(",");
        jstr(S.e[i].key); jput(":"); jstr(S.e[i].val);
    }
    jput("}}");
    return S.json;
}
