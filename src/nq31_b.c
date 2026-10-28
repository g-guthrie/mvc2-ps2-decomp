typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
extern u8 *D_004C2794;
void residual_002F9C80(u8 *p, s32 a) {
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_002F8D80(u8 *);
    extern void func_001E3C40();
    extern void func_002F9D60(u8 *, s32);
    u32 t;
    p[0x40D] = 0xFF;
    p[0x40C] = 0x10;
    p[0x33B] = 1;
    D_004C2794[0x76] = (*(s8 *)(p + 2) << 4) | 1;
    p[0x33C] = 0x10;
    t = p[7];
    p[7] = t + 1;
    *(u32 *)(p + 0x5C) = 0;
    *(u32 *)(p + 0x60) = 0;
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x6C) = 0;
    switch (p[0x20D]) {
    case 0: p[0x168] = 7; break;
    case 1: p[0x168] = 8; break;
    default: p[0x168] = 9; break;
    }
    func_001757E0(p, 0xF, p[0x168]);
    func_002F8D80(p);
    func_001E3C40();
    func_002F9D60(p, a);
}
