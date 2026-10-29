/* func_00415590: builds the model/part tables for one object (MW 3.0 -O3,p
   -sdatathreshold 8). The block scopes of the second and third passes are what
   give retail's saved-register assignment. */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern s32 D_004C2898;
extern s32 D_004C289C;
extern s32 D_004C2894;
extern u32 (*D_004C2B0C)(u32);
extern u8 D_004F9170[];
extern u8 D_0051DA70[];
extern u32 D_004F8470[];

s32 func_00415590(u8 *p, u32 *q, u32 r, s32 *list) {
    extern s32 func_003F1950(u32);
    extern u32 func_003F1E10(u32, s32);
    extern void func_003F1E70(u32, s32, u8 *);
    extern void func_00415A00(u32);
    extern void func_003DF850(s32, u32);
    extern s32 func_003DFF80(s32);
    extern void func_003DCF90(u8 *);
    extern void func_003DCFB0(u8 *);
    extern s32 func_003F2A50(u8 *, u32, s32);
    extern u32 func_003EE6F0(u8 *, u32);
    extern void func_0041B3C0(u8 *, u8 *, u32);
    extern s32 func_003F13A0(u32);
    extern s32 func_003F13E0(u32);
    extern u32 func_003F16D0(u32, s32);
    extern void func_003F1730(u8 *, u32, u32, s32);
    extern u32 func_003DE7E0(u8 *);
    extern void func_003DE880(u8 *, u32);
    extern s32 func_003DEC90(u32);
    extern void func_003DE860(u32);
    u8 buf[0x30];
    u8 mbuf[0x10];
    u8 lk0[8];
    u8 lk1[8];
    u8 *base;
    u32 tab;
    s32 done;
    s16 n;
    u32 h;
    s32 jb;
    s32 i;
    s32 off;
    s32 joff;
    s32 cnt;
    s32 st;
    s32 k;
    s32 m;
    s32 cur;

    cnt = 0;
    done = 0;
    if (list == 0) done = 1;
    h = q[0];
    n = (s16)func_003F1950(h);
    cur = D_004C2898;
    if (cur + n >= 0x340) return -1;
    *(s16 *)(p + 0x12) = cur;
    *(s16 *)(p + 0x10) = n;
    base = D_004F9170 + cur * 0xB4;
    *(u8 **)(p + 0x14) = base;
    D_004C2898 += n;
    tab = *(u32 *)(p + 4);
    i = 0;
    off = 0;
    while (i < n) {
        *(u32 *)(base + off + 0xC) = func_003F1E10(h, i);
        func_003F1E70(h, i, base + off + 0x10);
        off += 0xB4;
        i++;
    }
    {
        s32 ioff;
        u8 *e;
        s32 j;

        j = 0;
        jb = 0;
        joff = 0;
        while (j < n) {
            *(u32 *)((e = base + joff) + 4) = *(u32 *)(q[2] + jb);
            *(u32 *)(e + 8) = 0;
            func_00415A00(*(u32 *)(e + 4));
            for (k = 0, ioff = 0; k < *(u32 *)(e + 0xC); ioff += 4, k++) {
                func_003DF850(k + 0x39, tab + *(u32 *)(e + ioff + 0x10) * 0x4C);
            }
            st = func_003DFF80(1);
            if (st != 0) {
                if (func_003DFF80(0x15) == 1) func_003DF850(1, 0);
            }
            func_003DCF90(lk0);
            if (func_003F2A50(buf, h, j) != 0) {
                u32 a;
                if (done == 0) {
                    a = list[0];
                    if (++cnt >= list[1]) {
                        cnt = 0;
                        list += 2;
                    }
                    if (list[1] < 0) done = 1;
                } else {
                    a = r;
                }
                *(u32 *)e = func_003EE6F0(buf, a);
                func_0041B3C0(e + 0x90, buf, *(u32 *)e);
            } else {
                *(s32 *)e = -1;
            }
            func_003DCFB0(lk0);
            if (st != 0) func_003DF850(1, st);
            jb += 4;
            joff += 0xB4;
            j++;
        }
    }
    {
        u32 h;
        u8 *dst;
        u32 *slot;
        u32 mdl;

        h = q[1];
        m = (s16)func_003F13A0(h);
        cur = D_004C289C;
        if (cur + m >= 0x340) return -1;
        *(s16 *)(p + 0xA) = cur;
        *(s16 *)(p + 8) = m;
        dst = D_0051DA70 + cur * 400;
        *(u8 **)(p + 0xC) = dst;
        D_004C289C += m;
        n = (s16)func_003F13E0(h);
        cur = D_004C2894;
        if (cur + n >= 0x340) return -1;
        *(s32 *)(p + 0x18) = n;
        slot = D_004F8470 + cur;
        *(u32 **)(p + 0x1C) = slot;
        D_004C2894 += n;
        k = 0;
        while (k < n) {
            func_003DCF90(lk1);
            func_003F1730(mbuf, D_004C2B0C(func_003F16D0(h, k)), h, k);
            mdl = func_003DE7E0(mbuf);
            func_003DCFB0(lk1);
            func_003DE880(dst, mdl);
            *slot++ = (u32)dst;
            dst += func_003DEC90(mdl) * 400;
            func_003DE860(mdl);
            k++;
        }
    }
    return 0;
}
