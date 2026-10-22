typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { u8 pad[0x7C]; s16 f7c[1]; } G;
extern G *D_004C2794;
void func_0026D590(u8 *p) {
    extern void func_00175700(u8 *);
    extern s32 func_0018AB10(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    u32 v;
    s32 w;
    s16 h;
    u32 t;
    p[0x40C] = 2;
    p[0x33C] = 5;
    p[0x209] = 3;
    func_00175700(p);
    v = p[0x15B];
    if (v != 0) {
    w = v & 0xFF;
    if (w < 0x80) {
        p[0x1B5] = w + 0x38;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(s32 *)(p + 0x1D8) = 0;
        D_004C2794->f7c[p[2]]++;
        *(s16 *)(p + 0x1C0) = 0x10;
        p[0x15B] = 0;
    }
    }
    if (*(f32 *)(p + 0x6C) < *(f32 *)(p + 0x68)) *(f32 *)(p + 0x6C) += 1.0f;
    *(f32 *)(p + 0x50) = *(f32 *)(p + 0x298) + *(f32 *)(p + 0x6C) / *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x54) = *(f32 *)(p + 0x29C) + *(f32 *)(p + 0x6C) / *(f32 *)(p + 0x68);
    if (*(s16 *)(p + 0x1E) != 0 && func_0018AB10(p) != 0) {
        *(s16 *)(p + 0x1E) -= 1;
        *(s16 *)(p + 0x1C) += 1;
    }
    h = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = h;
    if (h < 0) {
        p[0x209] = 0;
        t = p[6];
        p[6] = t + 1;
        p[7] = 0;
        *(u32 *)(p + 0x68) = *(u32 *)(p + 0x6C) = 0x42080000;
        func_001757E0(p, 0x16, 2);
    }
}
extern u8 *D_004C2840;
extern u8 D_004F1F45[], D_004F1F46[];
void func_00266CA0(u8 *p, u8 *q) {
    extern void func_00176160(u8 *, s32, s32, s32);
    extern void func_00175C00(u8 *, s32);
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_001E3210(u8 *, s32);
    extern void func_00191210(u8 *);
    f32 f = 0.02f;
    f32 one = 1.0f;
    u32 t;
    p[0x40C] = 2;
    p[0x33C] = 5;
    if ((*(u32 *)(D_004C2840 + 0x1C) & 1) == 0) {
        func_00176160(p, 0, p[0x25] + 6, 1);
    } else {
        func_00175C00(p, 8);
    }
    if ((*(u32 *)(D_004C2840 + 0x1C) & 7) == 0) {
        D_004F1F45[0] = 2;
        D_004F1F46[0] = 1;
    }
    *(f32 *)(q + 0xC) += f;
    *(f32 *)(q + 0x14) += f;
    *(f32 *)(p + 0x50) = *(f32 *)(q + 0xC);
    *(f32 *)(p + 0x54) = *(f32 *)(q + 0x14);
    if (!(*(f32 *)(q + 0x14) <= one)) {
        *(f32 *)(q + 0xC) = one;
        *(f32 *)(q + 0xC) = one;
        *(f32 *)(p + 0x50) = one;
        *(f32 *)(p + 0x54) = *(f32 *)(q + 0x14);
        t = p[7];
        p[7] = t + 1;
        *(s16 *)(q + 8) = 0x1E;
        func_001757E0(p, 0x16, 0x37);
        func_00175C00(p, 0);
        func_00176160(p, 0, p[0x25] + 6, 1);
        func_00176160(p, 2, 0xC, 2);
        func_001E3210(p, 0x25);
    }
    t = p[0x216];
    p[0x216] = t | 0x80;
    p[0x1FF] = 2;
    func_00191210(p);
}
