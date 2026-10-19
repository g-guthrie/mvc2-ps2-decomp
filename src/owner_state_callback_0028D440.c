typedef unsigned char u8;
typedef unsigned int u32;
extern int func_00175700(u8 *);
extern void func_00126400(void);
extern void func_001E3A40(u8 *);

void func_0028D440(u8 *p)
{
    u8 *child;
    func_00175700(p);
    if (*(signed char *)(p + 0x151) == 1) {
        ++p[6];
        p[0x151] = 0;
        child = *(u8 **)(p + 0x1DC);
        *(u32 *)(child + 0x1C8) = (u32)p;
        child[0x1E6] = p[0x1E6] ^ 1;
        child[0x1B5] = 0x20;
        child[0x20A] = 1;
        func_00126400();
        func_001E3A40(p);
    }
}
