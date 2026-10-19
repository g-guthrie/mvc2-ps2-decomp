typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern void func_00328990(u8 *);
extern void func_00328C10(u8 *);
extern void func_00328E60(u8 *);
extern void func_003294B0(u8 *);

void func_0018E810(u8 *p, u8 *q)
{
    u8 mode;
    u8 dest;
    mode = (u8)(q[0x1C0] & 0xF);
    if (mode == 0) {
        mode = (u8)(p[0x245] & 7);
        if (mode == 0)
            return;
    }
    if (mode & 8)
        mode = 1;
    if (mode == 6)
        dest = 4;
    else if (mode == 3)
        dest = 3;
    else if (mode == 2)
        dest = 2;
    else if (mode == 1)
        dest = 1;
    else
        return;
    p[0x23E] = dest;
    if (p[0x23F] != dest)
        p[0x23D] = 0;
    if ((s8)p[0x23D] >= 4)
        return;
    if (dest == 4)
        func_003294B0(p);
    else if (dest == 3)
        func_00328E60(p);
    else if (dest == 2)
        func_00328C10(p);
    else if (dest == 1)
        func_00328990(p);
}
