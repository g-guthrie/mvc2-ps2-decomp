typedef signed int s32;
typedef signed short s16;
typedef signed char s8;

extern s32 func_003F89D8(void *, void *, s16 *, s8 *, s8 *, s8 *, s8 *, s32 *, s32 *, s32 *, s8 *);

s32 func_003F8AF8(s16 *r, void *a, void *b)
{
    s16 sp20;
    s32 ret;
    s8 *pe;
    s8 *pf;
    s32 *p10;

    pe = (s8 *)r + 0xE;
    p10 = (s32 *)((s8 *)r + 0x10);
    pf = (s8 *)r + 0xF;
    r[1] = 1;
    ret = func_003F89D8(a, b, &sp20, (s8 *)r + 0xC, (s8 *)r + 0xD, pf, pe, (s32 *)((s8 *)r + 0x14), (s32 *)((s8 *)r + 0x18), p10, (s8 *)r + 0x9A);
    if (ret >= 0) {
    *(s32 *)((s8 *)r + 0x34) = 0;
    *(s32 *)((s8 *)r + 0x30) = 0;
    *(s32 *)((s8 *)r + 0x2C) = 0;
    *(s32 *)((s8 *)r + 0x28) = 0;
    *(s32 *)((s8 *)r + 0x20) = 0;
    *(s16 *)((s8 *)r + 0x1C) = 0;
    *(s16 *)((s8 *)r + 0x26) = 0;
    *(s16 *)((s8 *)r + 0x24) = 0;
    *(s32 *)((s8 *)r + 0x50) = *pe;
    *(s32 *)((s8 *)r + 0x54) = *pf;
    *(s16 *)((s8 *)r + 0x98) = 2;
    *(s32 *)((s8 *)r + 0x58) = *p10;
    *(s32 *)((s8 *)r + 0x5C) = *(s32 *)((s8 *)r + 0x3C);
    *(s32 *)((s8 *)r + 0x60) = *(s32 *)((s8 *)r + 0x40);
    *(s32 *)((s8 *)r + 0x64) = *(s32 *)((s8 *)r + 0x44);
    *(s32 *)((s8 *)r + 0x8C) = 0;
    *(s32 *)((s8 *)r + 0x88) = 0;
    }
    else
        return 0;
    return sp20;
}
