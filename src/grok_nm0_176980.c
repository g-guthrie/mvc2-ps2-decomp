typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;

extern void func_0018CEA0(u8 *);
extern int func_00175700(u8 *);
extern void func_001843A0(u8 *);

void residual_00176980(u8 *p)
{
    if (p[6] == 0) {
        p[6]++;
        *(u32 *)(p + 0x60) = 0;
        *(u32 *)(p + 0x6C) = 0;
        return;
    }
    func_0018CEA0(p);
    if ((s8)func_00175700(p) < 0)
        func_001843A0(p);
}
