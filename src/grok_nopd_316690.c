typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

extern int func_00118FA8(f32);
extern int func_001757E0(u8 *, int, int);

void func_00316690(u8 *p, u8 *q)
{
    *(u32 *)(p + 92) = 0xC2200000u;
    *(u32 *)(p + 104) = 0x41555555u;
    *(u32 *)(p + 96) = 0x40892492u;
    *(u32 *)(p + 108) = 0x3C092492u;
    q[22] = 0;
    *(s16 *)(q + 28) = (s16)func_00118FA8(*(f32 *)(p + 52));
    *(f32 *)(q + 24) = *(f32 *)(p + 92);
    q[23] = 32;
    func_001757E0(p, 13, 28);
    p[6]++;
}
