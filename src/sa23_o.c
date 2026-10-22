typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x7C]; s16 h7c[8]; } G;
extern G *D_004C2794;

void func_003CBAB0(u8 *p, u8 *q) {
    extern void func_003CAB20(u8 *, u8 *, s32);
    extern void func_003CAB00(u8 *, u8 *);
    extern s32 func_00174780(u8 *);
    extern s32 func_00174470(u8 *);
    extern void func_001E3210(u8 *, s32);
    extern s8 func_00175700(u8 *);
    extern void func_001E7F60(u8 *);
    s16 h;
    s32 v;
    if (q[5] != 0) {
        func_003CAB20(p, q, 5);
        return;
    }
    if (func_00174780(p) == 0 || func_00174470(p) == 0) {
        func_003CAB00(p, q);
        return;
    }
    *(s32 *)(q + 0x2B8) = 4;
    if ((*(s8 *)(p + 0x1B2) & 0x11) != 0) {
        func_003CAB20(p, q, 0xD);
        return;
    }
    if (*(s8 *)(p + 0x1B3) != 0) {
        func_001E3210(p, 0x34);
        func_003CAB20(p, q, 9);
        return;
    }
    h = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = h;
    if (h == 0) func_001E3210(p, p[0x15B]);
    v = *(s8 *)(p + 0x1B4);
    if (v != 0) {
        p[0x1B4] = v - 1;
    } else {
        *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
        *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
        *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
        func_00175700(p);
        if (*(s8 *)(p + 0x1B2) != 0) {
            h = *(s16 *)(p + 0x1E) - 1;
            *(s16 *)(p + 0x1E) = h;
            if (h > 0) {
                p[0x1B5] = 0x50;
                p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
                *(s32 *)(p + 0x1D8) = 0;
                D_004C2794->h7c[p[2]]++;
            }
        }
    }
    func_001E7F60(p);
}
