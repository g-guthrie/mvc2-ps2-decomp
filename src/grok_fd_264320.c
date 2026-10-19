typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

extern void func_001757E0(u8 *, int, int);
extern u8 *func_001B3E30(u8 *, int, int);

void func_00264320(u8 *p)
{
    u8 *q;
    p[6]++;
    p[0x13C] = 1;
    *(f32 *)(p + 0x2B8) = *(f32 *)(p + 0x34);
    *(f32 *)(p + 0x38) += 205.71427917480469f;
    *(u32 *)(p + 0x60) = 0xC1092492;
    *(u32 *)(p + 0x6C) = 0x3EAB6DB6;
    if (p[2] == 0) {
        *(s16 *)(p + 0x140) = 1;
        *(f32 *)(p + 0x34) -= 320.0f;
        *(u32 *)(p + 0x5C) = 0x41555555;
        *(u32 *)(p + 0x68) = 0;
    } else {
        *(s16 *)(p + 0x140) = 0;
        *(f32 *)(p + 0x34) += 320.0f;
        *(u32 *)(p + 0x5C) = 0xC1555555;
        *(u32 *)(p + 0x68) = 0;
    }
    func_001757E0(p, 2, 5);
    q = func_001B3E30(p, 0xF, 8);
    if (q) {
        *(f32 *)(q + 0x5C) = -*(f32 *)(p + 0x5C);
        *(f32 *)(q + 0x68) = *(f32 *)(p + 0x68);
        *(f32 *)(q + 0x60) = *(f32 *)(p + 0x60);
        *(f32 *)(q + 0x6C) = *(f32 *)(p + 0x6C);
        *(s16 *)(q + 0x140) = *(s16 *)(p + 0x140);
    }
}
