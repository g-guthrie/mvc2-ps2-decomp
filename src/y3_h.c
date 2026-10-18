typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct S1B_y { u8 pad1[0x1]; u8 b1; u8 b2; u8 pad4[0x1]; u8 b4; u8 pad18[0x13]; struct S1B_y *src; u8 pad24[0x8]; s8 c24; u8 pad30[0xB]; s8 c30; u8 pad34[0x3]; f32 f34; f32 f38; u8 pad50[0x14]; f32 f50; f32 f54; f32 f58; u8 pad13C[0xE0]; u8 b13c; u8 pad1B7[0x7A]; u8 b1b7; u8 b1b8; } S1B_y;
typedef struct { s32 w[49]; } W49_y;
typedef struct { f32 x, y, z; } V3_y;
void func_001B7F20(S1B_y *p) {
    extern void func_001B8120();
    u32 t;
    t = p->b4;
    p->b4 = t + 1;
    *(W49_y *)((u8 *)p + 0xEC) = *(W49_y *)((u8 *)p->src + 0xEC);
    p->b13c = 1;
    p->b2 = p->src->b2;
    p->b1 = p->src->b1;
    p->f50 = p->src->f50;
    p->f54 = p->src->f54;
    p->b1b7 = p->src->b1b7;
    p->b1b8 = p->src->b1b8;
    p->c30 = p->src->c30;
    *(V3_y *)&p->f50 = *(V3_y *)&p->src->f50;
    p->c24 = p->src->c24;
    p->b13c = 1;
    p->c24 = 0xB;
    p->f34 = p->src->f34;
    p->f38 = p->src->f38;
    func_001B8120(p);
}

typedef struct { u8 pad1[0x1]; u8 b1; u8 b2; u8 pad10[0xD]; u8 *fn; u8 pad18[0x4]; u8 *src; u8 pad24[0x8]; s8 c24; u8 pad30[0xB]; s8 c30; u8 pad34[0x3]; f32 f34; f32 f38; f32 f3c; u8 pad50[0x10]; f32 f50; f32 f54; f32 f58; u8 pad13C[0xE0]; u8 b13c; u8 pad1B7[0x7A]; u8 b1b7; u8 b1b8; u8 pad430[0x277]; f32 f430; } S28_z;
typedef struct { s32 w[49]; } W49_z;
typedef struct { f32 x, y, z; } V3_z;
void func_00328420(S28_z *p) {
    extern S28_z *func_003DA750(s32, s32, s32);
    extern void func_00328510();
    S28_z *o = func_003DA750(0, 4, 0);
    if (o != 0) {
        *(void **)&o->fn = func_00328510;
        o->src = (u8 *)p;
        *(W49_z *)((u8 *)o + 0xEC) = *(W49_z *)((u8 *)p + 0xEC);
        o->b13c = 1;
        o->b2 = p->b2;
        o->b1 = p->b1;
        o->f50 = p->f50;
        o->f54 = p->f54;
        o->b1b7 = p->b1b7;
        o->b1b8 = p->b1b8;
        o->c30 = p->c30;
        *(V3_z *)&o->f50 = *(V3_z *)&p->f50;
        o->c24 = p->c24;
        *(V3_z *)&o->f34 = *(V3_z *)&p->f34;
        o->f38 = p->f430;
    }
}

