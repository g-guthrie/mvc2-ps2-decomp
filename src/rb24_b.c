typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef int s32;

s32 func_00167B10(u8 *a, s32 b) {
    extern s32 func_0016B240(u8 *, s32);
    extern void func_0016B0C0(u8 *, s32, s32);
    extern s32 func_00185DD0(u8 *);
    extern s32 func_0016A320(u8 *);
    extern void func_00186CE0(u8 *, u8);
    u16 s0;
    s32 h;
    u16 code;
    u16 v1;
    u32 t;
    if (func_0016B240(a, 1) == 0) return 0;
    func_0016B0C0(a, b, 0);
    func_0016B0C0(a, b, 1);
    *(s32 *)(a + 0x460) = *(s32 *)(a + 0x4C8);
    if (a[0x216] != 0 || *(s8 *)(a + 0x204) != 0 || func_00185DD0(a) == 0 || (h = (u16)func_0016A320(a)) == 0) return 1;
    t = a[0x451];
    a[0x451] = t + 1;
    s0 = 0x400;
    if (a[0x20D] == 2) {
        code = 0x13;
    } else {
        if (a[0x454] == 0x3C) {
            s0 |= 0x1000;
            v1 = 5;
        } else if ((u16)h & 4) {
            s0 |= 0x1000;
            v1 = 5;
        } else {
            v1 = 7;
        }
        func_00186CE0(a, v1);
        code = 0x12;
    }
    *(s32 *)(a + 0x464) = s0 ^ (a[0x1E6] * 3 << 10);
    *(s16 *)(a + 0x4F0) = *(s16 *)(a + 0x464);
    *(u16 *)(a + 0x35E) = s0;
    func_00186CE0(a, code);
    *(u16 *)(a + 0x35E) = 0;
    return 0;
}
