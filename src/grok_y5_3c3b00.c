typedef unsigned char u8;
typedef signed char s8;

typedef unsigned int u32;
extern const u32 jtbl_00475DD0[11];

/* Provisional: callback-table ABI and state bounds remain unresolved. */
void func_003C3B00(u8 *p, u8 *q)
{
    ((void (*)(u8 *, u8 *))jtbl_00475DD0[4 + p[4]])(p, q);
    p[0x24] = (s8)q[0x24] + (s8)p[0x31];
    if ((s8)p[0x24] > 7)
        p[0x24] = 7;
    if ((s8)p[0x24] < 0)
        p[0x24] = 0;
}
