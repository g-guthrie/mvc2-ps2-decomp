typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef signed int s32;
typedef unsigned int u32;
typedef unsigned long long u64;

extern s16 D_004C2784;
extern s16 D_004C2788;
extern s16 D_004C278C;
extern s16 D_004C2790;
extern u8 D_004C21EC;
extern u8 D_004C2668;
extern u8 D_004C27D0;
extern s32 D_004C2618;
extern s32 D_004C2814;
extern u32 D_004C2AD0;
extern u8 *D_004C2840;
extern u8 *D_004C28D8;
extern void func_003E0DB0(s32, u64 *, u64 *, u32);

void func_00128380(void) {
    D_004C2790 += 4096;
    D_004C278C += 2048;
    D_004C2788 += 1024;
    D_004C2784 += 512;
}

void func_0012F040(s32 v) {
    if (v == 0) {
        v = 1024;
    }
    D_004C2618 = v;
}

void func_001422E0(u8 *p, s32 a1) {
    p[35] = a1 + 55;
    *(s16 *)(p + 204) = p[35];
    *(s32 *)(p + 132) = D_004C2814;
    p[32] = 0;
    *(s32 *)(p + 116) = 0;
    *(s32 *)(p + 208) = 0;
    p[49] = a1 + 13;
    *(s32 *)(p + 64) = 0;
    *(s32 *)(p + 72) = 0;
}

void func_0016C480(u8 *p) {
    if (D_004C2668) {
        p[4]++;
        *(s16 *)(p + 28) = 32;
    }
}

void func_0032EE50(u8 *p) {
    if (!D_004C27D0) {
        *(s32 *)(p + 68) += 512;
    } else {
        *(s32 *)(p + 68) += 256;
    }
}

void func_003D92D0(u8 *p) {
    u8 v = *(&D_004C21EC + ((s8 *)D_004C2840)[70]);
    p[135] = v;
    p[65] = v;
}

void func_0041DB80(void) {
    D_004C2840[3] = 0;
    D_004C2840[4] = 0;
    D_004C2840[5] = 0;
}

void func_003F0070(s32 present, u64 *first, u64 *second)
{
    if (present) {
        func_003E0DB0(present, first, second, D_004C2AD0);
        second[1] = 8;
        first[1] = 6;
    } else {
        second[0] = 0;
        second[1] = 8;
        first[0] = 0;
        first[1] = 6;
    }
}
