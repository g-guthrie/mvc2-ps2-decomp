/* Metrowerks 3.0: ./try.sh src/grok_nopb_25e240.c "-O4,p -sdatathreshold 0" */
typedef unsigned char u8;

extern void func_00185490(u8 *);
extern int func_001757E0(u8 *, int, int);

void func_0025E240(u8 *p)
{
    p[7]++;
    func_00185490(p);
    func_001757E0(p, 19, 0);
}
