typedef unsigned char u8;

extern void (*jtbl_00472CC0[])(u8 *, u8 *, u8 *);

/* Dispatch head only (0x28 bytes). The catalog row's 0x22C also covers the
 * separate case-0 function at 0x003A3970 (own prologue after two pad nops). */
void func_003A3940(u8 *p)
{
    u8 *q = *(u8 **)(p + 0x18);
    jtbl_00472CC0[p[4]](p, q, q + 0x2B8);
}
