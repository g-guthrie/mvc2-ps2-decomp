typedef unsigned char u8;
typedef unsigned int u32;
typedef signed int s32;

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

static s32 func_003F1FF0(void *header)
{
    s32 *entry = (s32 *)func_003F1F90((u32 *)header, 0x100);
    if (entry == 0)
        return -1;
    return entry[1];
}

static s32 func_003F2060(void *a, s32 i) {
    s32 p = (s32)func_003F1F90(a, 0x400);
    if (p == 0) return -1;
    return *(s32 *)(p + 0xC + (i << 2));
}

s32 func_003F3700(s32 *header)
{
    s32 i;
    s32 count = func_003F1FF0(header);
    s32 first = func_003F2060(header, 0);

    i = 1;
    if (count > 1) {
        do {
            if (func_003F2060(header, i) != first)
                return 1;
            i++;
        } while (i < count);
    }
    return 0;
}
