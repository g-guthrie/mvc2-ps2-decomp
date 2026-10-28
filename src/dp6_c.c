/* try.sh -O3 -Op -sdatathreshold 8: 7/100 words differ, only $a0 vs $a2 for func_0015A950 ptr and 0x3F800000 temp. static func_0015A950 verified exact. */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;

extern s32 D_004C2838;
extern void func_0015A950(u8 *);

void func_0015AA90(u8 *a, V3 *pos, f32 x, s32 n, s32 i, u16 flags)
{
    extern u8 *func_003DA750();
    u8 *o;
    u32 fl = flags;

    if (!(fl & 0x20)) return;
    if (n > 1 && i != n - 1) return;
    if (fl & 0x200) {
        if ((o = func_003DA750(0, 0x26, 1)) == 0) return;
    } else {
        if ((o = func_003DA750(0, 0x27, 1)) == 0) return;
    }
    o[0x13C] = 0;
    *(void (**)(u8 *))(o + 0x10) = func_0015A950;
    *(u32 *)(o + 0xD0) = 0x800411;
    *(s16 *)(o + 0x1C) = 0xE;
    *(s16 *)(o + 0x1E) = 0x12;
    *(u32 *)(o + 0x78) = 0x3F800000;
    *(u32 *)(o + 0x7C) = 0x3F800000;
    *(u32 *)(o + 0x80) = 0x3F800000;
    *(s16 *)(o + 0xCC) = 0xB7;
    *(s32 *)(o + 0x84) = D_004C2838;
    *(f32 *)(o + 0x50) = x;
    *(f32 *)(o + 0x54) = x;
    *(f32 *)(o + 0x58) = x;
    o[0x23] = i;
    if (fl & 2) {
        *(f32 *)(o + 0x34) = *(f32 *)(a + 0x34);
        *(f32 *)(o + 0x38) = *(f32 *)(a + 0x38) + 2.142857074737549f * (f32)(a[0x14C] / 8) * *(f32 *)(a + 0x54);
    } else {
        *(V3 *)(o + 0x34) = *pos;
    }
    *(s32 *)(o + 0xD4) = i << 3;
    *(s32 *)(o + 0xD8) = (s32)x;
}
