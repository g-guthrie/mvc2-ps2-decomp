typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef unsigned long long u64;

extern s32 D_004C2AD0;

void func_003F00E0(s32 a0, u64 *a1, u64 *a2, s32 a3, u64 *t0, u64 *t1)
{
    extern void func_003E0DB0();
    if (a0 != 0) {
        func_003E0DB0(a0, a1, a2, D_004C2AD0);
        a2[1] = 8;
        a1[1] = 6;
    } else {
        a2[0] = 0;
        a2[1] = 8;
        a1[0] = 0;
        a1[1] = 6;
    }
    if (a3 != 0) {
        func_003E0DB0(a3, t0, t1, D_004C2AD0);
        a2[1] = 9;
        a1[1] = 7;
    } else {
        t1[0] = 0;
        t1[1] = 9;
        t0[0] = 0;
        t0[1] = 7;
    }
}
