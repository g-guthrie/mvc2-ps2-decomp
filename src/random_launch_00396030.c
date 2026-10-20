typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern int func_00174170(void);
extern void func_001E3210(u8 *, s32);
extern int func_001757E0(u8 *, s32, s32);
typedef struct { u8 pad[0x7C]; s16 f7c[8]; } G;
extern G *D_004C2794;

void func_00396030(u8 *p, u8 *q)
{
    s32 n;
    f32 d;
    s32 r;
    f32 k;

    *(s8 *)(p + 0x31) = -1;
    p[0x13C] = 1;
    *(f32 *)(p + 0x5C) = 0.0f;
    d = 153.333328f;
    *(f32 *)(p + 0x60) = 0.0f;
    *(f32 *)(p + 0x68) = 0.0f;
    *(f32 *)(p + 0x6C) = 0.0f;
    *(f32 *)(p + 0x5C) = -13.333333f;
    *(f32 *)(p + 0x60) = 13.333333f;
    n = func_00174170() & 0x3F;
    if (*(s16 *)(p + 0x140)) {
        n = -n;
        *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
        d = -d;
    }
    k = 1.66666663f;
    *(f32 *)(p + 0x34) = (*(f32 *)(q + 0x34) - d) + k * (f32)n;
    r = func_00174170() & 0x3F;
    *(f32 *)(p + 0x38) = *(f32 *)(q + 0x38) + 2.14285707f * (f32)(0x84 - r);
    p[0x1B0] = 2;
    p[0x1B1] = 0;
    {
        if (p[0x21] == 1) {
            p[0x1B5] = 0x67;
            p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
            *(u32 *)(p + 0x1D8) = 0;
            D_004C2794->f7c[p[2]]++;
        } else {
            p[0x1B5] = 0x51;
            p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
            *(u32 *)(p + 0x1D8) = 0;
            D_004C2794->f7c[p[2]]++;
        }
    }
    func_001E3210(p, 0x1E);
    func_001757E0(p, 0x17, 0xB);
}
