typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;


void func_0018DE90(u8 *p) {
    extern void func_0018E810(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    u8 *q;
    q = *(u8 **)(p + 0x1CC);
    if (q == 0) q = *(u8 **)(p + 0x220);
    p[0x247] = 3;
    p[0x248] = 0;
    p[0x1F3] = 0xFF;
    p[0x20D] = 2;
    *(u32 *)(p + 0x68) = 0;
    if (q[0x1E6] != 0) {
        *(u32 *)(p + 0x22C) = 0x40A00000;
    } else {
        *(u32 *)(p + 0x22C) = 0xC0A00000;
    }
    *(u32 *)(p + 0x230) = 0x421A4924;
    *(u32 *)(p + 0x6C) = 0xBF700000;
    p[0x1F5] = 0x50;
    p[0x201] = 2;
    p[0x1B1] = 0;
    func_0018E810(p);
    func_001757E0(p, 13, 28);
}
