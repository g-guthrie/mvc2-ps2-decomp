typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_002AF220(u8 *p) {
    extern void func_00175700(u8 *);
    extern void func_001757E0(u8 *, s32, u8);
    s32 t, h;
    u32 u;
    f32 w;
    func_00175700(p);
    t = *(s8 *)(p + 0x1B2);
    if (t & 1) {
        u = p[6];
        p[6] = u + 1;
        p[0x2C6] = 2;
        p[0x2C7] = 0;
        if (p[0x1E6] != 0) w = -3.3333332538604736f;
        else w = 3.3333332538604736f;
        *(f32 *)(p + 0x5C) = w;
        *(u32 *)(p + 0x68) = 0;
        *(u32 *)(p + 0x60) = 0x41092492;
        if (p[0x1B7] != 0) *(u32 *)(p + 0x60) = 0x41892492;
        *(u32 *)(p + 0x6C) = 0xBF4DB6DB;
        func_001757E0(p, 0x15, 4);
    } else if (t != 0) {
        p[6] = 5;
        p[0x2C6] = 1;
        p[0x2C7] = 0;
        *(u32 *)(p + 0x60) = 0x40092492;
        func_001757E0(p, 0x15, p[0x1B7] + 0x20);
    } else {
        *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
        *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
        *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
        h = *(s16 *)(p + 0x1C);
        *(s16 *)(p + 0x1C) = h - 1;
        if (h == 0) {
            p[6] = 6;
            p[0x2C6] = 2;
            p[0x2C7] = 0;
            if (p[0x1E6] != 0) w = -0.20833332836627960f;
            else w = 0.20833332836627960f;
            *(f32 *)(p + 0x68) = w;
            *(u32 *)(p + 0x60) = 0x40092492;
            *(u32 *)(p + 0x6C) = 0xBF4DB6DB;
            func_001757E0(p, 0x15, 0x1F);
        }
    }
}
