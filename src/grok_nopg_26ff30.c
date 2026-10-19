/* Metrowerks 3.0: ./try.sh src/grok_nopg_26ff30.c "-O4,p -sdatathreshold 0" */
typedef unsigned char u8;
typedef signed char s8;

extern int func_00175700(u8 *);
extern void func_001757E0(u8 *, int, int);
extern void func_001B7C70(u8 *, int);

void residual_0026FF30(u8 *p)
{
    if ((s8)func_00175700(p) < 0) {
        p[6]++;
        func_001757E0(p, 7, 4);
    }
    if (*(s8 *)(p + 337)) {
        p[337] = 0;
        func_001B7C70(p, 0);
        if (*(s8 *)(p + 434))
            func_001B7C70(p, 1);
    }
}
