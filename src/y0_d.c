typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_001AB8B0(u8 *p, u8 *q)
{
    extern void func_00175700();
    extern f32 func_001AC390();
    extern void func_001757E0();
    f32 d;
    func_00175700(p);
    if (q[0x1E4] == 0x16) {
        d = *(f32 *)(p + 0x34) - func_001AC390(q, 0x38);
        if (d < -13.33333301544189f || 13.33333301544189f < d)
            p[7] = 1;
        if (*(s8 *)(q + 0x151) != 0) {
            p[7] = 5;
            func_001757E0(p, 0x17, 0x13);
        }
    }
}

void func_00227FB0(u8 *p)
{
    extern void func_00175700();
    f32 a, b;
    u32 t;
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_00175700(p);
    if (*(s8 *)(p + 0x151) != 0) {
        t = p[6];
        p[6] = t + 1;
        p[0x151] = 0;
        p[0x20D] = 2;
        a = -10.0f;
        b = 0.625f;
        if (*(s16 *)(p + 0x140) != 0) {
            a = -a;
            b = -b;
        }
        *(f32 *)(p + 0x5C) = a;
        *(u32 *)(p + 0x60) = 0x414DB6DB;
        *(f32 *)(p + 0x68) = b;
        *(u32 *)(p + 0x6C) = 0xBF4DB6DB;
    }
}

void func_0022B060(u8 *p)
{
    extern void func_00175700();
    extern void func_001830D0();
    f32 a, b;
    u32 t;
    u32 v[4];
    p[0x40C] = 2;
    p[0x33C] = 5;
    p[0x405] = (p[0x269] == 6) ? 2 : 0;
    func_00175700(p);
    if (*(s8 *)(p + 0x151) != 0) {
        p[0x404] = 0;
        p[0x405] = 0;
        t = p[6];
        p[6] = t + 1;
        a = -16.66666603088379f;
        b = 0.625f;
        p[0x151] = 0;
        if (*(s16 *)(p + 0x140) != 0) {
            a = -a;
            b = -b;
        }
        *(f32 *)(p + 0x5C) = a;
        *(f32 *)(p + 0x68) = b;
        v[0] = 0xC2200000;
        v[1] = 0x424DB6DB;
        func_001830D0(p, v, 1);
    }
}

void func_0019AB90(u8 *p, u8 *q)
{
    extern void func_00175670();
    extern void func_0019A440();
    u32 t;
    func_00175670(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (*(s16 *)(p + 0x1C) == 0) {
        if (*(f32 *)(p + 0x38) < 205.7142791748047f + *(f32 *)(q + 0x430)) {
            *(s16 *)(p + 0x1C) = 1;
            func_0019A440(p, 3);
        }
    }
    if (*(f32 *)(p + 0x38) <= *(f32 *)(q + 0x430)) {
        t = p[4];
        p[4] = t + 1;
        p[0x13C] = 0;
    }
}
