typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

extern int func_00175700(u8 *);
extern int func_001DD8A0(u8 *, int, int);
extern void func_001E3710(u8 *, int);
extern u8 D_004F1F45;
extern u8 D_004F1F46;

void residual_00315CA0(u8 *p)
{
    func_00175700(p);
    if (*(s8 *)(p + 0x151)) {
        p[6]++;
        *(u32 *)(p + 0x5C) = 0xC1D55555;
        if (*(s16 *)(p + 0x140))
            *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
        D_004F1F45 = 3;
        D_004F1F46 = 1;
        func_001DD8A0(p, 8, 0);
        func_001E3710(p, 41);
    }
}
