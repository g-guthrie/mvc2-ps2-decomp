typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_002603C0(u8 *p) {
    extern void func_001830D0();
    extern s32 func_0036BFF0();
    extern void func_00175700();
    u32 v[4];
    p[0x40C] = 2;
    p[0x33C] = 5;
    if (*(s8 *)(p + 0x151) == 1) if (*(s8 *)(p + 0x151) == 1) {
        p[0x151] = 0;
        v[0] = 0x41555555;
        v[1] = 0x433C9249;
        func_001830D0(p, v, 1);
    }
    if (*(s8 *)(p + 0x151) == 2) {
        u32 t = p[6];
        p[6] = t + 1;
        p[0x1B7] = 0;
        func_0036BFF0(p, 0x16, 0x13, 0);
        p[0x151] = 0;
    }
    func_00175700(p);
}
