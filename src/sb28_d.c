typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_003A5790(u8 *p, u8 *q) {
    extern void func_003A5930(u8 *, s32);
    extern void func_00175700(u8 *);
    extern void func_001E7F60(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    extern s32 func_00174470(u8 *);
    extern void func_003A5900(u8 *, u8 *);
    s32 x = *(s32 *)(p + 0x14);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    func_003A5930(p, x);
    func_00175700(p);
    func_001E7F60(p);
    switch (q[0x2B8]) { default: { u32 t = p[5]; p[5] = t + 1; if (p[0x20] == 2) { func_001757E0(p, 0x17, 1); } else { func_001757E0(p, 0x17, 4); } return; } break; case 0: { if (func_00174470(p) == 0) { u32 t = p[4]; p[4] = t + 1; func_003A5900(p, q); } } break; }
}
