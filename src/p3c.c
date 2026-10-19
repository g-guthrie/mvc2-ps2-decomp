typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern void func_0011D8F8(void *, s32, s32);
extern u8 D_00490DA8[];
extern s32 D_004C24D8;

void func_0040F598(void) {
    if (--D_004C24D8 == 0) func_0011D8F8(D_00490DA8, 0, 0x4000);
}
