typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;

extern u8 *D_004C2840 __attribute__((section(".sdata")));
extern void func_0012AD00(u8 *);

void residual_001473E0(u8 *p)
{
    u8 *g;
    u8 st;

    st = p[0x20];
    if (st == 0)
        return;
    g = D_004C2840;
    if (*(s16 *)(g + 8) == (s16)(st - 1)) {
        if (p[0x21] != 0) {
            if ((signed char)g[5] == 3)
                p[0x13C] = 1;
            else
                p[0x13C] = 0;
        } else {
            *(u32 *)(p + 0x78) = 0x3F7AE148;
            *(u32 *)(p + 0x7C) = 0x3F800000;
            *(u32 *)(p + 0x80) = 0x3EA8F5C3;
        }
        func_0012AD00(p);
        return;
    }
    if (p[0x21] != 0) {
        p[0x13C] = 0;
        return;
    }
    *(u32 *)(p + 0x78) = 0x3E947AE1;
    *(u32 *)(p + 0x7C) = 0x3EF5C28F;
    *(u32 *)(p + 0x80) = 0x3F3851EC;
    *(s16 *)(p + 0x1E) = 0;
    *(u32 *)(p + 0x74) = 0x3F800000;
}
