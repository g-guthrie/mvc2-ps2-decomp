extern unsigned short dat_0c2f8918;
extern unsigned short dat_0c2f891a;
extern unsigned short dat_0c2f891c;
extern unsigned short dat_0c2f891e;
extern void func_0c1c1604(void);
extern void func_0c1c168a(void);
extern void func_0c1c260c(void);
extern void func_0c1c2894(void);
extern void func_0c1c3568(void);

void func_0c025b68(void)
{
    dat_0c2f8918 = dat_0c2f891a = dat_0c2f891c = dat_0c2f891e = 0;
    func_0c1c1604();
    func_0c1c168a();
    func_0c1c260c();
    func_0c1c2894();
    func_0c1c3568();
}

void func_0c025b98(void)
{
    dat_0c2f8918 += 0x1000;
    dat_0c2f891a += 0x800;
    dat_0c2f891c += 0x400;
    dat_0c2f891e += 0x200;
}
