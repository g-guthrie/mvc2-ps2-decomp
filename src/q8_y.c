typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern void (*D_00451150[])();

void func_0021BFA0(u8 *p) {
    extern s8 func_00175700();
    extern s32 func_00182E20();
    extern s32 func_00182D30();
    extern void func_001865B0();
    extern void func_001757E0();
    u8 *r, *q;
    q = *(u8 **)(p + 0x1DC);
    r = p + 0x2B8;
    if (*(s8 *)(p + 0x151) != 8 || *(s8 *)(p + 0x152) == 1) {
        if (*(s8 *)(r + 0xD) != 0) {
            p[0x151] = 8;
            p[0x152] = 4;
        }
    }
    r[0xD] = 0;
    if (func_00175700(p) < 0 && *(s8 *)(r + 0xC) < 0) {
        *(s8 *)(p + 0x1B1) = -0x80;
        p[0x201] = 0;
        func_001865B0(p);
        return;
    }
    if (*(s8 *)(r + 0xC) > 0) {
        if (func_00182E20(p) != 0) {
            p[0x152] = 1;
        }
        *(s16 *)(q + 0x270) = *(s16 *)(q + 0x270) - 1;
        if (func_00182D30(q) != 0) {
            *(s8 *)(r + 0xC) = -1;
            func_001757E0(p, 0xF, 3);
        }
    }
    D_00451150[*(s8 *)(p + 0x151) >> 1](p, q);
}
