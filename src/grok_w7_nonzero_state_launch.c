typedef unsigned char u8;
typedef unsigned int u32;

extern int func_00175700(u8 *);

void func_002E5600(u8 *p)
{
    func_00175700(p);
    if (p[0x15B] != 0) {
        p[6]++;
        *(u32 *)(p + 0x5C) = 0;
        *(u32 *)(p + 0x68) = 0;
        *(u32 *)(p + 0x60) = 0xC1892492;
        *(u32 *)(p + 0x6C) = 0xC0092492;
    }
}
