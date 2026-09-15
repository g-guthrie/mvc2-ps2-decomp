typedef signed int s32;
typedef float f32;

extern s32 func_0011F5D8(void);
extern void func_003DCAD0(void *, s32, s32, s32);
extern unsigned char D_004BEE60[];

f32 func_00417F60(void)
{
    return (f32)func_0011F5D8() / 2147483648.0f;
}

s32 func_00418B50(void)
{
    func_003DCAD0(D_004BEE60, 0, 0, 0);
    return 1;
}
