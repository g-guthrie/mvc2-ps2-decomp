typedef unsigned char u8;
typedef signed char s8;
typedef float f32;

extern int func_00175700(u8 *);
extern void func_002D7030(u8 *);

void func_002D6F70(u8 *p)
{
    func_00175700(p);
    if ((s8)p[0x151] == 0) {
        *(f32 *)(p + 0x5C) = 0;
        *(f32 *)(p + 0x60) = 0;
        *(f32 *)(p + 0x68) = 0;
        *(f32 *)(p + 0x6C) = 0;
        p[6]++;
        *(f32 *)(p + 0x60) = 0.8333333134651184f;
        *(f32 *)(p + 0x6C) = -0.15625f;
        *(f32 *)(p + 0x5C) = p[0x1E6] ? -11.666666030883789f : 11.666666030883789f;
        *(f32 *)(p + 0x68) = p[0x1E6] ? 0.1041666641831398f : -0.1041666641831398f;
        func_002D7030(p);
    }
}
