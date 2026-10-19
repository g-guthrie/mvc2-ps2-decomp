typedef unsigned char u8;
typedef signed short s16;

extern int func_001757E0(u8 *, int, int);

void func_002D71E0(u8 *p)
{
    p[6]++;
    p[0x13C] = 1;
    *(s16 *)(p + 0x1C) = 60;
    func_001757E0(p, 18, 0);
}
