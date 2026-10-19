/* Metrowerks 3.0: ./try.sh src/grok_nopk_1fb890.c "-O4,p -sdatathreshold 0" */
typedef unsigned char u8;
typedef signed char s8;

extern int func_00175700(u8 *);
extern void func_001843A0(u8 *);
extern void func_001266A0(u8 *, int, int);

void func_001FB890(u8 *p)
{
    u8 *q;

    if ((s8)func_00175700(p) < 0)
        func_001843A0(p);
    if (*(s8 *)(p + 337)) {
        p[337] = 0;
        q = *(u8 **)(p + 476);
        *(u8 **)(q + 456) = p;
        q[522] = 1;
        q[525] = 0;
        func_001266A0(p, 0, 0);
        q[437] = 33;
        q[486] = p[486];
    }
}
