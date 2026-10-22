typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { s8 b0; u8 pad[23]; } E39;
typedef struct { u8 pad0[4]; s8 f4; u8 pad5; s8 f6; } G39;
extern E39 D_004D157A[];
extern E39 D_004F7D3A[];
extern G39 *D_004C2840;
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

void func_0014F850(u8 *p)
{
    s32 r;

    func_0014E770(p);
    p[0x13C] = *(s8 *)(*(u8 **)(p + 0x18) + 0x13C);
    if (p[0x23] != 0) {
        if (D_004C2840->f4 != 0) {
            r = D_004D157A[D_004C2840->f6 + *(s16 *)(p + 0x1E)].b0 / 10;
        } else {
            r = D_004F7D3A[D_004C2840->f6 + *(s16 *)(p + 0x1E)].b0 / 10;
        }
        *(s16 *)(p + 0xCC) = r + 0x25;
        *(s32 *)(p + 0x84) = D_004C27FC;
    } else {
        if (D_004C2840->f4 != 0) {
            r = D_004D157A[D_004C2840->f6 + *(s16 *)(p + 0x1E)].b0 % 10;
        } else {
            r = D_004F7D3A[D_004C2840->f6 + *(s16 *)(p + 0x1E)].b0 % 10;
        }
        *(s16 *)(p + 0xCC) = r + 0x25;
        *(s32 *)(p + 0x84) = D_004C27FC;
    }
    *(f32 *)(p + 0x74) = *(f32 *)(*(u8 **)(p + 0x18) + 0x74);
}
