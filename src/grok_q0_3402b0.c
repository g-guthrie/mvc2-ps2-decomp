typedef unsigned char u8;
typedef signed short s16;

extern void func_001E3710(u8 *, int);

void func_003402B0(u8 *p)
{
    p[4]++;
    *(s16 *)(p + 0x1C) = 0x32;
    if (p[0x20] == 8) {
        func_001E3710(p, 0x30);
        func_001E3710(p, 0x49);
    }
}
