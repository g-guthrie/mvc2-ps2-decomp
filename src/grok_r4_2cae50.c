/* Metrowerks: ./try.sh src/grok_r4_2cae50.c "-O4,p -sdatathreshold 0" */
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

extern void func_002CAFA0(u8 *, u8 *);
extern void func_00183D10(u8 *);
extern void func_00186A20(u8 *);
extern void func_0018C4B0(u8 *, int);
extern void func_001757E0(u8 *, int, int);

void residual_002CAE50(u8 *p, u8 *q)
{
    if (p[533]) {
        func_002CAFA0(p, q);
        return;
    }
    p[6]++;
    if (p[525] != 2) {
        func_00183D10(p);
        func_00186A20(p);
    }
    func_0018C4B0(p, 2);
    p[533] = 1;
    p[528] = 0;
    *(s16 *)(q + 10) = 600;
    *(s16 *)(p + 28) = 16;
    *(f32 *)(p + 96) = 12.857142448425293f;
    *(f32 *)(p + 108) = -0.2678571343421936f;
    *(u32 *)(p + 92) = 0;
    *(u32 *)(p + 104) = 0;
    func_001757E0(p, 26, 0);
}
