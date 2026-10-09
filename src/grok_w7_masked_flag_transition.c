typedef unsigned char u8;
typedef unsigned short u16;
extern void func_002F4390(u8 *, u8 *, u8);
extern int func_00175700(u8 *);
void func_002F4570(u8 *p, u8 *q)
{
    if ((*(u16 *)(p + 0x35e) & 0x3c00) != 0) {
        u16 flags = *(u16 *)(p + 0x362);
        if ((flags & 0x300) != 0)
            func_002F4390(p, q, 0);
        else if ((flags & 0x60) != 0)
            func_002F4390(p, q, 1);
    }
    func_00175700(p);
}
