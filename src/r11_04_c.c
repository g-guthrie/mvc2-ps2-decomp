typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 f[6]; } Rec;
typedef struct {
    u8 pad0[0x538];
    s8 b538;
    u8 pad539[2];
    s8 b53B;
    u8 pad53C[0xC];
    u32 w548;
    u32 w54C;
    u8 pad550;
    u8 b551;
    u8 pad552[0x1A];
    u32 w56C;
    u8 pad570[0x5B8 - 0x570];
} Pl;

extern u8 *D_004C2840;
extern Pl D_004F20B0[];
extern s8 D_004D1570[];
extern s8 D_004F7D30[];
extern s8 D_004F25F0[];
extern s8 D_004F3160[];
extern s8 D_004F3CD0[];
extern s8 D_004F258D[];
extern s8 D_004F30FD[];
extern s8 D_004F3C6D[];

typedef struct { s8 b0; s8 c[0xF]; u32 w10; u32 w14; } Ent;

void func_00127C50(u8 *a0) {
    Ent *tbl;
    u32 n;
    s32 k;
    Rec *cur;
    Pl *pa;
    s32 side;
    Rec *prv;
    Rec tmp;

    if ((s8)D_004C2840[0x4C] != 7) {
        tbl = (Ent *)D_004D1570;
    } else {
        tbl = (Ent *)D_004F7D30;
    }
    pa = (Pl *)a0;
    n = a0[0x551];
    side = ((s8)a0[0x538] ^ 1) & 1;
    k = n - 1;
    tbl[n].c[0] = D_004F25F0[(s8)D_004C2840[0x9F] * 0x5B8];
    tbl[n].c[1] = D_004F3160[(s8)D_004C2840[0x9F] * 0x5B8];
    tbl[n].c[2] = D_004F3CD0[(s8)D_004C2840[0x9F] * 0x5B8];
    tbl[n].c[3] = D_004F258D[(s8)D_004C2840[0x9F] * 0x5B8];
    tbl[n].c[4] = D_004F30FD[(s8)D_004C2840[0x9F] * 0x5B8];
    tbl[n].c[5] = D_004F3C6D[(s8)D_004C2840[0x9F] * 0x5B8];
    tbl[n].c[6] = *(s8 *)(D_004C2840 + 0x8C);
    tbl[n].c[7] = *(s8 *)(a0 + 0x53B);
    if (*(u32 *)(a0 + 0x56C) >= 360000) {
        tbl[n].c[8] = 99;
        tbl[n].c[9] = 59;
        tbl[n].c[10] = 99;
    } else {
        tbl[n].c[8] = pa->w56C / 3600;
        tbl[n].c[9] = pa->w56C / 60 % 60;
        tbl[n].c[10] = pa->w56C % 60 * 100 / 60;
    }
    tbl[n].c[11] = 0x2A;
    tbl[n].c[12] = 0x2A;
    tbl[n].c[13] = 0x2A;
    tbl[n].c[14] = 0x2A;
    tbl[n].w10 = *(u32 *)(a0 + 0x54C);
    tbl[n].w14 = *(u32 *)(a0 + 0x548);
    if (n != 0) {
        do {
            if (tbl[n].w14 < tbl[k].w14) break;
            if (tbl[n].w14 == tbl[k].w14) {
                if (tbl[n].w10 < tbl[k].w10) break;
            }
            cur = (Rec *)&tbl[n];
            prv = (Rec *)&tbl[k];
            if (k == D_004F20B0[side].b551) {
                D_004F20B0[side].b551 = n;
            }
            n--;
            k--;
            tmp = *prv;
            *prv = *cur;
            *cur = tmp;
            *(s8 *)cur += 1;
            *(s8 *)prv -= 1;
        } while (n != 0);
    }
    a0[0x551] = n;
}
