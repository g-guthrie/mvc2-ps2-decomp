typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x7C]; s16 f7c[8]; } G95;

extern G95 *D_004C2794;
extern f32 D_00472390[];
extern f32 D_004723B0[];
extern f32 D_004723D0[];
extern u16 D_004C1E28[4];
extern u8 D_004C1E30[8];

typedef struct { u8 pad[0x34]; f32 x; f32 y; u8 pad2[0x20]; f32 f5c; f32 f60; f32 f64; f32 f68; f32 f6c; } F9;
void func_00395B30(u8 *p, u8 *q) {
    extern void func_001757E0(u8 *, s32, s32);
    u8 k;
    f32 *tbl;
    f32 v;
    s32 i;
    *(u8 *)(p + 0x13C) = 1;
    ((F9 *)p)->x = *(f32 *)(q + 0x34);
    *(f32 *)(p + 0x38) = *(f32 *)(q + 0x38);
    *(s8 *)(p + 0x31) = -1;
    p[0x1B0] = 2;
    p[0x1B1] = 0;
    switch (p[0x20]) {
    case 0:
        tbl = (f32 *)((u8 *)D_00472390 + p[0x1B7] * 16);
        k = 0;
        p[0x1B5] = p[0x1B7] * 2 + 0x44;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(s32 *)(p + 0x1D8) = 0;
        D_004C2794->f7c[p[2]]++;
        break;
    case 1:
        tbl = (f32 *)((u8 *)D_004723B0 + p[0x1B7] * 16);
        k = 1;
        p[0x1B5] = p[0x1B7] * 2 + 0x4E;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(s32 *)(p + 0x1D8) = 0;
        D_004C2794->f7c[p[2]]++;
        break;
    case 6:
        tbl = (f32 *)((u8 *)D_004723D0 + p[0x1B7] * 16);
        if (*(s16 *)(p + 0x140) == 0) {
            *(f32 *)(p + 0x34) -= 130.0f;
        } else {
            *(f32 *)(p + 0x34) += 130.0f;
        }
        *(f32 *)(p + 0x38) += 117.85713958740234f;
        k = 2;
        p[0x1B5] = *(s8 *)(p + 0x1B7) + 0x6D;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(s32 *)(p + 0x1D8) = 0;
        D_004C2794->f7c[p[2]]++;
        break;
    case 7:
        tbl = (f32 *)((u8 *)D_004723D0 + (p[0x1B7] * 4 + 8) * 4);
        if (*(s16 *)(p + 0x140) == 0) {
            *(f32 *)(p + 0x34) -= 115.0f;
        } else {
            *(f32 *)(p + 0x34) += 115.0f;
        }
        *(f32 *)(p + 0x38) += 83.57142639160156f;
        k = 3;
        p[0x1B5] = *(s8 *)(p + 0x1B7) + 0x6F;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(s32 *)(p + 0x1D8) = 0;
        D_004C2794->f7c[p[2]]++;
        break;
    }
    ((F9 *)p)->f5c = tbl[0];
    ((F9 *)p)->f68 = tbl[1];
    ((F9 *)p)->f60 = tbl[2];
    ((F9 *)p)->f6c = tbl[3];
    if (*(s16 *)(p + 0x140) != 0) {
        *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x68) = -*(f32 *)(p + 0x68);
    }
    i = k;
    *(u16 *)(p + 0x1C) = D_004C1E28[(i & 2) + p[0x1B7]];
    func_001757E0(p, 0x17, D_004C1E30[i]);
}
