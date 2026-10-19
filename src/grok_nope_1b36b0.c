/* Metrowerks 3.0: ./try.sh src/grok_nope_1b36b0.c "-O4,p -sdatathreshold 0" */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed char s8;

extern void func_001B3D90(u8 *, u8 *);
extern void func_001754A0(u8 *, int, int);
extern u8 D_004B5714[];

void residual_001B36B0(u8 *p)
{
    u8 *q = *(u8 **)(p + 24);
    u16 *id = (u16 *)(p + 0xD0);

    if (*(s8 *)(q + 0x151)) {
        p[6]++;
        p[316] = 1;
        func_001B3D90(q, p);
        func_001754A0(p, 27, D_004B5714[p[33] * 6]);
    }
    if (*id != *(u16 *)(q + 360)) {
        p[6] = 0;
        p[5] = 0;
        p[4] = 0;
        p[316] = 0;
    }
}
