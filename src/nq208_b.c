typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;
typedef struct { s32 w[0x31]; } B31;
typedef struct { u8 pad[0x7C]; s16 f7c[1]; } G3c;
extern G3c *D_004C2794;

void func_0037DD00(u8 *p, u8 *q)
{
    extern void func_0037D9F0(u8 *, u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    extern f32 func_00417500(s32);
    extern f32 func_00417440(s32);
    extern void func_0037DFD0(u8 *, u8 *);
    u32 t;
    u8 *s;
    f32 x;

    t = p[4]; p[4] = t + 1;
    *(B31 *)(p + 0xEC) = *(B31 *)(q + 0xEC);
    p[0x13C] = 1;
    s = p + 2;
    p[2] = q[2];
    p[1] = q[1];
    *(f32 *)(p + 0x50) = *(f32 *)(q + 0x50);
    *(f32 *)(p + 0x54) = *(f32 *)(q + 0x54);
    p[0x1B7] = q[0x1B7];
    p[0x1B8] = q[0x1B8];
    *(s8 *)(p + 0x30) = *(s8 *)(q + 0x30);
    *(V3 *)(p + 0x50) = *(V3 *)(q + 0x50);
    *(s8 *)(p + 0x24) = *(s8 *)(q + 0x24);
    p[0x13C] = 0;
    func_0037D9F0(p, q);
    func_001757E0(p, 0x17, 0x14);
    *(s8 *)(p + 0x24) = *(s8 *)(q + 0x24);
    *(s8 *)(p + 0x31) = -1;
    p[0x1B0] = 0x42;
    p[0x1B1] = 0x42;
    switch (p[0x23]) {
    case 3:
        p[0x1B5] = 0x3F;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(s32 *)(p + 0x1D8) = 0;
        D_004C2794->f7c[*s]++;
        break;
    case 4:
        p[0x1B5] = 0x42;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(s32 *)(p + 0x1D8) = 0;
        D_004C2794->f7c[*s]++;
        break;
    case 5:
        p[0x1B5] = 0x43;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(s32 *)(p + 0x1D8) = 0;
        D_004C2794->f7c[*s]++;
        break;
    default:
        p[0x1B5] = p[0x23] + 0x46;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(s32 *)(p + 0x1D8) = 0;
        D_004C2794->f7c[*s]++;
        break;
    }
    p[0x1B3] = 0;
    p[5] = 0;
    if (p[0x23] == 1) {
        if (*(s16 *)(p + 0x140) != 0) {
            x = func_00417500(0x1B06);
            x = 23.33333396911621f * x;
        } else {
            x = func_00417500(0x1B06);
            x = -23.33333396911621f * x;
        }
        *(f32 *)(p + 0x5C) = x;
        x = func_00417440(0x1B06);
        *(f32 *)(p + 0x60) = 23.33333396911621f * x;
    } else {
        if (*(s16 *)(p + 0x140) != 0) {
            x = 23.33333396911621f;
        } else {
            x = -23.33333396911621f;
        }
        *(f32 *)(p + 0x5C) = x;
    }
    *(s16 *)(p + 0x1C) = 0x1E;
    func_0037DFD0(p, q);
}
