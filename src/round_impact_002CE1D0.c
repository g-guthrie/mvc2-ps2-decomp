typedef unsigned char u8;
typedef signed char s8;
typedef int s32;
#define I(p, o) (*(s32 *)((u8 *)(p) + (o)))
extern int func_00175700(u8 *);
extern int func_001757E0(u8 *, int, int);
void func_002CE1D0(u8 *p)
{
    if ((s8)func_00175700(p) < 0) {
        p[6]++;
        I(p, 92) = 0;
        I(p, 104) = 0;
        I(p, 96) = (s32)0xC0092492;
        I(p, 108) = (s32)0xBF4DB6DB;
        func_001757E0(p, 21, 5);
    }
}
