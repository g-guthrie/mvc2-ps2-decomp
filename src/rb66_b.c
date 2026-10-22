typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s16 D_00633720[];
extern u8 *D_006337A0[];
extern s32 D_004C27FC;

void func_0041D9A0(void) {
    extern u8 *func_003DA750(s32, s32, s32);
    extern void func_0041CD30();
    s32 j16;
    s32 i2;
    s32 i8;
    s32 i;
    s32 j;
    f32 x, y;
    u8 *o;
    s32 k;
    s32 v, w;
    i = 0; i2 = 0; i8 = 0;
    y = 3.25f;
    do {
        x = -6.0f;
        j = 0; j16 = 0;
        do {
            v = *(s16 *)((u8 *)D_00633720 + i2 + j16);
            if (v != -1) {
                if ((o = func_003DA750(0, 0xD, 1)) == 0) {
                    return;
                }
                k = (v & 0xC0) ? 0xC7 : 0;
                if ((v & 0x3F) >= 0x18) {
                    v -= 3;
                }
                w = v & 0x3F;
                D_006337A0[w] = o;
                o[0x20] = (u8)(j + i8);
                o[0x23] = v;
                o[0x13C] = 1;
                *(s32 *)(o + 0x10) = (s32)func_0041CD30;
                if (k == 0) {
                    k = w + 0x3A;
                }
                *(s16 *)(o + 0xCC) = k;
                *(s32 *)(o + 0x84) = D_004C27FC;
                *(s32 *)(o + 0xD0) = 0x411;
                *(f32 *)(o + 0x34) = x;
                *(f32 *)(o + 0x38) = y;
                *(f32 *)(o + 0x3C) = -12.88f;
                if ((v & 0x100) == 0) {
                    *(f32 *)(o + 0x80) = 0.8f;
                    *(f32 *)(o + 0x7C) = 0.8f;
                    *(f32 *)(o + 0x78) = 0.8f;
                } else {
                    *(f32 *)(o + 0x80) = 0.4f;
                    *(f32 *)(o + 0x7C) = 0.4f;
                    *(f32 *)(o + 0x78) = 0.4f;
                }
                *(f32 *)(o + 0x54) = 1.0f;
                *(f32 *)(o + 0x50) = 1.0f;
                if (k == 0xC7 && (v & 0x80) != 0) {
                    o[0x13C] = 0;
                }
                if (k != 0xC7) {
                    *(s32 *)(D_006337A0[w] + 0xD8) = 0;
                }
            }
            j++; j16 += 16;
            x += 1.5f;
        } while (j < 8);
        y -= 1.5f;
        i++; i2 += 2; i8 += 8;
    } while (i < 8);
}
