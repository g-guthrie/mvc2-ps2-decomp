typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_00186DA0(u8 *p) {
    extern void func_001757E0();
    *(u32 *)(p + 0x5C) = 0;
    *(u32 *)(p + 0x60) = 0;
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x6C) = 0;
    if (p[0x217] != 0) {
        *(f32 *)(p + 0x21C) = *(f32 *)(p + 0x38);
        p[0x252] = 0;
        p[0x251] = 0;
    }
    p[0x210] = 0;
    p[0x20D] = 0;
    *(s8 *)(p + 0x1E7) = -1;
    switch (p[1]) {
    case 0x17:
        {
            u16 h = *(u16 *)(p + 0x168);
            if (h != 0x702 && h != 0x703 && h != 0xF01) func_001757E0(p, 0, 0);
        }
        break;
    case 0x38:
        (*(void (**)())(*(u8 **)(p + 0x43C) + 0x68))(p);
        break;
    case 0x3A:
        (*(void (**)())(*(u8 **)(p + 0x43C) + 0x60))(p);
        break;
    default:
        if (p[0x216] & 0x80) p[0x168] = 1; else p[0x168] = 0;
        func_001757E0(p, 0, p[0x168]);
        break;
    }
}
