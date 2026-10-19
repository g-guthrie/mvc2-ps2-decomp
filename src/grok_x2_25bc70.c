typedef unsigned char u8;
typedef signed char s8;
typedef float f32;

extern int func_00175700(u8 *);

void func_0025BC70(u8 *p)
{
    func_00175700(p);
    if ((s8)p[0x151] != 0) {
        p[6]++;
        p[0x151] = 0;
        *(int *)(p + 0x5C) = 0;
        *(int *)(p + 0x60) = 0;
        *(int *)(p + 0x68) = 0;
        *(int *)(p + 0x6C) = 0;
        *(f32 *)(p + 0x6C) = -1.6071428060531616f;
    }
}
