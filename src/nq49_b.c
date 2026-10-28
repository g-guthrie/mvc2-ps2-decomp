typedef unsigned char u8;
typedef signed char s8;
typedef short s16;
typedef int s32;
typedef unsigned int u32;

extern u8 *D_004C2840;
extern s16 D_004D1800[];
extern s16 D_004469E0[];
extern u8 *D_004469C0[];

void func_00171110(u8 *p) {
    s16 *g = D_004D1800;
    u32 i;
    u32 v;
    if (*(s8 *)(D_004C2840 + 0x2E) != 0) {
        g[1] = 0x1F;
        return;
    }
    i = 0;
    goto test;
body:
    if (*(s16 *)(p + 0x522) <= D_004469E0[i]) goto done;
    if (i + 1 >= 0x20) {
        *(s16 *)(p + 0x522) = D_004469E0[i + 1];
    }
    i++;
test:
    if (i < 0x1F) goto body;
done:
    g[1] = i;
    { u8 *r = D_004469C0[*(s8 *)(D_004C2840 + 0x29)]; r += (*(s8 *)(D_004C2840 + 0x85) & 7) + g[0] * 8; v = *r; }
    if (g[1] >= (s32)v) {
        g[1] = (u8)v;
        *(s16 *)(p + 0x522) = D_004469E0[g[1]];
    }
    g[1] &= 0x1F;
}
