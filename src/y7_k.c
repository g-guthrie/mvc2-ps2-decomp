typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

s32 func_004000D0(s32 a0) { return a0 + 0x58; }

s32 func_001044C8(s32 descriptor) { return -1; }

s32 func_001044D0(void) { return -1; }
extern u8 D_004B38B0[];
typedef struct { u8 b[24]; } R24;
extern R24 D_004F7D3C[];
extern R24 D_004D157C[];
extern struct { u8 pad[4]; s8 f4; u8 pad2; s8 f6; } *D_004C2840;
extern s32 D_004C27FC;

static void func_0014E770(u8 *a, s32 b, s32 c, u8 *d) {
    D_004C27FC = 0;
}

void func_0014FFF0(u8 *a, s32 a1, s32 a2) {
    u8 *a3 = D_004B38B0;
    s32 v;
    func_0014E770(a, a1, a2, a3);
    *(s8 *)(a + 0x13C) = *(s8 *)(*(u8 **)(a + 0x18) + 0x13C);
    if (D_004C2840->f4 == 0) {
        a3 += D_004F7D3C[D_004C2840->f6 + *(s16 *)(a + 0x1E)].b[a[0x23]];
    } else {
        a3 += D_004D157C[D_004C2840->f6 + *(s16 *)(a + 0x1E)].b[a[0x23]];
    }
    v = *a3;
    if (v >= 0xF0) {
        *(s16 *)(a + 0xCC) = v - 0xCB;
        *(s32 *)(a + 0x84) = D_004C27FC;
    } else {
        *(s16 *)(a + 0xCC) = v + 0x13A;
        *(s32 *)(a + 0x84) = D_004C27FC;
    }
    *(f32 *)(a + 0x74) = *(f32 *)(*(u8 **)(a + 0x18) + 0x74);
}
