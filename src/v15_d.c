typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern u16 D_004F4484;
extern u16 D_004F4498;

s32 func_00131660(void) {
    extern s32 func_001315E0();
    u16 a = func_001315E0(0);
    u16 b = func_001315E0(1);
    if ((D_004F4484 & a) || (D_004F4498 & b)) return 1;
    return 0;
}
