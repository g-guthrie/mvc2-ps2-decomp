/* Metrowerks 3.0: ./try.sh src/grok_q2_c1010.c "-O4,p -sdatathreshold 0" */
typedef unsigned char u8;

extern void func_001C1330(u8 *, u8 *);
extern void func_001C1080(u8 *, u8 *);

void residual_001C1010(u8 *p, u8 *q)
{
    p[5]++;
    p[0x24] = 8;
    p[0x14C] = 0x30;
    p[0x14D] = 0x30;
    p[0x14E] = 0x10;
    p[0x14F] = 0x10;
    func_001C1330(p, q);
    func_001C1080(p, q);
}
