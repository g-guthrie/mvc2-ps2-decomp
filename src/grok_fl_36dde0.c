typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef double f64;

extern int func_00175700(u8 *);
extern f64 litodp(s32);
extern f64 dpmul(f64, f64);
extern f64 dpdiv(f64, f64);
extern f64 dpadd(f64, f64);
extern u32 dptoul(f64);
extern f32 func_00417440(u32);

void func_0036DDE0(u8 *p, u8 *q)
{
    u8 *flag = q + 0x2B8;
    if (*(f32 *)(p + 0x50) > 1.0f) {
        *(f32 *)(p + 0x50) = 1.0f;
        *(f32 *)(p + 0x54) = 1.0f;
    } else {
        *(f32 *)(p + 0x50) += 0.039999999105930328369f;
        *(f32 *)(p + 0x54) += 0.039999999105930328369f;
    }
    func_00175700(p);
    {
        s16 c = *(s16 *)(p + 0x1C);
        *(s16 *)(p + 0x1C) = c - 1;
        if (c == 0) {
            p[4]++;
            p[0x13C] = 0;
            *flag = 0;
            return;
        }
    }
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    *(f32 *)(p + 0x38) += 5.0f * func_00417440((u32)dptoul(dpadd(0.5, dpdiv(dpmul(65536.0, litodp(*(s16 *)(p + 0x1E))), 360.0))) & 0xFFFF);
    {
        s16 ang = *(s16 *)(p + 0x1E);
        ang -= 6;
        *(s16 *)(p + 0x1E) = ang;
        if (ang == 0)
            *(s16 *)(p + 0x1E) = 0x168;
    }
}
