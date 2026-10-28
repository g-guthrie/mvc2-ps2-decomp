typedef unsigned char u8;
typedef signed char s8;
typedef int s32;
typedef unsigned int u32;

extern s8 D_004C2798[2];
extern u8 D_004D3170[];

s32 func_00185F90(u8 a)
{
    s8 i; s32 j;
    i = 0; j = 0;
    for (; i < D_004C2798[a ^ 1]; i++, j += 4) {
        u8 *q = *(u8 **)(D_004D3170 + (a ^ 1) * 0x178 + j);
        if (q[3] < 5) {
            if ((q[0x15A] & 0xE0) >= 0x80) return 1;
        }
    }
    return 0;
}
