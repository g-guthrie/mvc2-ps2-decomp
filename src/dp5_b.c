/* MWCC 3.0.3 or 3.0: ./try.sh src/x.c "-O3 -Op -fp off -sdatathreshold 0" -> 2/102 words: pointer q+0x2B8 in a1, retail a2 */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;


void residual_00155AD0(u8 *o) {
    extern void func_00170E00(s32, f32, f32, f32, f32);
    u8 *q;
    u8 *t;
    u8 v;
    f32 d;
    q = *(u8 **)(o + 0x18);
    t = q + 0x2B8;
    v = t[o[0x21]];
    o[0x13C] = v;
    if (v == 0) return;
    *(f32 *)(o + 0x74) = *(f32 *)(t + 4);
    *(V3 *)(o + 0x34) = *(V3 *)(q + 0x34);
    d = 40.0f * *(f32 *)(q + 0x50);
    if (*(s16 *)(q + 0x140) == 0) d = -d;
    *(f32 *)(o + 0x34) += d;
    *(f32 *)(o + 0x38) += 205.7142791748047f * *(f32 *)(q + 0x54);
    if (*(s8 *)(q + 0x1B4) == 0) {
        *(s16 *)(o + 0x1C) += 1;
        *(s32 *)(o + 0x44) = (u32)(s32)(0.5 + 65536.0 * (double)((*(s16 *)(o + 0x1C) + *(s16 *)(o + 0x1E)) * 2) / 360.0) & 0xFFFF;
        *(s32 *)(o + 0x48) = (u32)(s32)(0.5 + 65536.0 * (double)((*(s16 *)(o + 0x1C) + *(s16 *)(o + 0x1E)) * 3) / 360.0) & 0xFFFF;
    }
    func_00170E00(*(s32 *)(o + 0x84), *(f32 *)(q + 0x74), *(f32 *)(q + 0x78), *(f32 *)(q + 0x80), *(f32 *)(q + 0x80));
}
