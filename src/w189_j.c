typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

/* Metrowerks 3.0.3: ./try.sh src/w189_j.c "-O4,p -sdatathreshold 0" */
static u32 *func_003F1F90(u32 *h, u32 tag) {
    u32 *q;
    u32 i;
    if (h[0] & tag) {
        q = h + 3;
        h = (u32 *)h[1];
        for (i = 0; i < (u32)h; i++) {
            if (q[0] == tag) return q;
            q = (u32 *)((u8 *)q + q[2]);
        }
    }
    return 0;
}
s32 func_003F21F0(s32 a, s32 n) {
    u8 *p;
    s32 i;
    u32 flag;
    u32 w;
    p = (u8 *)func_003F1F90((u32 *)a, 0x100);
    if (p != 0) {
        p += 0xC;
        for (i = 0; i <= n; i++) {
            w = *(u32 *)p;
            flag = w & 0x80000000;
            p += (w & 0x7FFFFFFF) * 4 + 4;
        }
        return flag != 0;
    }
    return -1;
}
