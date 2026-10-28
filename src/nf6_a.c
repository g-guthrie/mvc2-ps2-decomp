typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
typedef float f32;

extern void func_001757E0(u8 *, s32, s32);

void residual_0019E000(u8 *p) {
    u8 *q = *(u8 **)(p + 0x18);
    f32 d;
    *(s8 *)(p + 0x31) = -2;
    *(s16 *)(p + 0x1C) = 0x28;
    d = 800.0f;
    *(f32 *)(p + 0x5C) = -3.3333332538604736f;
    *(f32 *)(p + 0x68) = -0.20833332836627960f;
    *(f32 *)(p + 0x60) = -4.285714149475098f;
    *(f32 *)(p + 0x6C) = 0.13392856717109680f;
    if (*(s16 *)(q + 0x140) == 0) {
        d = -d;
        *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x68) = -*(f32 *)(p + 0x68);
    }
    *(f32 *)(p + 0x34) = *(f32 *)(q + 0x34) + d;
    *(f32 *)(p + 0x38) = 480.0f + *(f32 *)(q + 0x38);
    p[0x13C] = 0;
    p[5] = 0;
    func_001757E0(p, 0x13, 8);
}
