typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s32 D_00449D60[], D_00449D64[], D_00449D68[], D_00449D6C[], D_00449D70[], D_00449D74[];

void func_00195750(u8 *p, u8 *q) {
    extern void func_00175670();
    extern void func_001975C0(u8 *, u8 *);
    extern void func_001956E0(u8 *, u8 *);
    f32 *v;
    s32 a, b, c;
    v = (f32 *)(p + 0x88);
    if (*(s8 *)(q + 0x151) == 0) {
        func_00175670();
        func_001975C0(p, q);
        return;
    }
    {
        u32 t = p[6];
        p[6] = t + 1;
    }
    *(f32 *)(p + 0x34) = *(f32 *)(q + 0x34);
    *(f32 *)(p + 0x38) = *(f32 *)(q + 0x38);
    a = D_00449D60[p[0x21] * 6];
    *(f32 *)(p + 0x60) = 2.142857074737549f * (f32)D_00449D64[p[0x21] * 6] / 65536.0f;
    b = D_00449D68[p[0x21] * 6];
    c = D_00449D6C[p[0x21] * 6];
    *(f32 *)(p + 0x6C) = 2.142857074737549f * (f32)D_00449D70[p[0x21] * 6] / 65536.0f;
    v[5] = 2.142857074737549f * (f32)D_00449D74[p[0x21] * 6] / 65536.0f;
    if (*(s16 *)(p + 0x140) == 0) {
        a = -a;
        b = -b;
        c = -c;
    }
    *(f32 *)(p + 0x5C) = 1.6666666f * (f32)a / 65536.0f;
    *(f32 *)(p + 0x68) = 1.6666666f * (f32)b / 65536.0f;
    v[4] = 1.6666666f * (f32)c / 65536.0f;
    *(s16 *)(p + 0x1C) = 30;
    func_001956E0(p, q);
}
