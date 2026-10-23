typedef unsigned char u8;
typedef signed char s8;
typedef float f32;

extern int func_00175700(u8 *);

void func_00198030(u8 *p, u8 *owner_unused)
{
    func_00175700(p);
    if ((s8)p[0x151] == 0)
        p[5]++;
    *(f32 *)(p + 0x38) -= 10.714284896850586f;
}
