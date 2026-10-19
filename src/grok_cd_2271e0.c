typedef unsigned char u8;
typedef signed char s8;
typedef float f32;

extern s8 func_00175700(u8 *);
extern void func_0022C5D0(u8 *);
extern int func_00118FA8(f32);
extern f32 data_u32_004517C0[];

void func_002271E0(u8 *p)
{
    f32 z;
    if ((s8)func_00175700(p) >= 0) {
    z = 0.0f;
    {
        s8 hit = *(s8 *)(p + 0x151);
        f32 hf = (f32)hit;
        if (hf > z) {
            p[0x151] = 0;
            z = data_u32_004517C0[func_00118FA8(hf)];
            if (!p[0x1E6])
                z = -z;
            *(f32 *)(p + 0x34) += z;
        } else {
            *(f32 *)(p + 0x5C) = z;
            *(f32 *)(p + 0x68) = z;
        }
    }
    } else
        func_0022C5D0(p);
}
