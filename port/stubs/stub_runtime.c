/* Stub hit logging for the host link (see mvc2_stubs.h). */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mvc2_stubs.h"

#define MVC2_STUB_LOG_LIMIT 3
#define MAX_SEEN 1024

static struct { const char *name; unsigned addr; const char *kind; unsigned hits; } seen[MAX_SEEN];
static unsigned nseen;
static int quiet = -1;
static const char *trap;

static unsigned slot(const char *name, unsigned addr, const char *kind)
{
    unsigned i;
    for (i = 0; i < nseen; i++)
        if (seen[i].name == name || strcmp(seen[i].name, name) == 0)
            return i;
    if (nseen < MAX_SEEN) {
        seen[nseen].name = name;
        seen[nseen].addr = addr;
        seen[nseen].kind = kind;
        seen[nseen].hits = 0;
        return nseen++;
    }
    return MAX_SEEN - 1;
}

void mvc2_stub_hit(const char *name, unsigned ee_addr, const char *kind)
{
    int s = -1;
    mvc2_stub_hit_slot(&s, name, ee_addr, kind);
}

void mvc2_stub_hit_slot(int *cache, const char *name, unsigned ee_addr, const char *kind)
{
    unsigned i;
    if (quiet < 0) {
        const char *q = getenv("MVC2_STUB_QUIET");
        quiet = q && *q && *q != '0';
        trap = getenv("MVC2_STUB_TRAP");
    }
    if (*cache < 0)
        *cache = (int)slot(name, ee_addr, kind);
    i = (unsigned)*cache;
    seen[i].hits++;
    if (!quiet && seen[i].hits <= MVC2_STUB_LOG_LIMIT)
        fprintf(stderr, "[stub] %s (EE 0x%08X, %s)%s\n", name, ee_addr, kind,
                seen[i].hits == MVC2_STUB_LOG_LIMIT ? " [further hits counted silently]" : "");
    if (trap && strcmp(trap, name) == 0) {
        fprintf(stderr, "[stub] MVC2_STUB_TRAP=%s hit, aborting\n", name);
        abort();
    }
}

unsigned mvc2_stub_hits(const char *name)
{
    unsigned i;
    for (i = 0; i < nseen; i++)
        if (strcmp(seen[i].name, name) == 0)
            return seen[i].hits;
    return 0;
}

void mvc2_stub_report(void)
{
    unsigned i;
    fprintf(stderr, "[stub] %u distinct faked symbols were hit (table lists %u):\n",
            nseen, mvc2_fake_count);
    for (i = 0; i < nseen; i++)
        fprintf(stderr, "  %8u  %-28s EE 0x%08X  %s\n", seen[i].hits, seen[i].name,
                seen[i].addr, seen[i].kind);
}
