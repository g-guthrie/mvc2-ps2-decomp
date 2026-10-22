typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 *p[94]; } T3170;
extern s8 D_004C2798[2];
extern T3170 D_004D3170[];

s32 func_0016AD50(u8 *a0, u8 *a1)
{
    extern s32 func_0016AF10();
    extern s32 func_0016AFE0();
    s16 v[4];
    u8 *o;
    u8 *s2;
    u16 *s3;
    s32 i;
    s32 j;
    s32 n;
    v[0] = *(s16 *)(a1 + 0);
    v[1] = *(s16 *)(a1 + 4);
    v[2] = (*(s16 *)(a0 + 0x140) & 1) ? *(s32 *)(a1 + 8) : -*(s32 *)(a1 + 8);
    v[3] = (*(s16 *)(a0 + 0x140) & 2) ? -*(s32 *)(a1 + 0xC) : *(s32 *)(a1 + 0xC);
    n = D_004C2798[a0[2] ^ 1];
    for (i = 0; i < n; i++) {
        o = D_004D3170[a0[2] ^ 1].p[i];
        s2 = *(u8 **)(o + 0x180);
        s3 = *(u16 **)(o + 0x1D4);
        if (o[3] == 0 || o[3] == 1 || o[3] == 3) {
            for (j = 0; j < 2; j++, s3++) {
                u32 k = *s3 & 0xFFF;
                if (k != 0) {
                    if (func_0016AF10(a0, o, v, s2 + k * 8) != 0) {
                        if (func_0016AFE0(a0, o, v, s2 + (*s3 & 0xFFF) * 8) != 0) return 1;
                    }
                }
            }
        }
    }
    return 0;
}
