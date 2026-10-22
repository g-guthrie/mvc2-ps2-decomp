typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 b0; u8 pad1[0x4E - 1]; s16 f4e[8]; u8 pad5e[0x78 - 0x5E]; s16 f78[8]; } G;
extern G *D_004C2794;
extern s16 D_004D18EE[];
extern s16 D_004D18F2[];
extern u8 D_004F20B0[];
extern u8 D_004D18A2[];

void func_00190F30(u8 *a, u8 *c, u8 *d)
{
    extern void func_001917F0(u8 *, s32, s32);
    s16 v;
    u8 f;
    u8 t;
    u8 k;
    s16 w;
    u8 *b = D_004F20B0 + c[0x1B8] * 0x5B8;
    if (D_004D18A2[0] == 0) {
        D_004D18A2[0] = b[2] | 0x80;
        func_001917F0(b, 0, 0x1000000);
    }
    v = *(s16 *)(a + 0x280);
    *(s16 *)(a + 0x282) = v;
    if (v == 0) {
        *(s16 *)(a + 0x27C) = *(s16 *)(a + 0x290) = *(s16 *)(a + 0x434);
        *(s16 *)(a + 0x342) = 0;
    }
    if ((d[0x12] & 0x10) == 0) {
        v = *(s16 *)(b + 0x274) + 1;
        *(s16 *)(b + 0x274) = v;
        if (v > 0x3E7) {
            *(s16 *)((s32)b + 0x274) = 0x3E7;
        }
        v = *(s16 *)(a + 0x280) + 1;
        *(s16 *)(a + 0x280) = v;
        if (v > 0x3E7) {
            *(s16 *)((s32)a + 0x280) = 0x3E7;
        }
        v = *(s16 *)(a + 0x284) + 1;
        *(s16 *)(a + 0x284) = v;
        if (v > 0x3E7) {
            *(s16 *)((s32)a + 0x284) = 0x3E7;
        }
        v = D_004D18EE[b[2]];
        v += 1;
        D_004D18EE[b[2]] = v;
        if (v > 0x3E7) {
            D_004D18EE[b[2]] = 0x3E7;
        }
        w = (s16)d[0x18];
        if (w == 0) w = 1;
        v = (D_004D18F2[b[2]] += w);
        if (v > 0x3E7) {
            D_004D18F2[b[2]] = 0x3E7;
        }
        if (D_004C2794->b0 < 6) {
            if (*(s16 *)(b + 0x27E) < *(s16 *)(b + 0x274)) {
                *(s16 *)(b + 0x27E) = *(s16 *)(b + 0x274);
            }
            if (D_004C2794->f78[b[2]] < D_004C2794->f4e[b[2]]) {
                D_004C2794->f78[b[2]] = D_004C2794->f4e[b[2]];
            }
        }
        t = *(s8 *)(d + 2) & 0x30;
        if (t) {
            *(s16 *)(b + 0x27A) = *(s16 *)(b + 0x278);
            *(s16 *)(b + 0x278) |= (u8)t;
        }
        b[0x288] = b[0x287];
        f = 0;
        if (b[0x20D] == 2) {
            f |= 1;
            if (b[0x288] & 1) f |= 2;
            if (a[0x20D] == 2) f |= 4;
        }
        if ((d[2] & 0x70) == 0) f |= 8;
        b[0x287] = f;
        b[0x28A] |= f;
        k = b[0x28A] & 0xE;
        if (k == 0xE) {
            if (*(s16 *)(b + 0x274) >= 3) {
                *(s16 *)(b + 0x278) |= 1;
            }
        }
    }
}
