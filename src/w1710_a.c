typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { u8 *p1c; u8 *p20; u32 x; } E1;
typedef struct { u8 pad0[0x1C]; E1 e[2]; } G1;
typedef struct { u8 pad[0x434]; s16 h434; s16 h438; u8 pad2[0x1b]; u8 b425; } P1;
extern G1 *D_004C2794;
extern s16 D_004D1802[];
extern u8 D_004490A0[];
u8 func_0018ACD0(u8 *p) {
    extern s32 func_00174170();
    u8 *a, *b, *t;
    s32 r;
    s32 i = p[2] ^ 1;
    G1 *g = D_004C2794;
    a = g->e[i].p1c;
    b = g->e[i].p20;
    if (*(s16 *)(a + 0x438) - *(s16 *)(a + 0x434) < *(s16 *)(b + 0x438) - *(s16 *)(b + 0x434)) { t = a; a = b; b = t; }
    r = func_00174170() & 0x1F;
    if (D_004490A0[D_004D1802[0]] < r) a = b;
    return a[0x425];
}

typedef struct { f32 x, y, z; } V3;
typedef struct { u8 pad0[0x10]; void *f10; u8 pad14[0x28]; u32 f3c; u8 pad40[0x10]; V3 v50; u8 pad5c[0x28]; s32 f84; u8 pad88[0x40]; s32 fc8; s16 fcc; u8 pad_ce[2]; s32 fd0; } O2;
void func_0014A2A0(u8 *a, s32 n) {
    extern O2 *func_003DA750();
    extern V3 D_00443E2C[];
    extern V3 D_00443DF0[];
    extern s32 D_004C27FC;
    extern void func_0014A380();
    O2 *o;
    if ((o = func_003DA750(0, 0xD, 1)) != 0) {
        o->f10 = func_0014A380;
        o->fcc = 0xBC;
        o->f84 = D_004C27FC;
        o->fd0 = 0x800031;
        o->f3c = 0xBC23D70A;
        if (n == 1) o->v50 = D_00443E2C[0];
        else o->v50 = D_00443DF0[n];
        o->fc8 = (s32)a + 0x88;
        *(u8 *)((u8 *)o + 0x20) = n;
    }
}
