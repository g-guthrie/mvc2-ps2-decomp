/* Shinobi hardware init/finish group at 0x0c206414 (syHw variant not in the bundled shinobi.lib). */
typedef struct {
    volatile long *addr;
    long value;
} HwRegInit;

extern long dat_0c2381cc;
extern long dat_0c269844;
extern long dat_0c2381c8;
extern HwRegInit dat_0c2381d0[];

extern void func_0c210720(long a, long b);
extern void func_0c20b58c(void);
extern void func_0c20acac(long a);
extern void func_0c206540(void);
extern void func_0c210140(void);
extern void func_0c20b6f8(int a);
extern void func_0c20b63a(void);

void func_0c20649e(void);
void func_0c2064ae(void);
void func_0c2064c8(void);

void func_0c206414(void)
{
    func_0c2064c8();
    func_0c210720(dat_0c2381cc, dat_0c269844);
    func_0c20b58c();
    ((void (*)(long))((unsigned long)func_0c20acac | 0xa0000000))(dat_0c2381c8);
    func_0c206540();
}

void func_0c20643e(void)
{
    func_0c210720(dat_0c2381cc, dat_0c269844);
    func_0c206540();
}

void func_0c206452(void)
{
    func_0c210140();
    func_0c20b6f8(0);
}

void func_0c206462(void)
{
    int mask = _builtin_get_imask();
    _builtin_set_imask(15);
    func_0c20b63a();
    func_0c20649e();
    _builtin_set_imask(mask);
}

void func_0c20649e(void)
{
    void (*fn)(void) = func_0c2064ae;
    unsigned long a = (unsigned long)fn | 0xa0000000;
    ((void (*)(void))a)();
}

void func_0c2064ae(void)
{
    volatile long *ccr = (volatile long *)0xff00001c;
    long p;
    *ccr = 0;
    for (p = 0xf4000000; p < 0xf4004000; p += 32)
        *(volatile long *)p = 0;
    *ccr = 0x800;
    *ccr = 0;
}

void func_0c2064c8(void)
{
    HwRegInit *e;
    *(volatile short *)0xffd00000 = 0;
    *(volatile short *)0xffd00004 = 0;
    *(volatile short *)0xffd00008 = 0;
    *(volatile short *)0xffd0000c = 0;
    e = dat_0c2381d0;
    for (;;) {
        if (!e->addr) break;
        *e->addr = e->value;
        e++;
    }
}
