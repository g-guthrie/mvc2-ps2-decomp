typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef signed char s8;

#define SWAP16(x) ((((x) >> 8) & 255) | (((x) << 8) & 0xFF00))
#define SWAP32(x) (((x) >> 24) | (((s32)(x) >> 8) & 0xFF00) | (((x) << 8) & 0xFF0000) | ((x) << 24))
/* big-endian 16-bit field: high byte via the signed halfword, low byte via the unsigned one */
#define BE16(p) (((*(const s16 *)(p) >> 8) & 0xFF) | ((*(const u16 *)(p) << 8) & 0xFF00))

int func_003F9D20(const u16 *p, int length, int *a, u16 *b, u16 *c, u32 *d, u32 *e, u32 *f, u32 *g)
{
    extern int func_003F9B70(const u16 *, int, u8 *, u8 *);
    u8 bits, version;
    int r, hdr, o;
    const u8 *q;
    const u8 *pc;
    *b = 0;
    r = func_003F9B70(p, length, &version, &bits);
    if (r != 0)
        return r;
    hdr = 0x30;
    if (version == 4)
        hdr = 0x3C;
    if (length < hdr)
        return -1;
    if ((u16)SWAP16(p[0]) != 0x8000)
        return -2;
    if ((s16)(((const u8 *)p)[3] | ((p[1] << 8) & 0xFF00)) < hdr - 4)
        return -1;
    o = 0x14;
    if (version == 4)
        o = 0x20;
    q = (const u8 *)p;
    *a = (s16)BE16(q + o);
    o += 2;
    *b = (s16)BE16(q + o);
    o += 2;
    if ((s16)*b != 1)
        return -2;
    o += 2;
    pc = q + o;
    o += 2;
    *d = SWAP32(*(const u32 *)(q + o));
    *c = BE16(pc);
    o += 4;
    *e = SWAP32(*(const u32 *)(q + o));
    o += 4;
    *f = SWAP32(*(const u32 *)(q + o));
    o += 4;
    *g = SWAP32(*(const u32 *)(q + o));
    return 0;
}

/* ADX stream header parsers (CRI ADX). */
typedef struct {
    u8 p0[4];
    u32 w4;
    s32 w8;
    u16 hC;
    u8 pE[0x114 - 0xE];
    s16 h114;
    s16 h116[1];
} AdxObj;

extern s32 D_0047C5B0, D_0047C5B4;
extern s32 D_0047C5AC;
extern s32 D_0047C5B8;
extern AdxObj *D_0047B180[];
extern u8 *D_0062F904;
extern char D_004BB058[], D_004BB090[], D_004BB098[], D_004BB0D0[];

s32 func_003FC090(s32 n) {
    extern void func_003FB128(char *);
    extern s32 func_003FD530(s32);
    extern s32 func_0011D6A8(u8 *, char *, s32);
    extern void func_003FBFD8(void);
    extern s32 func_003FCF88(s32, s32, u8 *);
    AdxObj *o;
    s16 *hdr;
    s16 *tab;
    s32 k;
    s32 m;
    s32 r;
    u8 *h;
    u8 *p4, *p5;

    if (n != D_0047C5B4) {
        func_003FB128(D_004BB058);
        return -3;
    }
    r = func_003FD530(D_0047C5B0);
    if (r != 3) return r;
    o = D_0047B180[n];
    hdr = &o->h114;
    tab = o->h116;
    if (o->w8 == 0) {
        s32 v;
        if (func_0011D6A8(D_0062F904, D_004BB090, 3) != 0) {
            func_003FB128(D_004BB098);
            func_003FBFD8();
            return 4;
        }
        h = D_0062F904; p4 = h + 4; p5 = h + 5;
        if (((*(s8 *)p4 & 0xFF) | ((*(s8 *)p5 & 0xFF) << 8) | (h[6] << 16) | (h[7] << 24)) > 0x10000) {
            func_003FB128(D_004BB0D0);
            func_003FBFD8();
            return 4;
        }
        k = 3;
        v = *p4 | (*p5 << 8);
        o->w8 = o->hC = v;
        o->w4 = ((u32)(o->w8 * 2 + 0x118) >> 2) << 2;
        *hdr = (h[8] | (h[9] << 8) | (h[10] << 16) | (h[11] << 24)) / 2048;
    } else {
        k = 1;
    }
    m = 0x200;
    for (; k < m; k += 2) {
        tab[D_0047C5AC++] = ((D_0062F904[k * 4] | (D_0062F904[k * 4 + 1] << 8) | (D_0062F904[k * 4 + 2] << 16) | (D_0062F904[k * 4 + 3] << 24)) + 0x7FF) / 2048;
        if (D_0047C5AC >= o->w8) {
            func_003FBFD8();
            r = 3;
            break;
        }
    }
    if (k >= m) {
        if (func_003FCF88(D_0047C5B0, 1, D_0062F904) < 0) {
            func_003FBFD8();
            r = 4;
        } else {
            r = *(s8 *)(D_0047C5B0 + 1);
        }
    }
    return r;
}

s32 func_003FC338(s32 n) {
    extern void func_003FB128(char *);
    extern s32 func_003FD530(s32);
    extern s32 func_0011D6A8(u8 *, char *, s32);
    extern void func_003FBFD8(void);
    extern s32 func_003FCF88(s32, s32, u8 *);
    AdxObj *o;
    s16 *hdr;
    s16 *tab;
    s32 k;
    s32 m;
    s32 r;
    u8 *h;
    u8 *p4, *p5;

    if (n != D_0047C5B4) {
        func_003FB128(D_004BB058);
        return -3;
    }
    r = func_003FD530(D_0047C5B0);
    if (r != 3) return r;
    o = D_0047B180[n];
    hdr = &o->h114;
    tab = o->h116;
    if (o->w8 == 0) {
        s32 v;
        if (func_0011D6A8(D_0062F904, D_004BB090, 3) != 0) {
            func_003FB128(D_004BB098);
            func_003FBFD8();
            return 4;
        }
        h = D_0062F904; p4 = h + 4; p5 = h + 5;
        if (((*(s8 *)p4 & 0xFF) | ((*(s8 *)p5 & 0xFF) << 8) | (h[6] << 16) | (h[7] << 24)) > 0x10000) {
            func_003FB128(D_004BB0D0);
            func_003FBFD8();
            return 4;
        }
        k = 3;
        v = *p4 | (*p5 << 8);
        o->w8 = o->hC = v;
        o->w4 = ((u32)(o->w8 * 2 + 0x118) >> 2) << 2;
        *hdr = (h[8] | (h[9] << 8) | (h[10] << 16) | (h[11] << 24)) / 2048;
    } else {
        k = 1;
    }
    m = D_0047C5B8 << 9;
    for (; k < m; k += 2) {
        tab[D_0047C5AC++] = ((D_0062F904[k * 4] | (D_0062F904[k * 4 + 1] << 8) | (D_0062F904[k * 4 + 2] << 16) | (D_0062F904[k * 4 + 3] << 24)) + 0x7FF) / 2048;
        if (D_0047C5AC >= o->w8) {
            func_003FBFD8();
            r = 3;
            break;
        }
    }
    if (k >= m) {
        if (func_003FCF88(D_0047C5B0, D_0047C5B8, D_0062F904) < 0) {
            func_003FBFD8();
            r = 4;
        } else {
            r = *(s8 *)(D_0047C5B0 + 1);
        }
    }
    return r;
}
