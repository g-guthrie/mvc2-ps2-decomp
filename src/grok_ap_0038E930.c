typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;

extern u16 D_004D18DC;
extern u8 D_004D18DB;
extern u8 *D_004C29C4 __attribute__((section(".sdata")));
extern void func_0038E660(u8 *);
extern void func_0038E6B0(u8 *);

void func_0038E930(u8 *p)
{
    u8 *q = *(u8 **)(p + 0x18);
    if (p[1] != q[1]) {
        p[4]++;
        p[0x13C] = 0;
        return;
    }
    if (q[0x169] != 0x16) {
        p[4]++;
        p[0x13C] = 0;
        return;
    }
    if (q[0x168] != 8) {
        p[5]++;
        *D_004C29C4 = 4;
        *(s16 *)(p + 0x1C) = 2;
        return;
    }
    if ((D_004D18DC & (1 << D_004D18DB)) != 0)
        return;
    D_004C29C4[7] = 0;
    if (*(s16 *)(*(u8 **)(p + 0x18) + 0x1C) <= 0) {
        p[5]++;
        *D_004C29C4 = 4;
        *(s16 *)(p + 0x1C) = 2;
    }
    func_0038E660(p);
    func_0038E6B0(p);
}
