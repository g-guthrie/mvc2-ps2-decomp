typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef float f32;

extern int func_00175700(u8 *);

void residual_002A2470(u8 *p)
{
    func_00175700(p);
    if ((s8)p[0x151] != 0) {
        p[6]++;
        p[0x151] = 0;
        *(s16 *)(p + 0x1C) = 0x12;
        *(f32 *)(p + 0x5C) = p[0x1E6] ? 19.16666603088379f : -19.16666603088379f;
        *(f32 *)(p + 0x68) = p[0x1E6] ? -0.7291666269302368f : 0.7291666269302368f;
        *(f32 *)(p + 0x60) = 9.64285659790039f;
        *(f32 *)(p + 0x6C) = -1.0044642686843872f;
    }
}
