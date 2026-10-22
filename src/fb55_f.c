typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct BF {
    unsigned f0 : 6;
    unsigned f6 : 1;
    unsigned f7 : 1;
} BF;

extern s32 D_0062BFD8;
extern u8 D_0062BBB4[];
extern u8 D_0062BBA0[];
extern u32 *D_0062BF9C[];

void func_003DC720(void)
{
    extern u32 *func_003DD030(s32, s32);
    extern void func_00104060(s32);
    extern void func_001028B0(BF *, u32);
    extern void func_003EF980(s32, s32, s32);
    u32 *base;
    u32 *m;
    s32 idx;
    s32 *B;
    u32 w;
    BF *dst;

    idx = D_0062BFD8 ^ 1;
    B = (s32 *)D_0062BBA0;
    if (((s32 *)D_0062BBB4)[idx] != 0) {
        dst = (BF *)D_0062BF9C[B[0]];
        base = func_003DD030(B[idx + 3], B[0]);
        w = base[B[idx + 9]];
        B[11] = w;
        switch ((w & 0xF0000000) >> 28) {
        case 0:
            dst->f6 = 1;
            dst->f7 = 1;
            func_00104060(0);
            func_001028B0(dst, w & 0xFFFFFFF);
            break;
        case 1:
            dst->f6 = 1;
            dst->f7 = 1;
            func_00104060(0);
            func_001028B0(dst, w & 0xFFFFFFF);
            break;
        case 2:
            m = (u32 *)(w & 0xFFFFFFF);
            if (m[2] != 0) {
                func_003EF980(m[2], m[1], m[3]);
            }
            dst->f6 = 1;
            dst->f7 = 1;
            func_00104060(0);
            func_001028B0(dst, m[0]);
            break;
        case 3:
            dst->f6 = 1;
            dst->f7 = 1;
            func_00104060(0);
            func_001028B0(dst, w & 0xFFFFFFF);
            break;
        }
    }
}
