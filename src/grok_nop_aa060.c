typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;

extern int func_001757E0(u8 *, int, int);
extern void func_001AA0D0(u8 *, u8 *);

void func_001AA060(u8 *p, u8 *q)
{
    p[7]++;
    *(u32 *)(p + 92) = 0;
    *(u32 *)(p + 104) = 0;
    *(u32 *)(p + 96) = 0;
    *(u32 *)(p + 108) = 0;
    *(s16 *)(p + 320) ^= 1;
    func_001757E0(p, 23, 14);
    func_001AA0D0(p, q);
}
