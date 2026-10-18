typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad0[4]; s8 b4; u8 pad5; s8 b6; } G2840;
extern G2840 *D_004C2840;
extern s8 D_004F7D31[][24];
extern s8 D_004D1571[][24];
extern s8 D_004CB012[][4];
extern u32 D_004C27FC;

void func_0014ECD0(u8 *p) {
    G2840 *g = D_004C2840;
    u8 *q;
    s8 x;
    q = *(u8 **)(p + 0x14);
    if (g->b4 == 0) {
        x = D_004F7D31[g->b6 + *(s16 *)(q + 0x1E)][q[0x21]];
    } else if (g->b4 == 1) {
        x = D_004D1571[g->b6 + *(s16 *)(q + 0x1E)][q[0x21]];
    } else if (g->b4 == 2) {
        x = D_004CB012[g->b6 + *(s16 *)(q + 0x1E)][0];
    }
    *(s8 *)(p + 0x13C) = *(s8 *)(*(u8 **)(p + 0x18) + 0x13C);
    if (x > 23) x -= 3;
    *(s16 *)(p + 0xCC) = x + 0x3A;
    *(u32 *)(p + 0x84) = D_004C27FC;
    *(f32 *)(p + 0x74) = *(f32 *)(*(u8 **)(p + 0x18) + 0x74);
}
