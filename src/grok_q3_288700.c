/* Metrowerks 3.0: ./try.sh src/grok_q3_288700.c "-O4,p -sdatathreshold 0" */
typedef unsigned char u8;

extern void func_00175C00(u8 *, int);
extern void func_00176160(u8 *, int, int, int);
extern void func_001757E0(u8 *, int, int);
extern void func_00288770(u8 *);

void residual_00288700(u8 *p)
{
    p[7]++;
    func_00175C00(p, 0);
    func_00176160(p, 7, 0x57 * p[0x25] + 0x39, 1);
    func_001757E0(p, 0x13, 8);
    func_00288770(p);
}
