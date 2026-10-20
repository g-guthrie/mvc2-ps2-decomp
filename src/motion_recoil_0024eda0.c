typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef float f32;

extern int func_00175700(u8 *);
extern void func_00183D90(u8 *);
extern void func_001843A0(u8 *);

void func_0024EDA0(u8 *p)
{
    f32 *s1;
    f32 *s2;

    if (p[6] == 0) {
        func_00175700(p);
        if (*(s8 *)(p + 0x151) == 0)
            return;
        p[6]++;
        *(f32 *)(p + 0x5C) = p[0x1E6] ? 14.166666f : -14.166666f;
        *(f32 *)(p + 0x68) = p[0x1E6] ? -0.729166627f : 0.729166627f;
        return;
    }
    func_00183D90(p);
    if (*(s8 *)(p + 0x151) != 0)
        *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    s2 = (f32 *)(p + 0x68);
    s1 = (f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    if ((s8)func_00175700(p) < 0) {
        *s1 = 0.0f;
        *(f32 *)(p + 0x60) = 0.0f;
        *s2 = 0.0f;
        *(f32 *)(p + 0x6C) = 0.0f;
        func_001843A0(p);
    }
}
