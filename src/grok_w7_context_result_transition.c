typedef unsigned char u8;
typedef signed char s8;
typedef signed int s32;

extern int func_00175700(u8 *);
extern void func_001E3210(u8 *, int);
extern int func_003B4040(u8 *, int);

void func_00306D20(u8 *p, u8 *context)
{
    int result;

    func_00175700(p);
    if (*(s8 *)(p + 0x150) == 0)
        return;

    *(s8 *)(p + 0x150) = 0;
    result = func_003B4040(p, (u8)(p[7] * 3 + p[0x1B7]));
    *(s32 *)(p + 0x14) = result;
    if (result == 0)
        context[4] = 1;

    p[6]++;
    func_001E3210(p, 20);
    func_001E3210(p, 37);
}
