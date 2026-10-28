typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;
typedef struct { s32 w[0x31]; } B147a;
typedef struct { u8 pad[0x7C]; s16 f7c[1]; } G147a;
typedef struct { u8 pad[0x5C]; u32 f5c; } P147a;
extern G147a *D_004C2794;
extern f32 D_004F1FCC[];
extern f32 D_004F1FC8[];

void func_003C5BF0(u8 *o, u8 *q) {
    extern void func_0015E630(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    u32 t;
    P147a *sa;
    sa = (P147a *)o;
    t = o[4];
    o[4] = t + 1;
    *(B147a *)(o + 0xEC) = *(B147a *)(q + 0xEC);
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
    o[0x1B1] = 0x44;
    o[0x1B0] = 0x44;
    o[0x14C] = 0x80;
    o[0x14D] = 0;
    o[0x14F] = 0x40;
    o[0x14E] = 0x40;
    *(s8 *)(o + 0x31) = -8;
    o[0x1B5] = 0x43;
    o[0x1B2] = *(u16 *)(o + 0x1C0) = 0;
    *(s32 *)(o + 0x1D8) = 0;
    { s32 x = o[2]; s16 y = D_004C2794->f7c[x]; D_004C2794->f7c[x] = y + 1; }
    *(u32 *)(o + 0x5C) = 0;
    *(u32 *)(o + 0x60) = 0;
    *(u32 *)(o + 0x68) = 0;
    *(u32 *)(o + 0x6C) = 0;
    *(f32 *)(o + 0x38) = 274.28570556640625f + *(f32 *)(q + 0x430);
    if (*(s16 *)(q + 0x140) != 0) {
        *(f32 *)(o + 0x34) = D_004F1FC8[0] - 106.66666412353516f;
        sa->f5c = 0x41855555;
    } else {
        *(f32 *)(o + 0x34) = 106.66666412353516f + D_004F1FCC[0];
        sa->f5c = 0xC1855555;
    }
    *(u32 *)(o + 0x60) = 0xC1700000;
    *(u32 *)(o + 0x6C) = 0x3F092492;
    *(s16 *)(o + 0x1C) = 2;
    func_001757E0(o, 0x15, 0x16);
    func_0015E630(o);
    o[0] = 1;
}
