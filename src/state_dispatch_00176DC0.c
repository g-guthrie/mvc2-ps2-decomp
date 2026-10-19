typedef unsigned char u8;
typedef void (*StateHandler)(u8 *);

/* Native uses a GP-relative reference for this nearby callback table. */
extern const StateHandler jtbl_004BF4C0[4] __attribute__((section(".sdata")));
extern void func_00176E20(u8 *);

void func_00176DC0(u8 *p)
{
    p[0x201] = 2;
    p[0x1B1] = 0;
    jtbl_004BF4C0[p[6]](p);
}

void func_00176DF0(u8 *p)
{
    p[6] += 1;
    *(float *)(p + 0x5C) = *(float *)(p + 0x22C);
    *(float *)(p + 0x60) = *(float *)(p + 0x230);
    *(unsigned int *)(p + 0x68) = 0;
    func_00176E20(p);
}
