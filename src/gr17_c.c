typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;
typedef struct { s32 w[0x31]; } B3c;
typedef struct { u8 pad[0x7C]; s16 f7c[1]; } G3c;
typedef struct { u8 pad[0x34]; f32 f34; } N3c;
extern G3c *D_004C2794;
extern u8 *D_004C29F0;
extern u8 *D_004C29F4;
extern f32 D_00472570[];
extern u8 D_004725C0[];

void residual_00399300(u8 *p) {
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_00399690(u8 *);
    extern void func_00399570(u8 *);
    u32 t;
    u32 i;
    u8 *q;
    f32 *ft;
    u8 *bt;
    t = p[4];
    p[4] = t + 1;
    if (D_004C29F0[2] == 0) {
        p[0x1B5] = 0x47;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(s32 *)(p + 0x1D8) = 0;
        { s16 *h = (s16 *)(((u32)p[2] << 1) + (u32)D_004C2794); h[0x7C / 2] = h[0x7C / 2] + 1; }
    } else {
        p[0x1B5] = 0x4D;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(s32 *)(p + 0x1D8) = 0;
        { s16 *h = (s16 *)(((u32)p[2] << 1) + (u32)D_004C2794); h[0x7C / 2] = h[0x7C / 2] + 1; }
    }
    *(s16 *)(p + 0x1C0) = 0x10;
    p[0x1B0] = 0x42;
    p[0x1B1] = 0x44;
    if (*(u16 *)D_004C29F0 != *(u16 *)((q = *(u8 **)(p + 0x18)) + 0x168)) {
        func_00399690(p);
        return;
    }
    *(B3c *)(p + 0xEC) = *(B3c *)(q + 0xEC);
    p[0x13C] = 1;
    p[2] = (*(u8 **)(p + 0x18))[2];
    p[1] = (*(u8 **)(p + 0x18))[1];
    *(f32 *)(p + 0x50) = *(f32 *)(*(u8 **)(p + 0x18) + 0x50);
    *(f32 *)(p + 0x54) = *(f32 *)(*(u8 **)(p + 0x18) + 0x54);
    p[0x1B7] = (*(u8 **)(p + 0x18))[0x1B7];
    p[0x1B8] = (*(u8 **)(p + 0x18))[0x1B8];
    *(s8 *)(p + 0x30) = *(s8 *)(*(u8 **)(p + 0x18) + 0x30);
    *(V3 *)(p + 0x50) = *(V3 *)(*(u8 **)(p + 0x18) + 0x50);
    *(s8 *)(p + 0x24) = *(s8 *)(*(u8 **)(p + 0x18) + 0x24);
    p[0x14E] = 0x20;
    p[0x14F] = 0x20;
    *(u32 *)(p + 0x5C) = 0;
    *(u32 *)(p + 0x60) = 0;
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x6C) = 0;
    D_004C29F0[2] = D_004C29F4[5];
    p[0x13C] = 1;
    *(f32 *)(p + 0x34) = *(f32 *)(*(u8 **)(p + 0x18) + 0x34);
    *(f32 *)(p + 0x38) = *(f32 *)(*(u8 **)(p + 0x18) + 0x38);
    *(f32 *)(p + 0x3C) = *(f32 *)(*(u8 **)(p + 0x18) + 0x3C);
    bt = D_004725C0;
    ft = D_00472570;
    i = D_004C29F0[3];
    ft += i;
    *(f32 *)(p + 0x38) += ft[1];
    bt += i;
    if (*(s16 *)(p + 0x140) == 0) {
        ((N3c *)p)->f34 += ft[0];
        p[0x22] = bt[0];
    } else {
        ((N3c *)p)->f34 -= ft[0];
        p[0x22] = bt[1];
    }
    func_001757E0(p, 0x14, 6);
    func_00399570(p);
}
