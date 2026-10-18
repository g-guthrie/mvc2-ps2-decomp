typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct O {
    u8 p0[0x34]; f32 f34; u8 p38[0x116]; u8 b14e; u8 p14f[0x97]; u8 b1e6;
} O;
typedef struct P {
    u8 p0[0x34]; f32 f34; u8 p38[0x1AC]; u8 b1e4; u8 p1e5[0x3B]; O *o220; u8 p224[0x22D]; u8 b451; u8 p452[0xE];
    f32 f460; f32 f464; u32 w468; s32 w46c; u8 p470[0x46]; s8 b4b6; u8 b4b7; u8 p4b8[0x10]; f32 f4c8;
    u8 p4cc[0x24]; u16 h4f0;
} P;
s32 func_001649C0(P *p, s32 q) {
    extern s32 func_0016B240(P *, s32);
    extern void func_0016B0C0(P *, s32, s32);
    extern s32 func_00164B10(P *, s32);
    O *o;
    f32 f;
    u16 m;
    if (func_0016B240(p, 6) == 0) return 0;
    func_0016B0C0(p, q, 0);
    o = p->o220;
    func_0016B0C0(p, q, 3);
    p->f460 = p->f4c8 + 1.6666666269302368f * o->b14e;
    func_0016B0C0(p, q, 4);
    p->f464 = p->f4c8;
    f = p->f460;
    if (o->b1e6 == 0) f = -f;
    f += o->f34;
    if (f < p->f34) {
        p->w46c = 0;
        m = 0x800;
    } else {
        m = 0x400;
        p->w46c = 1;
    }
    p->b451++;
    p->b4b7 = p->b1e4;
    p->w468 = m;
    p->h4f0 = m;
    p->b4b6 = -0x4C;
    return func_00164B10(p, q);
}
