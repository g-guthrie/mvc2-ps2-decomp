typedef unsigned char u8;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_00417A50(f32 r, f32 g, f32 b)
{
    extern void func_003DF850(s32, u32);
    u32 c;
    c = ((u32)(u8)(u32)(255.0f * r) << 16) | 0xFF000000;
    c |= (u32)(u8)(u32)(255.0f * g) << 8;
    func_003DF850(0x66, (u8)(u32)(255.0f * b) | c);
}
