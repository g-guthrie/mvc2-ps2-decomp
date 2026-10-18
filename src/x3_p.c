typedef float f32;
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

void func_0017CBE0(u8 *p) {
    extern void func_00175700();
    extern void func_001757E0();
    extern void func_00183d50();
    f32 *v1, *a3, *t0, *t1;
    func_00175700(p);
    v1 = (f32 *)(p + 0x5C);
    t0 = (f32 *)(p + 0x68);
    a3 = (f32 *)(p + 0x60);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    t1 = (f32 *)(p + 0x6C);
    if (*(f32 *)(p + 0x38) <= *(f32 *)(p + 0x430)) {
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        p[0x20D] = 0;
        *(u32 *)v1 = 0;
        *(u32 *)a3 = 0;
        *(u32 *)t0 = 0;
        *(u32 *)t1 = 0;
        p[0x404] = 0;
        p[0x405] = 0;
        func_001757E0(p, 0, 0);
        (*(void (**)(u8 *))(*(u8 **)(p + 0x43C) + 0x4C))(p);
        p[0x202] = 0x3C;
        func_00183d50(p);
    }
}
