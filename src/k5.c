#include "stream_group_types.h"
extern void func_0040E9F8(void);
extern void func_0040E950(void);
extern void func_0040EE90(void);
void func_003FF160(void) { func_0040E9F8(); }
void func_003FF130(void) { func_0040E950(); }
void func_003FF2B8(void) { func_0040EE90(); }
typedef struct W4 { s32 a; s32 b; s32 c; s32 d; } W4;
extern volatile s32 D_0048734C;
s32 func_00408930(void) { return D_0048734C; }
extern void func_0011D8F8(void *, s32, s32);
#include "runtime_directory_types.h"
void func_0040C798(void) { do { func_0011D8F8(&D_004895C0, 0, sizeof D_004895C0); } while (0); }
extern void func_003FB128(void *);
extern char D_004BB580[];
typedef struct SD8 { char pad0; signed char t; char pad[0x2A]; s32 f2C; } SD8;
void func_003FD8F0(SD8 *p, s32 v) { if (p->t == 2) func_003FB128(D_004BB580); else p->f2C = v; }
void func_003FF3B0(void *object) {
    StreamGroup *p = object;
    p->mode = 0; p->result_98 = 0;
    p->progress_2c = 0; p->progress_30 = 0; p->progress_34 = 0;
    p->consumed = 0; p->progress_44 = 0;
    p->maximum_available = 0x7FFFFFFF; p->remaining_limit = -1;
}
extern void func_0040EFB0(void);
extern void func_0040EAD0(void *);
extern void func_0040EFC0(void);
extern void func_00408CE8(void);
extern void func_00410F68(void);
extern signed char D_0048FD38[];
void func_0040EC90(void) {
    s32 i; signed char *p;
    func_0040EFB0();
    p = D_0048FD38;
    for (i = 7; i >= 0; i--, p += 0x58) if (p[0] == 1) func_0040EAD0(p);
    func_0040EFC0();
    func_00408CE8();
    func_00410F68();
}
extern s32 func_0011FFA0(const char *);
extern s32 func_0040A520(s32, s32);
s32 func_0040A578(const char *a, const char *b) {
    s32 n = func_0011FFA0(a), i;
    if (n != func_0011FFA0(b)) return -1;
    for (i = 0; i < n; i++) if (func_0040A520(a[i], b[i])) return -1;
    return 0;
}
