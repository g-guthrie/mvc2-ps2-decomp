typedef float f32;
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;


typedef struct { u8 p0[0x25]; u8 i; u8 p1[0x143]; u8 m; u8 p2[0x4d]; u8 f; } S;
extern void func_00176160(S *, s32, s32, s32);
void func_002E4710(S *p) {
    u8 m = p->m;
    if (m == 7 || m == 9 || m == 0xB) {
        if (p->f != 0) func_00176160(p, 0, p->i * 0x30 + 0x22, 1);
    }
}

extern s16 D_004D1802;
extern s32 func_00174170(void);
s32 func_00281040(s32 a, u8 *tbl) {
    s16 x = D_004D1802 - 20;
    if (x < 0) x = 0;
    if ((func_00174170() & 0x1F) < tbl[x % 12]) return 1;
    return 0;
}

typedef struct { u8 p0[2]; u8 c2; u8 p1[0x35F]; u16 u362; } A_001899D0;
typedef struct { u16 h0; s8 c2; u8 p0[5]; u16 u8; } B_001899D0;
typedef struct { u8 c0; s8 c1; u8 c2; u8 p0[3]; u16 h6; } C_001899D0;
extern s8 D_004F7FC8[];
extern u8 func_00189B40(A_001899D0 *, B_001899D0 *, C_001899D0 *);
u8 func_001899D0(A_001899D0 *a, B_001899D0 *b, C_001899D0 *c) {
    u32 m = a->u362 & b->u8;
    u32 t;
    if (m == 0) {
        return c->c0 = 0;
    }
    c->h6 = m;
    c->c2 = 1;
    t = c->c0;
    c->c0 = t + 1;
    c->c1 = b->c2;
    if (b->h0 == c->c2) {
        c->c0 = 2;
        c->c1 = D_004F7FC8[a->c2] * 10 + 0xE;
        return func_00189B40(a, b, c);
    }
    return 0;
}
