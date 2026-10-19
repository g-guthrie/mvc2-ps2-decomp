typedef unsigned char u8;
typedef unsigned int u32;
typedef signed short s16;
typedef float f32;

void func_00282720(u8 *p) {
    f32 v;
    u32 t = p[7];
    p[7] = t + 1;
    p[0x20D] = 2;
    if (p[0x1E6] != 0)
        v = 3.3333333f;
    else
        v = -3.3333333f;
    *(f32 *)(p + 0x5C) = v;
    *(u32 *)(p + 0x68) = 0;
    *(f32 *)(p + 0x60) = 25.714285f;
    *(f32 *)(p + 0x6C) = -1.0714285f;
    *(s16 *)(p + 0x1E) = 0;
}
