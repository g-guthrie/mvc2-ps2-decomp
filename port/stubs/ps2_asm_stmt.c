/*
 * Default meaning of every rewritten PS2 inline-asm statement (hostify R4/R5):
 * nothing.  Each site is logged once (file:line and the template), so the
 * runtime log names exactly which syscall / COP0 / VU0 sequence the platform
 * layer still has to give a meaning.  Outputs of the original statement were
 * already zeroed by the rewrite.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mvc2_stubs.h"

#define MAX_SITES 512
static struct { const char *file; int line; } sites[MAX_SITES];
static unsigned nsites, total;

void ps2_asm_stmt(const char *file, int line, const char *tmpl)
{
    unsigned i;
    total++;
    for (i = 0; i < nsites; i++)
        if (sites[i].line == line && (sites[i].file == file || strcmp(sites[i].file, file) == 0))
            return;
    if (nsites < MAX_SITES) {
        sites[nsites].file = file;
        sites[nsites].line = line;
        nsites++;
    }
    if (!getenv("MVC2_STUB_QUIET")) {
        char one[96];
        size_t n = strcspn(tmpl, "\n");
        if (n > sizeof one - 1)
            n = sizeof one - 1;
        memcpy(one, tmpl, n);
        one[n] = 0;
        fprintf(stderr, "[asm] %s:%d: %s%s (no host meaning yet; ignored)\n", file, line, one,
                tmpl[n] ? " ..." : "");
    }
    MVC2_STUB_ENTER("ps2_asm_stmt", 0u, "asm-hook");
}
