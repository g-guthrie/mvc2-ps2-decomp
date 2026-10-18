typedef signed int s32;
extern void func_0011D8F8(void *, int, int);
typedef unsigned int u32;
extern void func_0040ED28(void);
void func_003FF240(void) { func_0040ED28(); }
extern void func_0011EB60(void *);
extern char D_004BE928[];
void func_0040EED8(void) { func_0011EB60(D_004BE928); }
extern char D_00489000[];
void func_0040AA90(void) { do { func_0011D8F8(D_00489000, 0, 0x10); } while (0); }
extern void func_00404268(void);
extern void func_003F7970(void);
extern char D_004791F8[];
void func_003F7BB0(void) { func_00404268(); func_003F7970(); func_0011D8F8(D_004791F8, 0, 0xB00); }
extern void func_003FB128(void *);
extern char D_004BC400[];
s32 func_00402550(short *p) { if (p == 0) { func_003FB128(D_004BC400); return -1; } return p[0x30]; }
typedef struct S41 { char pad[0x140]; short flag; } S41;
extern void func_003DAC50(void *, int);
extern char D_0062C530[], D_0062C700[], D_0062C660[], D_0062C640[];
typedef struct S4017 { char pad0[8]; void *a; int pad1; int b; char pad2[0x28]; short c; short d; } S4017;
extern void func_00400BB8(void *, int, int);
extern void func_004007A0(void *, int);
extern void func_004006E8(void *);
extern void func_00401640(void *, int);
void func_00401708(S4017 *p) {
    func_00400BB8(p->a, p->d << 11, p->c << 11);
    func_004007A0(p->a, 0x19);
    func_004006E8(p->a);
    func_00401640(p, p->b);
}
extern s32 func_0011D6A8(const char *, const void *, int);
extern char D_004C2228[], D_004C2230[];
s32 func_003F7188(const char *s) {
    if (func_0011D6A8(s, D_004C2228, 4) == 0 || func_0011D6A8(s, D_004C2230, 4) == 0) return 1;
    else return 0;
}
s32 func_0040A4E8(signed char c) {
    s32 o = c;
    if ((u32)(c - 0x61) < 0x1A) c = c - 0x20;
    return o == 0x5C ? 0x2F : c;
}
typedef struct VT { char pad[0x24]; s32 (*f)(void *, int); } VT;
typedef struct Obj { VT *vt; } Obj;
typedef struct S4022 { char pad[0x14]; Obj *o; } S4022;
extern char D_004BC308[];
s32 func_00402238(S4022 *p) {
    if (p == 0) { func_003FB128(D_004BC308); return -1; }
    if (p->o) return p->o->vt->f(p->o, 1) / 2048;
    return 0;
}
typedef struct VT2 { char pad[0x34]; void (*f)(void *); } VT2;
typedef struct S4006 { VT2 *vt; void *arg; } S4006;
extern void func_00405DC8(void *);
extern char D_004BCDB0[], D_004BCDD0[];
void func_00406E88(S4006 *p) {
    if (p == 0) { func_00405DC8(D_004BCDB0); return; }
    if (p->vt->f) p->vt->f(p->arg); else func_00405DC8(D_004BCDD0);
}
extern void func_0010EC08(int, int, int);
void func_0010EF20(int a, int b) { do { func_0010EC08(a, b, 0); } while (0); }
extern long long func_00120838(const char *, int, int);
s32 func_00119DA0(const char *s) { return (s32)func_00120838(s, 0, 10); }
extern s32 func_00104210(int, u32 *);
extern char D_004C3570[];
typedef struct Ent { char pad[0x10]; int f10; char pad2[0xC]; } Ent;
extern char D_004C83D0[];
extern char *func_0010D860(int);
typedef struct S1073 { int p0; int f4; int p8; struct S1073b *fC; } S1073;
typedef struct S1073b { char pad[0x3C]; struct S1073b *f3C; } S1073b;
extern void func_0010CA20(void);
extern void func_0010CA68(void);
