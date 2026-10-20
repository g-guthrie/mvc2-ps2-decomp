typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern void func_001E7F60(u8 *);
extern void func_0015B200(u8 *, f32 *, s32, s32);
extern void func_001E3710(u8 *, s32);

void func_0038A3F0(u8 *p, u8 *q)
{
    f32 sp[3];
    f32 z;
    f32 lim;

    sp[2] = 0;
    sp[1] = 0;
    sp[0] = 0;
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    z = 0.0f;
    if (!p[6]) {
        if (!(*(f32 *)(p + 0x5C) * *(f32 *)(p + 0x68) <= z)) {
            p[6] += 1;
            *(f32 *)(p + 0x68) = z;
            *(f32 *)(p + 0x5C) = z;
        }
    }
    if (!*(s8 *)(p + 0x1B2) && !*(s8 *)(p + 0x1B3)) {
        lim = 17.142857074737549f;
        sp[1] = lim + *(f32 *)(q + 0x430);
        if (*(f32 *)(p + 0x38) <= sp[1])
            *(f32 *)(p + 0x38) = sp[1];
        else {
            func_001E7F60(p);
            return;
        }
    }
    *(s8 *)(p + 0x13D) = *(s8 *)(q + 0x13D);
    *(s16 *)(p + 0x13E) = *(s16 *)(q + 0x13E);
    p[4] += 1;
    p[0x13C] = 0;
    sp[0] = *(f32 *)(p + 0x34);
    lim = 17.142857074737549f;
    sp[1] = *(f32 *)(p + 0x38) - lim;
    func_0015B200(p, sp, 1, 8);
    func_001E3710(p, 0x49);
}
