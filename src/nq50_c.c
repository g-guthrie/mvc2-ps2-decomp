typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 D_004C1448[8];

void func_002FF790(u8 *p, u8 *q) {
    extern s32 func_002FFB30();
    extern void func_00175910(u8 *, s32, s32, s32);
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_001D91E0(u8 *, s32, s32);
    s16 h;
    (*(u8 **)(p + 0x220))[0x21] = 1;
    if (func_002FFB30(p) != 0) func_00175910(p, 0xF, 0, q[0xB]);
    h = *(s16 *)(p + 0x1C);
    *(s16 *)(p + 0x1C) = h - 1;
    if (h == 0) {
        u32 t = p[6]; p[6] = t + 1;
        func_001757E0(p, 0xF, 1);
        (*(u8 **)(p + 0x220))[0x21] = 0;
        *(f32 *)(p + 0x60) = 2.142857074737549f * (f32)(D_004C1448[*(s8 *)(q + 0xD)] << 16) / 65536.0f;
        *(f32 *)(p + 0x6C) = -0.8035714030265808f;
        func_001D91E0(p, 3, 0);
        func_001D91E0(p, 3, 1);
    }
}
