typedef unsigned char u8;
typedef signed short s16;
extern void func_003298B0(int, int, int);
void func_00328350(u8 *p)
{
    p[4]++;
    *(s16 *)(p + 0x1C) = 0x5C;
    func_003298B0(-1, 0x20, 1);
}
