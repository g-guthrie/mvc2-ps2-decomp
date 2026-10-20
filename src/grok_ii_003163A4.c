/* ./try.sh src/grok_ii_003163A4.c "-O4,p -sdatathreshold 8" */
typedef unsigned char u8;
typedef signed char s8;

extern int func_00175700(u8 *);
extern void func_001DD8A0(u8 *, int, int);

void residual_003163B0(u8 *p)
{
    func_00175700(p);
    if ((s8)p[0x151] == 0) {
        p[6]++;
        func_001DD8A0(p, 0xF, 0);
    }
}
