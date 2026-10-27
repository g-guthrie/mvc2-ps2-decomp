typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_00191F90(u8 *p) {
    extern void func_00192340(u8 *);
    extern void func_00192580(u8 *);
    extern void func_001926F0(u8 *);
    extern void func_001925A0(u8 *);
    extern void func_00192090(u8 *);
    switch (p[1]) {
    case 0x3:
    case 0xC:
    case 0xE:
    case 0x10:
    case 0x14:
    case 0x30:
        (*(void (**)(u8 *))(*(u8 **)(p + 0x43C) + 0x54))(p);
        return;
    case 0xA:
        func_00192340(p);
        break;
    case 0xF:
    case 0x2E:
    case 0x33:
        func_00192580(p);
        break;
    case 0x2A:
    case 0x2C:
    case 0x25:
        func_001926F0(p);
        break;
    case 0x35:
        func_001925A0(p);
        break;
    default:
        func_00192090(p);
        break;
    }
}

s32 func_0018BF90(u8 *p) {
    extern s32 func_00185DD0();
    u8 *q = *(u8 **)(p + 0x1D0);
    p[0x244] = q[2];
    if (p[0x244] & 8) return 1;
    if (p[0x425] != 0) return 1;
    if ((((u8 *)*(u8 **)(p + 0x1C8))[0x15A] & 0xE0) == 0) return 1;
    p[0x247] = *(s8 *)(q + 1) & 0x1F;
    if (p[5] == 3) return 1;
    if (p[5] == 0 && p[0x1E4] == 0x15) return 1;
    if (p[0x20D] == 3) return 1;
    if (p[0x1E4] == 0x19) return 1;
    if (p[5] == 2) return 1;
    if (func_00185DD0(p) == 0) return 1;
    return (p[0x15A] & 0xE0) != 0;
}

