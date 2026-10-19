typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern void func_00175700(u8 *);
extern void func_00230670(u8 *, u8 *);
extern s32 func_00118FA8(f32);

void func_002308E0(u8 *p, u8 *q)
{
    s8 hit;
    s32 n;
    f32 t;

    p[0x40C] = 2;
    p[0x33C] = 5;
    func_00175700(p);
    func_00230670(p, q);
    hit = (s8)p[0x150];
    if (hit != 3) {
        *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
        *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
        *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
        n = func_00118FA8(*(f32 *)(p + 0x430));
        t = (f32)n;
        if (*(f32 *)(p + 0x38) <= t)
            *(f32 *)(p + 0x38) = t;
        else
            return;
    }
    p[0x40D] = 0;
    p[0x40C] = 0;
    p[0x33B] = 0;
    p[0x33C] = 0;
    p[7]++;
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x5C) = 0;
    *(u32 *)(p + 0x60) = 0x41092492;
    *(u32 *)(p + 0x6C) = 0xBF892492;
}
