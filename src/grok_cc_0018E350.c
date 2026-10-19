typedef unsigned char u8;
typedef unsigned short u16;

extern void func_0011D8F8(u8 *, int, int);
extern void func_0018E6C0(u8 *);
extern void func_001757E0(u8 *, int, int);

void func_0018E350(u8 *p, u8 *q)
{
    int five;
    func_0011D8F8(p + 0x370, 0, 8);
    p[0x24A] = 0x78;
    p[0x247] = 0xF;
    p[0x248] = 0;
    p[0x1B7] = q[0x1B7];
    p[0x23E] = 5;
    {
        long five64 = 5;
        if (p[0x23F] != (u8)five64)
            p[0x23D] = 0;
        p[0x23C] = (u8)five64;
    }
    if (p[0x20D] != 2) {
        func_0018E6C0(p);
        return;
    }
    *(u16 *)(p + 0x1C) = 10;
    func_001757E0(p, 13, 16);
}
