typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_00389E60(u8 *p, u8 *q)
{
    extern int func_00174470(const void *);
    extern void func_00175700();
    extern void func_001E7F60(u8 *);
    extern void func_0015B200(u8 *, f32 *, s32, s32);
    extern void func_001E3710(u8 *, s32);
    f32 v[3];
    f32 *s;
    u32 t;

    v[2] = 0;
    s = &v[1];
    *s = 0;
    v[0] = 0;
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (func_00174470(p) == 0) {
        t = p[4];
        p[4] = t + 1;
        p[0x13C] = 0;
        return;
    }
    if (*(s8 *)(p + 0x1B2) != 0 || *(s8 *)(p + 0x1B3) != 0) {
        p[4]++;
        if (*(s16 *)(p + 0x140) == 0) {
            v[0] = *(f32 *)(p + 0x34);
        } else {
            v[0] = *(f32 *)(p + 0x34);
        }
        *s = *(f32 *)(p + 0x38);
        func_0015B200(p, v, 1, 8);
        func_001E3710(p, 0x49);
        return;
    }
    if (*(f32 *)(p + 0x38) <= *(f32 *)(q + 0x430)) {
        p[4]++;
        *(f32 *)(p + 0x38) = *(f32 *)(q + 0x430);
        if (*(s16 *)(p + 0x140) == 0) {
            v[0] = *(f32 *)(p + 0x34);
        } else {
            v[0] = *(f32 *)(p + 0x34);
        }
        *s = *(f32 *)(p + 0x38);
        func_0015B200(p, v, 1, 8);
        func_001E3710(p, 0x49);
    } else {
        func_00175700(p);
        func_001E7F60(p);
    }
}
