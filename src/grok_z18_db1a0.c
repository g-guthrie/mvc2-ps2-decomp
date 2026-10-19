typedef unsigned char u8;
typedef unsigned short u16;

extern int func_00175700(u8 *);
extern void func_001DB2E0(u8 *);

void residual_001DB1A0(u8 *p)
{
    u8 *owner = *(u8 **)(p + 0x18);
    func_00175700(p);
    if (*(u16 *)(owner + 0x168) != *(u16 *)(p + 0x1C))
        func_001DB2E0(p);
}
