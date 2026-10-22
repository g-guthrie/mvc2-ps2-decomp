typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;
typedef struct O2 { u8 pad0[0x18]; struct O3 *o; u8 pad1C[0x168 - 0x1C]; u16 h168; } O2;
typedef struct O3 { u8 pad0[5]; u8 b5; } O3;
typedef struct {
    u8 pad0[1];
    u8 b1;
    u8 pad2[2];
    u8 b4;
    u8 pad5[0x18 - 5];
    O2 *o;
    s16 h1C;
    u8 pad1E[0x23 - 0x1E];
    u8 b23;
    s8 b24;
    u8 pad25[0x34 - 0x25];
    V3 v34;
    u8 pad40[0xD0 - 0x40];
    u32 wD0;
    u8 padD4[0x118 - 0xD4];
    f32 f118;
    u8 pad11C[0x13C - 0x11C];
    u8 b13C;
    u8 pad13D[0x168 - 0x13D];
    u8 b168;
} P;
typedef struct {
    u8 pad0[1];
    u8 b1;
    u8 pad2[0x24 - 2];
    s8 b24;
    u8 pad25[0x34 - 0x25];
    V3 v34;
    u8 pad40[0x160 - 0x40];
    s8 b[8];
} Q;

void func_001BBFC0(P *p, Q *q) {
    s8 t, *s2, *pp;
    extern void func_001BC650();
    extern void func_00175580(P *, s32, s32, s32);
    if (p->b1 != q->b1) {
        func_001BC650(p, q);
        return;
    }
    if (p->b23 == 7) {
        if (p->o->o->b5 == 3) {
            p->b4 = 2;
            p->b13C = 0;
            func_001BC650(p, q);
        }
    } else {
        if (p->wD0 != p->o->h168) {
            p->b4 = 2;
            p->b13C = 0;
            func_001BC650(p, q);
        }
    }
    p->b24 = q->b24;
    p->h1C = p->h1C + 1;
    if (p->b23 != 7) {
        p->v34 = q->v34;
        if (p->h1C < 2) p->f118 += 0.3499999940395355f;
        else if (p->h1C < 4) p->f118 = 0.699999988079071f;
        else p->f118 -= 0.04374999925494194f;
    } else {
        p->v34 = q->v34;
        if (p->h1C < 2) p->f118 += 0.25f;
        else if (p->h1C < 4) p->f118 = 0.5f;
        else p->f118 -= 0.03125f;
    }
    pp = q->b;
    t = pp[1];
    s2 = pp + 1;
    if (t == 3) {
        p->b4 = 3;
        p->b13C = 0;
        func_001BC650(p, q);
    } else if (t != 0) {
        func_00175580(p, 0x1B, p->b168, t - 1);
        *s2 = 0;
    }
}
