typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;

extern u8 *func_003DA750(u8 *, int, int);
extern void func_0037BF40(u8 *);

u8 *func_0037BE60(u8 *owner)
{
    u8 *cur = 0;
    u8 *prev = 0;
    int i = 0;
    u8 *o;
    for (;;) {
        if (i == 0)
            o = func_003DA750(cur, 1, 0);
        else
            o = func_003DA750(cur, 1, 2);
        if (i == 0) {
            if (!o)
                return 0;
            *(u8 **)(o + 0x14) = 0;
            prev = 0;
        } else {
            if (!o)
                return 0;
        }
        *(void (**)(u8 *))(o + 0x10) = func_0037BF40;
        *(u8 **)(o + 0x18) = owner;
        *(s16 *)(o + 0x26) = 0x1703;
        o[0x23] = (u8)i;
        i++;
        *(s16 *)(o + 0x140) = *(s16 *)(*(u8 **)(o + 0x18) + 0x140);
        *(u8 **)(o + 0x14) = prev;
        prev = o;
        *(u16 *)(o + 0xD0) = *(u16 *)(*(u8 **)(o + 0x18) + 0x168);
        if (i >= 0x10)
            break;
        cur = o;
    }
    return o;
}
