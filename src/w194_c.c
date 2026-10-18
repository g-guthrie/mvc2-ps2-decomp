typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

s16 func_003EAA80(u8 *p, s16 w, s16 h) {
    switch (*(s32 *)(p + 0x1C)) {
    case 0:
    case 1: w = 0x40; h = 0x20; break;
    case 2: w = 0x40; h = 0x40; break;
    case 0x13: w = 0x80; h = 0x40; break;
    case 0x14: w = 0x80; h = 0x80; break;
    }
    return ((*(s16 *)(p + 0x18) + w - 1) / w) * ((*(s16 *)(p + 0x1A) + h - 1) / h) << 5;
}
