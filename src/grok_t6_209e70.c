/* Metrowerks 3.0: ./try.sh src/grok_t6_209e70.c "-O3 -Op" */
typedef unsigned char u8;
typedef signed char s8;
typedef float f32;

extern s8 func_00175700(u8 *);
extern void func_001757E0(u8 *, int, int);

void func_00209E70(u8 *p)
{
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (func_00175700(p) < 0) {
        p[6]++;
        *(f32 *)(p + 0x5C) = p[0x1E6] ? (20.0f / 3.0f) : -(20.0f / 3.0f);
        *(f32 *)(p + 0x68) = p[0x1E6] ? -(5.0f / 24.0f) : (5.0f / 24.0f);
        p[0x169] = 2;
        p[0x168] = 2;
        func_001757E0(p, p[0x169], p[0x168]);
    }
}
