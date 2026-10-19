typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;

extern void func_003AE8A0(u8 *);
extern void (*D_00473B00[])(u8 *);

void residual_003AD700(u8 *p)
{
    u8 *o = *(u8 **)(p + 0x18);
    if (p[0x20] == 0) {
        if (*(u16 *)(o + 0x168) == (u16)*(s16 *)(p + 0x1c) && o[0x1e4] == 20)
            goto dispatch;
        func_003AE8A0(p);
        return;
    }
    if (*(u16 *)(o + 0x168) == (u16)*(s16 *)(p + 0x1c) && o[0x1e4] == 21)
        goto dispatch;
    func_003AE8A0(p);
    return;
dispatch:
    D_00473B00[p[4]](p);
}
