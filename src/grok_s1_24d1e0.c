typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;

extern void func_0024B9B0(u8 *);
extern int func_00175700();
extern void func_0015D010(u8 *, float *);
extern void func_00184540(u8 *);

void residual_0024D1E0(u8 *p)
{
    u8 *q;
    float v[2];
    func_0024B9B0(p);
    func_00175700();
    if ((s8)p[0x150] == 1) {
        p[0x150] = 0;
        *(unsigned int *)(v + 0) = 0xC2CB5555;
        *(unsigned int *)(v + 1) = 0x42F89249;
        func_0015D010(p, v);
        p[0x1B4] = 10;
    }
    if ((s8)p[0x151] != 0) {
        p[6]++;
        q = *(u8 **)(p + 0x1DC);
        *(u8 **)(q + 0x1C8) = p;
        q[0x20A] = 1;
        q[0x20D] = 2;
        q[0x1B5] = 0x21;
        q[0x1E6] = (s8)p[0x1E6] ^ 1;
        if (*(u16 *)(p + 0x160) == 0)
            func_00184540(p);
    }
}
