typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef float f32;

extern int func_00175700(u8 *);
extern void func_0015F8D0(u8 *);
extern void func_00274FB0(u8 *);

void func_00274EF0(u8 *p)
{
    func_00175700(p);
    *(f32 *)(p + 0x5C) = 0;
    *(f32 *)(p + 0x60) = 0;
    *(f32 *)(p + 0x68) = 0;
    *(f32 *)(p + 0x6C) = 0;
    if ((s8)p[0x151] == 0) {
        func_0015F8D0(p);
        p[6]++;
        *(f32 *)(p + 0x5C) = p[0x1E6] ? 18.333332061767578f : -18.333332061767578f;
        *(f32 *)(p + 0x68) = p[0x1E6] ? -0.625f : 0.625f;
        *(s16 *)(p + 0x1C) = 0xC;
        func_00274FB0(p);
    }
}
