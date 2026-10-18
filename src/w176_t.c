typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x7C]; s16 h7c[1]; } G2794;
extern G2794 *D_004C2794;

void func_002B56E0(u8 *p) {
    extern s32 func_00175700(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_00183d50(u8 *);
    extern void func_00184540(u8 *);
    u32 t;
    s8 r;
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (*(f32 *)(p + 0x430) > *(f32 *)(p + 0x38)) {
        t = p[6];
        p[6] = t + 1;
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        p[0x20D] = 1;
        if (p[0x1B7] == 0) {
            func_001757E0(p, 0x15, 0x28);
        } else {
            func_001757E0(p, 0x15, 0x2A);
        }
        func_00183d50(p);
        return;
    }
    r = func_00175700(p);
    if (r < 0) {
        func_00184540(p);
    } else if (p[0x15B] != 0) {
        p[0x1B5] = p[0x15B];
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(u32 *)(p + 0x1D8) = 0;
        D_004C2794->h7c[p[2]]++;
        p[0x15B] = 0;
    }
}
