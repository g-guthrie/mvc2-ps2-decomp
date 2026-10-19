typedef unsigned char u8;
typedef signed char s8;
typedef float f32;

extern int func_00175700(u8 *);

void func_00263F10(u8 *p)
{
    func_00175700(p);
    if ((s8)p[0x151] != 0) {
        p[0x151] = 0;
        p[6]++;
        *(int *)(p + 0x5C) = 0;
        *(int *)(p + 0x60) = 0;
        *(int *)(p + 0x68) = 0;
        *(int *)(p + 0x6C) = 0;
        *(f32 *)(p + 0x5C) = p[0x1E6] ? 15.833333015441895f : -15.833333015441895f;
        *(f32 *)(p + 0x34) += p[0x1E6] ? 26.66666603088379f : -26.66666603088379f;
    }
}
