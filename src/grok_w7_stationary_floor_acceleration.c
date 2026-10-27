typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;

extern int func_00175700(u8 *);
extern u8 *func_001D45D0(u8 *, u8);

void func_002E6AB0(u8 *p)
{
    u8 *q = p + 0x2B8;
    p[0x1FE] = 1;
    p[0x206] = 3;
    func_00175700(p);
    if (*(s8 *)(p + 0x151) != 0) {
        p[7]++;
        p[0x20D] = 2;
        *(u32 *)(p + 0x60) = 0x41DEDB6D;
        *(u32 *)(p + 0x6C) = 0xBF2B6DB6;
        q[7] = 0;
        func_001D45D0(p, 3);
    }
}
