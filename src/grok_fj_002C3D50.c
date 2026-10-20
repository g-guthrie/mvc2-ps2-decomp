typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;
typedef f32 PlanarOffset[2] __attribute__((aligned(16)));

extern void func_00175700(u8 *);
extern void func_001266A0(u8 *, int, int);
extern void func_00154790(f32 *, s16, int, int);
extern void func_001E3A40(u8 *);

void func_002C3D50(u8 *p)
{
    u8 *q;
    PlanarOffset v;

    p[0x40C] = 2;
    p[0x33C] = 5;
    p[0x1FE] = 1;
    p[0x201] = 2;
    p[0x209] = 2;
    func_00175700(p);
    if (*(s8 *)(p + 0x151) != 0) {
        if (*(s8 *)(p + 0x151) > 0) {
            p[6]++;
            p[0x40D] = 0;
            p[0x40C] = 0;
            p[0x33B] = 0;
            p[0x33C] = 0;
            p[0x151] = 0;
            q = *(u8 **)(p + 0x1DC);
            *(u8 **)(q + 0x1C8) = p;
            q[0x20A] = 1;
            q[0x20D] = 0;
            func_001266A0(p, 0, 0);
            q[0x1B5] = 0x22;
            *(u32 *)(p + 0x68) = 0;
            *(u32 *)(p + 0x6C) = 0;
            *(u32 *)(p + 0x60) = 0x41892492;
            *(u32 *)(p + 0x6C) = 0xBECDB6DB;
            *(u32 *)(p + 0x5C) = 0x3FA00000;
            if (!p[0x1E6])
                *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
        } else {
            p[0x151] = 0;
            q = *(u8 **)(p + 0x1DC);
            *(u8 **)(q + 0x1C8) = p;
            q[0x1B5] = 0x27;
            v[0] = *(f32 *)(p + 0x34) - 133.3333282470703125f;
            if (!p[0x1E6])
                v[0] = *(f32 *)(p + 0x34) + 133.3333282470703125f;
            v[1] = *(f32 *)(p + 0x38);
            func_00154790(v, *(s16 *)(q + 0x140), 1, 0x10);
            func_001E3A40(p);
        }
    }
}
