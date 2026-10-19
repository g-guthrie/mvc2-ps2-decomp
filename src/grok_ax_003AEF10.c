typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;

extern void func_003AF6D0(u8 *, u8 *);
extern u16 D_004D18DC;
extern u8 D_004D18DB;
extern void func_003AEFE0(u8 *, u8 *);
extern void func_003AF160(u8 *, u8 *);

void func_003AEF10(u8 *p, u8 *q)
{
    u8 *o;
    p[0x13C] = 0;
    o = *(u8 **)(p + 0x18);
    *(s8 *)(q + 0x29) = *(s8 *)(q + 0x28);
    if (o[5] || o[0x1E4] != 0x15) {
        func_003AF6D0(p, q);
        return;
    }
    if (*(s8 *)(o + 0x1B4) || (D_004D18DC & (1 << D_004D18DB))) {
        u8 *c;
        p[0x13C] = 1;
        c = *(u8 **)(p + 0xC);
        c[0x13C] = 1;
        *(s16 *)(c + 0x1C) = 1;
        c = *(u8 **)(c + 0xC);
        c[0x13C] = 1;
        *(s16 *)(c + 0x1C) = 1;
    } else if (!p[5])
        func_003AEFE0(p, q);
    else
        func_003AF160(p, q);
}
