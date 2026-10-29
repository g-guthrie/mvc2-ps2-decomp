/* Metrowerks 3.0 (./try30.sh), -O3,p -Op -sdatathreshold 8.
 * func_00412260 draws one frame of a character sprite bank slot: for each part
 * it looks the sprite's cell up in one of three VRAM tile caches (by area),
 * uploads newly allocated cells, then emits a sprite packet per tile.
 * The frame layout depends on tex_addr being an inline function (its result
 * local is a level-1 inline temp), xx/yy being function-scope counters reused
 * by all three tiers, and h being reused as the sprite table base. */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef unsigned long long u64;
typedef float f32;

typedef struct { f32 x, y; } V2b;
typedef struct { V2b c[16]; } V2x16;
typedef struct { u8 b0, b1, b2, b3; u8 data[1]; } SPRb;
typedef struct { s32 w0; s32 w4; s32 w8; s32 wC; } HDRb;
typedef struct { HDRb *hdr; s32 h4; s32 h8; s32 hC; } ENTb;
typedef struct {
    u8 pad0[8];
    s32 w8;
    u8 padC[6];
    s16 h12;
    u8 pad14[4];
    s16 h18;
    s16 h1A;
    s16 h1C;
    u8 pad1E[0xA];
    s32 w28;
    u8 pad2C[0x14];
} TEXb;

extern ENTb D_00632610[];
extern u8 *D_004C250C;
extern u8 *D_004C2514;
extern TEXb D_006207A0[];
extern s16 D_004BECD0[];
extern V2x16 D_00496850[];
extern u8 D_0062BBA0[];
extern f32 D_0062BC30[];
extern u64 D_00632550[];
extern u64 D_00632558[];
extern u64 D_00632560[];
extern u64 D_00632568[];
extern u64 D_00632570[];
extern u64 D_00632578[];
extern u64 D_00632580[];
extern u8 D_00632588[];
extern u8 D_00632589[];
extern u8 D_0063258A[];
extern u8 D_0063258B[];
extern f32 D_0063258C[];
extern f32 D_00632590[];
extern f32 D_00632594[];
extern s32 D_0063259C[];
extern s32 D_006325AC[];
extern s32 D_006325BC[];
extern s32 D_006325CC[];
extern f32 D_006325D0[];
extern f32 D_006325D4[];

extern u8 *func_003DD030(s32);
static inline u8 *tex_addr(TEXb *t)
{
    u8 *d;
    d = func_003DD030(t->w28);
    return d;
}

s32 func_00412260(s32 id, s32 idx, u8 *obj, u32 color, s32 pal)
{
    extern u8 *func_003DD030(s32);
    extern void memcpy(void *, void *, s32);
    extern s32 func_00413B20(u8 *, s32, s32);
    extern void func_00413A80(u8 *, u8 *, u8 *);
    extern u32 func_003DBD20(u32);
    extern s32 func_003DBD70(u32);
    extern u8 *func_003DD160(s32, s32);
    extern void func_003DBD80(u8 *, s32, u8 *, s32, s16, s16, s32, s16, s16, s16, s16);
    extern s32 func_003DC2F0(u32, u8 *);
    extern void func_003DC120(void *, s32);
    extern void func_00413510(u64 *, u32, u32);
    extern s32 func_00413600(u8 *, f32 *, u64 *, s32, f32);
    extern s32 func_003DECC0(u64 *);
    s32 xx;
    s32 yy;
    f32 x;
    f32 y;
    f32 x0;
    f32 y0;
    f32 sz;
    f32 dx;
    f32 dy;
    s32 w;
    s32 hh;
    HDRb *h;
    s32 key;
    s32 g;
    SPRb *spr;
    ENTb *e;
    s32 n;
    u8 *save;
    u8 *pal_tab;
    u8 *clut_tab;
    s32 count;
    s32 area;
    s32 r;
    s32 pv;
    s32 *offs;
    s16 *s0;

    if ((u32)--id >= 16) return 0;
    e = &D_00632610[id];
    if ((h = e->hdr) == 0) return 0;
    offs = (s32 *)((u8 *)h + h->wC);
    h = (HDRb *)((u8 *)h + h->w4);
    save = func_003DD030(e->h4);
    pal_tab = func_003DD030(e->h8);
    clut_tab = func_003DD030(e->hC);
    memcpy(D_004C250C, save, 0x740);
    D_00632558[0] = 0;
    D_00632550[0] = 0x70000007;
    D_00632560[0] = 0xC400000000008001ULL;
    D_00632568[0] = 0x0000525252521860ULL;
    D_00632570[0] = 0x54;
    D_00632588[0] = (((color >> 16) & 0xFF) + 1) >> 1;
    D_00632589[0] = (((color >> 8) & 0xFF) + 1) >> 1;
    D_0063258A[0] = ((color & 0xFF) + 1) >> 1;
    D_0063258B[0] = (((color >> 24) & 0xFF) + 1) >> 1;
    D_0063258C[0] = 1.0f;
    g = (u32)(-0.5f * (*(f32 *)(obj + 0x38) - 1.0f) * D_0062BC30[0]);
    D_006325CC[0] = g;
    D_006325BC[0] = g;
    D_006325AC[0] = g;
    D_0063259C[0] = g;
    y = x = 0.0f;
    s0 = (s16 *)((u8 *)offs + offs[idx]);
    count = *s0++;
    do {
        x -= (f32)s0[0];
        y -= (f32)s0[1];
        key = s0[3];
        spr = (SPRb *)((u8 *)h + *(s32 *)((u8 *)h + key * 4));
        w = spr->b2 * 8;
        hh = spr->b3 * 8;
        area = w * hh;
        if (w >= hh) {
            n = w / hh;
            sz = (f32)hh;
            dx = 1.0f;
            dy = 0.0f;
        } else {
            n = hh / w;
            sz = (f32)w;
            dx = 0.0f;
            dy = 1.0f;
        }
        if (s0[2] & 0x8000) {
            dx *= -sz;
            x0 = (x + (f32)(spr->b0 * 8)) - sz;
        } else {
            dx *= sz;
            x0 = x;
        }
        if (s0[2] & 0x4000) {
            dy *= -sz;
            y0 = (y + (f32)(spr->b1 * 8)) - sz;
        } else {
            dy *= sz;
            y0 = y;
        }
        if (area <= 0x100) 
            {
                u8 *dst;
                V2b *tab;
                u8 *dbase;
                r = func_00413B20(D_004C250C + 0, 0x100, key);
                pv = *(s32 *)(pal_tab + ((r >> 6) & 0xFF) * 4 + 0);
                if (r >= 0) {
                    u8 *src;
                    s32 wid;
                    s32 stride;
                    s32 hgt;
                    s32 j;
                    u8 *pkt;
                    TEXb *t;
                    func_00413A80(spr->data, D_004C2514, D_004C2514 + area / 2);
                    t = &D_006207A0[pv - 1];
                    hgt = (s32)(sz);
                    wid = hgt >> 1;
                    tab = D_00496850[D_004BECD0[hgt]].c;
                    dbase = tex_addr(t);
                    src = D_004C2514;
                    stride = t->h18 >> 1;
                    dst = dbase + (((r >> 3) & 7) << 4) * stride + ((r & 7) * 16) / 2;
                    for (j = 0; j < n; j++) {
                        u8 *row;
                        row = dst + stride * (s32)(tab[j].y) + (s32)(tab[j].x) / 2;
                        yy = 0;
                        goto LT1;
                    LB1:
                        for (xx = 0; xx < wid; xx++) row[xx] = *src++;
                        yy++;
                        row += stride;
                    LT1:
                        if (yy < hgt) goto LB1;
                    }
                    pkt = func_003DD160(func_003DBD20(t->w8), 0x10);
                    func_003DBD80(pkt, 1, dbase, t->w8, t->h12, t->h18 / 64, t->h1C, 0, 0,
                                  t->h18, t->h1A);
                    func_003DC2F0(((u32)pkt & 0xFFFFFFF) | 0x10000000, D_0062BBA0);
                    pkt = func_003DD160(func_003DBD70(t->w8), 0x10);
                    func_003DC120(pkt, 1);
                    func_003DC2F0((u32)pkt & 0xFFFFFFF, D_0062BBA0);
                }
                {
                    f32 ox;
                    f32 oy;
                    u32 iu;
                    u32 iv;
                    s32 j;
                    s32 hgt;
                    V2b *tab2;
                    ox = (f32)((r & 7) * 16);
                    oy = (f32)(((r >> 3) & 7) * 16);
                    hgt = (s32)(sz);
                    tab2 = D_00496850[D_004BECD0[hgt]].c;
                    for (j = 0; j < n; j++) {
                        f32 u;
                        f32 v;
                        u64 tag;
                        u64 tag2;
                        D_006325D0[0] = x0;
                        D_006325D4[0] = y0;
                        u = ox + tab2[j].x;
                        v = oy + tab2[j].y;
                        x0 += dx;
                        y0 += dy;
                        iu = (u32)(u);
                        iv = (u32)(v);
                        D_00632590[0] = 0.0078125f * u;
                        D_00632594[0] = 0.0078125f * v;
                        tag = ((u64)iu << 4) | 0xA;
                        tag2 = tag | ((u64)(u32)((f32)iu + sz) << 14);
                        tag2 = ((u64)iv << 24) | tag2;
                        tag = (u64)(u32)((f32)iv + sz) << 34;
                        tag |= tag2;
                        D_00632580[0] = tag;
                        func_00413510(D_00632578, pv, *(s32 *)(clut_tab + (((s0[2] >> 4) + pal) & 0xF) * 4));
                        if (func_00413600(obj, D_006325D0, D_00632550, s0[2], sz) != 0)
                            func_003DECC0(D_00632550);
                    }
                }
            }
        else if (area <= 0x400) 
            {
                u8 *dst;
                V2b *tab;
                u8 *dbase;
                r = func_00413B20(D_004C250C + 0x400, 0xA0, key);
                pv = *(s32 *)(pal_tab + ((r >> 4) & 0xFF) * 4 + 0x10);
                if (r >= 0) {
                    u8 *src;
                    s32 wid;
                    s32 stride;
                    s32 hgt;
                    s32 j;
                    u8 *pkt;
                    TEXb *t;
                    func_00413A80(spr->data, D_004C2514, D_004C2514 + area / 2);
                    t = &D_006207A0[pv - 1];
                    hgt = (s32)(sz);
                    wid = hgt >> 1;
                    tab = D_00496850[D_004BECD0[hgt]].c;
                    dbase = tex_addr(t);
                    src = D_004C2514;
                    stride = t->h18 >> 1;
                    dst = dbase + (((r >> 2) & 3) << 5) * stride + ((r & 3) * 32) / 2;
                    for (j = 0; j < n; j++) {
                        u8 *row;
                        row = dst + stride * (s32)(tab[j].y) + (s32)(tab[j].x) / 2;
                        yy = 0;
                        goto LT2;
                    LB2:
                        for (xx = 0; xx < wid; xx++) row[xx] = *src++;
                        yy++;
                        row += stride;
                    LT2:
                        if (yy < hgt) goto LB2;
                    }
                    pkt = func_003DD160(func_003DBD20(t->w8), 0x10);
                    func_003DBD80(pkt, 1, dbase, t->w8, t->h12, t->h18 / 64, t->h1C, 0, 0,
                                  t->h18, t->h1A);
                    func_003DC2F0(((u32)pkt & 0xFFFFFFF) | 0x10000000, D_0062BBA0);
                    pkt = func_003DD160(func_003DBD70(t->w8), 0x10);
                    func_003DC120(pkt, 1);
                    func_003DC2F0((u32)pkt & 0xFFFFFFF, D_0062BBA0);
                }
                {
                    f32 ox;
                    f32 oy;
                    u32 iu;
                    u32 iv;
                    s32 j;
                    s32 hgt;
                    V2b *tab2;
                    ox = (f32)((r & 3) * 32);
                    oy = (f32)(((r >> 2) & 3) * 32);
                    hgt = (s32)(sz);
                    tab2 = D_00496850[D_004BECD0[hgt]].c;
                    for (j = 0; j < n; j++) {
                        f32 u;
                        f32 v;
                        u64 tag;
                        u64 tag2;
                        D_006325D0[0] = x0;
                        D_006325D4[0] = y0;
                        u = ox + tab2[j].x;
                        v = oy + tab2[j].y;
                        x0 += dx;
                        y0 += dy;
                        iu = (u32)(u);
                        iv = (u32)(v);
                        D_00632590[0] = 0.0078125f * u;
                        D_00632594[0] = 0.0078125f * v;
                        tag = ((u64)iu << 4) | 0xA;
                        tag2 = tag | ((u64)(u32)((f32)iu + sz) << 14);
                        tag2 = ((u64)iv << 24) | tag2;
                        tag = (u64)(u32)((f32)iv + sz) << 34;
                        tag |= tag2;
                        D_00632580[0] = tag;
                        func_00413510(D_00632578, pv, *(s32 *)(clut_tab + (((s0[2] >> 4) + pal) & 0xF) * 4));
                        if (func_00413600(obj, D_006325D0, D_00632550, s0[2], sz) != 0)
                            func_003DECC0(D_00632550);
                    }
                }
            }
        else 
            {
                u8 *dst;
                V2b *tab;
                u8 *dbase;
                r = func_00413B20(D_004C250C + 0x680, 0x30, key);
                pv = *(s32 *)(pal_tab + ((r >> 2) & 0xFF) * 4 + 0x38);
                if (r >= 0) {
                    u8 *src;
                    s32 wid;
                    s32 stride;
                    s32 hgt;
                    s32 j;
                    u8 *pkt;
                    TEXb *t;
                    func_00413A80(spr->data, D_004C2514, D_004C2514 + area / 2);
                    t = &D_006207A0[pv - 1];
                    hgt = (s32)(sz);
                    wid = hgt >> 1;
                    tab = D_00496850[D_004BECD0[hgt]].c;
                    dbase = tex_addr(t);
                    src = D_004C2514;
                    stride = t->h18 >> 1;
                    dst = dbase + (((r >> 1) & 1) << 6) * stride + ((r & 1) * 64) / 2;
                    for (j = 0; j < n; j++) {
                        u8 *row;
                        row = dst + stride * (s32)(tab[j].y) + (s32)(tab[j].x) / 2;
                        yy = 0;
                        goto LT3;
                    LB3:
                        for (xx = 0; xx < wid; xx++) row[xx] = *src++;
                        yy++;
                        row += stride;
                    LT3:
                        if (yy < hgt) goto LB3;
                    }
                    pkt = func_003DD160(func_003DBD20(t->w8), 0x10);
                    func_003DBD80(pkt, 1, dbase, t->w8, t->h12, t->h18 / 64, t->h1C, 0, 0,
                                  t->h18, t->h1A);
                    func_003DC2F0(((u32)pkt & 0xFFFFFFF) | 0x10000000, D_0062BBA0);
                    pkt = func_003DD160(func_003DBD70(t->w8), 0x10);
                    func_003DC120(pkt, 1);
                    func_003DC2F0((u32)pkt & 0xFFFFFFF, D_0062BBA0);
                }
                {
                    f32 ox;
                    f32 oy;
                    u32 iu;
                    u32 iv;
                    s32 j;
                    s32 hgt;
                    V2b *tab2;
                    ox = (f32)((r & 1) * 64);
                    oy = (f32)(((r >> 1) & 1) * 64);
                    hgt = (s32)(sz);
                    tab2 = D_00496850[D_004BECD0[hgt]].c;
                    for (j = 0; j < n; j++) {
                        f32 u;
                        f32 v;
                        u64 tag;
                        u64 tag2;
                        D_006325D0[0] = x0;
                        D_006325D4[0] = y0;
                        u = ox + tab2[j].x;
                        v = oy + tab2[j].y;
                        x0 += dx;
                        y0 += dy;
                        iu = (u32)(u);
                        iv = (u32)(v);
                        D_00632590[0] = 0.0078125f * u;
                        D_00632594[0] = 0.0078125f * v;
                        tag = ((u64)iu << 4) | 0xA;
                        tag2 = tag | ((u64)(u32)((f32)iu + sz) << 14);
                        tag2 = ((u64)iv << 24) | tag2;
                        tag = (u64)(u32)((f32)iv + sz) << 34;
                        tag |= tag2;
                        D_00632580[0] = tag;
                        func_00413510(D_00632578, pv, *(s32 *)(clut_tab + (((s0[2] >> 4) + pal) & 0xF) * 4));
                        if (func_00413600(obj, D_006325D0, D_00632550, s0[2], sz) != 0)
                            func_003DECC0(D_00632550);
                    }
                }
            }
        s0 += 4;
    } while (--count != 0);
    memcpy(save, D_004C250C, 0x740);
    return 1;
}
