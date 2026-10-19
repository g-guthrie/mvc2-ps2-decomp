/* Metrowerks 3.0: ./try.sh src/grok_nopj_001BDC40.c "-O4,p -sdatathreshold 0" */
typedef unsigned char u8;
typedef unsigned int u32;

extern u8 *func_003DA750(u8 *, int, int);
extern void func_001BDCC0(u8 *, u8 *);
extern void func_001BC7A0(void);

void func_001BDC40(u8 *p, u8 *a1)
{
    u8 *o;
    u32 t = p[5];
    p[5] = t + 1;
    *(int *)(p + 72) = 0x2600;
    o = func_003DA750(p, 3, 2);
    if (o) {
        *(void (**)(void))(o + 16) = func_001BC7A0;
        *(u8 **)(o + 24) = p;
        o[32] = 18;
    }
    func_001BDCC0(p, a1);
}
