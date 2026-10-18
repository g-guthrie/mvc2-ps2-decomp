typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s32 func_00153AA0();
extern void func_00170DA0(s32 a, s32 b, s32 c, s16 d);
extern s32 D_004C283C;
void func_0032FAF0(u8 *p) {
    switch (p[4]) {
    case 0: {
        s32 r;
        *(s16 *)(p + 0x1C) = *(s16 *)(p + 0x1C) + 1;
        if (*(s16 *)(p + 0x1C) >= 500) *(s16 *)(p + 0x1C) = 0;
        r = func_00153AA0(p);
        func_00170DA0(D_004C283C, 2, r, *(s16 *)(p + 0xCC));
        *(s32 *)(p + 0xE0) = 0;
        *(f32 *)(p + 0xE4) = -0.0020000000949949026f * (f32)*(s16 *)(p + 0x1C);
        *(u32 *)(p + 0xD0) |= 0x20000;
        break;
    }
    }
}

