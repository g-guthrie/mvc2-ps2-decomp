typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

static u32 *func_003F1F90(u32 *p, u32 key)
{
    u32 *e = p;
    u32 i;
    if (p[0] & key) {
        e += 3;
        for (i = 0; i < p[1]; i++) {
            if (e[0] == key) return e;
            e = (u32 *)((u8 *)e + e[2]);
        }
    }
    return 0;
}

s32 func_003F21F0(u8 *p, s32 n)
{
    u8 *q;
    s32 i;
    u32 sz;
    u32 f;
    q = (u8 *)func_003F1F90((u32 *)p, 0x100);
    if (q != 0) {
        q += 12;
        for (i = 0; i <= n; i++) {
            sz = *(u32 *)q;
            f = sz & 0x80000000;
            q += (sz & 0x7FFFFFFF) * 4 + 4;
        }
        return f != 0;
    }
    return -1;
}
