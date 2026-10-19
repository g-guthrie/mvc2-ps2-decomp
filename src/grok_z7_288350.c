typedef unsigned char u8;

extern void func_00288EE0(u8 *);
extern void func_002883A0(u8 *);

void residual_00288350(u8 *p)
{
    p[6]++;
    if (p[0x20] == 0)
        func_00288EE0(p);
    func_002883A0(p);
}
