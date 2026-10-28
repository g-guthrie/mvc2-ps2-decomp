/* MW 3.0.3 (./try.sh) -O3 -sdatathreshold 8. func_00185980 takes one argument (retail 0x00185980 reads only $a0). */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x7C]; s16 f7c[16]; } G_d;
extern G_d *D_004C2794;

void func_0037D420(u8 *p, u8 *q) {
    extern void func_001BAE10(u8 *, u8 *, s32);
    extern s32 func_00185980(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    extern s32 func_00174470(u8 *);
    extern void func_001E7F60(u8 *);
    f32 *d;
    u8 *c;
    u32 t;
    s16 h;
    if (q[5] == 3) {
        func_001BAE10(p, q, 3);
        p[4] = 2;
        return;
    }
    if (q[0x425] != 0) {
        p[4] = 2;
        func_001BAE10(p, q, 3);
        return;
    }
    if (*(s8 *)(p + 0x1B2) != 0) {
        if (*(u8 *)(*(u8 **)(p + 0x1C4) + 3) != 0) {
            p[0x1B5] = 0x40;
            p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
            *(u32 *)(p + 0x1D8) = 0;
            D_004C2794->f7c[p[2]] += 1;
        } else {
            *(u32 *)(q + 0x2E0) = 0;
            if ((*(s8 *)(p + 0x1B2) & 0x11) == 0 && func_00185980(p) != 0) {
            } else {
                func_001BAE10(p, q, 3);
                p[4] = 2;
                return;
            }
            t = p[5];
            p[5] = t + 1;
            *(u32 *)(p + 0x5C) = 0;
            *(u32 *)(p + 0x60) = 0;
            *(u32 *)(p + 0x68) = 0;
            *(u32 *)(p + 0x6C) = 0;
            *(u32 *)(q + 0x2E8) = 1;
            func_001757E0(p, 0x17, 0xC);
            c = *(u8 **)(p + 0x1C4);
            c[0x20D] = 0;
            *(f32 *)(c + 0x38) = *(f32 *)(q + 0x430);
            *(u32 *)(p + 0xD0) = 0x42D55555;
            d = (f32 *)(p + 0xD0);
            if (*(s16 *)(p + 0x140) != 0) {
                *d = -*d;
            }
            *(f32 *)(c + 0x34) = *(f32 *)(p + 0x34) - *(f32 *)(p + 0xD0);
            *(u32 *)(p + 0xD4) = *(u32 *)(p + 0x1C4);
            d = (f32 *)(p + 0xD0);
            if ((*(s8 *)(p + 0x1B2) & 0x11) != 0) {
                *(u32 *)d = 0;
            }
            p[0x22] = 0;
            return;
        }
    }
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (func_00174470(p) == 0) {
        *(u32 *)(q + 0x2E0) = 0;
        func_001BAE10(p, q, 3);
        p[4] = 2;
        return;
    }
    h = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = h;
    if (h < 0) {
        *(u32 *)(q + 0x2E0) = 0;
        p[5] = 2;
        *(u32 *)(p + 0x68) = 0x3F200000;
        if (*(s16 *)(p + 0x140) != 0) {
            *(f32 *)(p + 0x68) = -*(f32 *)(p + 0x68);
        }
        func_001757E0(p, 2, 2);
    } else {
        func_001E7F60(p);
    }
}
