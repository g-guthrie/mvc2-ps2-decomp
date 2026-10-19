typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;

extern int func_001757E0(u8 *, int, int);
extern void func_003888B0(u8 *, int);
extern void func_0028ACE0(u8 *, u8 *);

void func_0028AC40(u8 *p, u8 *e)
{
    e[0x18]++;
    *(s16 *)(p + 0x1C) = 6;
    e[0x19] = 0;
    if (p[0x1E6] == 0)
        *(u32 *)(p + 0x5C) = 0xC1555555;
    else
        *(u32 *)(p + 0x5C) = 0x41555555;
    *(u32 *)(p + 0x68) = 0;
    func_001757E0(p, 0x16, 8);
    func_003888B0(p, 2);
    func_0028ACE0(p, e);
}
