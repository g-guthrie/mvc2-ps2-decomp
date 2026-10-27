typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_00230020(u8 *p, u8 *work_unused) {
    f32 a = 5.0f;
    f32 b = -0.1041666641831398f;
    if (*(s16 *)(p + 320) == 0) {
        a = -a;
        b = -b;
    }
    *(f32 *)(p + 92) = a;
    *(f32 *)(p + 104) = b;
    *(u32 *)(p + 96) = 0;
    *(u32 *)(p + 108) = 0;
}


void func_0013F7A0(u8 *p) {
    *(s16 *)(p + 30) = *(s16 *)(p + 30) + 1;
    if (*(s16 *)(p + 30) >= 200) *(s16 *)(p + 30) = 0;
    *(u32 *)(p + 208) = *(u32 *)(p + 208) | 0x20000;
    *(f32 *)(p + 224) = -0.005f * *(s16 *)(p + 30);
    *(f32 *)(p + 228) = -0.005f * *(s16 *)(p + 30);
}

extern int func_00175700(u8 *);
extern void func_001757E0(u8 *, s32, u8);

void func_001F4BE0(u8 *p) {
    func_00175700(p);
    if (((s8 *)p)[337] != 0) {
        u32 t;
        p[337] = 0;
        t = p[7];
        p[7] = t + 1;
        *(f32 *)(p + 92) = 8.333333015441895f;
        *(f32 *)(p + 104) = 0.0f;
        *(f32 *)(p + 96) = 28.928569793701172f;
        *(f32 *)(p + 108) = -1.3392856121063232f;
        if (p[486] == 0) {
            *(f32 *)(p + 92) = -*(f32 *)(p + 92);
            *(f32 *)(p + 104) = -*(f32 *)(p + 104);
        }
    }
}

extern void func_002A70B0(u8 *);

void func_002A6FB0(u8 *p) {
    f32 a, b;
    func_002A70B0(p);
    *(f32 *)(p + 56) = *(f32 *)(p + 56) - 2.142857074737549f;
    a = *(f32 *)(p + 56);
    b = 102.85713958740234f + *(f32 *)(p + 1072);
    if (a <= b || (*(u16 *)(p + 862) & 0x400) == 0) {
        u32 t = p[6];
        p[6] = t + 1;
        func_001757E0(p, 20, 4);
    }
}

extern u8 *func_003DA750(s32, s32, s32);
extern void func_003BDA40(void);

void func_003BD9A0(u8 *a, u8 *b) {
    u32 i;
    for (i = 0; (u8)i < 5; i = (i + 1) & 0xff) {
        u8 *r = func_003DA750((s32)a, 1, 2);
        if (r != 0) {
            r[0] = 1;
            *(void **)(r + 16) = func_003BDA40;
            *(u8 **)(r + 24) = b;
            *(u8 **)(r + 220) = a;
            r[1] = b[1];
            *(s16 *)(r + 38) = 13824;
            r[32] = 1;
            r[33] = i;
        }
    }
}

typedef struct { f32 x, y, z, w; } V2;
extern void func_0015D010(u8 *, V2 *);
extern void func_001266A0(u8 *, s32, s32);
extern void func_0018C6E0(void *);

void func_0025B6C0(u8 *p) {
    V2 v;
    if ((*(u16 *)(p + 526) & 0x400) != 0) {
        ((s8 *)p)[486] = ((s8 *)p)[486] ^ 1;
        *(s16 *)(p + 320) = *(s16 *)(p + 320) ^ 1;
    }
    v.x = -83.33332824707031f;
    v.y = 158.57142639160156f;
    func_0015D010(p, &v);
    p[436] = 10;
    func_001266A0(p, 5, 5);
    func_0018C6E0(p);
    func_001757E0(p, 15, 2);
}

void func_001C8220(u8 *p, u8 *q) {
    f32 lim;
    *(f32 *)(p + 52) += *(f32 *)(p + 92);
    *(f32 *)(p + 92) += *(f32 *)(p + 104);
    *(f32 *)(p + 56) += *(f32 *)(p + 96);
    *(f32 *)(p + 96) += *(f32 *)(p + 108);
    lim = 6.428571224212646f + *(f32 *)(q + 1072);
    if (*(f32 *)(p + 56) <= lim) {
        u32 t = p[7];
        p[7] = t + 1;
        *(f32 *)(p + 56) = lim;
        func_001757E0(p, 18, 8);
    }
}
