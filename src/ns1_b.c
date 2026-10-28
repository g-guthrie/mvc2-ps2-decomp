/* func_0019F520: case body of func_0019F4F0's dispatch; runs func_0019F470 over indices 0..8 then sets up motion. */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_0019F520(u8 *p, u8 *q)
{
    extern void func_0019F470(u8 *, s32, s32);
    extern void func_001757E0(u8 *, s32, s32);
    s32 *s0;
    f32 a, b, c;
    s32 v;
    s0 = (s32 *)(p + 0x88);
    func_0019F470(p, 1, 0);
    func_0019F470(p, 1, 1);
    func_0019F470(p, 1, 2);
    func_0019F470(p, 1, 3);
    func_0019F470(p, 1, 4);
    func_0019F470(p, 1, 5);
    func_0019F470(p, 1, 6);
    func_0019F470(p, 1, 7);
    func_0019F470(p, 1, 8);
    p[0x13C] = 0;
    a = 222.8571319580078f;
    *(f32 *)(p + 0x34) = *(f32 *)(q + 0x34);
    *(f32 *)(p + 0x38) = a + *(f32 *)(q + 0x38);
    v = 0x100000;
    if (*(s16 *)(p + 0x140) == 0) v = -0x100000;
    b = 1.66666662693f;
    *(f32 *)(p + 0x5C) = b * (f32)v / 65536.0f;
    *(u32 *)(p + 0x60) = 0xC0700000;
    c = 64.0f;
    *(f32 *)(p + 0x68) = *(f32 *)(p + 0x5C) / c;
    *(f32 *)(p + 0x6C) = *(f32 *)(p + 0x60) / c;
    *s0 = 0;
    func_001757E0(p, 0x17, 1);
}
