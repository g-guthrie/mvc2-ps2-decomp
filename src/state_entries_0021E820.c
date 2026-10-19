typedef unsigned char u8;
typedef signed char s8;
typedef float f32;

extern int func_00175700(void *);

void func_0021E820(u8 *p)
{
    func_00175700(p);
    if ((s8)p[0x151] == 0) {
        p[6]++;
        *(f32 *)(p + 0x5C) = 0;
        *(f32 *)(p + 0x60) = 0;
        *(f32 *)(p + 0x68) = 0;
        *(f32 *)(p + 0x6C) = 0;
        *(f32 *)(p + 0x5C) = p[0x1E6] ? (50.0f / 3.0f) : -(50.0f / 3.0f);
    }
}
