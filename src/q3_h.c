typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 D_004F1F45;
extern u8 D_004F1F46;

void func_002BF340(u8 *p) {
    extern int func_00175700(u8 *);
    extern void func_00185490();
    u8 *q;
    f32 f;
    func_00175700(p);
    if (*(s8 *)(p + 0x151) != 0) {
        u32 t = p[6];
        p[6] = t + 1;
        p[0x151] = 0;
        q = *(u8 **)(p + 0x1DC);
        *(u8 **)(q + 0x1C8) = p;
        q[0x20A] = 3;
        q[0x1B5] = 0x23;
        if (p[0x1E6] != 0) f = 3.33333325f; else f = -3.33333325f;
        *(f32 *)(p + 0x5C) = f;
        *(u32 *)(p + 0x68) = 0;
        *(u32 *)(p + 0x60) = 0x414DB6DB;
        *(u32 *)(p + 0x6C) = 0xBF4DB6DB;
        func_00185490(p);
        D_004F1F45 = 2;
        D_004F1F46 = 1;
    }
}
