typedef float f32;
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern volatile s32 D_004C283C;

void func_00343B10(u8 *p) {
    extern void func_003DAA40();
    extern s32 func_00153AA0();
    extern void func_00170DA0();
    switch (p[4]) {
    case 0: {
        s32 r;
        s16 v = *(s16 *)(p + 0x1C) + 1;
        *(s16 *)(p + 0x1C) = v;
        if (v >= 100) *(s16 *)(p + 0x1C) = 0;
        r = func_00153AA0(p);
        func_00170DA0(D_004C283C, p[0x20] * 2 + 0x49, r, *(s16 *)(p + 0xCC));
        *(u32 *)(p + 0xE0) = 0;
        *(f32 *)(p + 0xE4) = 0.01f * -(f32)*(s16 *)(p + 0x1C);
        *(u32 *)(p + 0xD0) = *(u32 *)(p + 0xD0) | 0x20000;
        break;
    }
    case 1:
        func_003DAA40(p);
        break;
    }
}
