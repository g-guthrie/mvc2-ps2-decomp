typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3_001556E0;
extern s32 D_004C283C;
extern V3_001556E0 D_00444A78;
void func_00155600(void);
void func_001556E0(u8 *p) {
    extern u8 *func_003DA750(u8 *, s32, s32);
    u8 *o;
    *(s32 *)(p + 0xD0) = 0x40D;
    *(s16 *)(p + 0xCC) = 0x58;
    *(s32 *)(p + 0x84) = D_004C283C;
    *(u32 *)(p + 0x78) = 0x3F800000;
    *(s32 *)(p + 0x7C) = 0;
    *(s32 *)(p + 0x80) = 0;
    if (p[3] == 8) {
        *(s32 *)(p + 0xD0) |= 0x10;
        *(V3_001556E0 *)(p + 0x50) = D_00444A78;
    }
    if ((o = func_003DA750(p, p[3], 2)) != 0) {
        *(void **)(o + 0x10) = func_00155600;
        *(s32 *)(o + 0x18) = *(s32 *)(p + 0x18);
        o[0x20] = *(s8 *)(p + 0x20) + 1;
        o[0x21] = p[0x21];
    }
}

typedef struct G_0013BE20 {
    u8 pad0[3];
    s8 b3;
    u8 pad4[0x89 - 4];
    s8 b89;
} G_0013BE20;
extern G_0013BE20 *D_004C2840;
extern u8 D_00583BC3[];
void func_0013BE20(u8 *p) {
    switch (p[6]) {
    case 0:
        if (D_004C2840->b3 < 3) {
            break;
        }
        p[6] = p[6] + 1;
        D_00583BC3[0] |= p[0x20];
    case 1: {
        G_0013BE20 *g = D_004C2840;
        if (g->b3 == 3) {
            if ((g->b89 & p[0x21]) != 0) {
                D_00583BC3[0] |= 3;
                { u32 t = p[6]; p[6] = t + 1; }
            }
        } else if (g->b3 == 5) {
            { u32 t = p[6]; p[6] = t + 1; }
            D_00583BC3[0] |= 3;
        }
        break;
    }
    case 2:
        break;
    }
}
