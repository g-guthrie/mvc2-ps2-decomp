typedef unsigned char u8;
typedef signed char s8;
typedef float f32;
typedef struct { f32 x, y, z; } Vec3;

extern void func_0015B200(u8 *, Vec3 *, int, int);
extern void func_001E3710(u8 *, int);

void func_00350B80(u8 *p)
{
    Vec3 tmp;
    u8 *o = *(u8 **)(p + 0x18);
    if (*(s8 *)(o + 0x151) == 0)
        return;
    p[5]++;
    tmp = *(Vec3 *)(p + 0x34);
    tmp.y += 25.7142848968505859375f;
    func_0015B200(p, &tmp, 1, 0xc9);
    func_001E3710(p, 0x49);
}
