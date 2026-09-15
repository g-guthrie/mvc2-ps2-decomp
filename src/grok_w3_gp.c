typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef signed int s32;

extern u8 *D_004C2840;
extern s32 D_004C2AB4;
extern s32 D_004C2B70;
extern s32 D_004C2B74;
extern s16 D_00633720[];

void func_0032BFF0(void) {
    s8 *p;
    *(s16 *)(D_004C2840 + 8) = *(s16 *)(D_004C2840 + 8) - 1;
    p = (s8 *)D_004C2840;
    if (*(s16 *)(p + 8) <= 0) {
        p[4]++;
        D_004C2840[7] = 1;
        *(s16 *)(D_004C2840 + 8) = 50;
    }
}

void func_0032C750(void) {
    *(s16 *)(D_004C2840 + 8) = *(s16 *)(D_004C2840 + 8) - 1;
    if (*(s16 *)(D_004C2840 + 8) <= 0)
        D_004C2840[3] = 6;
}

void func_0032CFE0(void) {
    s8 *p;
    *(s16 *)(D_004C2840 + 8) = *(s16 *)(D_004C2840 + 8) - 1;
    p = (s8 *)D_004C2840;
    if (*(s16 *)(p + 8) <= 0)
        p[4]++;
}

s32 func_003D70D0(void) {
    s8 *p = (s8 *)D_004C2840;
    if (p[0] == 2 && p[1] == 1 && p[2] == 2)
        return 1;
    return 0;
}

s32 func_003D7130(void) {
    s8 *p = (s8 *)D_004C2840;
    if (p[0] == 2 && p[1] == 1 && p[2] == 4)
        return 1;
    return 0;
}

void func_003D8F60(u8 *p) {
    s16 t = *(s16 *)(p + 18) - 1;
    *(s16 *)(p + 18) = t;
    t = (s16)t;
    if (t <= 0)
        D_004C2840[4] = 3;
}

void func_003EBA10(s32 *p, s32 *n) {
    s32 *old = 0;
    if (p) {
        old = (s32 *)p[1];
        p[1] = (s32)n;
    } else {
        D_004C2AB4 = (s32)n;
    }
    n[0] = (s32)p;
    n[1] = (s32)old;
    if (old)
        old[0] = (s32)n;
}

s32 func_0041CB30(void) {
    s16 *t = (s16 *)((u8 *)D_00633720 + (D_004C2B70 << 4) + (D_004C2B74 << 1));
    return *t & 0xFFC0;
}
