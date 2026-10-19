typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;

extern void func_0037F3A0(u8 *);
extern void func_0037F3F0(u8 *);
extern u8 *D_004C299C;
extern u16 D_004D18DC;
extern u8 D_004D18DB;

void func_0037F7C0(u8 *p)
{
    u8 *q = *(u8 **)(p + 0x18);
    if (p[1] != q[1]) {
        p[4]++;
        p[0x13C] = 0;
        return;
    }
    if (*(u16 *)(q + 0x168) != 0x1503) {
        p[5]++;
        D_004C299C[0] = 3;
        *(s16 *)(p + 0x1C) = 1;
        return;
    }
    if (D_004D18DC & (1 << D_004D18DB))
        return;
    D_004C299C[7] = 0;
    if (*(s16 *)(q + 0x1C) <= 0) {
        p[5]++;
        D_004C299C[0] = 3;
        *(s16 *)(p + 0x1C) = 1;
    }
    func_0037F3A0(p);
    func_0037F3F0(p);
}
