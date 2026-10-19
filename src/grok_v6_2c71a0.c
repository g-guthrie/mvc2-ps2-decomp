typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef float f32;

extern int func_00175700(u8 *);

void residual_002C71A0(u8 *p)
{
    func_00175700(p);
    if ((s8)p[0x151] == 0) {
        p[6]++;
        *(f32 *)(p + 0x5C) = 0;
        *(f32 *)(p + 0x60) = 0;
        *(f32 *)(p + 0x68) = 0;
        *(f32 *)(p + 0x6C) = 0;
        *(f32 *)(p + 0x5C) = p[0x1E6] ? -15.833333015441895f : 15.833333015441895f;
        *(f32 *)(p + 0x68) = p[0x1E6] ? 0.3125f : -0.3125f;
        *(s16 *)(p + 0x1C) = 0x1C;
    }
}
