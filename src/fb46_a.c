typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;

extern s32 fptosi(f32);

void func_0015F8E0(u8 *p) {
    extern void func_003DAA40(u8 *);
    u8 *o;
    s16 v;
    *(V3 *)(p + 0x34) = *(V3 *)(*(u8 **)(p + 0x14) + 0x34);
    o = *(u8 **)(p + 0x14);
    v = fptosi(13.333333015441895f * *(f32 *)(o + 0x50));
    if (*(s16 *)(o + 0x140) == 0) v = -v;
    *(f32 *)(p + 0x34) = *(f32 *)(o + 0x34) + (f32)v;
    *(f32 *)(p + 0x38) += 222.8571319580078f * *(f32 *)(*(u8 **)(p + 0x14) + 0x54);
    if (*(s8 *)(*(u8 **)(p + 0x14) + 0x1B4) == 0) {
        *(s16 *)(p + 0x1C) = *(s16 *)(p + 0x1C) + 1;
        *(u32 *)(p + 0x44) = (u32)(s32)(0.5 + 65536.0 * (double)((*(s16 *)(p + 0x1C) + *(s16 *)(p + 0x1E)) * 2) / 360.0) & 0xFFFF;
        *(u32 *)(p + 0x48) = (u32)(s32)(0.5 + 65536.0 * (double)((*(s16 *)(p + 0x1C) + *(s16 *)(p + 0x1E)) * 3) / 360.0) & 0xFFFF;
    }
    if (*(u8 *)(*(u8 **)(p + 0x14) + 4) != 0) func_003DAA40(p);
    if (*(u8 *)(*(u8 **)(p + 0x14) + 1) != 0x18) func_003DAA40(p);
}
