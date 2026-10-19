typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef float f32;

extern int func_00175700(u8 *);
extern void func_001843A0(u8 *);

void residual_00310B70(u8 *p)
{
    if ((s8)func_00175700(p) < 0) {
        func_001843A0(p);
        return;
    }
    {
        s8 a = *(s8 *)(p + 0x151);
        if (a) {
            if (*(s16 *)(p + 0x140))
                *(s8 *)(p + 0x151) = -a;
            *(f32 *)(p + 0x34) -= (f32)*(s8 *)(p + 0x151);
            *(s8 *)(p + 0x151) = 0;
        }
    }
}
