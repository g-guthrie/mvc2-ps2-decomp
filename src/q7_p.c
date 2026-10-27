typedef struct SA37_J0 SA37_J0;
typedef struct SA37_R SA37_R;
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;


s32 func_001659F0(u8 *p, u8 *b) {
    extern s32 func_0016B250();
    extern s32 func_0016B360(u8 *, u8 *);
    extern void func_0016B0C0(SA37_J0 *, SA37_R *, s32);
    extern void func_00186CE0();
    u16 g;
    s32 v;
    *(s8 *)(p + 0x4A9) |= 0x10;
    if (func_0016B250(p, 0) == 0) return 0;
    if (func_0016B360(p, b) == 0) return 0;
    func_0016B0C0((SA37_J0 *)p, (SA37_R *)b, 0);
    func_0016B0C0((SA37_J0 *)p, (SA37_R *)b, 1);
    v = *(s32 *)(p + 0x4C8);
    switch (v) {
    case 0:
        g = 0x2800;
        break;
    case 0xFF:
        g = 0x2000;
        break;
    case 1:
        g = 0x2400;
        break;
    }
    p[0x1E7] = v;
    *(u16 *)(p + 0x35E) = g;
    func_00186CE0(p, 0xD);
    *(u16 *)(p + 0x35E) = 0;
    if (g & 0xC00) {
        g = g ^ (p[0x1E6] * 3 << 10);
    }
    *(u16 *)(p + 0x4F0) = g;
    return 0;
}
