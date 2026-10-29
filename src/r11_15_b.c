/* CRI ADX: open a stream and read its sector table (EE GCC 2.96). */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

#define RD32(p) ((p)[0] | ((p)[1] << 8) | ((p)[2] << 16) | ((p)[3] << 24))

typedef struct { s16 a; s16 b; s32 c; } Ent;

extern s32 D_0047B180[];
extern u8 D_0062D840[];
extern s32 D_0062F900, D_0062F904;
extern u8 D_004BB108[], D_004BB130[], D_004BB160[];

s32 func_003FC5E8(s32 a0, s32 a1, u8 *a2, s32 a3)
{
    extern s32 func_003FB5F0();
    extern s32 func_003FCA60();
    extern void func_003FB128();
    extern void func_00120440();
    extern s32 func_003FB638();
    extern void func_003FCCF0();
    s32 k;
    s32 idx;
    s32 v;
    s32 r;
    u8 *p;
    s32 w;
    s32 tries;
    Ent *ent;
    Ent *e;
    s32 cnt;
    s32 h;
    s32 ret;
    u8 *q;
    r = func_003FB5F0(a0, a2);
    if (r < 0) return r;
    h = func_003FCA60(a1, 0);
    if (h == 0) {
        func_003FB128(D_004BB108);
        return -1;
    }
    k = 0;
    *(s32 *)a2 = D_0047B180[a0];
    D_0047B180[a0] = (s32)a2;
    ret = -1;
    ent = (Ent *)(a2 + 0x114);
    cnt = 0;
    tries = 0;
    func_00120440(a2 + 0x10, a1, 0x100);
    a2[0xE] = 1;
    v = (s32)D_0062D840 & -0x40;
    D_0062F900 = v;
    D_0062F904 = v;
    *(s32 *)(a2 + 8) = 0;
    do {
        if (func_003FB638(h, 1, D_0062F904) > 0) {
            idx = 0;
            if (*(s32 *)(a2 + 8) == 0) {
                p = (u8 *)D_0062F904;
                w = RD32(p + 4);
                if (w > 0x10000) {
                    *(s32 *)(p + 4) = 0x10000;
                    ret = -4;
                    func_003FB128(D_004BB130);
                    goto fin;
                }
                *(s32 *)(a2 + 8) = a3 < w ? a3 : w;
                idx = 2;
            }
            if (idx < 0x200) {
                do {
                    u8 *p0, *p3, *p2, *p1;
                    p0 = (u8 *)(idx * 4 + D_0062F904);
                    p3 = p0 + 3; p2 = p0 + 2; p1 = p0 + 1;
                    if (((*(s8 *)p0 & 0xFF) | ((*(s8 *)p1 & 0xFF) << 8) | ((*(s8 *)p2 & 0xFF) << 16) | ((*(s8 *)p3 & 0xFF) << 24)) == 0) {
                        idx += 2;
                    } else {
                        e = &ent[cnt++];
                        idx += 4;
                        e->a = k;
                        q = (u8 *)(idx * 4 + D_0062F904);
                        idx += 4;
                        e->c = (s32)((*p0 | (*p1 << 8) | (*p2 << 16) | (*p3 << 24)) + 2047) / 2048;
                        e->b = (s32)(RD32(q) + 2047) / 2048;
                    }
                    k++;
                    if (!(k < *(s32 *)(a2 + 8))) { ret = 0; goto fin; }
                } while (idx < 0x200);
            }
            tries = 0;
        } else {
            tries++;
        }
    } while (tries < 3);
    if (tries == 3) func_003FB128(D_004BB160);
fin:
    *(u16 *)(a2 + 0xC) = cnt;
    *(s32 *)(a2 + 4) = *(s32 *)(*(s32 *)a2 + 4) + (u32)(*(u16 *)(a2 + 0xC) * 8 + 0x114);
    func_003FCCF0(h);
    return ret;
}
