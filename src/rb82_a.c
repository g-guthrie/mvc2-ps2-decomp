typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern s32 D_004C29B0;
extern u8 D_004C2740;
extern u8 D_004C273C;
extern u8 D_004C2738;
extern s8 D_005852A0[];
extern s8 D_0058C020[];
extern s8 D_00583D00[];
extern u16 D_0058C770[];
extern u16 D_0058C772[];
extern u8 D_00584340[];
extern u8 D_00584AC0[];
extern u8 D_00584AC1[];
extern u8 D_004CDAE0[];
extern u8 D_004CD720[];
extern u8 D_004CD360[];
extern u8 D_004CD350[];
extern u8 D_00584700[];

s32 func_0038C210(u8 mode)
{
    s32 n;
    s8 *src;
    s8 *dst;
    s32 i;
    u16 r;
    extern void func_0011D8F8(void *, s32, s32);
    extern u16 func_0038CB20(void);
    extern u16 func_0038CA90(void);
    extern void *memcpy(void *, void *, s32);

    n = D_004C29B0;
    src = D_005852A0;
    switch (mode) {
    case 0:
        return -0xBF;
    case 1:
        if (n != 0x754) return -0xBF;
        dst = D_0058C020;
        func_0011D8F8(dst, 0, 0x754);
        break;
    case 2:
        return -0xBF;
    case 3:
        return -0xBF;
    case 4:
        if (n != 0xDD4) return -0xBF;
        dst = D_00583D00;
        func_0011D8F8(dst, 0, 0xDD4);
        break;
    default:
        if (n != 0x754) return -0xBF;
        dst = D_0058C020;
        func_0011D8F8(dst, 0, 0x754);
        break;
    }
    for (i = 0; i < n; i++) *dst++ = *src++;
    if (mode == 1) {
        r = func_0038CB20();
        if (D_0058C770[0] != r) return -0xBF;
        r = func_0038CA90();
        if (D_0058C772[0] != r) return -0xBF;
    } else if (mode == 4) {
        memcpy(D_004CDAE0, D_00583D00, 0x640);
        D_004C2740 = D_00584340[0];
        memcpy(D_004CD720, D_00584340 + 1, 0x3BF);
        memcpy(D_004CD360, D_00584700, 0x3C0);
        D_004C273C = D_00584AC0[0];
        D_004C2738 = D_00584AC1[0];
        memcpy(D_004CD350, D_00584AC0 + 2, 0x10);
    }
    return 0;
}
