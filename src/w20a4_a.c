typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_002384A0(u8 *p, u8 *q) {
    extern int func_00175700(u8 *);
    extern void func_001266A0(u8 *, s32, s32);
    extern void func_00238B70(u8 *, u8 *);
    extern void func_001A1F00(u8 *, s32, s32);
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_00238A10(u8 *, u8 *);
    f32 d;
    p[0x40C] = 2;
    p[0x33C] = 5;
    func_00175700(p);
    if (*(s8 *)(q + 0x38) > 0) {
        u32 t;
        s8 x;
        t = p[7];
        p[7] = t + 1;
        p[0x1FE] = 1;
        (*(u8 **)(p + 0x1DC))[0x208] = 2;
        x = (p[2] != 0) ? 4 : 3;
        func_001266A0(p, x, x);
        func_00238B70(p, q);
        *(u32 *)(p + 0x5C) = 0xBFD55555;
        *(u32 *)(p + 0x68) = 0;
        *(u32 *)(p + 0x60) = 0x414DB6DB;
        *(u32 *)(p + 0x6C) = 0xBE960000;
        if (p[0x1E6] != 0) {
            *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
        }
        func_001A1F00(p, 8, 0);
        func_001757E0(p, 0x16, 0x23);
        p[0x22] = p[0x15B];
        d = (f32)(u32)p[0x22];
        *(f32 *)(q + 0x2C) = d;
        *(f32 *)(q + 0x30) = d;
        func_00238A10(p, q);
        return;
    }
    if (*(s8 *)(q + 0x38) < 0) {
        u32 t;
        f32 two = 2.0f;
        t = p[6];
        p[6] = t + 1;
        p[7] = 0;
        *(f32 *)(p + 0x5C) = *(f32 *)(p + 0x5C) / two;
        *(u32 *)(p + 0x60) = 0;
        *(u32 *)(p + 0x6C) = 0xBF4DB6DB;
        q[0x38] = 0;
        func_001757E0(p, 0x16, 0x22);
    }
}
