typedef unsigned char u8;
typedef unsigned short u16;
extern void func_00303950(u8 *);
void func_00300C10(u8 *p)
{
    u16 *timer = (u16 *)(p + 0x2b8);
    u16 remaining;
    if (p[0x215] == 0)
        return;
    if (p[5] != 0)
        return;
    remaining = timer[2];
    remaining -= 1;
    timer[2] = remaining;
    if (remaining != 0)
        return;
    if (*(u8 *)(p + 0x1e4) == 21)
        timer[2] = 1;
    else
        func_00303950(p);
}
