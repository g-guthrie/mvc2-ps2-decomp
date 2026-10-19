/* Metrowerks 3.0: ./try.sh src/grok_nopi_350ee0.c "-O4,p -sdatathreshold 0" */
typedef unsigned char u8;
typedef float f32;

extern int func_00175700(u8 *);
extern void func_001757E0(u8 *, int, int);

void residual_00350EE0(u8 *p)
{
    u8 *q;

    *(f32 *)(p + 52) += *(f32 *)(p + 92);
    *(f32 *)(p + 92) += *(f32 *)(p + 104);
    *(f32 *)(p + 56) += *(f32 *)(p + 96);
    *(f32 *)(p + 96) += *(f32 *)(p + 108);
    func_00175700(p);
    q = *(u8 **)(p + 24);
    if (*(f32 *)(p + 56) < *(f32 *)(q + 0x430)) {
        p[5]++;
        q = *(u8 **)(p + 24);
        *(f32 *)(p + 56) = *(f32 *)(q + 0x430);
        func_001757E0(p, 23, 37);
    }
}
