typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct RQ { u8 pad0[0x18]; s32 w18; } RQ;
typedef struct RT { u8 pad0[8]; s32 w8; u8 padC[0x1C - 0xC]; s32 w1C; u8 pad20[0x40 - 0x20]; RQ *w40; u8 pad44[0x170 - 0x44]; } RT;
typedef struct RE { u32 w0, w4; } RE;
typedef struct RO { s32 w0; s32 w4; s32 w8; s32 wC; s32 w10; s32 w14; s32 w18; s32 w1C; s32 w20; } RO;
typedef struct RB { u8 pad[0x14]; s32 w14; } RB;
typedef struct RH { u16 a, b; } RH;

extern RT D_005BF2F0[];
extern RE D_004A6D54[];
extern u8 D_0041BC80[];
extern u8 D_0041BD90[];
extern u8 D_0041BEC0[];
extern u8 D_0041C010[];

void func_0041B3C0(RO *a, RB *b, s32 c) {
    extern void func_0011D8F8(void *, s32, s32);
    extern s32 func_0041B710(RB *);
    extern s32 func_003DCFE0(s32, s32);
    extern void func_003DCF90(void *);
    extern s32 func_003DCF70(s32);
    extern void func_0041B7E0(RH *, RB *);
    extern void func_0041B8B0(RO *, RH *);
    extern void func_0011EBD0(RH *, s32, s32, void *);
    extern void func_0041B380();
    extern s32 func_003DD030(s32);
    extern void func_003DCFB0(void *);
    RH *h;
    RH *dd;
    u32 run, prev, kk;
    RT *t;
    RQ *q;
    s32 n, i, j, cnt, k, w;
    u16 *d;
    u8 stk[8];
    t = &D_005BF2F0[c - 1];
    q = t->w40;
    func_0011D8F8(a, 0, 0x24);
    a->w0 = c;
    a->w4 = D_004A6D54[q->w18].w0;
    n = func_0041B710(b);
    w = b->w14;
    a->w14 = w;
    k = w + 1;
    a->wC = func_003DCFE0(n * 2, 1);
    k *= 4;
    a->w8 = func_003DCFE0(k, 1);
    func_003DCF90(stk);
    h = (RH *)func_003DCF70(k);
    for (i = 0; i < n; i++) {
        h[i].a = 0xFFFF;
        h[i].b = 0;
    }
    func_0041B7E0(h, b);
    func_0041B8B0(a, h);
    func_0011EBD0(h, n, 4, func_0041B380);
    run = 0;
    prev = h[0].a;
    kk = 0;
    d = (u16 *)func_003DD030(a->wC);
    dd = (RH *)func_003DD030(a->w8);
    for (j = 0, cnt = 0; j < n; j++) {
        d[j] = h[j].b;
        if ((u16)prev != h[j].a) {
            dd[cnt].a = kk;
            dd[cnt].b = run;
            cnt++;
            kk = (u16)j;
            prev = h[j].a;
            run = 1;
        } else {
            run++;
        }
    }
    dd[cnt].a = kk;
    dd[cnt].b = run;
    cnt++;
    dd[cnt].a = 0xFFFF;
    dd[cnt].b = 0xFFFF;
    func_003DCFB0(stk);
    switch (t->w8) {
    case 0x25:
        a->w18 = (s32)D_0041BC80;
        a->w1C = (s32)D_0041BEC0;
        break;
    case 0x35:
        a->w18 = (s32)D_0041BD90;
        a->w1C = (s32)D_0041C010;
        break;
    }
}
