typedef unsigned char u8;
typedef signed short s16;

int func_003D9000(void *actor)
{
    u8 *p = actor;

    if (p[0]) {
        if (p[1] == 0x18 && *(s16 *)(p + 0x434) == 0)
            return !(p[0x1e4] == 0x17);
        if (!p[5]) {
            if (p[0x1e4] == 0x17 || p[0x1e4] == 0 || p[0x1e4] == 0x16)
                return 0;
        }
        return 1;
    }
    return 0;
}
