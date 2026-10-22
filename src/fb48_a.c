typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x7C]; s16 f7c[1]; } G48a;
extern G48a *D_004C2794;

void func_0023DAB0(u8 *p) {
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_00176160(u8 *, s32, s32, s32);
    extern void func_0035C7B0(u8 *, u8, u8);
    u8 *q;
    s32 v;
    u32 t;
    u32 h;
    f32 f1;
    f32 c;
    f32 d;
    s32 i;
    q = *(u8 **)(p + 0x220);
    p[0x40C] = 2;
    p[0x33C] = 5;
    v = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = v;
    if ((s16)v != 0) return;
    {
        t = p[6];
        p[6] = t + 1;
        h = *(u16 *)(p + 0x35E);
        if (h & 0x800) {
            p[0x20] = 0;
        } else if (h & 0x400) {
            p[0x20] = 1;
        } else if (h & 0x1000) {
            p[0x20] = 2;
        } else {
            f1 = *(f32 *)(p + 0x34);
            c = 53.33333206176758f;
            d = *(f32 *)(q + 0x34);
            if (d < c + f1 && d > f1 - c) {
                p[0x20] = 2;
            } else if (d < f1) {
                if (p[0x1E6] == 0) p[0x20] = 0; else p[0x20] = 1;
            } else {
                if (p[0x1E6] == 0) p[0x20] = 1; else p[0x20] = 0;
            }
        }
        p[0x1B5] = *(s8 *)(p + 0x20) + 0x3F;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(s32 *)(p + 0x1D8) = 0;
        D_004C2794->f7c[p[2]]++;
        p[0x169] = 0x16;
        p[0x168] = *(s8 *)(p + 0x20) + 1;
        func_001757E0(p, p[0x169], p[0x168]);
        switch (p[0x20]) {
        case 0:
            *(u32 *)(p + 0x5C) = 0xC0D55555;
            break;
        case 1:
            *(u32 *)(p + 0x5C) = 0x40D55555;
            break;
        default:
            *(u32 *)(p + 0x5C) = 0;
            break;
        }
        if (p[0x1E6] != 0) {
            *(f32 *)(p + 0x5C) *= -1.0f;
        }
        *(u32 *)(p + 0x60) = 0xC1892492;
        *(u32 *)(p + 0x6C) = 0xBF4DB6DB;
        func_00176160(p, 2, 1, 1);
        func_0035C7B0(p, 0, 0);
        i = 0;
        do {
            func_0035C7B0(p, 2, i);
            i++;
        } while (i <= 0);
    }
}
