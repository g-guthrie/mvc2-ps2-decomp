typedef unsigned char u8;
typedef signed int s32;
typedef unsigned int u32;
typedef float f32;
extern s32 func_00175700(u8 *);
extern s32 func_001757E0(u8 *, s32, s32);

void func_00218750(u8 *p) {
    f32 z = 0.0f;
    f32 *a, *b;
    u32 t;
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    a = (f32 *)(p + 0x5C);
    b = (f32 *)(p + 0x68);
    if (!(*(f32 *)(p + 0x5C) * *(f32 *)(p + 0x68) < z)) {
        *a = z;
        *b = z;
    }
    func_00175700(p);
    if (*(f32 *)(p + 0x60) < z) {
        t = p[6];
        p[6] = t + 1;
        p[7] = 0;
        p[0x1B2] = 1;
        *(u32 *)(p + 0x6C) = 0xBF9A4924;
        func_001757E0(p, 0x15, 4);
    }
}
