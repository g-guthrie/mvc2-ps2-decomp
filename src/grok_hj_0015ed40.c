typedef unsigned char u8;
typedef signed short s16;
typedef signed int s32;
typedef float f32;

extern s16 D_004B3D70[];
extern f32 D_004B3D30[];
extern void func_0015EDB0(u8 *);

void residual_0015ED40(u8 *p)
{
    s32 index = *(s32 *)(p + 0xDC);
    unsigned int scale = (unsigned int)D_004B3D30;
    unsigned int life = (unsigned int)D_004B3D70;
    p[0x13C] = 1;
    life += index * 16;
    scale += index * 32;
    life += *(s16 *)(p + 0x1C) * 2;
    *(s16 *)(p + 0x1E) = *(s16 *)life;
    scale += *(s16 *)(p + 0x1C) * 4;
    *(f32 *)(p + 0x74) = *(f32 *)scale;
    p[4]++;
    func_0015EDB0(p);
}
