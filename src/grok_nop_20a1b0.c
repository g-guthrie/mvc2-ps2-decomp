/* Metrowerks 3.0: ./try.sh src/grok_nop_20a1b0.c "-O3 -sdatathreshold 8" */
typedef unsigned char u8;
typedef signed short s16;

extern int func_00417A40(void);
extern void func_0020A210(u8 *);
extern s16 D_004BFE18[4];

void residual_0020A1B0(u8 *p)
{
    int i;

    p[6]++;
    p[316] = 1;
    i = func_00417A40() & 3;
    *(s16 *)(p + 30) = D_004BFE18[i];
    func_0020A210(p);
}
