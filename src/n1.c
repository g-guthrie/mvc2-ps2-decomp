typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s32 func_001757E0(u8 *, s32, s32);
extern s32 func_00175700(u8 *);
extern s32 func_001315E0(s32);

void func_00230D30(u8 *p) {
    f32 v;
    u32 t;
    p[0x40D] = 0;
    p[0x40C] = 0;
    p[0x33B] = 0;
    p[0x33C] = 0;
    t = p[7];
    p[7] = t + 1;
    v = 4.1666665f;
    if (*(s16 *)(p + 0x140) == 0) v = -v;
    *(f32 *)(p + 0x5C) = v;
    *(s32 *)(p + 0x68) = 0;
    *(s32 *)(p + 0x60) = 0;
    *(s32 *)(p + 0x6C) = 0;
    p[0x169] = 0x16;
    p[0x168] = 4;
    func_001757E0(p, p[0x169], p[0x168]);
}
