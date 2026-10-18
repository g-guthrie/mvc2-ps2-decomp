typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
void func_002BC230(u8 *p) {
    extern s32 func_00175700(u8 *);
    extern void func_00183d50(u8 *);
    extern s32 func_001757E0(u8 *, s32, s32);
    f32 *a, *b, *c, *d;
    u32 k;
    func_00175700(p);
    a = (f32 *)(p + 0x5C);
    c = (f32 *)(p + 0x68);
    b = (f32 *)(p + 0x60);
    d = (f32 *)(p + 0x6C);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    k = p[0x1E6];
    if ((k == 0 && !(*(f32 *)(p + 0x5C) <= 0.0f)) || (k != 0 && *(f32 *)(p + 0x5C) < 0.0f)) {
        *(u32 *)a = 0;
        *(u32 *)c = 0;
    }
    if (*(f32 *)(p + 0x38) <= *(f32 *)(p + 0x430)) {
        u32 t = p[6];
        p[6] = t + 1;
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        p[0x20D] = 0;
        *(u32 *)a = 0;
        *(u32 *)b = 0;
        *(u32 *)c = 0;
        *(u32 *)d = 0;
        func_00183d50(p);
        func_001757E0(p, 0x15, 0x1B);
    }
}
