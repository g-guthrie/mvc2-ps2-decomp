typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

static s32 *func_003F1F90(s32 *h, s32 key) {
    s32 *p;
    u32 i;
    if ((h[0] & key) != 0) {
        p = h + 3;
        for (i = 0; i < (u32)h[1]; i++) {
            if (p[0] == key) return p;
            p = (s32 *)((u8 *)p + p[2]);
        }
    }
    return 0;
}

s32 func_003F2810(s32 *a, s32 n) {
    s32 *p;
    s32 *q;
    s32 i;
    s32 t;
    p = func_003F1F90(a, 0x20000);
    if (p == 0) return 0;
    q = p + 3;
    for (i = 0; i <= n; i++) {
        t = *q;
        q++;
        q += t;
    }
    return t;
}
