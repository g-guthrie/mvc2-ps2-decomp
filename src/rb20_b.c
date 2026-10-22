typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern f32 D_004F1FC8;
extern f32 D_004F1FCC;

void func_00374000(u8 *p)
{
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_00176160(u8 *, s32, s32, s32);
    extern void func_00154470(u8 *, s32, s32, f32, f32);
    u8 *q;
    u32 t;
    f32 f, cur;

    t = p[5];
    p[5] = t + 1;
    p[6] = 0;
    *(f32 *)(p + 0x54) = 1.0f;
    *(f32 *)(p + 0x50) = 1.0f;
    func_001757E0(p, 0x16, p[0x20]);
    q = *(u8 **)(p + 0x18);
    *(s16 *)(p + 0x140) = *(s16 *)(q + 0x140);
    *(f32 *)(p + 0x5C) = 0.0f;
    *(f32 *)(p + 0x68) = 0.0f;
    *(f32 *)(p + 0x60) = 6.4285712242126465f;
    *(f32 *)(p + 0x6C) = -0.46875f;
    func_00176160(p, 2, 2, 2);
    func_00154470(p, 0, 0x90, 4.0f, 4.0f);
    func_00154470(p, 0x10, 0x90, 4.0f, 4.0f);
    func_00154470(p, 0xF0, 0x90, 4.0f, 4.0f);
    if (*(s16 *)(q + 0x140) != 0) {
        f = D_004F1FCC - 160.0f;
        cur = *(f32 *)(p + 0x34);
        if (cur > f) *(f32 *)(p + 0x34) = f;
    } else {
        f = 160.0f + D_004F1FC8;
        cur = *(f32 *)(p + 0x34);
        if (cur < f) *(f32 *)(p + 0x34) = f;
    }
}
