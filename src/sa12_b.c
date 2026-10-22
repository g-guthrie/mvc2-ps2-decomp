typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_00187370(u8 *p) {
    extern s32 func_001879C0(u8 *);
    extern void func_001757E0(u8 *, s32, u8);
    extern void func_00181D90(u8 *);
    u8 a;
    u32 h;
    p[0x20D] = 0;
    p[0x210] = 1;
    p[0x1EC] = 0;
    p[0x1EB] = 0;
    p[0x1E8] = 0;
    p[0x1E9] = 0;
    p[0x1ED] = 0;
    if (func_001879C0(p) != 0) return;
    if (*(s8 *)(p + 0x539) == 0) {
        h = *(u16 *)(p + 0x35E);
        if ((h & 0xC00) == 0) {
            *(s8 *)(p + 0x1E7) = -1;
            p[0x168] = 6;
        } else if ((h & 0x800) != 0) {
            p[0x1E7] = 0;
            p[0x168] = 7;
        } else {
            p[0x1E7] = 1;
            p[0x168] = 8;
        }
    }
    switch (*(s8 *)(p + 0x1E7)) {
    case 0: a = 7; break;
    case 1: a = 8; break;
    default: a = 6; break;
    }
    func_001757E0(p, 1, a);
    func_00181D90(p);
}
