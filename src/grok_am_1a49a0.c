typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef signed int s32;
typedef float f32;

extern u8 D_004D18DB;
extern u16 D_004D18DC;
extern s32 func_00174470(u8 *);

void func_001A49A0(u8 *p, u8 *q, s8 *r)
{
    if (D_004D18DC & (1 << D_004D18DB))
        return;
    *(f32 *)(p + 0x34) = *(f32 *)(*(u8 **)(p + 0x14) + 0x34) + *(f32 *)(p + 0x5C);
    if (*r == 0) {
        if (p[0x21] != 0) {
            if (func_00174470(p) == 0) {
                p[4] = 2;
                p[0x13C] = 0;
                (*(u8 **)(p + 0xC))[0x21] = 1;
                *(u8 **)(*(u8 **)(p + 0xC) + 0x14) = q;
                return;
            }
        }
    }
    p[5]++;
    *(s32 *)(p + 0x68) = 0x41D55555;
    if (*(s16 *)(p + 0x140) != 0) {
        f32 v = *(f32 *)(p + 0x68);
        *(f32 *)(p + 0x68) = (v < 0) ? -v : v;
    }
}
