typedef signed int s32;
typedef unsigned char u8;
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
extern char D_004895C0[];
void func_0040C798(void) { do { func_0011D8F8(D_004895C0, 0, 0x10); } while (0); }
extern void func_003FB128(void *);
extern char D_004BB580[];
typedef struct SD8 { char pad0; signed char t; char pad[0x2A]; s32 f2C; } SD8;
void func_003FD8F0(SD8 *p, s32 v) { if (p->t == 2) func_003FB128(D_004BB580); else p->f2C = v; }
typedef struct S3B { u8 pad0[3]; u8 f3; char pad1[0x28]; s32 f2C, f30, f34, f38, f3C, f40, f44; char pad2[0x50]; s32 f98; } S3B;
void func_003FF3B0(void *object) {
    S3B *p = object;
    p->f3 = 0; p->f98 = 0; p->f2C = 0; p->f30 = 0; p->f34 = 0; p->f40 = 0; p->f44 = 0; p->f38 = 0x7FFFFFFF; p->f3C = -1;
}
typedef unsigned int u32;
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
