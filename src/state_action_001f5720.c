typedef unsigned char u8;
typedef signed char s8;
typedef signed int s32;

void func_001F5720(u8 *p)
{
    extern s32 func_00175700(u8 *);
    extern void func_001843A0(u8 *);
    if ((s8)func_00175700(p) < 0)
        func_001843A0(p);
}
