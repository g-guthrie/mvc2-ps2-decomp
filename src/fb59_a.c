typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct {
    u8 pad0[4];
    s8 b4;
    u8 pad5;
    s8 b6;
} G_a;

extern G_a *D_004C2840;
extern s8 D_004D157B[];
extern s8 D_004F7D3B[];
extern s32 D_004C27FC;

static void func_0014E770(u8 *p) {
    u8 *q = *(u8 **)(p + 24);
    if (*(s32 *)(q + 220) != 0) {
        if (q[4] == 1) {
            *(s16 *)(p + 30) = *(s16 *)(q + 30);
        } else {
            *(s16 *)(p + 30) = *(s16 *)(q + 30);
        }
    }
}

void func_0014FB00(u8 *p) {
    s32 v;
    func_0014E770(p);
    *(s8 *)(p + 0x13C) = *(s8 *)(*(u8 **)(p + 0x18) + 0x13C);
    if (p[0x23] != 0) {
        if (D_004C2840->b4 != 0) {
            v = D_004D157B[(D_004C2840->b6 + *(s16 *)(p + 0x1E)) * 24] / 10;
        } else {
            v = D_004F7D3B[(D_004C2840->b6 + *(s16 *)(p + 0x1E)) * 24] / 10;
        }
        *(s16 *)(p + 0xCC) = v + 0x25;
        *(s32 *)(p + 0x84) = D_004C27FC;
    } else {
        if (D_004C2840->b4 != 0) {
            v = D_004D157B[(D_004C2840->b6 + *(s16 *)(p + 0x1E)) * 24] % 10;
        } else {
            v = D_004F7D3B[(D_004C2840->b6 + *(s16 *)(p + 0x1E)) * 24] % 10;
        }
        *(s16 *)(p + 0xCC) = v + 0x25;
        *(s32 *)(p + 0x84) = D_004C27FC;
    }
    *(f32 *)(p + 0x74) = *(f32 *)(*(u8 **)(p + 0x18) + 0x74);
}
