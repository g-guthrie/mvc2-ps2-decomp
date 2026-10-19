typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef float f32;

extern int func_00175700(u8 *);

void func_002FD7D0(u8 *p)
{
    func_00175700(p);
    if ((s8)p[0x151] == 0) {
        p[6]++;
        *(f32 *)(p + 0x5C) = p[0x1E6] ? -13.333333015441895f : 13.333333015441895f;
        *(f32 *)(p + 0x5C) = 16.66666603088379f;
        *(f32 *)(p + 0x68) = 0;
        *(f32 *)(p + 0x60) = 6.4285712242126465f;
        *(f32 *)(p + 0x6C) = -0.6026785373687744f;
        if (*(s16 *)(p + 0x140))
            *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
    }
}
