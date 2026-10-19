typedef unsigned char u8;
typedef signed short s16;
typedef float f32;

extern int func_002FFB30(u8 *);
extern int func_00175910(u8 *, int, int, int);
extern int func_001757E0(u8 *, int, int);

void residual_00300090(u8 *p, u8 *q)
{
    s16 t;

    if (func_002FFB30(p)) {
        func_00175910(p, 15, 1, q[0xB]);
    }
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    t = *(s16 *)(p + 0x1C);
    *(s16 *)(p + 0x1C) = t - 1;
    if (t == 0) {
        p[6]++;
        func_001757E0(p, 15, 2);
        *(unsigned int *)(p + 0x60) = 0x40092492;
        *(unsigned int *)(p + 0x6C) = 0;
    }
}
