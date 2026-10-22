typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct X3 X3;
typedef struct { u8 pad[0x20]; X3 *kid[13]; } M3;
typedef struct { u8 pad[0x7C]; s16 h7C[1]; } G3;
struct X3 {
    u8 p0[2];
    u8 b2;
    u8 p1[1];
    u8 b4;
    u8 b5;
    u8 p2[0xE];
    X3 *sub;
    X3 *own;
    s16 h1C;
    s16 h1E;
    u8 b20;
    u8 p3[0x13];
    f32 f34;
    f32 f38;
    u8 p4[0x20];
    f32 f5C;
    f32 f60;
    u8 p5[4];
    f32 f68;
    f32 f6C;
    u8 p6[0x60];
    u16 hD0;
    u8 p7[2];
    f32 fD4;
    u8 p8[0x64];
    u8 b13C;
    u8 p9[3];
    s16 h140;
    u8 p10[0x26];
    u16 h168;
    u8 p11[0x46];
    u8 b1B0;
    u8 b1B1;
    s8 b1B2;
    u8 p12[1];
    s8 b1B4;
    u8 b1B5;
    u8 p13[0xA];
    u16 h1C0;
    u8 p14[0x16];
    s32 w1D8;
    u8 p15[0xDC];
    M3 mv;
};

extern u8 D_004F1F45[];
extern u8 D_004F1F46[];
extern G3 *D_004C2794;
extern s16 D_004B8410[];
extern s16 D_004B8412[];

#define RESET(x, c) do { (x)->b1B5 = (c); (x)->b1B2 = (x)->h1C0 = 0; (x)->w1D8 = 0; D_004C2794->h7C[(x)->b2]++; } while (0)

s32 func_003733B0(X3 *p)
{
    extern void func_00158C70(f32 *, s32);
    extern void func_001E3710(X3 *, s32);
    extern s32 func_001E7F60(X3 *);
    extern s32 func_001745B0(void);
    X3 *o = p->own;
    X3 *sub;
    s32 w;
    M3 *mv;
    s8 i;
    X3 *k;
    u16 *hp;
    s8 v;
    u32 t;

    if (p->b20 == 0) {
        hp = &p->hD0;
        if (p->fD4 >= p->f38) {
            p->f38 = p->fD4;
            t = p->b5;
            p->b5 = t + 1;
            p->h1C = 10;
            D_004F1F45[0] = 3;
            D_004F1F46[0] = 1;
            func_00158C70(&p->f34, -1);
            func_001E3710(p, 0x31);
            return;
        }
        if (*hp != o->h168) {
            t = p->b5;
            p->b5 = t + 1;
            p->h1C = 1;
            return;
        }
        if (p->b1B2 != 0) {
            p->b1B2 = 0;
            p->f60 /= 2.0f;
            p->h1E = p->h1E + 1;
            p->b1B0 = 0;
            p->b1B1 = 0;
            mv = &o->mv;
            for (i = 1; i < 13; i++) {
                k = mv->kid[i];
                if (k != 0) {
                    k->b1B0 = 0;
                    k->b1B1 = 0;
                }
            }
        }
        if (p->b1B4 != 0) {
            o->b1B4 = p->b1B4;
            v = p->b1B4 - 1;
            p->b1B4 = v;
            if (v != 0) return;
            if (p->h1E == 5) return;
            p->b1B0 = 0x42;
            p->b1B1 = 0x42;
            if (p->h1E == 4) {
                RESET(p, 0x3B);
                RESET(o, 0x3B);
            } else {
                RESET(p, 0x3A);
                RESET(o, 0x3A);
            }
            mv = &o->mv;
            for (i = 1; i < 13; i++) {
                k = mv->kid[i];
                if (k != 0) {
                    k->b1B0 = 0x42;
                    k->b1B1 = 0x42;
                    if (p->h1E == 4) {
                        RESET(k, 0x3B);
                        RESET(o, 0x3B);
                    } else {
                        RESET(k, 0x3A);
                        RESET(o, 0x3A);
                    }
                }
            }
        }
        p->f34 += p->f5C;
        p->f5C += p->f68;
        p->f38 += p->f60;
        p->f60 += p->f6C;
        if (p->h1E <= 4) return func_001E7F60(p);
    } else {
        sub = p->sub;
        if (sub->b4 > 1) {
            t = p->b4;
            p->b4 = t + 1;
            p->b13C = 0;
            return;
        }
        if (func_001745B0() != 0) p->b13C = 1; else p->b13C = 0;
        p->f34 = sub->f34;
        p->f38 = sub->f38;
        p->f38 += (f32)*(s16 *)((u8 *)D_004B8412 + p->b20 * 4);
        if (o->h140 != 0) {
            w = -*(s16 *)((u8 *)D_004B8410 + p->b20 * 4);
        } else {
            w = *(s16 *)((u8 *)D_004B8410 + p->b20 * 4);
        }
        p->f34 += (f32)w;
        if (p->b1B2 != 0) {
            p->b1B2 = 0;
            p->f60 /= 2.0f;
            sub->h1E = sub->h1E + 1;
            sub->b1B0 = 0;
            sub->b1B1 = 0;
            mv = &o->mv;
            for (i = 1; i < 13; i++) {
                k = mv->kid[i];
                if (k != 0) {
                    k->b1B0 = 0;
                    k->b1B1 = 0;
                }
            }
        }
        if (p->b1B4 != 0) {
            o->b1B4 = p->b1B4;
            sub->b1B4 = p->b1B4;
            p->b1B4 = 0;
        } else {
            if (sub->b1B4 != 0) return;
            if (sub->h1E <= 4) return func_001E7F60(p);
        }
    }
}
