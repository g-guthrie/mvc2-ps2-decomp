/*
 * Memory card (Port J): libmc at its API, backed by a host directory.  The
 * game's own wrapper (init func_00418CC0, request/sync/retry state machine
 * func_00418D70, the request functions func_004194xx) is credited C and runs
 * unchanged on top of it.
 *
 * The card in port 0 is an 8 MB PS2 card, formatted, stored under
 * $MVC2_MEMCARD (default ./mvc2_memcard/), one host file per card file
 * ("<dir>/BASLUS-20486/<name>").  Port 1 is empty.  Every request completes
 * at once: the sceMc* call records (function number, result) and the next
 * sceMcSync reports it, as libmc does when the IOP has finished.
 */
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include "host.h"
#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#endif

/* The web page keeps the card directory in IndexedDB (IDBFS mounted at
 * /mvc2_memcard by port/web/shell.html): after a change reaches the card,
 * ask the page to write it back (Module.mcPersist, debounced there).
 * Natively the directory is already on disk. */
static void mc_persist(void)
{
#ifdef __EMSCRIPTEN__
    EM_ASM({ if (Module.mcPersist) Module.mcPersist(); });
#endif
}

#define MC_FD_MAX 8
static struct { FILE *f; int used; } mc_fd[MC_FD_MAX];
static int pend_cmd, pend_res, pend_valid;
static int info_calls;
static char mc_cwd[128] = "/";

static const char *mc_root(void)
{
    const char *e = getenv("MVC2_MEMCARD");
    return e && *e ? e : "mvc2_memcard";
}

static void mc_done(int cmd, int res)
{
    pend_cmd = cmd;
    pend_res = res;
    pend_valid = 1;
    if (host_verbose)
        host_log("libmc: cmd %d -> %d", cmd, res);
}

/* card path ("/BASLUS-20486/x" or relative to the card cwd) -> host path */
static void mc_path(char *out, size_t n, const char *name)
{
    char full[256];
    if (!name)
        name = "";
    if (name[0] == '/')
        snprintf(full, sizeof full, "%s", name);
    else
        snprintf(full, sizeof full, "%s%s%s", mc_cwd, mc_cwd[strlen(mc_cwd) - 1] == '/' ? "" : "/", name);
    snprintf(out, n, "%s%s", mc_root(), full);
}

static void mc_mkroot(void)
{
#ifdef _WIN32
    mkdir(mc_root());
#else
    mkdir(mc_root(), 0755);
#endif
}

int func_0010FD90(void) /* sceMcInit */
{
    mc_mkroot();
    return 0;
}

/* sceMcSync(mode, &cmd, &result): 1 = finished, -1 = nothing pending */
int func_001107B8(int mode, void *cmd, void *result)
{
    (void)mode;
    if (!pend_valid)
        return -1;
    if (cmd)
        *(s32 *)cmd = pend_cmd;
    if (result)
        *(s32 *)result = pend_res;
    pend_valid = 0;
    return 1;
}

/* sceMcGetInfo(port, slot, &type, &free, &format): result 0 = same card,
 * -1 = a formatted card that is new since the last call, -10 = no card */
int func_001108F0(int port, int slot, void *type, void *free_, void *format)
{
    (void)slot;
    if (port != 0) {
        if (type) *(s32 *)type = 0;
        if (free_) *(s32 *)free_ = 0;
        if (format) *(s32 *)format = 0;
        mc_done(1, -10);
        return 0;
    }
    mc_mkroot();
    if (type) *(s32 *)type = 2;          /* PS2 card */
    if (free_) *(s32 *)free_ = 0x1F00;   /* KB free */
    if (format) *(s32 *)format = 1;
    mc_done(1, info_calls++ ? 0 : -1);
    return 0;
}

int func_00110CB0(int port, int slot, void *newdir, void *curdir) /* sceMcChdir */
{
    char hp[300];
    struct stat st;
    (void)slot;
    if (curdir)
        strcpy((char *)curdir, mc_cwd);
    if (!newdir) {
        mc_done(12, 0);
        return 0;
    }
    mc_path(hp, sizeof hp, (const char *)newdir);
    if (port != 0 || stat(hp, &st) != 0 || !S_ISDIR(st.st_mode)) {
        mc_done(12, -4);
        return 0;
    }
    if (((const char *)newdir)[0] == '/')
        snprintf(mc_cwd, sizeof mc_cwd, "%s", (const char *)newdir);
    else
        snprintf(mc_cwd + strlen(mc_cwd), sizeof mc_cwd - strlen(mc_cwd), "%s%s",
                 mc_cwd[strlen(mc_cwd) - 1] == '/' ? "" : "/", (const char *)newdir);
    mc_done(12, 0);
    return 0;
}

int func_00110260(int port, int slot, int name) /* sceMcMkdir */
{
    char hp[300];
    (void)slot;
    mc_path(hp, sizeof hp, (const char *)(uintptr_t)name);
    if (port != 0) {
        mc_done(11, -10);
        return 0;
    }
    mc_mkroot();
#ifdef _WIN32
    mc_done(11, mkdir(hp) == 0 ? 0 : -4);
#else
    mc_done(11, mkdir(hp, 0755) == 0 ? 0 : -4);
#endif
    mc_persist();
    return 0;
}

int func_00110138(int port, int slot, void *name, int mode) /* sceMcOpen */
{
    char hp[300];
    const char *m;
    int i;
    (void)slot;
    if (port != 0) {
        mc_done(2, -10);
        return 0;
    }
    mc_path(hp, sizeof hp, (const char *)name);
    for (i = 0; i < MC_FD_MAX && mc_fd[i].used; i++)
        ;
    if (i == MC_FD_MAX) {
        mc_done(2, -7);
        return 0;
    }
    if (mode & 0x200) /* SCE_CREAT */
        m = (mode & 3) == 1 ? "rb" : "w+b";
    else
        m = (mode & 3) == 1 ? "rb" : "r+b";
    mc_fd[i].f = fopen(hp, m);
    if (host_verbose)
        host_log("libmc: open %s mode 0x%x -> %s", hp, mode, mc_fd[i].f ? "ok" : "no");
    if (!mc_fd[i].f) {
        mc_done(2, -4);
        return 0;
    }
    mc_fd[i].used = 1;
    mc_done(2, i);
    return 0;
}

int func_00110298(int fd) /* sceMcClose */
{
    if (fd >= 0 && fd < MC_FD_MAX && mc_fd[fd].used) {
        fclose(mc_fd[fd].f);
        mc_fd[fd].used = 0;
        mc_done(3, 0);
        mc_persist();
    } else {
        mc_done(3, -4);
    }
    return 0;
}

int func_00110350(int fd, int off, int origin) /* sceMcSeek */
{
    if (fd < 0 || fd >= MC_FD_MAX || !mc_fd[fd].used) {
        mc_done(4, -4);
        return 0;
    }
    fseek(mc_fd[fd].f, off, origin == 1 ? SEEK_CUR : origin == 2 ? SEEK_END : SEEK_SET);
    mc_done(4, (int)ftell(mc_fd[fd].f));
    return 0;
}

int func_001104B8(int fd, void *buf, int size) /* sceMcRead */
{
    if (fd < 0 || fd >= MC_FD_MAX || !mc_fd[fd].used) {
        mc_done(5, -4);
        return 0;
    }
    mc_done(5, (int)fread(buf, 1, (size_t)size, mc_fd[fd].f));
    return 0;
}

int func_001105D0(int fd, void *buf, int size) /* sceMcWrite */
{
    if (fd < 0 || fd >= MC_FD_MAX || !mc_fd[fd].used) {
        mc_done(6, -4);
        return 0;
    }
    mc_done(6, (int)fwrite(buf, 1, (size_t)size, mc_fd[fd].f));
    return 0;
}

int func_00110FD8(int fd) /* sceMcFlush */
{
    if (fd >= 0 && fd < MC_FD_MAX && mc_fd[fd].used)
        fflush(mc_fd[fd].f);
    mc_done(10, 0);
    return 0;
}

int func_00110DF0(int port, int slot) /* sceMcFormat */
{
    (void)slot;
    mc_mkroot();
    mc_done(16, port == 0 ? 0 : -10);
    return 0;
}

int func_00110EC0(int port, int slot, void *name) /* sceMcDelete */
{
    char hp[300];
    (void)slot;
    mc_path(hp, sizeof hp, (const char *)name);
    mc_done(15, port == 0 && (remove(hp) == 0) ? 0 : -4);
    mc_persist();
    return 0;
}

int func_00111480(int port, int slot, void *path) /* sceMcGetEntSpace */
{
    (void)slot; (void)path;
    mc_done(18, port == 0 ? 0x1F00 : -10);
    return 0;
}

/* simple '*' / '?' match */
static int wild(const char *p, const char *s)
{
    if (!*p)
        return !*s;
    if (*p == '*')
        return wild(p + 1, s) || (*s && wild(p, s + 1));
    if (*s && (*p == '?' || *p == *s))
        return wild(p + 1, s + 1);
    return 0;
}

/* sceMcGetDir(port, slot, name, mode, maxent, table): 64-byte sceMcTblGetDir
 * entries; result = number of entries. */
int func_00110AE0(int port, int slot, void *name, unsigned int mode, int maxent, void *table)
{
    char hp[300], dirp[300], pat[64];
    const char *nm = (const char *)name, *slash;
    DIR *d;
    struct dirent *de;
    int n = 0;
    u8 *t = (u8 *)table;
    (void)slot; (void)mode;
    if (port != 0) {
        mc_done(13, -10);
        return 0;
    }
    mc_path(hp, sizeof hp, nm);
    if (host_verbose)
        host_log("libmc: getdir %s", hp);
    slash = strrchr(hp, '/');
    if (!slash) {
        mc_done(13, 0);
        return 0;
    }
    snprintf(dirp, sizeof dirp, "%.*s", (int)(slash - hp), hp);
    snprintf(pat, sizeof pat, "%s", slash + 1);
    if (!strchr(pat, '*') && !strchr(pat, '?')) {
        /* a directory or file by name: report it if it exists */
        struct stat st;
        if (stat(hp, &st) == 0 && n < maxent && t) {
            memset(t, 0, 64);
            *(u32 *)(t + 0x10) = (u32)st.st_size;
            *(u16 *)(t + 0x14) = S_ISDIR(st.st_mode) ? 0x8427 : 0x8417;
            snprintf((char *)t + 0x20, 32, "%s", pat);
            n = 1;
        }
        mc_done(13, n);
        return 0;
    }
    d = opendir(dirp);
    if (d) {
        while ((de = readdir(d)) && n < maxent) {
            char fp[600];
            struct stat st;
            if (!wild(pat, de->d_name) || !strcmp(de->d_name, ".") || !strcmp(de->d_name, ".."))
                continue;
            snprintf(fp, sizeof fp, "%s/%s", dirp, de->d_name);
            if (stat(fp, &st) != 0)
                continue;
            if (t) {
                u8 *e = t + 64 * n;
                memset(e, 0, 64);
                *(u32 *)(e + 0x10) = (u32)st.st_size;
                *(u16 *)(e + 0x14) = S_ISDIR(st.st_mode) ? 0x8427 : 0x8417;
                snprintf((char *)e + 0x20, 32, "%s", de->d_name);
            }
            n++;
        }
        closedir(d);
    }
    mc_done(13, n);
    return 0;
}
