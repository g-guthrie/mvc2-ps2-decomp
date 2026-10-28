typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_001BFFB0(u8 *p) {
    extern void func_001754A0();
    extern int func_00175670(u8 *);
    f32 one = 1.0f;
    f32 z = 0.0f;
    f32 d;
    u8 *q = *(u8 **)(p + 0x18);
    u32 t;
    p[0x13C] = 0;
    *(f32 *)(p + 0x118) = one;
    if (*(s16 *)(p + 0x1E) != *(s16 *)(q + 0x168)) {
        p[4] = 2;
        return;
    }
    p[0x13C] = 1;
    switch (p[5]) {
    case 0:
        p[5] = p[5] + 1;
        func_001754A0(p, 0x1B, 0);
        break;
    case 1:
        func_00175670(p);
        if (*(s8 *)(p + 0x151) != 0) {
            t = p[5];
            p[5] = t + 1;
            *(u32 *)(p + 0x5C) = 0x3F800000;
            *(u32 *)(p + 0x68) = 0x3D800000;
        }
        break;
    case 2:
        *(f32 *)(p + 0x5C) -= *(f32 *)(p + 0x68);
        d = *(f32 *)(p + 0x5C);
        if (d < z) {
            t = p[4];
            p[4] = t + 1;
            *(f32 *)(p + 0x118) = one;
            p[0x13C] = 0;
        }
        *(f32 *)(p + 0x118) = *(f32 *)(p + 0x5C);
        break;
    }
}
