typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef signed short s16;
typedef struct { u8 p0[0x18]; s16 h18; s16 h1A; u8 p1[0x10]; s16 h2C; u8 p2[0x12]; } E64;
extern E64 D_0061C7A0[];
extern s32 func_003E96A0(s32, void *, s32 *, s32, s32);

s32 func_003E95E0(s32 a, u32 idx, s32 *out, s32 d) {
    E64 *e = &D_0061C7A0[idx - 1];
    if (idx > 0x100) return 0;
    if (e->h2C == 0) return 0;
    if (func_003E96A0(a, e, out, d, 1) == 0) return 0;
    if (e->h18 == 16 && e->h1A == 16) {
        out[1] = 0x100;
        out[2] = 1;
    } else {
        out[1] = 16;
        out[2] = 1;
    }
    return 1;
}
