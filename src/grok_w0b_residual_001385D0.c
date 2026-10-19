typedef unsigned char u8;
typedef signed short s16;

extern void func_00138350(u8 *, int);

void residual_001385D0(u8 *p)
{
    *(s16 *)(p + 0x1C) -= 1;
    if (*(s16 *)(p + 0x1C) > 0)
        return;
    p[4]++;
    *(s16 *)(p + 0x1C) = 5;
    func_00138350(p, 0);
    p[0x21]--;
}
