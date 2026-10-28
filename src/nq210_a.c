typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

#define RD32(p) ((p)[0] | ((p)[1] << 8) | ((p)[2] << 16) | ((p)[3] << 24))

extern s32 D_0047B180[];
extern u8 D_0062D840[];
extern s32 D_0062F900, D_0062F904;
extern u8 D_004BAE98[], D_004BAEC8[], D_004BAEF8[];

s32 func_003FB740(s32 a0, s32 a1, u8 *a2, s32 a3)
{
    extern s32 func_003FB5F0();
    extern s32 func_003FCA60();
    extern void func_003FB128();
    extern s32 func_0011D8F8();
    extern void func_00120440();
    extern s32 func_003FB638();
    extern void func_003FCCF0();
    s32 idx;
    s32 v;
    s32 r;
    u8 *p;
    s32 n;
    s32 w, w2;
    s32 tries;
    s16 *hdr;
    s32 cnt;
    s32 h;
    s16 *out;
    s32 ret;
    r = func_003FB5F0(a0, a2);
    if (r < 0) return r;
    h = func_003FCA60(a1, 0);
    if (h == 0) {
        func_003FB128(D_004BAE98);
        return -1;
    }
    goto init;
err4:
    ret = -4;
    goto done;
ok:
    ret = 0;
    goto done;
init:
    ret = -1;
    func_0011D8F8(a2, 0, 0x118);
    D_0047B180[a0] = (s32)a2;
    *(s32 *)a2 = 0;
    func_00120440(a2 + 0x10, a1, 0x100);
    hdr = (s16 *)(a2 + 0x114);
    a2[0xE] = 0;
    v = (s32)D_0062D840 & -0x40;
    D_0062F904 = v;
    D_0062F900 = v;
    cnt = 0;
    tries = 0;
    *(s32 *)(a2 + 8) = 0;
    out = (s16 *)(a2 + 0x116);
    do {
        tries++;
        if (func_003FB638(h, 1, D_0062F904) <= 0) continue;
        idx = 1;
        if (*(s32 *)(a2 + 8) == 0) {
            p = (u8 *)D_0062F904;
            w = RD32(p + 4);
            if (w > 0x10000) {
                *(s32 *)(p + 4) = 0x10000;
                goto err4;
            }
            n = a3 < w ? a3 : w;
            idx = 3;
            *(s16 *)(a2 + 0xC) = n;
            *(s32 *)(a2 + 8) = n & 0xFFFF;
            *(s32 *)(a2 + 4) = (((u32)((n & 0xFFFF) * 2 + 0x118) >> 2) << 2);
            w2 = RD32(p + 8);
            *hdr = w2 / 2048;
        }
        tries = 0;
        if (idx < 0x200) {
            do {
                w = RD32((u8 *)D_0062F904 + idx * 4);
                cnt++;
                idx += 2;
                out[cnt - 1] = (w + 2047) / 2048;
                if (!(cnt < *(s32 *)(a2 + 8))) goto ok;
            } while (idx < 0x200);
            tries = 0;
        }
    } while (tries < 3);
    if (tries == 3) func_003FB128(D_004BAEC8);
done:
    if (ret == -4) func_003FB128(D_004BAEF8);
    func_003FCCF0(h);
    return ret;
}

s32 func_003FBA18(s32 a0, s32 a1, s32 a2, u8 *a3)
{
    extern s32 func_003FB5F0();
    extern s32 func_003FCA60();
    extern void func_003FB128();
    extern s32 func_0011D8F8();
    extern void func_00120440();
    extern s32 func_003FB638();
    extern void func_003FCCF0();
    s32 idx;
    s32 v;
    s32 r;
    u8 *p;
    s32 n;
    s32 w, w2;
    s32 tries;
    s16 *hdr;
    s32 cnt;
    s32 h;
    s16 *out;
    s32 ret;
    r = func_003FB5F0(a0, a3);
    if (r < 0) return r;
    h = func_003FCA60(a1, a2);
    if (h == 0) {
        func_003FB128(D_004BAE98);
        return -1;
    }
    ret = -1;
    func_0011D8F8(a3, 0, 0x118);
    D_0047B180[a0] = (s32)a3;
    *(s32 *)a3 = 0;
    func_00120440(a3 + 0x10, a1, 0x100);
    hdr = (s16 *)(a3 + 0x114);
    *(s32 *)(a3 + 0x110) = a2;
    v = (s32)D_0062D840 & -0x40;
    a3[0xE] = 0;
    D_0062F900 = v;
    D_0062F904 = v;
    cnt = 0;
    *(s32 *)(a3 + 8) = 0;
    tries = 0;
    out = (s16 *)(a3 + 0x116);
    do {
        tries++;
        if (func_003FB638(h, 1, D_0062F904) <= 0) continue;
        idx = 1;
        if (*(s32 *)(a3 + 8) == 0) {
            p = (u8 *)D_0062F904;
            if (RD32(p + 4) > 0x10000) {
                *(s32 *)(p + 4) = 0x10000;
                func_003FB128(D_004BAEF8);
                ret = -4;
                goto fin;
            }
            idx = 3;
            n = *(u16 *)(a3 + 0xC) = p[4] | (p[5] << 8);
            *(s32 *)(a3 + 8) = n;
            *(s32 *)(a3 + 4) = (((u32)(n * 2 + 0x118) >> 2) << 2);
            w2 = RD32(p + 8);
            *hdr = w2 / 2048;
        }
        tries = 0;
        if (idx < 0x200) {
            do {
                w = RD32((u8 *)D_0062F904 + idx * 4);
                cnt++;
                idx += 2;
                out[cnt - 1] = (w + 2047) / 2048;
                if (!(cnt < *(s32 *)(a3 + 8))) { ret = 0; goto fin; }
            } while (idx < 0x200);
            tries = 0;
        }
    } while (tries < 3);
    if (tries == 3) func_003FB128(D_004BAEC8);
fin:
    func_003FCCF0(h);
    return ret;
}
