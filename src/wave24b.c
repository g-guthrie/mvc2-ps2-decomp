typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;

void func_003DAA40(void *p);
void func_003C9EC0(void *a, void *b);
s32 func_00175700(void *p);
void func_00224BB0(void *p);
void func_001757E0(void *p, s32 a, s32 b);

void func_0015D010(void *a, f32 *b);
extern void func_0018C6E0(void *);
void func_001266A0(void *a, s32 b, s32 c);
void func_0026A100(u8 *a0) {
    f32 v[3];
    v[0] = -53.333332f;
    v[1] = 171.42856f;
    func_0015D010(a0, v);
    a0[436] = 10;
    func_0018C6E0(a0);
    func_001266A0(a0, 5, 5);
}


void *func_003DA750(s32 a, s32 b, s32 c);
void func_001BF4E0(u8 *a0) {
    f32 f;
    *(f32 *)(a0 + 52) = *(f32 *)(*(u8 **)(a0 + 24) + 52);
    *(f32 *)(a0 + 56) = *(f32 *)(*(u8 **)(a0 + 24) + 56);
    f = 1.6666666f * (f32)(s32)(a0[35] << 6);
    if (*(s16 *)(a0 + 320) == 0) f = -f;
    *(f32 *)(a0 + 52) += f;
    *(f32 *)(a0 + 80) = *(f32 *)(*(u8 **)(a0 + 24) + 80);
    *(f32 *)(a0 + 84) = *(f32 *)(*(u8 **)(a0 + 24) + 84);
}

void func_0016CD20(void);
void func_0016CCA0(void) {
    u8 *p = func_003DA750(0, 7, 1);
    if (p != 0) {
        p[316] = 0;
        *(u32 *)(p + 16) = (u32)func_0016CD20;
        *(s32 *)(p + 236) = 2;
        *(s32 *)(p + 240) = 0;
        *(s32 *)(p + 244) = 0;
        *(f32 *)(p + 248) = 0.4f;
        *(f32 *)(p + 252) = 20.0f;
        *(f32 *)(p + 256) = 15.0f;
        *(s32 *)(p + 276) = 0;
        *(s32 *)(p + 284) = 2;
        *(s32 *)(p + 288) = 4101;
        *(f32 *)(p + 280) = 1.0f;
    }
}

extern f32 D_004F1FC8;
extern f32 D_004F1FCC;
s16 func_00118FA8(f32 x);
void func_003C1530(u8 *a0) {
    s16 *s0 = (s16 *)(a0 + 208);
    if (*(s16 *)(a0 + 320) == 0) {
        s0[1] = func_00118FA8(D_004F1FCC);
    } else {
        s0[1] = func_00118FA8(D_004F1FC8);
    }
    if ((f32)s0[0] > 213.33333f) s0[0] = 213;
}

void func_003766B0(u8 *a0) {
    u8 *a1 = *(u8 **)(a0 + 20);
    if (a1[5] >= 4) {
        a0[4] = 2;
    } else if (((s8 *)a1)[337] != 0) {
        f32 k = 92.14285f;
        { u32 t = a0[5]; a0[5] = t + 1; }
        a0[316] = 1;
        *(V3 *)(a0 + 52) = *(V3 *)(*(u8 **)(a0 + 20) + 52);
        *(f32 *)(a0 + 56) = k + *(f32 *)(*(u8 **)(a0 + 20) + 56);
    } else {
        a0[316] = 0;
    }
}

void func_0018D6F0(void *a, s32 b, f32 *c);
void func_00159E50(f32 *v, s32 a);
void func_001E3710(void *a, u8 b);
void func_0016EDA0(s32 a, s32 b);
void func_0018D660(u8 *a0, s32 a1) {
    f32 v[3];
    func_0018D6F0(a0, a1, v);
    *(f32 *)(a0 + 608) = v[0];
    *(f32 *)(a0 + 612) = v[1];
    func_00159E50(v, *(s16 *)(a0 + 320));
    {
        u8 t = 37;
        if ((*(u32 *)(a0 + 1064) & 0x18000) | (*(u32 *)(a0 + 1068) & 0x184000)) t = 38;
        func_001E3710(a0, t);
    }
    func_0016EDA0(a0[2], 2);
}
