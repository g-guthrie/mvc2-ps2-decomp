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

void func_00191480(u8 *a, u8 *b, s32 d)
{
    s16 v;
    a[0x289] = 0xFF;
    v = *(s16 *)(a + 0x280);
    *(s16 *)(a + 0x282) = v;
    if (v == 0) {
        *(s16 *)(a + 0x27C) = *(s16 *)(a + 0x290) = *(s16 *)(a + 0x434);
        *(s16 *)(a + 0x342) = 0;
    }
    v = *(s16 *)(b + 0x274) + d;
    *(s16 *)(b + 0x274) = v;
    if (v > 0x3E7) {
        *(s16 *)((s32)b + 0x274) = 0x3E7;
    }
    v = *(s16 *)(a + 0x280) + d;
    *(s16 *)(a + 0x280) = v;
    if (v > 0x3E7) {
        *(s16 *)((s32)a + 0x280) = 0x3E7;
    }
    v = *(s16 *)(a + 0x284) + d;
    *(s16 *)(a + 0x284) = v;
    if (v > 0x3E7) {
        *(s16 *)((s32)a + 0x284) = 0x3E7;
    }
    v = D_004D18EE[b[2]];
    v += d;
    D_004D18EE[b[2]] = v;
    if (v > 0x3E7) {
        D_004D18EE[b[2]] = 0x3E7;
    }
    v = D_004D18F2[b[2]];
    v += d;
    D_004D18F2[b[2]] = v;
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
}
