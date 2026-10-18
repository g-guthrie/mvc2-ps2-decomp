typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

static s32 func_003F5180(u8 *p, s32 n)
{
    u32 al = p[5] ? 0x80 : 0x10;
    u32 r = n % al;
    if (r != 0) {
        n += al - (n - (n / al) * al) % al;
    }
    return n;
}

s32 func_003F51F0(u8 *p, s32 n)
{
    s32 i;
    u8 *a;
    u8 *q;
    a = p;
    p += func_003F5180(p, 16);
    q = p;
    i = 0;
    if (i < n) do {
        if (i >= *(u16 *)(a + 6)) break;
        p += func_003F5180(a, 0x30);
        p += *(s32 *)q;
        i++;
        q = p;
    } while (i < n);
    return (s32)q;
}
