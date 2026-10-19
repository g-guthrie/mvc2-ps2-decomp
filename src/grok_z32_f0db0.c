typedef signed int s32;

s32 func_003F0DB0(s32 *p, s32 idx)
{
    if ((idx - 1) >= p[0] || idx == 0)
        return 0;
    return *(s32 *)(p[2] + ((idx - 1) << 4));
}
