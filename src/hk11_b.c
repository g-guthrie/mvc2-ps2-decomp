typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

s32 func_0040BDC8(s32 a0, s32 a1)
{
    s32 r = 0;
    extern s32 func_0040BD48(void);
    extern s32 func_0040BD68(void);
    extern s32 func_0040BD98(void);
    extern s32 func_0040BDB0(void);

    if (a0 == 0) {
        return 0;
    }
    switch (a1) {
    case 0xC8: r = func_0040BD48(); break;
    case 0xC9: r = func_0040BD68(); break;
    case 0xCA: r = func_0040BD98(); break;
    case 0xCB: r = func_0040BDB0(); break;
    case 0xCC: r = func_0040BD98(); break;
    case 0xCD: r = func_0040BDB0(); break;
    case 0x12B: r = 1; break;
    }
    return r;
}
