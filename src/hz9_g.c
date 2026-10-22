typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef unsigned int u32;
typedef float f32;

void func_00391350(u8 *p, u8 *q) {
    extern void func_00175700(u8 *);
    extern s32 func_00174170(void);
    f32 *a, *b, *c, *d;
    func_00175700(p);
    a = (f32 *)(p + 0x5C);
    c = (f32 *)(p + 0x68);
    b = (f32 *)(p + 0x60);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    d = (f32 *)(p + 0x6C);
    if (*(s8 *)(p + 0x1B2) != 0) {
        *(s32 *)(p + 0xD0) = 1;
        goto blockA;
    } else {
        if (51.42856979370117f + *(f32 *)(q + 0x430) <= *(f32 *)(p + 0x38)) return;
        if (*(s16 *)(p + 0x1C) != 0) {
            u32 t;
blockA:
            t = p[5];
            p[5] = t + 1;
            *(s16 *)(p + 0x1C) = (func_00174170() & 7) + 0x10;
            *(u32 *)a = 0;
            *(u32 *)b = 0;
            *(u32 *)c = 0;
            *(u32 *)d = 0;
            return;
        }
    }
    {
        s16 h = *(s16 *)(p + 0x1C) + 1;
        f32 z, w, two;
        *(s16 *)(p + 0x1C) = h;
        z = 0.0f;
        w = *(f32 *)(p + 0x60);
        if (w < z) w = -w;
        *(f32 *)(p + 0x60) = w;
        two = 2.0f;
        *(f32 *)(p + 0x60) /= two;
        *(f32 *)(p + 0x6C) /= two;
    }
}
