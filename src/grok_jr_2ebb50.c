typedef unsigned char u8;
/* Entries differ in arity (func_002EB850(p, context), func_002EBAE0(p)),
 * so the table is typed with an unprototyped pointer compatible with both. */
typedef void (*DispatchFn)();

extern const DispatchFn jtbl_004C1188[2] __attribute__((section(".sdata")));

void func_002EBB50(u8 *p, u8 *context)
{
    if (p[0x20D] == 2)
        p[6] = 1;
    jtbl_004C1188[p[6]](p, context);
}
