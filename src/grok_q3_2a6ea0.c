/* Metrowerks 3.0: ./try.sh src/grok_q3_2a6ea0.c "-O4,p -sdatathreshold 0" */
typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;

extern void func_001757E0(u8 *, int, int);
extern void func_002A6F10(u8 *);

void residual_002A6EA0(u8 *p)
{
    p[6]++;
    (*(s8 *)(p + 489))++;
    p[488] = 0;
    p[490] = 17;
    p[525] = 2;
    *(s16 *)(p + 28) = 60;
    *(s16 *)(p + 320) = p[486] ^ 1;
    func_001757E0(p, 20, 2);
    func_002A6F10(p);
}
