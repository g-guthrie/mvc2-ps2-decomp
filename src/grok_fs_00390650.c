typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef float f32;

extern s32 func_00174470(u8 *);
extern void func_00390630(u8 *);
extern void func_001C9490(u8 *, s32, s32);
extern int func_00175700(u8 *);
extern void func_001E7F60(u8 *);

void func_00390650(u8 *p)
{
    u8 *q = *(u8 **)(p + 0x18);
    *(s8 *)(p + 0x24) = *(s8 *)(q + 0x24);
    if (!p[5]) {
        if (!func_00174470(p)) {
            p[4] = 2;
            *(s32 *)(q + 0x30C) = 0;
            return;
        }
        if (*(s8 *)(p + 0x1B2)
            || !(*(s16 *)(p + 0x1C) -= 1)
            || *(s8 *)(p + 0x1B3)
            || q[0x169] == 0x16) {
            func_00390630(p);
            return;
        }
        if (*(f32 *)(p + 0x38) < *(f32 *)(*(u8 **)(p + 0x18) + 0x430)) {
            *(f32 *)(p + 0x38) = *(f32 *)(*(u8 **)(p + 0x18) + 0x430);
            func_00390630(p);
            return;
        }
        *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
        *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
        *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
        if (*(s8 *)(p + 0x151)) {
            *(s8 *)(p + 0x151) = 0;
            func_001C9490(p, 3, (p[0x20] >> 1) & 0xFF);
        }
        func_00175700(p);
        func_001E7F60(p);
    } else {
        s32 r = func_00175700(p);
        if ((s8)r < 0)
            p[4] += 1;
    }
}
