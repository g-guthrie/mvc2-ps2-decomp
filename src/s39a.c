typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef signed long long s64;
typedef signed int s32;
extern s32 func_003F8138(void *);
s32 func_004000B8(s32 *p) { return func_003F8138((void *)p[1]); }
extern void (*D_004C245C)(s32, s32);
extern s32 D_004C2460, D_004C2464;
void func_0040D4F0(void) { if (D_004C245C) D_004C245C(D_004C2460, D_004C2464); }
extern s32 D_004C23FC, D_004C23C4;
void func_00401950(s32 a) { if (a == 1) D_004C23FC = 0x176A; else if (a == 2) D_004C23FC = 0x1388; D_004C23C4 = a; }
extern void func_003FB128(void *);
extern void func_003FFEE0(s32);
extern char D_004BC5E8[];
void func_00402BD8(s32 *p) { if (p == 0) func_003FB128(D_004BC5E8); else func_003FFEE0(p[1]); }
extern s32 D_004BEDA0[];
s32 func_0040BD68(u8 *p) { u64 a = *(u64 *)(p + 8); u64 b = (u64)*(s32 *)(p + 0x28) << 11; if (a < b) b = a; return (s32)(b & 0xFFFFFFFF); }
extern void func_003F93C8(void *), func_003F9230(void *), func_003F90B8(void *);
s32 func_003F8140(u8 *p) {
    s32 h = *(s16 *)(p + 0x98);
    s32 m;
    if (h == 0) return 0x10;
    if (h == 2) { m = *(s16 *)(p + 0x9A); if (m == 2) return 4; return m == 1 ? 8 : 0x10; }
    if (h == 1) { m = *(s16 *)(p + 0x9A); return m == 2 ? 4 : 0x10; }
    return 0x10;
}
extern void func_00103CE0(s32, void *);
extern s32 func_00103D50(s32);
s32 func_003FE1F8(s32 a) {
    s32 r = 0; s32 buf[12];
    if (a) { func_00103CE0(a, buf); if (buf[0] != 8 && buf[0] != 0xC) r = func_00103D50(a); }
    return r;
}
extern s32 func_00400468(s32, s32, s32);
extern s32 func_00400BE0(s32);
extern void func_003FB128(void *);
extern char D_004BB190[], D_004BB1C8[];
s32 func_003FC9C8(s32 *p, s32 a, s32 b) {
    s32 r, x;
    if (a == 0) { func_003FB128(D_004BB190); return -1; }
    r = func_00400468(a, b, 0);
    if (r == 0) { func_003FB128(D_004BB1C8); return -1; }
    p[1] = r;
    x = func_00400BE0(r);
    p[4] = x;
    p[3] = (x + 0x7FF) / 0x800;
    return 0;
}
