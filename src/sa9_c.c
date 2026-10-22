typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

/* Metrowerks 3.0: ./try30.sh src/sa9_c.c "-O3 -Op -sdatathreshold 0" */

typedef struct {
    u8 pad0[0x10];
    void *f10;
    u8 pad1[0x34 - 0x14];
    f32 f34, f38, f3c;
    u8 pad2[0x50 - 0x40];
    f32 f50, f54, f58;
    u8 pad3[0xD0 - 0x5C];
    u32 fD0;
    u8 pad4[0x13C - 0xD4];
    u8 b13C;
    u8 pad5[3];
    s16 h140;
} S154;

void func_00154470(S154 *p, u8 a, u32 n, f32 x, f32 y)
{
    extern S154 *func_003DA750(s32, s32, s32);
    extern void func_00154400();
    S154 *o;
    if ((o = func_003DA750(0, 0x13, 1)) != 0) {
        s32 d;
        o->b13C = 1;
        o->f10 = (void *)func_00154400;
        o->fD0 = 0x800011;
        o->f34 = p->f34;
        o->f38 = p->f38;
        o->f3c = 0;
        d = p->h140 != 0 ? a : -a;
        o->f34 += d;
        o->f38 += (f32)n;
        o->f50 = x;
        o->f54 = y;
        o->f58 = 0;
    }
}
