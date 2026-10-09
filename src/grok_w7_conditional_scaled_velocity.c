typedef unsigned char u8;
typedef unsigned short u16;
typedef signed char s8;
typedef unsigned int u32;
typedef float f32;
typedef union { u32 bits; f32 value; } FloatBits;
extern int func_00175700(u8 *);
extern int func_001757E0(u8 *, int, int);
void func_0030D4B0(u8 *p)
{
    u16 phase;
    func_00175700(p);
    if (*(s8 *)(p + 0x1B2) == 0)
        return;
    p[6]++;
    *(f32 *)(p + 0x5C) = -(*(f32 *)(p + 0x5C)) * 3.0f / 4.0f;
    ((FloatBits *)(p + 0x60))->bits = 0x41892492;
    ((FloatBits *)(p + 0x6C))->bits = 0xBF4DB6DB;
    phase = p[0x168];
    phase++;
    p[0x168] = phase;
    func_001757E0(p, 12, (u8)phase);
}
