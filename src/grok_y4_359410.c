typedef unsigned char u8;
typedef signed char s8;

extern void (*D_004630F0[])(u8 *, u8 *);
extern void func_003593F0(u8 *, u8 *);

void func_00359410(u8 *p, u8 *q)
{
    u8 *o = *(u8 **)(p + 0x18);
    o[0x2C6] = 0;
    q[0xD] = 0;
    q[0xE] = 0;
    if (p[0x21] != o[0x2C7]) {
        p[0x21] = o[0x2C7];
        p[5] = 0;
    }
    if (o[4] >= 2)
        p[4]++;
    else if ((s8)o[0x13C] == 0)
        p[0x13C] = 0;
    else {
        D_004630F0[p[0x21]](p, q);
        func_003593F0(p, q);
    }
}
