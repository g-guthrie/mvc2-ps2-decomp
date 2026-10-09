typedef unsigned char u8;
typedef unsigned short u16;

extern void func_002F4390(u8 *, u8 *, u8);
extern void func_002F4A50(u8 *, void *, int);

void func_002F4360(u8 *p, u8 *q)
{
    *(u16 *)(p + 862) = *(u16 *)(q + 20);
    p[486] ^= q[17];
    *(u16 *)(p + 320) = p[486];
    func_002F4390(p, q, q[22]);
}

void func_002F4A20(u8 *p, u8 *q)
{
    *(u16 *)(p + 862) = *(u16 *)(q + 20);
    p[486] ^= q[17];
    *(u16 *)(p + 320) = p[486];
    func_002F4A50(p, q, q[22]);
}
