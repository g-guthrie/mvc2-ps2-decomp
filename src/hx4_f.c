typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_001F9B00(u8 *p)
{
    extern void func_00347AA0();
    extern void func_00347F90(u8 *, s32);
    extern void func_00183d50(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_001F9CB0(u8 *);
    extern s8 func_00175700(u8 *);
    extern void func_00184540(u8 *);
    u32 t;
    f32 z;
    if (*(s8 *)(p + 0x150) != 0) {
        func_00347AA0();
        func_00347F90(p, 0);
        p[0x150] = 0;
    }
    if (*(f32 *)(p + 0x38) < *(f32 *)(p + 0x430)) {
        t = p[6];
        p[6] = t + 1;
        *(u32 *)(p + 0x5C) = 0;
        *(u32 *)(p + 0x68) = 0;
        *(u32 *)(p + 0x60) = 0;
        *(u32 *)(p + 0x6C) = 0;
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        p[0x20D] = 1;
        func_00183d50(p);
        func_001757E0(p, 0x15, 4);
        func_001F9CB0(p);
        return;
    }
    z = 0.0f;
    if (*(f32 *)(p + 0x60) > z) {
        *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
        *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
        *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
        func_00175700(p);
    } else {
        if (func_00175700(p) < 0) {
            func_00184540(p);
            return;
        }
        if (*(f32 *)(p + 0x5C) <= z) {
            *(f32 *)(p + 0x5C) = z;
            *(f32 *)(p + 0x68) = z;
        }
        *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
        *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
        *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    }
}
