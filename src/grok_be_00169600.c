#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef signed int s32;

extern u8 D_004D18A5;
extern s32 (*D_00446160[])(u8 *);
extern s32 func_00169A50(u8 *);

s32 func_00169600(u8 *p)
{
    s32 r;
    s8 v;

    do {
        D_004D18A5 = 0;
        v = *(s8 *)(p + 0x45E) + 1;
        p[0x45E] = v;
        if (v >= *(s8 *)(p + 0x45F)) {
            p[0x45F] = p[0x45E];
            if (*(s8 *)(p + 0x45F) >= 0x20)
                return 0;
        }
        if (p[5] != 0)
            return 0;
        if (p[0x494] != 0)
            r = func_00169A50(p);
        else
            r = D_00446160[p[0x450]](p);
    } while (r == 1);
    if (r == 2) {
        return 1;
    }
    r = 0;
    return r;
}
