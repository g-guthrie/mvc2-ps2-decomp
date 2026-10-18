typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

s32 func_003BD050(u8 *a)
{
    u8 *b = a + 0xD0;
    u8 *v = *(u8 **)b;
    if (*(s16 *)(v + 0x434) == 0) return -1;
    if (v[5] == 0) {
        b[8] = 0xFF;
        return 0;
    }
    return b[8] ? -1 : 0;
}

extern s32 D_004F1CF0;
void func_00122880(void)
{
    extern s32 func_003D70D0();
    extern s32 func_003D7120();
    extern void func_00122960();
    extern void func_00122CD0();
    extern void func_003DF850();
    s32 x, y, z;
    z = 0;
    y = 0;
    x = 0;
    if (func_003D70D0() != 0 || func_003D7120() != 0) {
        func_00122960(&x, &y, &z);
    } else {
        func_00122CD0(&x, &y, &z);
    }
    switch (D_004F1CF0) {
    case 0:
        func_003DF850(0x14, x);
        break;
    case 1:
        func_003DF850(0x14, x);
        break;
    case 2:
        func_003DF850(0x14, x);
        break;
    case 3:
        func_003DF850(0x14, x);
        break;
    }
}
