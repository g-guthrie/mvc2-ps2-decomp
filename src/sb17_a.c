typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef double f64;

void func_0036A620(u8 *);
s32 func_0036A5F0(u8 *);
void func_001757E0(u8 *, s32, s32);

void func_00369DA0(u8 *p) {
    u8 *q = *(u8 **)(p + 0x1DC);
    f32 z;
    f32 v;
    f64 d;
    *(u8 *)(*(u8 **)(p + 0x18) + 0x1FE) = 1;
    if (func_0036A5F0(p) != 0) {
        p[5] = 0xF;
        return;
    }
    func_0036A620(p);
    z = 0.0f;
    if (*(f32 *)(q + 0x60) <= z) {
        if (*(f32 *)(q + 0x38) <= 274.2857056f + *(f32 *)(q + 0x430)) {
            goto body;
        }
        return;
    }
    return;
    body:
    {
        {
            u32 t = p[5];
            p[5] = t + 1;
            *(f32 *)(p + 0x5C) = z;
            *(f32 *)(p + 0x60) = z;
            *(f32 *)(p + 0x68) = z;
            *(f32 *)(p + 0x6C) = z;
            if (*(s16 *)(p + 0x140) != 0) {
                v = -186.66665649f;
            } else {
                v = 186.66665649f;
            }
            v = *(f32 *)(q + 0x34) + v;
            *(f32 *)(p + 0x5C) = v;
            d = (f64)(v - *(f32 *)(p + 0x34));
            d = d / 16.0;
            *(f32 *)(p + 0x5C) = (f32)d;
            *(s16 *)(p + 0x1C) = 3;
            *(s16 *)(p + 0x1E) = 3;
            func_001757E0(p, 0x17, 0x1C);
        }
    }
}

extern u8 *D_004C2988 __attribute__((section(".sdata")));

void func_00369AA0(u8 *p) {
    u8 *q = *(u8 **)(p + 0x1DC);
    f32 z;
    f32 v;
    f64 d;
    *(u8 *)(*(u8 **)(p + 0x18) + 0x1FE) = 1;
    if (func_0036A5F0(p) != 0) {
        p[5] = 0xF;
        return;
    }
    func_0036A620(p);
    z = 0.0f;
    if (*(f32 *)(q + 0x60) <= z) {
        if (*(f32 *)(q + 0x38) <= 274.2857056f + *(f32 *)(q + 0x430)) {
            goto body;
        }
        return;
    }
    return;
    body:
    {
        {
            u32 t = p[5];
            p[5] = t + 1;
            *(f32 *)(p + 0x5C) = z;
            *(f32 *)(p + 0x60) = z;
            *(f32 *)(p + 0x68) = z;
            *(f32 *)(p + 0x6C) = z;
            if (*(s16 *)(p + 0x140) != 0) {
                v = 186.66665649f;
            } else {
                v = -186.66665649f;
            }
            v = *(f32 *)(q + 0x34) + v;
            *(f32 *)(p + 0x5C) = v;
            d = (f64)(v - *(f32 *)(p + 0x34));
            d = d / 16.0;
            *(f32 *)(p + 0x5C) = (f32)d;
            *(s16 *)(p + 0x1C) = 4;
            *(s16 *)(p + 0x1E) = 3;
            D_004C2988[0xB] = 1;
            func_001757E0(p, 0x17, 0x1B);
        }
    }
}
