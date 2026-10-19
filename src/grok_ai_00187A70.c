typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern u8 D_004D18A1;
extern u8 D_004D18BC[];
extern u8 *D_004C2794;

void func_00187A70(u8 *p)
{
    u8 *q;
    u8 *row;
    s32 bit;
    if (p[0x1E4] != 0x1D)
        return;
    if (p[0x268])
        return;
    if (D_004D18A1 & 4)
        return;
    q = *(u8 **)(D_004D18BC + p[2] * 12);
    row = D_004C2794 + q[2];
    bit = (s8)q[0x1B8];
    bit = bit / 2;
    if (row[0x4A] & (1 << bit))
        return;
    if (q[0])
        return;
    if (*(s16 *)(q + 0x434) <= 0)
        return;
    if (*(s16 *)(q + 0x2B4))
        return;
    *(u16 *)(q + 0x354) = *(u16 *)(p + 0x354);
    *(u16 *)(q + 0x35C) = *(u16 *)(p + 0x35C);
    *(u16 *)(q + 0x356) = *(u16 *)(p + 0x356);
    *(u16 *)(q + 0x358) = *(u16 *)(p + 0x358);
    *(u16 *)(q + 0x35A) = *(u16 *)(p + 0x35A);
    *(u16 *)(q + 0x35E) = *(u16 *)(p + 0x35E);
    *(u16 *)(q + 0x362) = *(u16 *)(p + 0x362);
    *(u16 *)(q + 0x360) = *(u16 *)(p + 0x360);
    if (((s32 (*)(u8 *))(*(u32 *)(*(u8 **)(q + 0x43C) + 0x34)))(q)) {
        p[0x268] = 6;
        p[0x26B] = 1;
    }
}
