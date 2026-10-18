typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
extern int func_00189310(u8 *, void *, u8 *);
extern void func_0018A990(u8 *, u8 *);
extern u8 D_00451680[];
s32 func_00226770(u8 *p) {
    if (func_00189310(p, D_00451680, p + 0x398) == 0) return 0;
    if (**(s8 **)(p + 0x420) == 0) return 0;
    func_0018A990(p, p + 0x398);
    p[0x26C] = 0x14;
    return 1;
}
extern int func_00189660(u8 *, void *, u8 *);
extern void func_0018A990(u8 *, u8 *);
extern void func_00186A60(u8 *, s32);
extern u8 D_004524A8[];
s32 func_00239E60(u8 *p) {
    if (func_00189660(p, D_004524A8, p + 0x380) == 0) return 0;
    func_0018A990(p, p + 0x380);
    p[5] = 0;
    if (p[0x425] == 0) p[6] = 0;
    p[7] = 0;
    p[0x1FD] = 0;
    func_00186A60(p, 0x15);
    return 1;
}
extern void func_00175700(u8 *);
extern f32 func_002ADC20(u8 *);
extern void func_001757E0(u8 *, s32, s32);
extern void func_00183D90(u8 *);
void func_002AD5E0(u8 *p) {
    if (func_002ADC20(p) < 0.0f) {
        u32 t = p[7];
        p[7] = t + 1;
        *(f32 *)(p + 0x34) = *(f32 *)(p + 0x2B8);
        func_001757E0(p, 0x12, 2);
    } else {
        func_00175700(p);
        func_00183D90(p);
    }
}
extern int func_00189660(u8 *, void *, u8 *);
extern u8 D_00458018[];
s32 func_0029B610(u8 *p) {
    if (func_00189660(p, D_00458018, p + 0x3B8) == 0) return 0;
    if (*(s32 *)(p + 0x30C) != 0) return 0;
    func_0018A990(p, p + 0x3B8);
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    p[0x1FD] = 7;
    func_00186A60(p, 0x15);
    return 1;
}
extern void func_001AD170(u8 *, s32, s32);
extern void func_001E3710(u8 *, s32);
void func_0024F9A0(u8 *p) {
    p[0x33A] = 0xFF;
    func_00175700(p);
    switch (*(s8 *)(p + 0x151)) {
    case 1:
        p[0x151] = 0;
        func_001AD170(p, 0xA, 0);
        func_001E3710(p, 0x49);
        break;
    case 2:
        p[0x151] = 0;
        func_001AD170(p, 0xB, 0);
        break;
    }
}
