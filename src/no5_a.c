typedef unsigned char u8;
typedef signed char s8;
typedef short s16;
typedef int s32;
typedef unsigned int u32;

void residual_0038D810(u8 *p, s32 a)
{
    extern void func_0038D850(u8 *, s32);
    u32 t = p[5];
    p[5] = t + 1;
    p[0x14C] = 0x18;
    p[0x14D] = 0x18;
    p[0x14E] = 0x10;
    p[0x14F] = 0x10;
    *(u32 *)(p + 0x6C) = 0xBF892492;
    func_0038D850(p, a);
}
