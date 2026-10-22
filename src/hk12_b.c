typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

s32 func_00415250(u8 *p) {
    extern s32 func_00418410();
    extern s32 func_00418570();
    extern s32 func_00418200();
    extern s32 func_00415B00();
    u32 w = *(u32 *)(p + 4) & 0xFFFF0000;
    switch (w) {
    case 0x0: return func_00415B00(p, 4);
    case 0x10000: return func_00418200(*(s32 *)(p + 8), 4);
    case 0x20000: return func_00418570(*(s32 *)(p + 8), 4);
    case 0x30000: return func_00418410(*(s32 *)(p + 8), 4);
    }
    return 0;
}
