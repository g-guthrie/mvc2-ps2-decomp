/* Metrowerks 3.0: ./try.sh src/grok_nopg_29a6a0.c "-O4,p -sdatathreshold 0" */
typedef unsigned char u8;
typedef signed char s8;

extern void func_001266A0(u8 *, int, int);
extern int func_00175700(u8 *);
extern void func_001843A0(u8 *);

void residual_0029A6A0(u8 *p)
{
    u8 *q;

    if (*(s8 *)(p + 337)) {
        p[337] = 0;
        q = *(u8 **)(p + 476);
        *(u8 **)(q + 456) = p;
        q[522] = 1;
        q[525] = 2;
        func_001266A0(p, 0, 0);
        q[437] = 32;
        q[486] = p[486];
    }
    if ((s8)func_00175700(p) < 0)
        func_001843A0(p);
}
