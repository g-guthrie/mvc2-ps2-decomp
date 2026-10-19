/* Metrowerks 3.0: ./try.sh src/grok_t6_20c2f0.c "-O3 -sdatathreshold 0" */
typedef unsigned char u8;
typedef unsigned short u16;
typedef float f32;

extern int func_0020D2F0(u8 *, u8 *);
extern void func_0020D250(u8 *, u8 *, int);
extern void func_00175700(u8 *);

void func_0020C2F0(u8 *p, u8 *q)
{
    if (func_0020D2F0(p, q) != 0) {
        func_0020D250(p, q, 5);
        return;
    }
    {
        u16 w = *(u16 *)(p + 0x35E);
        if (w & 0x300) {
            p[0x1B7] = (w & 0x100) ? 0 : 1;
            func_0020D250(p, q, 3);
        } else if (w & 0x60) {
            if (w & 0x1000)
                func_0020D250(p, q, 6);
            else {
                p[0x1B7] = (w & 0x20) ? 1 : 0;
                func_0020D250(p, q, 4);
            }
        } else if (w & 0x800) {
            func_0020D250(p, q, 2);
        } else if (!(w & 0x2000)) {
            func_0020D250(p, q, 0);
        } else {
            *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
            *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
            if (*(f32 *)(p + 0x38) < *(f32 *)(p + 0x430) + (5520.0f / 7.0f)) {
                *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430) + (5520.0f / 7.0f);
                *(f32 *)(p + 0x60) = 0;
                *(f32 *)(p + 0x6C) = 0;
            }
            func_00175700(p);
        }
    }
}
