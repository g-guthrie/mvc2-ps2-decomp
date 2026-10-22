typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x7C]; s16 f7c[1]; } G7a;
extern G7a *D_004C2794;

void func_003911A0(u8 *p, u8 *q) {
    extern s32 func_00174170(void);
    s16 t = *(s16 *)(p + 0x1E);
    if (t == 0) {
        f32 a, b, c, d, e;
        u32 n = p[5];
        s32 m;
        p[5] = n + 1;
        p[0x13C] = 1;
        *(f32 *)(p + 0x34) = *(f32 *)(q + 0x34);
        *(f32 *)(p + 0x38) = 51.42856979f + *(f32 *)(q + 0x38);
        *(s32 *)(p + 0x68) = 0;
        m = func_00174170() & 7;
        *(f32 *)(p + 0x60) = 2.142857075f * (f32)((m + 4) << 16) / 65536.0f;
        *(u32 *)(p + 0x6C) = 0xBFCDB6DB;
        a = 5.0f;
        b = -93.33332825f;
        if (*(s16 *)(q + 0x140) != 0) {
            a = -a;
            b = -b;
        }
        if (*(s16 *)(q + 0x140) != 0) {
            c = 266.6666565f + *(f32 *)(q + 0x34) + a;
        } else {
            c = *(f32 *)(q + 0x34) - 266.6666565f + a;
        }
        *(f32 *)(p + 0x34) = *(f32 *)(q + 0x34) + b;
        *(f32 *)(p + 0x38) = 51.42856979f + *(f32 *)(q + 0x38);
        *(f32 *)(p + 0x5C) = (c - *(f32 *)(p + 0x34)) / 16.0f;
        p[0x1B0] = 0x42;
        p[0x1B1] = 0x42;
        p[0x1B5] = 0x40;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(s32 *)(p + 0x1D8) = 0;
        D_004C2794->f7c[p[2]]++;
    } else {
        *(s16 *)(p + 0x1E) = t - 1;
    }
}
