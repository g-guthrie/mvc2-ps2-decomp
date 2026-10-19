typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;

#define SWAP16(x) ((((x) >> 8) & 255) | (((x) << 8) & 0xFF00))

int func_003F9AF0(const u16 *p, int length, u16 *out)
{
    if (length < 18)
        return -1;
    if ((u16)SWAP16(p[0]) != 0x8000)
        return -2;
    if ((s16)(((const u8 *)p)[3] | ((p[1] << 8) & 0xFF00)) < 14)
        return -1;
    *out = SWAP16(p[8]);
    return 0;
}

int func_003F9B70(const u16 *p, int length, u8 *first, u8 *second)
{
    if (length < 20)
        return -1;
    if ((u16)SWAP16(p[0]) != 0x8000)
        return -2;
    if ((s16)(((const u8 *)p)[3] | ((p[1] << 8) & 0xFF00)) < 16)
        return -1;
    *first = ((const u8 *)p)[18];
    *second = ((const u8 *)p)[19];
    return 0;
}
