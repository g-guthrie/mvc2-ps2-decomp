/* Metrowerks: ./try.sh src/grok_q1_1363f0.c "-O3 -sdatathreshold 8" */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;

extern u8 *D_004C2840;
extern u16 D_004F4480[];
extern u16 D_004F4494[];
extern void func_00136480(u8 *);

void residual_001363F0(u8 *p)
{
    s8 f = *(s8 *)(D_004C2840 + 0x18);
    s16 t;

    if (!(((f & 1) && (D_004F4480[0] & 0x360)) || ((f & 2) && (D_004F4494[0] & 0x360)))) {
        t = *(s16 *)(p + 0x1C) - 1;
        *(s16 *)(p + 0x1C) = t;
        if (t > 0)
            return;
    }
    p[5]++;
    p[0x13C] = 1;
    func_00136480(p);
}
