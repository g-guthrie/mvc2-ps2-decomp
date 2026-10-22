typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef double f64;

extern u8 D_004D18DB;
extern u16 D_004D18DC;
extern f32 D_00476240[];
extern u8 D_004762A0[];
extern s16 *D_004C2794 __attribute__((section(".sdata")));
extern s32 func_00174170();
extern void func_003DAA40(u8 *);
extern void func_001E3210(u8 *, s32);

void func_003C8DD0(u8 *o, u8 *t) {
    s16 h;
    f32 *tb;
    f32 x, y, vx, vy;
    if ((D_004D18DC & (1 << D_004D18DB)) == 0) {
        if (*(u8 *)(*(s32 *)(o + 0x18) + 0x425) == 0 && t[0x425] == 0) {
            h = *(s16 *)(o + 0x1C) - 1;
            *(s16 *)(o + 0x1C) = h;
            if (h < 0) {
                o[7]++;
                *(f32 *)(o + 0x34) = *(f32 *)(t + 0x34);
                *(f32 *)(o + 0x38) = *(f32 *)(t + 0x38);
                tb = D_00476240 + (o[0x20] * 8 + (func_00174170() & 3) * 2);
                x = tb[0];
                y = tb[1];
                if (*(s16 *)(o + 0x140) != 0) x = -x;
                *(f32 *)(o + 0x34) += x;
                x *= 16.0f;
                *(f32 *)(o + 0x38) += y;
                y *= 16.0f;
                *(s16 *)(o + 0x140) = 0;
                vx = -x / 256.0f;
                vy = -y / 256.0f;
                *(f32 *)(o + 0x5C) = vx;
                if (!(vx < 0.0f)) *(s16 *)(o + 0x140) = 1;
                *(f32 *)(o + 0x60) = vy;
                *(s16 *)(o + 0x1C) = 0x20;
                if (o[0x20] == 1) {
                    *(s8 *)(o + 0x1B5) = 0x3E;
                    o[0x1B2] = *(u16 *)(o + 0x1C0) = 0;
                    *(s32 *)(o + 0x1D8) = 0;
                    D_004C2794[o[2] + 0x3E] += 1;
                } else {
                    *(s8 *)(o + 0x1B5) = 0x3F;
                    o[0x1B2] = *(u16 *)(o + 0x1C0) = 0;
                    *(s32 *)(o + 0x1D8) = 0;
                    D_004C2794[o[2] + 0x3E] += 1;
                }
                func_001E3210(o, D_004762A0[o[0x20] * 4]);
            }
        } else {
            func_003DAA40(o);
        }
    }
}
