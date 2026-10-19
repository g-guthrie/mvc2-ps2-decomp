/* Metrowerks 3.0: ./try.sh src/grok_nopa_1b4120.c "-O4,p -sdatathreshold 0" */
typedef unsigned char u8;
typedef signed char s8;

extern void func_001B5350(u8 *, u8 *);
extern void func_001754A0(u8 *, int, int);

void residual_001B4120(u8 *p)
{
    u8 *q = *(u8 **)(p + 24);
    if (p[209] != q[361]) {
        p[4] = 2;
    } else if (*(s8 *)(q + 337) != 0) {
        p[6]++;
        p[316] = 1;
        func_001B5350(q, p);
        *(s8 *)(p + 36) = *(s8 *)(q + 36);
        *(s8 *)(p + 49) = -2;
        func_001754A0(p, 27, p[32]);
    }
}
