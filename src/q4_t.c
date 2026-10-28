typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad0[0x7C]; s16 f7c[2]; } G4t;
extern G4t *D_004C2794;
typedef struct { u8 b0; u8 pad1; s16 a; s16 b; s16 c; s16 d; } T4t;
extern T4t D_00463090[];

void func_00359710(u8 *p, s32 a1, u8 idx)
{
    s16 a, b, c, d;
    p[0x1B5] = D_00463090[idx].b0;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    D_004C2794->f7c[p[2]]++;
    a = D_00463090[idx].a;
    b = D_00463090[idx].b;
    c = D_00463090[idx].c;
    d = D_00463090[idx].d;
    if (*(s16 *)(p + 0x140) == 0) {
        a = -a;
        c = -c;
    }
    *(f32 *)(p + 0x34) += 1.6666666269302368f * (f32)a;
    *(f32 *)(p + 0x38) += 2.142857074737549f * (f32)b;
    *(f32 *)(p + 0x5C) = 1.6666666269302368f * (f32)c;
    *(f32 *)(p + 0x60) = 2.142857074737549f * (f32)d;
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x6C) = 0;
}
