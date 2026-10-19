typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;

extern u8 *D_004C2794;
extern void func_003282F0(u8 *);

void func_00328290(u8 *p)
{
    u8 *q = *(u8 **)(p + 0x18);
    if (*(s16 *)(q + 0x434) || q[0x425]) {
        p[4] = 2;
        return;
    }
    *(s16 *)(p + 0x1c) = 0x40;
    *(u16 *)(D_004C2794 + 0x3c) = 0xaaaa;
    p[4]++;
    func_003282F0(p);
}
