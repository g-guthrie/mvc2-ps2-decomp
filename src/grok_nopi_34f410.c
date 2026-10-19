/* Metrowerks 3.0: ./try.sh src/grok_nopi_34f410.c "-O4,p -sdatathreshold 0" */
typedef unsigned char u8;
typedef signed short s16;
typedef float f32;

extern void func_0034FA60(u8 *);
extern u8 D_00462400[];
extern u8 D_00462404[];

void residual_0034F410(u8 *p)
{
    u8 *q = *(u8 **)(p + 24);

    if (q[5] != 0) {
        func_0034FA60(p);
        return;
    }
    if (--*(s16 *)(p + 28) < 0) {
        p[5]++;
        p[0x13C] = 1;
        *(f32 *)(p + 96) = *(f32 *)(D_00462400 + p[33] * 8);
        *(f32 *)(p + 108) = *(f32 *)(D_00462404 + p[33] * 8);
    }
}
