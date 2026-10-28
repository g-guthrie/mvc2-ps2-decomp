typedef unsigned char u8;
typedef unsigned int u32;
typedef signed int s32;

/* Metrowerks 3.0: ./try30.sh src/s5b_a.c "-O4,p -sdatathreshold 0" */
/* func_003F1F90: static copy of the real callee (verified in src/w2_f.c) */
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

/* The list walk must use its own pointer (t = q + 12), not q itself:
 * walking q (the call result, pinned to v0) makes MW schedule the
 * sll of k ahead of the q+4 addiu in the bounds-checked tail. */
s32 func_003F2350(u8 *p, s32 n, s32 k)
{
    u8 *q;
    u8 *t;
    s32 i;
    s32 r, sz;
    q = (u8 *)func_003F1F90((u32 *)p, 0x100);
    if (q != 0) {
        t = q + 12;
        for (i = 0; i < n; i++) {
            t += (*(u32 *)t & 0x7FFFFFFF) * 4 + 4;
        }
        sz = *(u32 *)t & 0x7FFFFFFF;
        if (k >= sz) r = -1; else r = ((s32 *)(t + 4))[k];
        return r;
    }
    return -1;
}
