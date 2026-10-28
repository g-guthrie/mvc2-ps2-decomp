typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x29]; s8 b29; } G91c;
typedef struct { u8 b0, b1, b2, b3; f32 f4, f8, fC, f10; s32 w14; u8 b18, b19, b1A, b1B; } E91c;

extern E91c D_00441E30[];
extern u8 *D_004CACB0[];
extern G91c *D_004C2840;
extern s32 D_004C2814;
extern s32 D_004C2644;
extern s16 D_00442530[];

u8 *func_00142610(s32 a)
{
    extern void func_001415B0(u8 *);
    E91c *e;
    u8 *o;
    f32 f;
    e = &D_00441E30[a];
    o = D_004CACB0[e->b18];
    if (o == 0) {
        return 0;
    }
    o[0] = 1;
    o[0x13C] = 1;
    *(s32 *)(o + 0x10) = e->w14;
    o[0x23] = e->b2;
    if (D_004C2840->b29 != 0) {
        if (o[0x23] == 0x14) {
            o[0x23] = 0x2C;
        }
        if (o[0x23] == 0x16) {
            o[0x23] = 0x29;
        }
        if (o[0x23] == 0x19) {
            o[0x23] = 0x2A;
        }
    }
    *(s16 *)(o + 0xCC) = o[0x23];
    *(s32 *)(o + 0x84) = D_004C2814;
    o[0x20] = e->b3;
    *(s32 *)(o + 0x74) = 0;
    *(s32 *)(o + 0xD0) = 0;
    o[0x31] = e->b18;
    o[0x24] = e->b19;
    if (a == 0x14 || a == 0x15) {
        *(s32 *)(o + 0xD0) = 0x200000;
    }
    if (o[0x23] == 0x30) {
        *(s32 *)(o + 0xD0) = 0x20000;
        *(u32 *)(o + 0xE4) = 0xBA83126F;
    }
    *(f32 *)(o + 0x34) = 10.0f * e->f8;
    *(f32 *)(o + 0x38) = 10.0f * e->fC;
    *(f32 *)(o + 0x3C) = 10.0f * e->f10;
    *(s32 *)(o + 0x48) = 0;
    *(s32 *)(o + 0x44) = 0;
    *(s32 *)(o + 0x40) = 0;
    *(f32 *)(o + 0x58) = 1.0f;
    *(f32 *)(o + 0x54) = 1.0f;
    *(f32 *)(o + 0x50) = 1.0f;
    f = e->f4;
    *(f32 *)(o + 0x80) = f;
    *(f32 *)(o + 0x7C) = f;
    *(f32 *)(o + 0x78) = f;
    *(f32 *)(o + 0x74) = f;
    if (1.0f == f) {
        o[0x25] = 0;
    } else {
        o[0x25] = 1;
    }
    if (o[0x23] == 0x1F || o[0x23] == 0x20) {
        o[0x25] = 0;
    }
    if (o[0x23] == 0x2B) {
        if (*(s8 *)(o + 0x31) == 0x22 || *(s8 *)(o + 0x31) == 0x21) {
            *(u32 *)(o + 0x54) = 0x3F6147AE;
            *(u32 *)(o + 0x50) = 0x3F6147AE;
        }
        o[0x25] = 2;
    }
    if (o[0x23] == 0x1D || o[0x23] == 0x1E) {
        *(s32 *)(o + 0x48) = (u32)(s32)(0.5 + 65536.0 * (double)(D_00442530[D_004C2644]) / 360.0) & 0xFFFF;
        D_004C2644 += 1;
    }
    *(s32 *)(o + 0xDC) = 0;
    *(s32 *)(o + 0xD8) = 0;
    *(s32 *)(o + 0xD4) = 0;
    *(s32 *)(o + 0x64) = 0;
    *(s32 *)(o + 0x60) = 0;
    *(s32 *)(o + 0x5C) = 0;
    *(s32 *)(o + 0x70) = 0;
    *(s32 *)(o + 0x6C) = 0;
    *(s32 *)(o + 0x68) = 0;
    func_001415B0(o);
    *(s16 *)(o + 0x1E) = 0xF0;
    return o;
}
