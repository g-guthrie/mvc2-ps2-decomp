/* Metrowerks 3.0: ./try.sh src/grok_q3_245640.c "-O4,p -sdatathreshold 0" */
typedef unsigned char u8;
typedef signed short s16;

extern int func_00174170(u8 *);
extern int func_001757E0(u8 *, int, int);
extern void func_00176160(u8 *, int, int, int);

void func_00245640(u8 *p)
{
    unsigned r;

    p[6]++;
    p[316] = 1;
    r = (unsigned)func_00174170(p) & 1;
    if (r == 0) {
        func_001757E0(p, 18, 0);
        *(s16 *)(p + 30) = 7;
    } else {
        p[6]++;
        func_001757E0(p, 18, 1);
        func_00176160(p, 0, p[37] * 28, 3);
    }
}
