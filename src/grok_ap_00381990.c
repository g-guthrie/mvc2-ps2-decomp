typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;

extern u16 D_004D18DC;
extern u8 D_004D18DB;
extern u8 *D_004C29A4 __attribute__((section(".sdata")));
extern void func_003816C0(u8 *);

void func_00381990(u8 *p)
{
    u16 v = *(u16 *)(*(u8 **)(p + 0x18) + 0x168);
    if (v != 0x1506 && v != 0x1508 && v != 0x1507 && v != 0x1509) {
        p[5]++;
        *(s16 *)(p + 0x1C) = 1;
        return;
    }
    if ((D_004D18DC & (1 << D_004D18DB)) != 0)
        return;
    {
        u8 *g = D_004C29A4;
        s16 t;
        g[3] = 0;
        t = *(s16 *)(*(u8 **)(p + 0x18) + 0x1C);
        if (t <= 0) {
            p[5]++;
            *(s16 *)(p + 0x1C) = 10;
            *(u32 *)(p + 0x54) = 0x3F800000;
        }
    }
    func_003816C0(p);
}
