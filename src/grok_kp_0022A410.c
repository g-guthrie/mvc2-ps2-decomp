/* ./try.sh src/grok_kp_0022A410.c "-O4,p -sdatathreshold 8" */
typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef float f32;
typedef f32 PlanarOffset[2] __attribute__((aligned(16)));

extern u8 *func_001E7FD0(u8 *);
extern void func_00185770(u8 *, u8 *);
extern void func_0022B870(u8 *);
extern void func_0015D010(u8 *, f32 *);
extern void func_0022C5D0(u8 *);

void func_0022A410(u8 *p)
{
    s16 t;
    u8 *q;

    p[0x40C] = 2;
    p[0x33C] = 5;
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    if (*(s8 *)(p + 0x211) & (1 << (p[0x1E6] ^ 1)))
        goto die;
    t = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = t;
    if (t <= 0) {
    die:
        p[0x40D] = 0;
        p[0x40C] = 0;
        p[0x33B] = 0;
        p[0x33C] = 0;
        func_0022C5D0(p);
        return;
    }
    if (*(s16 *)(p + 0x1E)) {
        *(s16 *)(p + 0x1E) = *(s16 *)(p + 0x1E) - 1;
        return;
    }
    if ((q = func_001E7FD0(p)) != 0) {
        PlanarOffset st;
        p[6]++;
        p[0x20B] = 0xC4;
        func_00185770(p, q);
        func_0022B870(p);
        st[0] = -83.3333282470703125f;
        st[1] = 158.5714263916015625f;
        func_0015D010(p, st);
    }
}
