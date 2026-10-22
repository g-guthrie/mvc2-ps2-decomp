typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x7C]; s16 f7c[1]; } GD;
extern GD *D_004C2794;

void func_002BBDA0(u8 *p) {
    extern void func_00175700();
    extern void func_001757E0(u8 *, s32, s32);
    f32 z;
    f32 *q5c, *q68;
    p[0x40C] = 2;
    p[0x33C] = 5;
    func_00175700(p);
    if (p[0x15B] != 0) {
        p[0x1B5] = 0x41;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(s32 *)(p + 0x1D8) = 0;
        D_004C2794->f7c[p[2]]++;
    }
    q5c = (f32 *)(p + 0x5C);
    q68 = (f32 *)(p + 0x68);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if ((p[0x1E6] == 0 && *(f32 *)(p + 0x5C) > 0.0f) || (p[0x1E6] != 0 && *(f32 *)(p + 0x5C) < 0.0f)) {
        *(s32 *)q5c = 0;
        *(s32 *)q68 = 0;
    }
    z = 0.0f;
    if (*(f32 *)(p + 0x60) <= z) {
        p[6]++;
        *q5c = z;
        *q68 = z;
        p[0x40D] = 0;
        p[0x40C] = 0;
        p[0x33B] = 0;
        p[0x33C] = 0;
        func_001757E0(p, 0x15, 0x11);
    }
}
