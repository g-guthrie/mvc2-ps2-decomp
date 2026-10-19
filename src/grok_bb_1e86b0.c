typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;

extern s32 func_001E8310(u8 *, u8 *, s32, s32);
extern void func_0018D620(u8 *, u8 *);

void func_001E86B0(u8 *p, u8 *q)
{
    s16 a;
    s16 b;
    s32 r;
    if (p[0] == 0)
        return;
    if ((*(u16 *)(p + 0x1C2) & 0x80) == 0)
        return;
    a = *(s16 *)(*(u8 **)(p + 0x1D4) + 2);
    if (a > 0)
        return;
    if (q[0] == 0)
        return;
    r = 0;
    b = *(s16 *)(*(u8 **)(q + 0x1D4) + 0);
    if (b > 0) {
        r = func_001E8310(p, q, a & 0x1FFF, b);
        *(s16 *)(q + 0x1BC) = b;
    }
    if (r == 0) {
        b = *(s16 *)(*(u8 **)(q + 0x1D4) + 2);
        if (b > 0) {
            r = func_001E8310(p, q, a & 0x1FFF, b);
            *(s16 *)(q + 0x1BC) = b;
        }
    }
    if (r == 0)
        return;
    p[0x1B4] = 0xA;
    q[0x1B4] = 0xB;
    p[0x1B1] = 0;
    p[0x201] = 8;
    *(u16 *)(p + 0x1C2) = *(u16 *)(p + 0x1C2) & 0x7F;
    *(s16 *)(p + 0x1BE) = (s16)(a & 0x1FFF);
    func_0018D620(p, q);
}
