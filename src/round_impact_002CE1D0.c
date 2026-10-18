typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef union {float value;u32 bits;} FloatBits;
#define F(p, o) (((FloatBits *)((u8 *)(p) + (o)))->bits)
extern int func_00175700(u8 *);
extern int func_001757E0(u8 *, int, int);
void func_002CE1D0(u8 *p)
{
    if ((s8)func_00175700(p) < 0) {
        p[6]++;
        F(p, 92) = 0;
        F(p, 104) = 0;
        F(p, 96) = 0xC0092492;
        F(p, 108) = 0xBF4DB6DB;
        func_001757E0(p, 21, 5);
    }
}
