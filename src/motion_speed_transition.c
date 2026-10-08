typedef unsigned char u8;
typedef unsigned int u32;
typedef signed short s16;
typedef float f32;

extern void func_001757E0(u8 *, int, int);

void func_002AD6F0(u8 *p)
{
    f32 distance;
    f32 velocity;

    p[316] = 1;
    p[7]++;
    *(s16 *)(p + 28) = 32;
    *(f32 *)(p + 696) = *(f32 *)(p + 52);
    distance = 640.0f;
    velocity = 13.333333f;
    if (*(s16 *)(p + 320) != 0) {
        distance = -distance;
        velocity = -velocity;
    }
    *(f32 *)(p + 92) = velocity;
    *(f32 *)(p + 52) = *(f32 *)(p + 52) - distance;
    *(u32 *)(p + 108) = 0;
    *(u32 *)(p + 96) = 0;
    *(u32 *)(p + 104) = 0;
    func_001757E0(p, 18, 0);
}
