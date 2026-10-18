typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern f32 D_004F1F4C;

void func_0020B220(u8 *p) {
    extern s32 func_00175700();
    extern void func_00186A20();
    extern double func_00119058(f32);
    extern void func_001757E0();
    if ((s8)func_00175700(p) < 0) {
        f32 c;
        f32 d;
        u32 t = p[6];
        p[6] = t + 1;
        p[0x1EA] = 0x11;
        func_00186A20(p);
        if (p[0x212] != 0) c = 68.5714264f; else c = 274.285706f;
        *(f32 *)(p + 0x38) += c;
        *(f32 *)(p + 0x34) = func_00119058(D_004F1F4C) - 320.0;
        if (p[0x1B7] != 0) d = 746.666626f; else d = 0.0f;
        *(f32 *)(p + 0x34) += d;
        func_001757E0(p, 0x15, 3);
    }
}
