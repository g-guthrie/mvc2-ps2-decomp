typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;
typedef struct { u8 pad0[5]; u8 b5; u8 pad6[0x16]; s16 h1c; u8 pad1e[3]; u8 b21; u8 pad22[0x12]; V3 pos; u8 pad40[0x1C]; f32 f5c; f32 f60; u8 pad64[4]; f32 f68; } S28;
void func_001A42A0(S28 *p, u8 *q) {
    p->pos = *(V3 *)(q + 0x34);
    p->pos.x += p->f5c;
    if (*(s8 *)(q + 0x2B8) != 0) {
        u32 t = p->b5;
        p->b5 = t + 1;
        p->f68 = -p->f68;
        p->h1c = 8;
    }
    p->f60 = p->f5c / (f32)(u32)p->b21;
}

extern void (*D_00450F80[])();
void func_00217650(u8 *p) {
    extern s8 func_00175700();
    extern void func_00184540();
    extern s32 func_001864a0();
    extern void func_001865B0();
    switch (p[0x1FC]) {
    case 0:
    case 1:
        if (func_00175700(p) < 0) {
            func_00184540(p);
        } else {
            if (func_001864a0(p) != 0) func_001865B0(p);
        }
        break;
    case 2:
        D_00450F80[p[6]](p);
        break;
    }
}

typedef struct { u8 pad0[7]; u8 b7; u8 pad8[0x2C]; f32 f34; f32 f38; u8 pad3c[0x20]; f32 f5c; f32 f60; u8 pad64[4]; f32 f68; f32 f6c; u8 pad70[0x3C0]; f32 f430; } S10;
void func_002354E0(S10 *p) {
    extern void func_00175700();
    f32 *x0, *x1, *x2, *x3;
    *(u8 *)((u8 *)p + 0x209) = 2;
    func_00175700(p);
    x0 = &p->f5c;
    x2 = &p->f68;
    x1 = &p->f60;
    x3 = &p->f6c;
    p->f34 += p->f5c;
    p->f5c += p->f68;
    p->f38 += p->f60;
    p->f60 += p->f6c;
    if (p->f38 < p->f430) {
        u32 t = p->b7;
        p->b7 = t + 1;
        p->f38 = p->f430;
        *(u8 *)((u8 *)p + 0x20D) = 0;
        *x0 = 0;
        *x1 = 0;
        *x2 = 0;
        *x3 = 0;
    }
}

typedef struct { u8 pad0[4]; u8 b4; u8 b5; u8 pad6[0x16]; s16 h1c; u8 pad1e[0x16]; f32 f34; f32 f38; u8 pad3c[0x20]; f32 f5c; f32 f60; u8 pad64[4]; f32 f68; f32 f6c; } S3;
void func_0037DFD0(S3 *p) {
    extern void func_001E7F60();
    if (((s8 *)p)[0x1B3] != 0) {
        u32 t = p->b5;
        p->b5 = t + 1;
    }
    if (p->h1c != 0) {
        p->h1c = p->h1c - 1;
    } else {
        p->b4 = 2;
    }
    if (p->b5 == 0) func_001E7F60(p);
    p->f34 += p->f5c;
    p->f5c += p->f68;
    p->f38 += p->f60;
    p->f60 += p->f6c;
}

extern void (*D_00475DA0[])();
void func_003C3830(u8 *p, u8 *q) {
    u8 *r = q + 0x2B8;
    u32 t;
    if (q[5] != 0) {
        t = p[4];
        p[4] = t + 1;
        return;
    }
    if (q[0x169] != 0x16) {
        t = p[4];
        p[4] = t + 1;
        return;
    }
    if (r[0xC] == 0) {
        t = p[4];
        p[4] = t + 1;
        return;
    }
    D_00475DA0[p[5]](p, q);
    p[0x24] = *(s8 *)(q + 0x24) + *(s8 *)(p + 0x31);
    if (*(s8 *)(p + 0x24) > 7) *(s8 *)(p + 0x24) = 7;
    if (*(s8 *)(p + 0x24) < 0) *(s8 *)(p + 0x24) = 0;
}

