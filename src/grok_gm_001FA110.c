typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef float f32;

extern int func_00175700(u8 *);
extern void func_001FA3B0(u8 *);
extern void func_001757E0(u8 *, int, int);

void func_001FA110(u8 *p)
{
    f32 *s1;
    f32 *s2;
    p[0x40C] = 2;
    p[0x33C] = 5;
    s1 = (f32 *)(p + 0x5C);
    s2 = (f32 *)(p + 0x68);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (p[0x1E6] != 0) {
        if (*(f32 *)(p + 0x5C) < 0.0f)
            goto zero;
    }
    if (p[0x1E6] == 0) {
        if (!(*(f32 *)(p + 0x5C) <= 0.0f))
            goto zero;
    }
    goto after;
zero:
    *(u32 *)s1 = 0;
    *(u32 *)s2 = 0;
after:
    if (*(s8 *)(p + 0x161) >= 0) {
        func_00175700(p);
        func_001FA3B0(p);
    }
    if (*(f32 *)(p + 0x60) < 0.0f) {
        u32 t = p[6];
        p[6] = t + 1;
        *s1 = 0.0f;
        *s2 = 0.0f;
        p[0x40D] = 0;
        p[0x40C] = 0;
        p[0x33B] = 0;
        p[0x33C] = 0;
        func_001757E0(p, 22, 4);
    }
}
