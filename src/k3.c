typedef signed int s32;
typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long long u64;
typedef long long s64;


typedef struct S40BD { u8 p0[8]; u64 a; u8 p1[0x18]; s32 n; } S40BD;
s32 func_0040BD48(S40BD *p) { u64 l = (s64)p->n << 11; u64 v = p->a; if (v < l) l = v; return l >> 32; }

extern void func_003FB128(void *);
extern char D_004BC528[];
s32 func_00402680(signed char *p) { if (p == 0) { func_003FB128(D_004BC528); return -1; } return p[0x71]; }

typedef struct S4117 { s32 a, b; } S4117;
extern S4117 D_00632440[];
extern void func_00411288();
extern void func_004112B0();
void func_004117C0(s32 i, s32 a, s32 b) { func_00411288(); D_00632440[i].a = a; D_00632440[i].b = b; func_004112B0(); }

extern char D_0062FD48[];
extern s32 func_0011FFA0(char *);
extern void func_0011D740(char *, char *, s32);


extern s32 func_00103CE0(s32, void *);
extern s32 func_00103D70(s32);
s32 func_003FE190(s32 p) {
    s32 buf[12]; s32 r = 0;
    if (p) {
        func_00103CE0(p, buf);
        if (buf[0] == 8 || buf[0] == 12) r = func_00103D70(p);
    }
    return r;
}

typedef struct S4066 { s32 a, b; } S4066;
extern S4066 D_0062FA08[];
S4066 *func_00406610(void) {
    s32 i;
    for (i = 0; i < 40 && D_0062FA08[i].b != 0; i++) ;
    if (i == 40) return 0;
    else return &D_0062FA08[i];
}

typedef struct VT3F { char pad[0xC]; void (*f)(void *); } VT3F;
typedef struct Ob3F { VT3F *vt; } Ob3F;
typedef struct S3FCC { char p0[2]; signed char b2; char p1[5]; Ob3F *o; char p2[0x18]; s32 x24; u32 x28; } S3FCC;
extern s32 D_0047B580;
extern void func_003FB370(s32, unsigned long);
void func_003FCC80(S3FCC *p) {
    if (p->o && p->b2 == 0) {
        if (D_0047B580 == 1) func_003FB370(p->x24, p->x28);
        p->o->vt->f(p->o);
        p->o = 0;
    }
}

typedef struct E40D { s32 k; char pad[0x38]; s32 v; } E40D;
typedef struct S40D { char pad[0x38]; E40D e[16]; } S40D;
extern char D_004BE2F8[], D_004BE368[];
extern void func_0040D5A0(const char *, ...);
s32 func_0040D398(S40D *p, s32 key) {
    s32 i;
    if (p == 0) {
        func_0040D5A0(D_004BE2F8);
    } else {
        for (i = 0; i < 16 && p->e[i].k != key; i++)
            ;
        if (i == 16)
            func_0040D5A0(D_004BE368);
        else
            return p->e[i].v;
    }
    return 0;
}

extern void func_00411438(s64, char *, long);
extern s32 func_0011FFA0(char *);
extern void func_001200D8(char *, char *, s32);
extern char D_004C2508[];
void func_00411548(s64 a, s64 b, char *c, long d) {
    char *e;
    func_00411438(a, c, d);
    func_001200D8(c, D_004C2508, (s32)d - func_0011FFA0(c) - 1);
    e = c + func_0011FFA0(c);
    func_00411438(b, e, (u32)(4 - func_0011FFA0(c)));
}

extern s32 func_003F99F0();
s32 func_00402940(u16 *p, s32 n, s32 *out) {
    u32 v;
    short s10; u8 b12, b13, b14, b15; s32 w18, w1C, w20;
    if (n < 2) return 0;
    v = *p;
    v = ((v >> 8) | (v << 8)) & 0xFFFF;
    if (v != 0x8000) return 0;
    if (func_003F99F0(p, n, &s10, &b12, &b13, &b14, &b15, &w20, &w18, &w1C) < 0) return 0;
    *out = s10;
    return 1;
}
