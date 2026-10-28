#pragma opt_propagation off
typedef unsigned char u8; typedef signed char s8; typedef unsigned short u16; typedef signed short s16; typedef unsigned int u32; typedef signed int s32; typedef float f32;
#pragma pack(1)
typedef struct { f32 w; u8 b; } B;
#pragma pack()
typedef union { B s; s8 c[5]; } U;
extern B D_004BF3A8;
extern B D_004BF3B0;
void func_001489E0(s32 a, s32 b) {
    extern u8 *func_00147870();
    s32 i;
    s32 s3;
    U x;
    U y;
    u8 *r;
    x.s = D_004BF3A8;
    y.s = D_004BF3B0;
    i = 4;
    do {
        if (i == 4) s3 = a;
        else s3 = b;
        if (s3 <= 8) {
            s8 c = x.c[i];
            r = func_00147870(0, c);
        } else {
            s8 c = y.c[i];
            r = func_00147870(4, c);
        }
        r[0x21] = s3;
        i--;
    } while (i >= 0);
}

typedef struct { f32 x, y, z; } V3_00146D80;
typedef struct { f32 x, y, z, w; } V4_00146D80;
typedef struct { V3_00146D80 v; u16 hC; u8 bE; s8 bF; } E_00146D80;
typedef struct { u8 p0[4]; u8 b4; u8 p1[0xB]; void *w10; u8 p2[0xC]; u8 b20; u8 b21; u8 p3[1]; u8 b23; u8 p4[0x10]; V3_00146D80 v34; u8 p5[0x10]; V3_00146D80 v50; u8 p6[0x18]; V4_00146D80 v74; s32 w84; u8 p7[0x40]; u8 *wC8; u16 hCC; u8 p8[2]; s32 wD0; u8 p9[0x68]; u8 b13C; } O_00146D80;
extern E_00146D80 D_00442900[];
extern V3_00146D80 D_00442890;
extern V4_00146D80 D_004428A0;
extern V4_00146D80 D_004428B0;
extern s32 D_004C2804;
extern s32 D_004C27E4;
extern void D_00147560();

void func_00146D80(u8 *a, s32 b, s32 idx) {
    extern O_00146D80 *func_003DA750(s32, s32, s32);
    O_00146D80 *o;
    E_00146D80 *e;
    s32 n;
    e = &D_00442900[idx];
    n = 1;
    for (;;) {
        if ((e->bE & 1) == 0) { s32 z = 0; o = func_003DA750(z, 0xD, 0); } else { s32 z = 0; o = func_003DA750(z, 0xD, 1); }
        if (o == 0) return;
        o->b13C = 1;
        o->b4 = 1;
        o->w10 = (void *)D_00147560;
        o->b23 = b;
        o->b20 = a[0x20];
        o->b21 = n;
        o->wC8 = a + 0x88;
        n++;
        if (!(e->bE & 0x80)) {
            o->hCC = e->hC;
            o->w84 = D_004C2804;
        } else {
            o->hCC = e->hC;
            o->w84 = D_004C27E4;
        }
        o->v34 = e->v;
        o->wD0 = 0x431;
        o->v50 = D_00442890;
        if (a[0x20] != 0 && o->b21 != 0) {
            o->b13C = 0;
            o->v74 = D_004428B0;
        } else {
            o->v74 = D_004428A0;
        }
        if (e->bF < 0) return;
        e++;
    }
}
