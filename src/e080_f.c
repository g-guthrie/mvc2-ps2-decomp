/* residual_0019C890: MW 3.0 (MWCCPS2_30) "-O3 -Op -fp off -sdatathreshold 0", compiled after src/e080_b.c (func_00174F60) in the same mwccps2 invocation (soft-float warm rule). */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u32 w[0x31]; } Blk31;
typedef struct { f32 x, y, z; } V3;
typedef struct Obj {
    u8 pad0;
    u8 b1;
    u8 b2;
    u8 pad3;
    u8 b4;
    u8 pad5[0x13];
    struct Obj *src;
    u8 pad1C[4];
    u8 b20;
    u8 pad21[3];
    s8 b24;
    u8 pad25[0xB];
    s8 b30;
    u8 pad31[3];
    f32 f34;
    f32 f38;
    u8 pad3C[0x14];
    V3 v50;
    u8 pad5C[0xE0];
    u8 b13C;
    u8 pad13D[3];
    s16 h140;
    u8 pad142[0x75];
    u8 b1B7;
    u8 b1B8;
} Obj;

void residual_0019C890(Obj *p) {
    extern void func_001757E0(Obj *, s32, s32);
    extern void func_0019CA20(Obj *);
    f32 k;
    u32 t;
    u8 one;
    one = 1;
    t = p->b4;
    p->b4 = t + 1;
    *(Blk31 *)((u8 *)p + 0xEC) = *(Blk31 *)((u8 *)p->src + 0xEC);
    p->b13C = one;
    p->b2 = p->src->b2;
    p->b1 = p->src->b1;
    p->v50.x = p->src->v50.x;
    p->v50.y = p->src->v50.y;
    p->b1B7 = p->src->b1B7;
    p->b1B8 = p->src->b1B8;
    p->b30 = p->src->b30;
    p->v50 = p->src->v50;
    p->b24 = p->src->b24;
    p->b13C = one;
    p->f34 = p->src->f34;
    p->f38 = p->src->f38;
    if (p->b20 != 0) {
        p->b24 = 7;
        k = 8.0f;
        if (p->b20 == 1) {
            k = 6.0f;
            if (p->src->h140 != 0) {
                p->f34 += 236.66665649414062f;
            }
            p->h140 = 0;
        }
    } else {
        k = 5.0f;
        p->b24 = 0;
    }
    func_001757E0(p, 0x13, (s32)k);
    func_0019CA20(p);
}
