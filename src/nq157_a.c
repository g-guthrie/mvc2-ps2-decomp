typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern u8 D_006207A0[];
extern u8 D_004BA770[];
extern u8 D_004BA7B0[];
extern u8 D_004BA7F0[];

s32 func_003E8C00(u8 *a, s32 id, s32 c) {
    extern void func_003ED0D0();
    extern s16 func_003EAA30(s32);
    extern s16 func_003EAA80(u8 *);
    extern s32 func_003EA990(u8 *);
    u8 *e = D_006207A0 + ((id & 0xFFFF) - 1) * 64;

    *(s16 *)(e + 0x2C) = 1;
    *(s32 *)(e + 0x0) = c;
    *(s32 *)(e + 0x4) = *(s32 *)(a + 0x0);
    *(s16 *)(e + 0x18) = *(s16 *)(a + 0x4);
    *(s16 *)(e + 0x1A) = *(s16 *)(a + 0x8);
    *(s32 *)(e + 0x20) = 0;
    *(s32 *)(e + 0x28) = 0;
    *(s32 *)(e + 0x30) = 0;
    *(s32 *)(e + 0x34) = 0;
    switch (*(s32 *)(a + 0x14)) {
    default:
        func_003ED0D0(D_004BA770);
        return 0;
    case 0:
        *(s32 *)(e + 0x1C) = 0x14;
        *(s32 *)(e + 0xC) = 0;
        break;
    case 1:
        *(s32 *)(e + 0x1C) = 0x13;
        *(s32 *)(e + 0xC) = 1;
        break;
    case 2:
        *(s32 *)(e + 0x1C) = 2;
        *(s32 *)(e + 0xC) = 2;
        break;
    case 3:
        *(s32 *)(e + 0x1C) = 1;
        *(s32 *)(e + 0xC) = 3;
        break;
    case 4:
        *(s32 *)(e + 0x1C) = 0;
        *(s32 *)(e + 0xC) = 4;
        break;
    }
    switch (*(s32 *)(a + 0x4)) {
    case 0x400: case 0x200: case 0x100: case 0x80: case 0x40: case 0x20:
        break;
    default:
        func_003ED0D0(D_004BA7B0, *(s32 *)(a + 0x4));
        return 0;
    }
    *(s16 *)(e + 0x14) = func_003EAA30(*(s16 *)(e + 0x18));
    switch (*(s32 *)(a + 0x8)) {
    case 0x400: case 0x200: case 0x100: case 0x80: case 0x40: case 0x20:
        break;
    default:
        func_003ED0D0(D_004BA7F0, *(s32 *)(a + 0x8));
        return 0;
    }
    *(s16 *)(e + 0x16) = func_003EAA30(*(s16 *)(e + 0x1A));
    *(s16 *)(e + 0x10) = func_003EAA80(e);
    *(s32 *)(e + 0x8) = func_003EA990(e);
    return 1;
}
