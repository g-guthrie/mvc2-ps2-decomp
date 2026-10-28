typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;

s32 func_00405778(u8 *t, u32 n, u8 *d)
{
    u8 *q = t + 4;
    if (n < 0x10) return 0;
    {
        u32 a, b, c, e;
        a = t[0]; b = t[2]; c = t[1]; a <<= 24; e = t[3]; b <<= 8; c <<= 16;
        a |= e; b |= c; a |= b;
        *(u32 *)d = a;
    }
    {
        u32 c = q[1], a = q[0], b = q[2], e;
        c <<= 16; e = q[3];
        q = t + 0xA;
        a <<= 24; b <<= 8; b |= c; a |= e; a |= b;
        *(u32 *)(d + 4) = a;
    }
    d[8] = t[8];
    d[9] = t[9];
    {
        u32 b = q[0], a = q[1];
        q = t + 0xC;
        b <<= 8; a |= b;
        *(u16 *)(d + 0xA) = a;
    }
    {
        u32 c = q[1], a = q[0], b = q[2], e;
        c <<= 16; e = q[3];
        a <<= 24; b <<= 8; a |= e; b |= c; a |= b;
        *(u32 *)(d + 0xC) = a;
    }
    return 0x10;
}
