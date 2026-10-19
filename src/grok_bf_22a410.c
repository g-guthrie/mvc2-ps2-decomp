typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

extern u8 *func_001E7FD0(void);
extern void func_00185770(u8 *, u8 *);
extern void func_0022B870(u8 *);
extern void func_0015D010(u8 *, f32 *);
extern void func_0022C5D0(u8 *);

void func_0022A410(u8 *p)
{
    s16 t;
    u8 *q;
    f32 st[2];

    p[0x40C] = 2;
    p[0x33C] = 5;
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    if (((s8)p[0x211] & (1 << (p[0x1E6] ^ 1)))
        || (t = *(s16 *)(p + 0x1C) - 1, *(s16 *)(p + 0x1C) = t, t <= 0)) {
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
    q = func_001E7FD0();
    if (q) {
        p[6]++;
        p[0x20B] = 0xC4;
        func_00185770(p, q);
        func_0022B870(p);
        *(u32 *)&st[0] = 0xC2A6AAAA;
        *(u32 *)&st[1] = 0x431E9249;
        func_0015D010(p, st);
    }
}
