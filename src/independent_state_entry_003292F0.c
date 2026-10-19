typedef unsigned char u8;
typedef signed short s16;
extern void func_00329310(u8 *);
void func_003292F0(u8 *p)
{
    p[4]++;
    *(s16 *)(p + 0x1C) = 0;
    *(s16 *)(p + 0x1E) = 0;
    p[0x22] = 0;
    func_00329310(p);
}
