typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;

extern int func_00175700(u8 *);
extern void func_001AD1E0(u8 *, s32, s32);
extern s32 func_00174470(u8 *);
extern void func_00368FB0(u8 *);
extern void func_001E7F60(u8 *);
extern void func_0015B200(u8 *, V3 *, s32, s32);

void residual_00368E90(u8 *p)
{
    s16 v;
    V3 t;

    func_00175700(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    v = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = v;
    if (v == 0) {
        *(s16 *)(p + 0x1C) = 0xC;
        func_001AD1E0(p, 7, 0);
    }
    if ((s8)p[0x1B2] == 0) {
        if (func_00174470(p) == 0)
            func_00368FB0(p);
        else
            func_001E7F60(p);
    } else {
        p[5]++;
        t = *(V3 *)(p + 0x34);
        func_0015B200(p, &t, 1, 0x159);
    }
}
