typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;

extern void func_0021D280(u8 *);
extern void func_0018A990(u8 *, u8 *);

void func_0021D400(u8 *p)
{
    u8 *s0;
    func_0021D280(p);
    if (p[0x1E4] != 0x15)
        return;
    if (p[0x1FD] != 1)
        return;
    if (p[6] != 2)
        return;
    if (p[5] != 0)
        return;
    if (*(u16 *)(p + 0x2DA) == 0)
        return;
    s0 = p + 0x2B8;
    if ((*(u16 *)(p + 0x35E) & 0x360) == 0)
        return;
    func_0018A990(s0, p + 0x388);
    if (p[0x1B7]) {
        p[6] = 0;
        *(u32 *)(p + 0x5C) = 0;
        *(u32 *)(p + 0x60) = 0;
        *(u32 *)(p + 0x68) = 0;
        *(u32 *)(p + 0x6C) = 0;
        *(s16 *)(s0 + 0x22) -= 1;
    }
}
