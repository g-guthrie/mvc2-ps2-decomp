#include "runtime_decode_descriptor.h"
#include "runtime_stream_query.h"
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef long long s64;
typedef unsigned long long u64;

void func_0010B930(s32 a, s32 b, s32 c)
{
    extern void func_0010B360(s32, s32, s32, void *);
    s32 buf[4];
    func_0010B360(a, b, c, buf);
}

s32 func_003FB638(s32 a0, s32 a1, s32 a2)
{
    extern s32 func_003FCF88();
    extern void func_00406A88();
    extern void func_00400AF8();
    extern void func_003FD2A0();
    extern void func_003FB5C0();
    extern s32 func_003FD530();
    extern s32 func_003FD500();
    s32 i = 0;
    while (i < 10000) {
        if (func_003FCF88(a0, a1, a2) > 0) break;
        i++;
        func_00406A88();
        func_00400AF8();
        func_003FD2A0();
        func_003FB5C0();
    }
    if (i == 10000) return 0;
    i = 0;
    while (i < 10000) {
        i++;
        func_00406A88();
        func_00400AF8();
        func_003FD2A0();
        if (func_003FD530(a0) == 3) break;
        func_003FB5C0();
    }
    return func_003FD500(a0);
}

void func_0040A118(u8 *p)
{
    extern void func_004098A8();
    extern void func_00408078();
    extern void func_004084E8();
    extern void func_00409A10();
    extern void func_0040A218();
    extern void func_0011EB60();
    extern u8 D_004BDBA8[];
    extern u8 D_004BDC08[];
    extern s32 D_00489018;
    s32 i = 0;
    if (p == 0) {
        func_004098A8(p, D_004BDBA8);
        return;
    }
    if (p[2] >= 2) {
        if (*(s32 *)(p + 0x1C) != 0) func_00408078(*(s32 *)(p + 0x1C));
        for (;;) {
            func_004084E8();
            func_00409A10();
            func_0040A218(p);
            if (*(s8 *)(p + 2) != 2) break;
            i++;
            if (i > 0x9FFFF) {
                if (D_00489018 != *(s8 *)(p + 2)) func_0011EB60(D_004BDC08);
                break;
            }
        }
        p[2] = 0;
        *(s32 *)(p + 0x14) = 0;
    }
}

void func_003F8810(u8 *p)
{
    extern s32 func_00404400();
    extern void func_003F84E8();
    extern void func_004044E0(RuntimeDecodeDescriptor *);
    extern void func_003F8690();
    extern void func_004044B0();
    s32 r;
    if (*(s32 *)(p + 4) == 1) {
        if (func_00404400(*(s32 *)(p + 8)) == 0) {
            (*(RuntimeStreamQuery *)(p + 0x78))((u8 *)*(void **)(p + 0x7C), (int *)(p + 0x68), (int *)(p + 0x6C), (int *)(p + 0x70));
            func_003F84E8(p);
            *(s32 *)(p + 4) = 2;
        }
    }
    if (*(s32 *)(p + 4) == 2) {
        func_004044E0(*(RuntimeDecodeDescriptor **)(p + 8));
        r = func_00404400(*(s32 *)(p + 8));
        if (r == 3) {
            func_003F8690(p);
            func_004044B0(*(s32 *)(p + 8));
            (*(RuntimeStreamCommit *)(p + 0x80))((u8 *)*(void **)(p + 0x84), *(s32 *)(p + 0x94), *(s32 *)(p + 0x90));
            *(s32 *)(p + 4) = r;
        }
    }
}

extern volatile s32 D_00479DF8;
extern s32 D_00479DFC;
extern u8 D_00479E00[], D_0047B180[], D_0047B588[], D_0047C588[];
extern s32 D_0047C5A8, D_0047B580, D_0047C5AC, D_0047C5B0, D_0047C5B4;
void func_003FB398(void)
{
    extern void func_0011D8F8();
    (void)D_00479DF8;
    if (D_00479DFC == 0) {
        func_0011D8F8(D_00479E00, 0, 0x1380);
        func_0011D8F8(D_0047B180, 0, 0x400);
        func_0011D8F8(D_0047B588, 0xFF, 0x1000);
        func_0011D8F8(D_0047C588, 0, 0x20);
        D_0047C5A8 = 0;
        D_0047B580 = 0;
        D_0047C5AC = 0;
        D_0047C5B0 = 0;
        D_0047C5B4 = -1;
    }
    D_00479DFC++;
}

void func_00404DA8(u8 *p)
{
    extern s32 func_00405318();
    extern void func_00405100();
    extern void func_00405350();
    extern void func_00400658();
    extern void func_004007A0();
    extern void func_004006E8();
    extern void func_00405118();
    s32 v[2];
    s32 t;
    t = *(s32 *)(p + 0x1B0) + 1;
    *(s32 *)(p + 0x1B0) = t;
    if (*(s8 *)(p + 0x1A8) == 1) {
        if (t >= *(s32 *)(p + 0x1BC)) {
            *(s32 *)(p + 0x1B0) = *(s32 *)(p + 0x1B8);
        }
    }
    if (*(s8 *)(p + 0x1A9) == 1) {
        if (*(s32 *)(p + 0x1B0) < func_00405318(*(s32 *)(p + 4))) {
            func_00405100();
            func_00405350(*(s32 *)(p + 4), *(s32 *)(p + 0x1B0), &v[0], &v[1]);
            func_00400658(*(s32 *)(p + 8), v[0] / 2048);
            func_004007A0(*(s32 *)(p + 8), (v[0] + v[1]) / 2048);
            func_004006E8(*(s32 *)(p + 8));
            func_00405118();
        }
    }
}


s32 func_003FBE88(s32 a0, s32 a1, s32 a2, u8 *a3)
{
    extern s32 func_003FB5F0();
    extern void func_003FB128();
    extern s32 func_003FCA60();
    extern s32 func_0011D8F8();
    extern void func_00120440();
    extern s32 func_003FCF88();
    extern void func_003FCCF0();
    extern s32 D_0062F900, D_0062F904;
    extern u8 D_004BAFE8[], D_004BB020[], D_0062D840[];
    s32 r;
    s32 v;
    r = func_003FB5F0(a0, a3);
    if (r < 0) return r;
    if (D_0047C5B4 >= 0) {
        func_003FB128(D_004BAFE8);
        return -1;
    }
    D_0047C5B0 = func_003FCA60(a1, a2);
    if (D_0047C5B0 == 0) {
        func_003FB128(D_004BB020);
        return -1;
    }
    D_0047C5B4 = a0;
    D_0047C5AC = 0;
    func_0011D8F8(a3, 0, 0x118);
    *(s32 *)(D_0047B180 + a0 * 4) = (s32)a3;
    *(s32 *)a3 = 0;
    func_00120440(a3 + 0x10, a1, 0x100);
    *(s32 *)(a3 + 0x110) = a2;
    a3[0xE] = 0;
    v = (s32)D_0062D840 & -0x40;
    D_0062F900 = v;
    D_0062F904 = v;
    r = func_003FCF88(D_0047C5B0, 1, v);
    if (r < 0) {
        func_003FCCF0(D_0047C5B0);
        return r;
    }
    *(s32 *)(a3 + 8) = 0;
    return 0;
}

void func_003F8BF0(u8 *p)
{
    extern s32 func_00404400();
    u8 *c = p + 0x48;
    u16 *src = *(u16 **)c;
    s32 n, m, i;
    u16 *d0, *d1;
    if (*(s32 *)(p + 4) == 1) {
        if (func_00404400(*(s32 *)(p + 8)) == 0) {
            (*(RuntimeStreamQuery *)(p + 0x78))((u8 *)*(void **)(p + 0x7C), (int *)(p + 0x68), (int *)(p + 0x6C), (int *)(p + 0x70));
            n = *(s32 *)(c + 0x18) - *(s32 *)(c + 0x20);
            if (n > *(s32 *)(c + 0x24)) n = *(s32 *)(c + 0x24);
            if (n > *(s32 *)(c + 4)) n = *(s32 *)(c + 4);
            d0 = (u16 *)(*(u8 **)(c + 0x14) + *(s32 *)(c + 0x20) * 2);
            if (*(s8 *)(p + 0xE) == 2) {
                d1 = (u16 *)(*(u8 **)(c + 0x14) + (*(s32 *)(c + 0x1C) + *(s32 *)(c + 0x20)) * 2);
                for (i = 0; i < n; i++) {
                    d0[i] = src[i * 2];
                    d1[i] = src[i * 2 + 1];
                }
            } else {
                for (i = 0; i < n; i++) {
                    d0[i] = src[i];
                }
            }
            *(s32 *)(p + 4) = 2;
            *(s32 *)(p + 0x90) = n;
            *(s32 *)(p + 0x94) = n * *(s8 *)(p + 0xE) * 2;
        }
    }
    if (*(s32 *)(p + 4) == 2) {
        (*(RuntimeStreamCommit *)(p + 0x80))((u8 *)*(void **)(p + 0x84), *(s32 *)(p + 0x94), *(s32 *)(p + 0x90));
        *(s32 *)(p + 4) = 3;
    }
}

void func_003F90B8(u8 *p)
{
    extern s32 func_00404400(void *);
    u8 *c = p + 0x48;
    u16 *src = *(u16 **)c;
    s32 n, i;
    u16 *d0, *d1;
    if (*(s32 *)(p + 4) == 1) {
        if (func_00404400(*(void **)(p + 8)) == 0) {
            (*(RuntimeStreamQuery *)(p + 0x78))((u8 *)*(void **)(p + 0x7C), (int *)(p + 0x68), (int *)(p + 0x6C), (int *)(p + 0x70));
            n = *(s32 *)(c + 0x18) - *(s32 *)(c + 0x20);
            if (n > *(s32 *)(c + 0x24)) n = *(s32 *)(c + 0x24);
            if (n > *(s32 *)(c + 4)) n = *(s32 *)(c + 4);
            d0 = (u16 *)(*(u8 **)(c + 0x14) + *(s32 *)(c + 0x20) * 2);
            if (*(s8 *)(p + 0xE) == 2) {
                d1 = (u16 *)(*(u8 **)(c + 0x14) + (*(s32 *)(c + 0x1C) + *(s32 *)(c + 0x20)) * 2);
                for (i = 0; i < n; i++) {
                    d0[i] = src[i * 2];
                    d1[i] = src[i * 2 + 1];
                }
            } else {
                for (i = 0; i < n; i++) {
                    d0[i] = src[i];
                }
            }
            *(s32 *)(p + 4) = 2;
            *(s32 *)(p + 0x90) = n;
            *(s32 *)(p + 0x94) = n * *(s8 *)(p + 0xE) * 2;
        }
    }
    if (*(s32 *)(p + 4) == 2) {
        (*(RuntimeStreamCommit *)(p + 0x80))((u8 *)*(void **)(p + 0x84), *(s32 *)(p + 0x94), *(s32 *)(p + 0x90));
        *(s32 *)(p + 4) = 3;
    }
}

void func_003F9230(u8 *p)
{
    extern s32 func_00404400(void *);
    u8 *c = p + 0x48;
    u8 *src = *(u8 **)c;
    s32 n, i;
    u16 *d0, *d1;
    if (*(s32 *)(p + 4) == 1) {
        if (func_00404400(*(void **)(p + 8)) == 0) {
            (*(RuntimeStreamQuery *)(p + 0x78))((u8 *)*(void **)(p + 0x7C), (int *)(p + 0x68), (int *)(p + 0x6C), (int *)(p + 0x70));
            n = *(s32 *)(c + 0x18) - *(s32 *)(c + 0x20);
            if (n > *(s32 *)(c + 0x24)) n = *(s32 *)(c + 0x24);
            if (n > *(s32 *)(c + 4)) n = *(s32 *)(c + 4);
            d0 = (u16 *)(*(u8 **)(c + 0x14) + *(s32 *)(c + 0x20) * 2);
            if (*(s8 *)(p + 0xE) == 2) {
                d1 = (u16 *)(*(u8 **)(c + 0x14) + (*(s32 *)(c + 0x1C) + *(s32 *)(c + 0x20)) * 2);
                for (i = 0; i < n; i++) {
                    d0[i] = (u16)(((u32)src[i * 2] - 128u) << 8);
                    d1[i] = (u16)(((u32)src[i * 2 + 1] - 128u) << 8);
                }
            } else {
                for (i = 0; i < n; i++) {
                    d0[i] = (u16)(((u32)src[i] - 128u) << 8);
                }
            }
            *(s32 *)(p + 4) = 2;
            *(s32 *)(p + 0x90) = n;
            *(s32 *)(p + 0x94) = n * *(s8 *)(p + 0xE);
        }
    }
    if (*(s32 *)(p + 4) == 2) {
        (*(RuntimeStreamCommit *)(p + 0x80))((u8 *)*(void **)(p + 0x84), *(s32 *)(p + 0x94), *(s32 *)(p + 0x90));
        *(s32 *)(p + 4) = 3;
    }
}

void func_003F93C8(u8 *p)
{
    extern s32 func_00404400(void *);
    u8 *c = p + 0x48;
    u8 *src = *(u8 **)c;
    s32 n, i;
    u16 *d0, *d1;
    if (*(s32 *)(p + 4) == 1) {
        if (func_00404400(*(void **)(p + 8)) == 0) {
            (*(RuntimeStreamQuery *)(p + 0x78))((u8 *)*(void **)(p + 0x7C), (int *)(p + 0x68), (int *)(p + 0x6C), (int *)(p + 0x70));
            n = *(s32 *)(c + 0x18) - *(s32 *)(c + 0x20);
            if (n > *(s32 *)(c + 0x24)) n = *(s32 *)(c + 0x24);
            if (n > *(s32 *)(c + 4)) n = *(s32 *)(c + 4);
            d0 = (u16 *)(*(u8 **)(c + 0x14) + *(s32 *)(c + 0x20) * 2);
            if (*(s8 *)(p + 0xE) == 2) {
                d1 = (u16 *)(*(u8 **)(c + 0x14) + (*(s32 *)(c + 0x1C) + *(s32 *)(c + 0x20)) * 2);
                for (i = 0; i < n; i++) {
                    d0[i] = (u16)(src[i * 4] | (src[i * 4 + 2] << 8));
                    d1[i] = (u16)(src[i * 4 + 1] | (src[i * 4 + 3] << 8));
                }
            } else {
                for (i = 0; i < n; i++) {
                    d0[i] = (u16)(src[i * 2] | (src[i * 2 + 1] << 8));
                }
            }
            *(s32 *)(p + 4) = 2;
            *(s32 *)(p + 0x90) = n;
            *(s32 *)(p + 0x94) = n * *(s8 *)(p + 0xE) * 2;
        }
    }
    if (*(s32 *)(p + 4) == 2) {
        (*(RuntimeStreamCommit *)(p + 0x80))((u8 *)*(void **)(p + 0x84), *(s32 *)(p + 0x94), *(s32 *)(p + 0x90));
        *(s32 *)(p + 4) = 3;
    }
}

/* After its callees in this unit: EE GCC 2.96 treats calls to functions it has
   already compiled as non-throwing, which retail's plain bne depends on. */
void func_003F95D0(u8 *p)
{
    s16 v = *(s16 *)(p + 0x9A);
    if (v == 2) func_003F93C8(p);
    else if (v == 1) func_003F9230(p);
    else if (v == 0) func_003F90B8(p);
}
