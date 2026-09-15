typedef unsigned char u8;
typedef signed char s8;
typedef signed int s32;
typedef float f32;

#define F(p, o) (*(f32 *)((u8 *)(p) + (o)))

extern int func_00175700(u8 *);
extern void func_001843A0(u8 *);
extern void func_003B38F0(u8 *, int, int);

void func_002EBB00(u8 *p)
{
    if (!p[533]) {
        F(p, 56) += F(p, 96);
        F(p, 96) += F(p, 108);
    }
    {
        f32 lim = F(p, 1072);
        if (!(lim <= F(p, 56)))
            *(f32 *)(p + 56) = lim;
    }
}

void func_00301A00(u8 *p)
{
    if ((s8)func_00175700(p) < 0)
        func_001843A0(p);
    else if (*(s8 *)(p + 0x151)) {
        p[0x151] = 0;
        func_003B38F0(p, 1, 4);
    }
}
