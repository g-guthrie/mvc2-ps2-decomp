typedef unsigned char u8;
typedef unsigned int u32;
typedef float f32;
typedef int s32;

extern void func_001741D0(u8 *, f32 *);
extern s32 func_00118FA8(f32);

s32 func_001745B0(u8 *p)
{
    f32 t[2];
    f32 s;
    f32 acc;
    u32 bits;
    s32 r1;
    s32 r2;

    func_001741D0(p + 0x34, &t[0]);
    bits = 0x40092492;
    s = (f32)(u32)p[0x14D] * *(f32 *)&bits * *(f32 *)(p + 0x54);
    acc = (f32)(u32)p[0x14C] * *(f32 *)&bits * *(f32 *)(p + 0x54) + s;
    bits = 0x42892492;
    r1 = func_00118FA8(480.0f + (*(f32 *)&bits + acc));
    bits = 0x42092492;
    r2 = func_00118FA8(t[1] + (*(f32 *)&bits + s));
    return ((r1 & 0xFFFF) >= (r2 & 0xFFFF));
}
