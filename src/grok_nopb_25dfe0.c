/* Metrowerks 3.0: ./try.sh src/grok_nopb_25dfe0.c "-O4,p -sdatathreshold 0" */
typedef unsigned char u8;

extern void func_001B0F40(u8 *, int);
extern int func_001757E0(u8 *, int, int);

void func_0025DFE0(u8 *p)
{
    p[6]++;
    p[316] = 1;
    func_001B0F40(p, 13);
    func_001757E0(p, 18, 0);
}
