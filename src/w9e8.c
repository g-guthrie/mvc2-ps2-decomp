typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s32 D_004C24D0;
extern u8 D_004908F8[];
extern void *func_0011D8F8(void *, s32, u32);
void func_0040F070(void)
{
    s32 v = D_004C24D0 - 1;
    D_004C24D0 = v;
    if (v == 0) {
        func_0011D8F8(D_004908F8, 0, 0x480);
    }
}
