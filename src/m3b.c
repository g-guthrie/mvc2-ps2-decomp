typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern s32 func_00189310(u8 *, u8 *, u8 *);
extern u8 D_0045DDA0[];
extern u8 D_0045D6C0[];
extern u8 D_0045D700[];

s32 func_003228E0(u8 *p) {
    if (!func_00189310(p, D_0045DDA0, p + 0x398)) return 0;
    if (**(s8 **)(p + 0x420) == 0) return 0;
    p[0x13C] = 1;
    p[0x26C] = 5;
    p[0x216] = 0x80;
    *(s32 *)(p + 0xD0) = 0x3C;
    return 1;
}

s32 func_00317390(u8 *p) {
    if (func_00189310(p, D_0045D6C0, p + 0x378) && **(s8 **)(p + 0x420) != 0) {
        p[0x26C] = 0;
        p[0x1B7] = 1;
        return 1;
    }
    if (func_00189310(p, D_0045D700, p + 0x398) && **(s8 **)(p + 0x420) != 0) {
        p[0x26C] = 6;
        p[0x1B7] = 1;
        return 1;
    }
    return 0;
}
