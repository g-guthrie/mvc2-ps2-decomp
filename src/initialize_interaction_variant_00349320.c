/* Initialize the paired actor interaction variant. */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;
typedef struct { u8 pad0[0x7C]; s16 h7c[2]; } G12;
extern G12 *D_004C2794;

void func_00349320(u8 *p, u8 *q) {
    extern void func_00175910();
    extern void func_0034A080();
    u8 *r = *(u8 **)(p + 0x14);
    u16 *d = (u16 *)(p + 0x88);
    *(u32 *)(p + 0x14C) = 0x20202020;
    p[0x1B0] = 0x42;
    p[0x1B1] = 0;
    p[0x1B5] = 0x47;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    D_004C2794->h7c[p[2]]++;
    *(u32 *)(p + 0x5C) = 0x43055555;
    *(u32 *)(p + 0x68) = 0x42A00000;
    if (*(s16 *)(p + 0x140) == 0) {
        *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x68) = -*(f32 *)(p + 0x68);
    }
    *d = *(u16 *)(q + 0x168);
    p[0x169] = 0x16;
    p[0x168] = 0x25;
    func_00175910(p, p[0x169], p[0x168], *(s8 *)(r + 0x151));
    *(s8 *)(p + 0x31) = -6;
    func_0034A080(p, q);
}

