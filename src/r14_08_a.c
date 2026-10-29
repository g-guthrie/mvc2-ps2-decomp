typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct {
    u8 pad0[0x538];
    s8 b538;
    u8 pad539[2];
    s8 b53B;
    u8 pad53C[0xC];
    u32 w548;
    u32 w54C;
    u8 pad550[2];
    u8 b552;
    u8 pad553[0x19];
    u32 w56C;
    u8 pad570[0x5B8 - 0x570];
} Pl;

extern u8 *D_004C2840;
extern Pl D_004F20B0[];
extern s8 D_004F25F0[];
extern s8 D_004F3160[];
extern s8 D_004F3CD0[];
extern s8 D_004F258D[];
extern s8 D_004F30FD[];
extern s8 D_004F3C6D[];

typedef struct { s8 b0; s8 c[0x7]; u8 b8; s8 d[7]; u32 w10; u32 w14; } Ent;
extern Ent D_004D1370[];

void func_00127FA0(u8 *a0) {
    Ent *tbl;
    u32 n;
    s32 k;
    Pl *pa;
    s32 side;
    s32 c0;
    Ent etmp;

    pa = (Pl *)a0;
    side = (pa->b538 ^ 1) & 1;
    n = a0[0x552];
    tbl = D_004D1370;
    c0 = (s8)a0[0x538];
    k = n - 1;
    tbl[n].c[0] = D_004F25F0[c0 * 0x5B8];
    tbl[n].c[1] = D_004F3160[(s8)a0[0x538] * 0x5B8];
    tbl[n].c[2] = D_004F3CD0[(s8)a0[0x538] * 0x5B8];
    tbl[n].c[3] = D_004F258D[(s8)a0[0x538] * 0x5B8];
    tbl[n].c[4] = D_004F30FD[(s8)a0[0x538] * 0x5B8];
    tbl[n].c[5] = D_004F3C6D[(s8)a0[0x538] * 0x5B8];
    tbl[n].c[6] = *(s8 *)(D_004C2840 + 0x8C);
    tbl[n].b8 = *(s8 *)(a0 + 0x53B);
    if (*(u32 *)(a0 + 0x56C) >= 360000) {
        tbl[n].d[0] = 99;
        tbl[n].d[1] = 59;
        tbl[n].d[2] = 99;
    } else {
        tbl[n].d[0] = pa->w56C / 3600;
        tbl[n].d[1] = pa->w56C / 60 % 60;
        tbl[n].d[2] = pa->w56C % 60 * 100 / 60;
    }
    tbl[n].d[3] = 0x2A;
    tbl[n].d[4] = 0x2A;
    tbl[n].d[5] = 0x2A;
    tbl[n].d[6] = 0x2A;
    tbl[n].w10 = *(u32 *)(a0 + 0x54C);
    tbl[n].w14 = *(u32 *)(a0 + 0x548);
    if (n != 0) {
        do {
            if (tbl[n].b8 < tbl[k].b8) break;
            if (k == D_004F20B0[side].b552) {
                D_004F20B0[side].b552 = n;
            }
            etmp = tbl[k];
            tbl[k] = tbl[n];
            tbl[n] = etmp;
            tbl[n].b0++;
            tbl[k].b0--;
            n--;
            k--;
        } while (n != 0);
    }
    a0[0x552] = n;
}
