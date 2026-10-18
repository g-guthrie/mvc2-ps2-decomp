typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0xC]; void (*fn)(u8 *); } VT;

void func_0017BC60(u8 *p) {
    extern s32 func_001884C0(u8 *);
    extern s32 func_00184720(u8 *);
    s32 b;
    u8 t;
    f32 z = 0.0f;
    f32 k = 4.0f;
    if (func_001884C0(p) != 0) return;
    if (p[0x20D] != 2) {
        if (p[0x1B7] != 1) {
            b = *(s8 *)(p + 0x1B2);
            if (b != 0 && ((s8)b & 9) == 0) {
                p[0x1B2] = b | 8;
                t = p[0x1E6];
                if ((t == 0 && *(f32 *)(p + 0x5C) < z) || (t != 0 && *(f32 *)(p + 0x5C) > z)) {
                    *(f32 *)(p + 0x68) *= k;
                }
            }
        }
    }
    if (func_00184720(p) != 0) return;
    (*(VT **)(p + 0x43C))->fn(p);
    if (p[0x214] != 0 && p[0x1E4] == 0x14) {
        (*(VT **)(p + 0x43C))->fn(p);
    }
}

extern void func_003A2540(void);

void func_003A22C0(u8 *p, u8 b) {
    extern u8 *func_003DA750(s32, s32, s32);
    s32 i;
    s32 x;
    u8 *o;
    x = 0;
    for (i = 0; i < 3; i++) {
        if ((o = func_003DA750(0, 1, 0)) != 0) {
            *(u32 *)(o + 0x10) = (u32)func_003A2540;
            o[0x20] = b;
            o[0x21] = 0;
            *(u8 **)(o + 0x18) = p;
            o[1] = p[1];
            if (*(s16 *)(p + 0x140) != 0) {
                *(f32 *)(o + 0x34) = *(f32 *)(p + 0x34) + 1.6666666269302368f * (f32)(i * 0x40 + 0x1C);
            } else {
                *(f32 *)(o + 0x34) = *(f32 *)(p + 0x34) - 1.6666666269302368f * (f32)(i * 0x40 + 0x1C);
            }
            *(f32 *)(o + 0x38) = *(f32 *)(p + 0x430) - 8.571428298950195f;
            *(s16 *)(o + 0x26) = 0x2C02;
            *(s16 *)(o + 0x1C) = x;
            *(s16 *)(o + 0x1E) = 3;
            x += 10;
        }
    }
}
