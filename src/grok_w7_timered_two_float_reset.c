typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;
typedef union { u32 bits; f32 value; } FloatBits;
extern int func_00175700(u8 *);
extern int func_001757E0(u8 *, int, int);
extern void func_001D9D80(u8 *, int, int);
void func_00302800(u8 *p)
{
    s16 timer;
    func_00175700(p);
    timer = *(s16 *)(p + 0x1C);
    timer--;
    *(s16 *)(p + 0x1C) = timer;
    if (timer != 0)
        return;
    p[6]++;
    *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
    ((FloatBits *)(p + 0x60))->bits = 0x41892492;
    ((FloatBits *)(p + 0x6C))->bits = 0xBF892492;
    func_001757E0(p, 18, 9);
    func_001D9D80(p, 0, 0);
}
