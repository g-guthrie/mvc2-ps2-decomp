typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_0017C5E0(u8 *p)
{
    extern void func_0018F460(u8 *);
    extern s8 func_00175700(u8 *);
    extern s32 func_001864A0(u8 *);
    extern void func_0017C7F0(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    f32 *v5c; f32 *v60; f32 *v68; f32 *v6c;
    u32 t;
    v5c = (f32 *)(p + 0x5C);
    v68 = (f32 *)(p + 0x68);
    v60 = (f32 *)(p + 0x60);
    v6c = (f32 *)(p + 0x6C);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_0018F460(p);
    if (func_00175700(p) >= 0) {
        if (func_001864A0(p) != 0) {
            *v5c = 0;
            *v60 = 0;
            *v68 = 0;
            *v6c = 0;
            p[0x20D] = 0;
            *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
            p[6] = 3;
            func_0017C7F0(p);
        }
    } else {
        t = p[6];
        p[6] = t + 1;
        p[0x1E7] = 1;
        p[0x210] = 1;
        p[0x20D] = 2;
        *(f32 *)(p + 0x6C) = -0.8035714030265808f;
        func_001757E0(p, 1, 0xB);
    }
}
