typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 D_004C27D0;
extern s32 D_004C283C;

void func_0033CAB0(u8 *p) {
    extern s32 func_00153AA0(u8 *);
    extern void func_00170DA0(s32, s32, s32, s16);
    f32 f;
    switch (p[4]) {
    case 0:
    *(s16 *)(p + 0x1C) += 1;
    if (D_004C27D0 == 4) {
        if (*(s16 *)(p + 0x1C) >= 100) *(s16 *)(p + 0x1C) = 0;
    } else {
        if (*(s16 *)(p + 0x1C) >= 500) *(s16 *)(p + 0x1C) = 0;
    }
    func_00170DA0(D_004C283C, 3, func_00153AA0(p), *(s16 *)(p + 0xCC));
    if (D_004C27D0 == 4) {
        f = 0.009999999776482582f * *(s16 *)(p + 0x1C);
    } else {
        f = 0.0020000000949949026f * *(s16 *)(p + 0x1C);
    }
    f = -f;
    *(s32 *)(p + 0xE0) = 0;
    *(f32 *)(p + 0xE4) = f;
    *(u32 *)(p + 0xD0) |= 0x20000;
    break;
    default:
    break;
    }
}
