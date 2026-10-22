#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct {
    s8 b0;
    u8 pad1[2];
    s8 b3;
    s32 w4;
    s32 w8;
    s32 wC;
    s32 w10;
    s32 w14;
    s32 w18[2];
    s32 w20;
    s32 w24;
    s32 w28;
    s32 w2C;
    s32 w30;
    s32 w34;
    s32 w38;
    s16 h3C;
    s16 h3E;
    s16 h40;
    s16 h42[9];
    s32 w54;
    s32 w58;
    s32 w5C;
    s16 h60;
    u8 pad62[2];
    s32 w64;
    s16 h68;
    s16 h6A;
    s8 b6C;
    s8 b6D;
    u8 pad6E[4];
    s8 b72;
    u8 pad73[0x15];
    s32 w88;
    u8 pad8C[8];
    s32 w94;
    s8 b98;
    u8 pad99[0x13];
} SlotC;

extern SlotC D_0047C620[];
extern char D_004BBFA0[];
extern void func_003FB128(char *);
extern void *func_0011D8F8(void *, s32, s32);
extern s32 func_0040F5E0(s32, s32, s32);
extern s32 func_003FF3E8(s32, s32, s32 *);
extern s32 func_003FF0C8(s32 *, s32);
extern s32 func_0040CC30(s32);
extern void func_00401428(SlotC *);

SlotC *func_00401150(s32 n, s32 size, s32 total)
{
    s32 s1;
    s32 s2;
    s32 j, k;
    SlotC *p;
    s32 r;
    s1 = (size + 0x3F) & -0x40;
    s2 = total - (s1 - size);
    if (n < 0 || size == 0 || total < 0) {
        func_003FB128(D_004BBFA0);
        return 0;
    }
    k = 0;
    while (k < 16 && D_0047C620[k].b0 != 0) k++;
    if (k == 16) return 0;
    p = &D_0047C620[k];
    func_0011D8F8(p, 0, 0xAC);
    p->b3 = n;
    p->w20 = s1 + n * 0x40C0;
    p->w28 = 0x24;
    p->w2C = s1;
    p->w30 = 0x2000;
    p->w34 = 0x2060;
    p->w24 = (s2 - n * 0x40C0 - 0x24) / 0x800 * 0x800;
    p->w14 = 0;
    p->w10 = func_0040F5E0(p->w20, p->w24, 0x24);
    if (p->w10 == 0) goto fail;
    for (j = 0; j < n; j++) {
        r = func_0040F5E0(p->w2C + p->w34 * j * 2, p->w30 * 2, (p->w34 - p->w30) * 2);
        p->w18[j] = r;
        if (r == 0) goto fail;
    }
    p->w4 = func_003FF3E8(p->w10, n, p->w18);
    if (p->w4 == 0) goto fail;
    p->wC = func_003FF0C8(p->w18, n);
    if (p->wC == 0) goto fail;
    p->w94 = func_0040CC30(p->w10);
    if (p->w94 != 0) goto ok;
fail:
    func_00401428(p);
    return 0;
ok:
    p->w38 = 0x3C;
    p->h3C = p->w24 / 0x800;
    p->h3E = (s32)((double)p->h3C * 0.85);
    p->h40 = 0;
    for (j = 0; j < n; j++) p->h42[j] = -0x80;
    p->b6C = 1;
    p->w54 = 0;
    p->w58 = 0;
    p->w5C = 0;
    p->h60 = 0;
    p->w64 = 0;
    p->h68 = 0;
    p->h6A = 0;
    p->b6D = 1;
    p->b0 = 1;
    p->b72 = 0;
    p->w88 = 0;
    p->b98 = 0;
    return p;
}
