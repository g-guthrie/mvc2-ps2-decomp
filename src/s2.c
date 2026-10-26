#include "stream_group_types.h"
#include "runtime_stream_query.h"

extern void func_0040EF00(void);
extern s32 func_0010F148(s32);
extern void func_003F7B78(void);
extern void *func_0011D8F8(void *, s32, s32);

void func_003FF300(void) { func_0040EF00(); }
int func_00400038(void *object) { return func_003F81C0(*(void **)((u8 *)object + 4)); }
int func_003FFFA8(void *object) { return func_003F8140(*(void **)((u8 *)object + 4)); }


void func_003FF358(void) { func_003F7B78(); func_0011D8F8(D_00484100, 0, sizeof D_00484100); }

typedef struct { s16 a; s16 b; s32 c; s32 d; } S7D58;
extern void func_004043C0(s32);
void func_003F7D58(S7D58 *p) {
    if (p) {
        func_004043C0(p->d);
        func_0011D8F8(p, 0, 0xB0);
        p->a = 0;
    }
}


typedef struct { s32 a, b, c, d; } Q4;
extern Q4 D_00632140;
extern s32 func_00409708(s32, void *, s32, s32, s32);
s32 func_00410A30(s32 a, s32 b, s32 *c) {
    s32 c0 = c[0];
    D_00632140.a = a;
    D_00632140.b = b;
    D_00632140.c = c0;
    D_00632140.d = c[1];
    return func_00409708(0x27, &D_00632140, 4, 0, 0);
}

typedef struct { char pad[0x2C]; s16 f; char pad2[0x12]; } E64;
extern E64 D_0061C7A0[];
extern s32 func_003EA130(E64 *);

typedef struct { s32 a; s32 n; } H1530;
typedef struct { u8 t; u8 p[7]; s32 len; } Ent;
extern H1530 D_0048F000;

typedef struct { s32 (**vt)(s32); s32 x; } O75E0;
extern char D_004BD190[], D_004BD1B0[];
extern void func_00405DC8(void *);
s32 func_004075E0(O75E0 *o) {
    s32 r = 0;
    if (!o) {
        func_00405DC8(D_004BD190);
        return 0;
    }
    {
        s32 (*fn)(s32) = ((s32 (**)(s32))(*(char **)o))[0x60 / 4];
        if (fn) r = fn(o->x);
        else func_00405DC8(D_004BD1B0);
    }
    return r;
}

typedef struct { char p[0x34]; float x; float y; char q[0x108]; s16 h; } F41B;
typedef union { u32 u; float f; } UF;

typedef struct { u8 b0, b1, b2; signed char n; s32 p4, p8; s32 w; char pad[0x32]; s16 v[1]; } S4028;
extern char D_004BC188[], D_004BC1B8[];
extern void func_003FB128(void *);
extern void func_003FF270(s32 *, s32, s32);

typedef struct Cell { struct Cell *next; s32 x4; s32 x8; s32 xC; } Cell;
typedef struct { s32 x0, x4, x8; Cell *cells; s32 n; Cell *head; s32 tab[4]; } Pool;

extern s32 func_004064E8(s32, s32, s32);
extern s32 func_00400258(s32, s32, s32, s32);
extern void func_00400658(s32, s32);
extern void func_003FB178(void *, s32);
extern char D_004BBEB0[];
s32 func_00400328(s32 a, s32 b, s32 c, s32 d, s32 e) {
    s32 r = func_004064E8(a, b, 0);
    s32 s;
    if (!r) {
        func_003FB178(D_004BBEB0, a);
        return 0;
    }
    s = func_00400258(r, c, d << 11, e);
    if (s) func_00400658(s, 0);
    return s;
}

typedef struct { u8 b0, b1, b2; u8 p3; char pad[0x2C]; s32 x30; s32 x34; } S7F18;
extern char D_004BD570[];
extern s32 func_001089F0(s32, s32, s32 *);
extern void func_00407EC8(void);
extern void func_0011EB60(void *);
void func_00407F18(S7F18 *o) {
    s32 st = 1;
    s32 i = 0;
    for (;;) {
        s32 r;
        if (st != 1) return;
        r = func_001089F0(o->x30, 1, &st);
        if (r < 0) {
            o->b2 = 9;
            o->x34 = r;
            return;
        }
        func_00407EC8();
        i++;
        if (i > 0x6000) {
            func_0011EB60(D_004BD570);
            return;
        }
    }
}
