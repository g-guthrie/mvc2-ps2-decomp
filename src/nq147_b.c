typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;
typedef struct { s32 w[0x31]; } B147b;
typedef struct { u8 pad[0x7C]; s16 f7c[1]; } G147b;
extern G147b *D_004C2794;
extern f32 D_00476670[];
extern f32 D_00476660[];

void func_003CD130(u8 *o, u8 *q) {
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_003CD310(u8 *, u8 *);
    u32 t;
    f32 f;
    u8 *b;
    t = o[4];
    o[4] = t + 1;
    *(B147b *)(o + 0xEC) = *(B147b *)(q + 0xEC);
    b = o + 2;
    o[0x13C] = 1;
    o[2] = q[2];
    o[1] = q[1];
    *(f32 *)(o + 0x50) = *(f32 *)(q + 0x50);
    *(f32 *)(o + 0x54) = *(f32 *)(q + 0x54);
    o[0x1B7] = q[0x1B7];
    o[0x1B8] = q[0x1B8];
    *(s8 *)(o + 0x30) = *(s8 *)(q + 0x30);
    *(V3 *)(o + 0x50) = *(V3 *)(q + 0x50);
    *(s8 *)(o + 0x24) = *(s8 *)(q + 0x24);
    o[0x24] = 8;
    o[0x1B0] = 0x44;
    o[0x1B1] = 0x44;
    f = D_00476670[o[0x20]];
    if (*(s16 *)(o + 0x140) != 0) f = -f;
    *(f32 *)(o + 0x34) = *(f32 *)(q + 0x34) + f;
    *(f32 *)(o + 0x38) = *(f32 *)(q + 0x38);
    *(s16 *)(o + 0x1C) = 0x50;
    *(s16 *)(o + 0x1E) = 0x1E;
    if (o[0x20] > 1) {
        *(u32 *)(o + 0x54) = 0x3F000000;
        *(u32 *)(o + 0x50) = 0x3F000000;
    }
    f = D_00476660[o[0x20]];
    if (*(s16 *)(o + 0x140) != 0) f = -f;
    *(f32 *)(o + 0x5C) = f;
    *(u32 *)(o + 0x68) = 0;
    *(u32 *)(o + 0x60) = 0;
    *(u32 *)(o + 0x6C) = 0;
    o[0x22] = 0;
    o[0x14F] = 0x20;
    o[0x14E] = 0x20;
    o[0x14D] = 0x20;
    o[0x14C] = 0x20;
    o[0x1B5] = 0x7B;
    o[0x1B2] = *(u16 *)(o + 0x1C0) = 0;
    *(s32 *)(o + 0x1D8) = 0;
    { s32 x = *b; s16 y = D_004C2794->f7c[x]; D_004C2794->f7c[x] = y + 1; }
    func_001757E0(o, 0x17, 0x22);
    func_003CD310(o, q);
}

