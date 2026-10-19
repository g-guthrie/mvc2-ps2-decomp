typedef unsigned char u8;
typedef signed char s8;
typedef signed int s32;
typedef float f32;

extern void func_00183D90(u8 *);
extern s32 func_00175700(u8 *);
extern void func_001843A0(u8 *);
extern void func_0029C450(u8 *);

void func_0029C360(u8 *p)
{
    f32 f20;
    func_00183D90(p);
    f20 = *(f32 *)(p + 0x5C);
    if (p[6] == 2) {
        *(f32 *)(p + 0x34) += f20;
        *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
        *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
        *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
        if ((s8)func_00175700(p) < 0) {
            func_001843A0(p);
            return;
        }
        {
            f32 z = 0.0f;
            f32 f0 = *(f32 *)(p + 0x5C);
            if (f0 != z) {
                if (f0 * f20 < z) {
                    *(f32 *)(p + 0x68) = z;
                    *(f32 *)(p + 0x5C) = z;
                }
            }
        }
    } else {
        func_0029C450(p);
    }
}
