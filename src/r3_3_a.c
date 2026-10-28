typedef int s32; typedef unsigned int u32;
u32 func_003F9FE0(s32 f, u32 a, u32 b, u32 c)
{
    u32 v = b + c;
    u32 x = v;
    if (f == 0)
        return ((a + v + 0x21) / c) * c - b;
    return ((a + x + 0x39) / c) * c - b;
}
