typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef float f32;

extern int func_00175700(u8 *);

void residual_001F89E0(u8 *p)
{
    func_00175700(p);
    if ((s8)p[0x151] != 0) {
        p[6]++;
        p[0x151] = 0;
        p[0x20D] = 0;
        *(f32 *)(p + 0x5C) = 20.0f / 3.0f;
        *(f32 *)(p + 0x68) = 0;
        if (p[0x1E6] == 0) {
            *(f32 *)(p + 0x5C) = -(20.0f / 3.0f);
            *(f32 *)(p + 0x68) = 0;
        }
        *(f32 *)(p + 0x60) = 6.4285712242126465f;
        *(f32 *)(p + 0x6C) = -0.8035714030265808f;
    }
}
