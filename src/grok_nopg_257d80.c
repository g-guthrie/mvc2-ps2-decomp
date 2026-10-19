/* Metrowerks 3.0: ./try.sh src/grok_nopg_257d80.c "-O4,p -sdatathreshold 0" */
typedef unsigned char u8;
typedef signed char s8;

extern int func_00175700(u8 *);
extern void func_0036A930(u8 *, int, int, int);
extern void func_001843A0(u8 *);

void residual_00257D80(u8 *p)
{
    if (*(s8 *)(p + 434)) {
        p[7]++;
        func_0036A930(p, 3, 0, 0);
    }
    if ((s8)func_00175700(p) < 0)
        func_001843A0(p);
}
