typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;


void func_00377500(u8 *p, u8 *q) {
    extern s8 func_00175700();
    extern void func_001E7F60();
    extern void func_001757E0();
    s32 t;
    if (func_00175700(p) < 0) {
        p[4] = 2;
        p[5] = 3;
        *(u32 *)(p + 0x5C) = 0;
        *(u32 *)(p + 0x60) = 0;
        *(u32 *)(p + 0x68) = 0;
        *(u32 *)(p + 0x6C) = 0;
        func_001757E0(p, 0x17, 0xC);
        return;
    }
    t = *(s8 *)(p + 0x1B2);
    if (t != 0) {
    if (((s8)t & 1) != 0) {
        p[4] = 2;
        p[5] = 1;
        *(f32 *)(p + 0x5C) = 2.0f * -*(f32 *)(p + 0x5C);
        *(u32 *)(p + 0x60) = 0x40CDB6DB;
        *(u32 *)(p + 0x6C) = 0xBF4DB6DB;
        func_001757E0(p, 0x17, 0xD);
    } else {
        u8 *r = *(u8 **)(p + 0x1C4);
        if (r[3] == 0 && r[5] == 3 && *(s16 *)(r + 0x434) != 0) {
            p[4] = 2;
            p[5] = 5;
            *(u32 *)(p + 0x5C) = 0;
            *(u32 *)(p + 0x60) = 0;
            *(u32 *)(p + 0x68) = 0;
            *(u32 *)(p + 0x6C) = 0;
            *(f32 *)(p + 0x38) = *(f32 *)(q + 0x430);
        }
    }
    } else {
        func_001E7F60(p);
    }
}
