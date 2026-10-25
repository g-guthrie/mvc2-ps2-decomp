typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

#define F(o) (*(float *)(p + (o)))

extern u8 *func_003DA750();
extern void func_00342D40();
extern s32 D_004C283C;
typedef struct { float x, y, z; } V3;
extern V3 D_004606E0;
void func_003431D0(void) {
    u8 *o = func_003DA750(0, 6, 0);
    if (o) {
        o[0x13C] = 1;
        *(void **)(o + 0x10) = func_00342D40;
        *(s16 *)(o + 0xCC) = 5;
        *(s32 *)(o + 0x84) = D_004C283C;
        *(s32 *)(o + 0xD0) = 0x80B;
        *(V3 *)(o + 0x34) = D_004606E0;
    }
}

extern void func_00330AA0();
extern V3 D_004B7870[];
void func_00330B80(s32 n) {
    u8 *o = func_003DA750(0, 6, 1);
    if (o) {
        o[0x13C] = 1;
        *(void **)(o + 0x10) = func_00330AA0;
        *(s16 *)(o + 0xCC) = n + 0xC;
        *(s32 *)(o + 0x84) = D_004C283C;
        *(s32 *)(o + 0xD0) = 0x801;
        *(V3 *)(o + 0x34) = D_004B7870[n];
        o[0x20] = n;
    }
}

extern s8 func_00175700();
extern s32 func_0036A5F0();
extern void func_0036A600();
extern u8 *D_004C2988;
void func_0036A140(u8 *p) {
    func_00175700(p);
    if (func_0036A5F0(p)) {
        p[5] = 0xF;
    } else if (*(s8 *)(D_004C2988 + 0xC)) {
        u32 t = p[5];
        p[5] = t + 1;
        *(s16 *)(p + 0x1C) = 0x78;
    } else {
        s16 t = *(s16 *)(p + 0x1C) - 1;
        *(s16 *)(p + 0x1C) = t;
        if (t == 0) func_0036A600(p);
    }
}

extern void func_001757E0();
extern void func_003C9200();
extern u8 D_004C2178[4][2];
void func_003C9170(u8 *p,void *owner_unused) {
    u8 *q = *(u8 **)(p + 0x18);
    if (*(s8 *)(q + 0x2BC) == 3) {
        u32 t = p[7];
        u8 *r;
        p[7] = t + 1;
        r = *(u8 **)(q + 0x220);
        *(float *)(p + 0x34) = *(float *)(r + 0x34);
        *(float *)(p + 0x38) = *(float *)(r + 0x38);
        func_001757E0(p, 0x14, D_004C2178[p[0x20]][0]);
        func_003C9200(p, q);
    } else {
        func_003C9200(p, q);
    }
}

extern void func_00341800();
typedef struct { s32 a[2]; } P2;
extern P2 D_004C1958;
extern P2 D_004C1960;
void func_00341900(u8 *p) {
    P2 a = D_004C1958;
    P2 b = D_004C1960;
    s32 j, i;
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 8; j++) {
            func_00341800(p, a.a[i] + j - 1, b.a[i], 5);
        }
    }
}

typedef void (*Fn2)(u8 *, u8 *);
extern Fn2 D_004C2150[2];
void func_003C4350(u8 *p) {
    u8 *q = *(u8 **)(p + 0x18);
    s8 t;
    D_004C2150[p[0x20]](p, q);
    *(s8 *)(p + 0x24) = *(s8 *)(q + 0x24) + *(s8 *)(p + 0x31);
    if (*(s8 *)(p + 0x24) > 7) *(s8 *)(p + 0x24) = 7;
    if (*(s8 *)(p + 0x24) < 0) *(s8 *)(p + 0x24) = 0;
}

extern u8 *D_004C299C;
void func_0037F1D0(u8 *p) {
    float f;
    u8 *q = *(u8 **)(p + 0x18);
    *(float *)(p + 0x34) = *(float *)(q + 0x34);
    *(float *)(p + 0x38) = *(float *)(*(u8 **)(p + 0x18) + 0x38);
    f = 1.6666666f * (float)(D_004C299C[6] << 5);
    if (*(s16 *)(p + 0x140) == 0) f = -f;
    *(float *)(p + 0x34) += f;
}
