typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;


void func_0036B670(u8 *p) {
    extern void func_00175700(u8 *);
    extern void func_0036AA70(u8 *, s32, s32);
    u32 t;
    s16 h;
    func_00175700(p);
    *(f32 *)(p + 0x50) /= 1.6666666269302368f;
    *(f32 *)(p + 0x54) /= 2.142857074737549f;
    *(f32 *)(p + 0x50) += *(f32 *)(p + 0x6C);
    *(f32 *)(p + 0x54) -= *(f32 *)(p + 0x68);
    switch ((double)(*(f32 *)(p + 0x54)) <= 0.004666666815016009) { case 0: break; default: {
        *(u32 *)(p + 0x54) = 0x3B98EAD7;
        if (*(s16 *)(p + 0x1C) % 5 == 0) {
            func_0036AA70(p, 9, p[0x23]);
            func_0036AA70(p, 10, p[0x23]);
            t = p[0x23];
            p[0x23] = t + 1;
        }
    } break; }
    h = *(s16 *)(p + 0x1C);
    *(s16 *)(p + 0x1C) = h - 1;
    if (h == 0) {
        t = p[4];
        p[4] = t + 1;
        p[0x13C] = 0;
    }
}
