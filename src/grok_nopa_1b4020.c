/* Metrowerks 3.0: ./try.sh src/grok_nopa_1b4020.c "-O4,p -sdatathreshold 0" */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed char s8;

extern void func_001B5350(u8 *, u8 *);
extern void func_001754A0(u8 *, int, int);
extern void func_001E3710(u8 *, int);

void residual_001B4020(u8 *p)
{
    u8 *q = *(u8 **)(p + 24);
    if (*(u16 *)(p + 208) != *(u16 *)(q + 360)) {
        p[4] = 2;
    } else if (*(s8 *)(q + 336) != 0) {
        p[6]++;
        p[316] = 1;
        func_001B5350(q, p);
        if (p[32] == 5)
            p[36] = 7;
        else
            p[36] = 0;
        func_001754A0(p, 27, p[32]);
        func_001E3710(p, 47);
    }
}
