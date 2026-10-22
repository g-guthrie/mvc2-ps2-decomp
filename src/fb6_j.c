typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct { s32 (**vtbl)(void *); } Iface;

extern s32 D_0047B580;
extern char D_004BB298[];
extern char D_004BB2C0[];
extern char D_004BB2F0[];
extern char D_004BB318[];
extern void func_003FB128(void *);
extern void func_003FB510(s32, s32, u8 *, s32, s32);
extern Iface *func_0040F5E0(s32, s32, s32);
extern void func_003F9630(void);
extern void func_003F9660(void);
extern void func_003FB370(s32, long);
extern s32 func_003FCDE0(u8 *, s32, Iface *);

s32 func_003FCF88(u8 *a, s32 n, s32 p) {
    Iface *h;
    s32 sz;
    s32 r;
    func_003FB510(4, 0, a, n, p);
    if (a == 0) {
        func_003FB128(D_004BB298);
        return -3;
    }
    if (n < 0) {
        func_003FB128(D_004BB2C0);
        return -3;
    }
    if (p == 0) {
        func_003FB128(D_004BB2F0);
        return -3;
    }
    if (*(s8 *)(a + 1) == 2) return 0;
    if (*(s32 *)(a + 8) != 0) {
        func_003FB128(D_004BB318);
        return -1;
    }
    sz = n << 11;
    h = func_0040F5E0(p, sz, 0);
    if (h == 0) return -2;
    *(s32 *)(a + 0x28) = sz;
    *(s32 *)(a + 0x24) = p;
    func_003F9630();
    if (D_0047B580 == 1) func_003FB370(*(s32 *)(a + 0x24), *(u32 *)(a + 0x28));
    func_003F9660();
    r = func_003FCDE0(a, n, h);
    if (r <= 0) {
        (*h->vtbl[3])(h);
        a[2] = 0;
    } else {
        *(Iface **)(a + 8) = h;
        a[2] = 0;
    }
    func_003FB510(4, 1, a, n, p);
    return r;
}
