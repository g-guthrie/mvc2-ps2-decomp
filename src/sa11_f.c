typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_002BBF00(u8 *p) {
    extern void func_00175700();
    extern void func_00183d50();
    extern void func_001757E0();
    f32 *a;
    u32 t;
    f32 *b;
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    a = (f32 *)(p + 0x5C);
    b = (f32 *)(p + 0x68);
    t = p[0x1E6];
    if ((t == 0 && *(f32 *)(p + 0x5C) > 0.0f) || (t != 0 && *(f32 *)(p + 0x5C) < 0.0f)) {
        *a = 0;
        *b = 0;
    }
    func_00175700(p);
    if (*(f32 *)(p + 0x38) <= *(f32 *)(p + 0x430)) {
        u32 c = p[6];
        p[6] = c + 1;
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        p[0x20D] = 0;
        func_00183d50(p);
        func_001757E0(p, 0x15, 0x12);
    }
}
