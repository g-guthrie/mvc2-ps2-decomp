typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
extern s32 func_001891F0(void *, s32);
extern void func_00186A60(void *, s32);
typedef struct { u8 pad0[5]; u8 b5, b6, b7; u8 pad1[0x1FD-8]; u8 b1FD; u8 pad2[0x2DC-0x1FE]; s32 f2DC; } S;
s32 func_003227C0(S *p) {
    if (func_001891F0(p, 4) == 0) return 0;
    {
        u8 v = 4;
        if (p->f2DC > 0) {
            p->f2DC = 0;
            v = 10;
        }
        p->b1FD = v;
    }
    p->b5 = 0; p->b7 = 0; p->b6 = 0; func_00186A60(p, 0x15);
    return 1;
}
