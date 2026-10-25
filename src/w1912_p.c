typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u16 D_004D18DC[];
extern u8 D_004D18DB[];

void func_001A5F10(u8 *a, u8 *b) {
    extern void func_001A6060(u8 *, u8 *);
    extern void func_001A6690(u8 *, u8 *);
    extern void func_001A62B0(u8 *, u8 *);
    extern void func_001A61B0(u8 *);
    extern void func_001A6940(u8 *, u8 *);
    extern void func_001A64D0(u8 *, u8 *);
    u8 *c = b + 0x2B8;
    u32 t;
    if (b[5] != 0 || b[0x1E4] != 0x1A || b[0x169] != 0x14 || b[0x168] != 3) {
        a[4] = 2;
        func_001A6060(a, b);
        return;
    }
    if ((D_004D18DC[0] & (1u << D_004D18DB[0])) != 0) return;
    if (a[5] == 0) {
        func_001A6690(a, b);
        func_001A62B0(a, b);
        if (*(s8 *)(c + 0x20) == -1) {
            t = a[5];
            a[5] = t + 1;
            a[0x21] = 10;
        }
    } else {
        u32 q = a[0x21];
        u8 r = q - 1;
        a[0x21] = r;
        if (r == 0) {
            a[4] = 2;
            a[0x13C] = 0;
            func_001A6060(a, b);
        } else {
            func_001A61B0(a);
            func_001A6940(a, b);
            func_001A64D0(a, b);
            func_001A62B0(a, b);
        }
    }
}
