typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;


extern u8 D_004C1450[4];
void func_002FF950(u8 *p, u8 *q) {
    extern void func_00175700();
    u8 *r;
    s32 a;
    u32 t;
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_00175700(p);
    a = *(s8 *)(p + 0x151);
    if (a & 2) {
        p[0x151] = a & ~2;
        t = p[6];
        p[6] = t + 1;
        *(u32 *)(p + 0x6C) = 0xBF4DB6DB;
    } else if (a & 1) {
        p[0x151] = a & ~1;
        r = *(u8 **)(p + 0x1DC);
        r[0x20A] = 1;
        r[0x20D] = 2;
        p[0x219] = D_004C1450[*(s8 *)(q + 0xD)];
        r[0x1B5] = 0x20;
        p[0x1B5] = 0x20;
        r[0x1E6] = p[0x1E6];
        t = r[0x1E6];
        r[0x1E6] = t ^ 1;
    }
}
