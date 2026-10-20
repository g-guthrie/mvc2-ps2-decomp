typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef f32 PlanarOffset[2] __attribute__((aligned(16)));

extern void func_001830D0(u8 *, const f32 *, s32);
extern void func_0036BFF0(void *, u32, u32, u32);
extern void func_00175700(u8 *);

void func_00260960(u8 *p)
{
    p[0x40C] = 2;
    p[0x33C] = 5;
    if (*(s8 *)(p + 0x151) == 1) {
        PlanarOffset values;

        p[0x151] = 0;
        values[0] = -26.66666603088379f;
        values[1] = 274.28570556640625f;
        func_001830D0(p, values, 1);
        func_0036BFF0(p, 14, 19, 14);
        *(s16 *)(p + 0x1C) = 180;
    }
    if (*(s8 *)(p + 0x153) < 0)
        p[6]++;
    func_00175700(p);
}
