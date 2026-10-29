/*
 * The newlib string/memory routines the game calls by address but that have
 * no credited C (MMI assembly in src/mmi_a.c, src/s3w9a.c, src/w2_p.c, or
 * unmatched spans).  Identified by link order (alphabetical newlib objects)
 * and by the callers' prototypes; each forwards to the host C library.
 */
#include <string.h>
#include "mvc2_stubs.h"

#define FWD(name, addr, what) MVC2_STUB_ENTER(name, addr, "libc forward: " what)

void *func_0011D5C8(const void *s, int c, unsigned n) { FWD("func_0011D5C8", 0x0011D5C8u, "memchr"); return memchr(s, c, n); }
int func_0011D6A8(const void *a, const void *b, unsigned n) { FWD("func_0011D6A8", 0x0011D6A8u, "memcmp"); return memcmp(a, b, n); }
void *func_0011D740(void *d, const void *s, unsigned n) { FWD("func_0011D740", 0x0011D740u, "memcpy"); return memcpy(d, s, n); }
void *func_0011D7F0(void *d, const void *s, unsigned n) { FWD("func_0011D7F0", 0x0011D7F0u, "memmove"); return memmove(d, s, n); }
void *func_0011D8F8(void *d, int c, unsigned n) { FWD("func_0011D8F8", 0x0011D8F8u, "memset"); return memset(d, c, n); }
char *func_0011FC10(char *d, const char *s) { FWD("func_0011FC10", 0x0011FC10u, "strcat"); return strcat(d, s); }
int func_0011FD40(const char *a, const char *b) { FWD("func_0011FD40", 0x0011FD40u, "strcmp"); return strcmp(a, b); }
char *func_0011FE88(char *d, const char *s) { FWD("func_0011FE88", 0x0011FE88u, "strcpy"); return strcpy(d, s); }
unsigned func_0011FFA0(const char *s) { FWD("func_0011FFA0", 0x0011FFA0u, "strlen"); return (unsigned)strlen(s); }
char *func_001200D8(char *d, const char *s, unsigned n) { FWD("func_001200D8", 0x001200D8u, "strncat"); return strncat(d, s, n); }
int func_00120288(const char *a, const char *b, unsigned n) { FWD("func_00120288", 0x00120288u, "strncmp"); return strncmp(a, b, n); }
char *func_00120440(char *d, const char *s, unsigned n) { FWD("func_00120440", 0x00120440u, "strncpy"); return strncpy(d, s, n); }
