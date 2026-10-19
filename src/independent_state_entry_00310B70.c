typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef float f32;

extern int func_00175700(u8 *);
extern void func_001843A0(u8 *);

void func_00310B70(u8 *p)
{
    if ((s8)func_00175700(p) < 0) {
        func_001843A0(p);
    } else if ((s8)p[0x151] != 0) {
        if (*(s16 *)(p + 0x140) != 0)
            p[0x151] = (u8)-(s8)p[0x151];
        *(f32 *)(p + 0x34) -= (f32)(s8)p[0x151];
        p[0x151] = 0;
    }
}
