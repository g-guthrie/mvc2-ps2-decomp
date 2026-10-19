typedef unsigned char u8;
typedef signed char s8;

extern int func_00175700(u8 *);
extern void func_00199DC0(u8 *);
extern void func_001994B0(u8 *);
extern void func_001E3210(u8 *, int);

void residual_00199CF0(u8 *p)
{
    if ((s8)func_00175700(p) < 0) {
        func_00199DC0(p);
        return;
    }
    if (*(s8 *)(p + 0x151) != 0) {
        *(s8 *)(p + 0x151) = 0;
        func_001994B0(p);
        func_001E3210(p, 0x20);
    }
}
