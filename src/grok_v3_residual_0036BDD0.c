typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern int func_00175700(u8 *);
extern double func_00119058(f32);
extern void func_001757E0(u8 *, int, int);

void residual_0036BDD0(u8 *p)
{
    s16 t;

    func_00175700(p);
    *(f32 *)(p + 0x50) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    t = *(s16 *)(p + 0x1C);
    if (!(t < 3))
        ;
    else {
        *(f32 *)(p + 0x118) -= 0.2f;
        if (func_00119058(*(f32 *)(p + 0x118)) < 0.1)
            *(u32 *)((s32)p + 0x118) = 0x3DCCCCCD;
    }
    t = *(s16 *)(p + 0x1C);
    *(s16 *)(p + 0x1C) = t - 1;
    if (t < 0) {
        p[5]++;
        *(s16 *)(p + 0x1C) = 6;
        *(u32 *)(p + 0x118) = 0x3F800000;
        *(u32 *)(p + 0x50) = 0x3F800000;
        *(u32 *)(p + 0x54) = 0x3F800000;
        *(u32 *)(p + 0x5C) = 0x3C23D70A;
        *(u32 *)(p + 0x68) = 0xB99D4952;
        *(u32 *)(p + 0x60) = 0x3CA3D70A;
        *(u32 *)(p + 0x6C) = 0xB99D4952;
        func_001757E0(p, 0x17, 9);
    }
}
