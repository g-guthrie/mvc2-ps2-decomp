typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s8 func_00175700();
extern s32 func_00186570();
extern void func_00175910();
extern void func_00183d50();
extern void func_001843A0();

void func_00317800(u8 *p) {
    u32 t = p[6];
    if (t == 0) {
        u32 n;
        func_00175700(p);
        if (((s8 *)p)[0x151] == 0) {
            n = p[6];
            p[6] = n + 1;
            *(u32 *)(p + 0x5C) = 0xC0D55555;
            *(u32 *)(p + 0x68) = 0x3ED55555;
            *(u32 *)(p + 0x60) = 0x41092492;
            *(u32 *)(p + 0x6C) = 0xBF4DB6DB;
            if (p[0x1E6] != 0) {
                *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
                *(f32 *)(p + 0x68) = -*(f32 *)(p + 0x68);
            }
        }
    } else if ((u8)t == 1) {
        u32 n;
        func_00175700(p);
        if (func_00186570(p) != 0) {
            p[0x20D] = 0;
            n = p[6];
            p[6] = n + 1;
            *(u32 *)(p + 0x5C) = 0;
            *(u32 *)(p + 0x60) = 0;
            *(u32 *)(p + 0x68) = 0;
            *(u32 *)(p + 0x6C) = 0;
            func_00175910(p, 8, 2, 7);
            func_00183d50(p);
        }
    } else {
        if (func_00175700(p) < 0) func_001843A0(p);
    }
}
