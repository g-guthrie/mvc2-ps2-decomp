typedef signed int s32;
typedef unsigned char u8;
typedef struct S64 { char pad[0xA4]; void *h; } S64;
extern void (*D_004C2210)(void *);
void func_003F64A0(S64 *p) { if (p->h) D_004C2210(p->h); }
extern void func_00122340(char *, const char *, char *);
extern char D_00489708[];
extern void (*D_004C2468)(void *, char *);
extern void *D_004C246C;
void func_0040D5A0(const char *fmt, ...) {
    char *ap = (char *)__builtin_next_arg(fmt) - 56;
    func_00122340(D_00489708, fmt, ap);
    if (D_004C2468) D_004C2468(D_004C246C, D_00489708);
}
