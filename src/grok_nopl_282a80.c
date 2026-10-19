/* Metrowerks 3.0: ./try.sh src/grok_nopl_282a80.c "-O4,p -sdatathreshold 0" */
typedef unsigned char u8;
typedef signed char s8;
typedef float f32;

extern f32 D_004F1F4C;
extern int func_00175700(u8 *);
extern void func_00184540(u8 *);
extern void func_00181D90(u8 *);

void residual_00282A80(u8 *p)
{
    f32 y;
    f32 g;

    if (!*(s8 *)(p + 434)) {
        if ((s8)func_00175700(p) < 0)
            func_00184540(p);
        return;
    }
    p[7]++;
    p[528] = 0;
    y = *(f32 *)(p + 52);
    g = D_004F1F4C;
    if (!(g - 160.0f <= y)) {
        if (p[486])
            p[487] = 0;
        else
            p[487] = 1;
    } else if (g + 160.0f < y) {
        if (p[486])
            p[487] = 1;
        else
            p[487] = 0;
    }
    func_00181D90(p);
}
