typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;

extern void func_001757E0(u8 *, int, int);
extern void func_0017FB10(u8 *);

void residual_0017FA80(u8 *p)
{
    p[6]++;
    p[0x201] = 2;
    *(s16 *)(p + 0x140) = p[0x1E6];
    p[0x20D] = 2;
    *(s16 *)(p + 0x1C) = 7;
    *(s16 *)(p + 0x1E) = 0;
    p[0x13C] = 1;
    *(u32 *)(p + 0x48) = 0;
    *(V3 *)(p + 0x50) = *(V3 *)(p + 0x298);
    *(u32 *)(p + 0x118) = 0x3F800000;
    func_001757E0(p, 0xD, 0x10);
    func_0017FB10(p);
}
