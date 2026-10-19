typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

extern int func_00175700(u8 *);
extern void func_001E7F60(u8 *);

void func_003BF420(u8 *p, u8 *q)
{
    s16 t;
    func_00175700(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    t = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = t;
    if (t == 0)
        p[4]++;
    if (q[5] || !q[0]) {
        p[0x20] = 1;
        p[7] = 0;
        *(u32 *)(p + 0x60) = 0;
        *(u32 *)(p + 0x68) = 0;
        *(u32 *)(p + 0x5C) = 0;
        *(u32 *)(p + 0x6C) = 0xBF4DB6DB;
    }
    func_001E7F60(p);
}
