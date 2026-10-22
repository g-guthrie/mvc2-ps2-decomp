typedef unsigned char u8;
typedef unsigned int u32;
typedef signed int s32;

/* Metrowerks 3.0: ./try30.sh src/sb19_a.c "-O3,p -sdatathreshold 0" */

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

u32 func_003F25D0(u32 *p, s32 n)
{
    u32 *r = func_003F1F90(p, 0x10000);
    u32 *q;
    s32 i;
    if (r == 0) return -1;
    q = r + 3;
    for (i = 0; i < n; i++) { u32 w = *q; q++; q += w * 2; }
    return *q;
}
