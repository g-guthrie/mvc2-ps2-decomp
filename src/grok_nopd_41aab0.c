typedef unsigned char u8;
typedef signed short s16;
typedef float f32;

typedef struct { f32 x, y, z; } Vec3;

extern int func_001754A0(u8 *, int, int);
extern void func_0041AB30(u8 *, u8 *);

void residual_0041AAB0(u8 *p, u8 *q)
{
    p[5]++;
    *(s16 *)(p + 320) = 0;
    p[49] = 1;
    *(Vec3 *)(p + 52) = *(Vec3 *)(q + 52);
    func_001754A0(p, 27, 43);
    func_0041AB30(p, q);
}
