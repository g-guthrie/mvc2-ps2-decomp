/* Placeholder: actor phase bounds and DATA callback signatures remain unproved. */
typedef unsigned char u8;
typedef signed char s8;
extern void (*jtbl_00476010[])(u8 *, u8 *);
void func_003C7480(u8 *p, u8 *q)
{
    p[0x24] = *(s8 *)(q + 0x24);
    jtbl_00476010[36 + p[5]](p, q);
}
