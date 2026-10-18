typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;
extern V3 D_00442590[];
extern V3 D_00442780[];
extern s8 D_00442838[];
extern s8 D_00442828[];
extern u8 *D_004C2840;
extern s32 D_004C27E4;
extern s32 D_004C2804;
void func_001465D0(u8 *p) {
    if (p[0x20] == 0) {
        s8 m;
        u8 t = p[4];
        if (t == 0) {
            p[4] = t + 1;
            p[0x13C] = 1;
        }
        *(V3 *)(p + 0x34) = D_00442590[0];
        m = *(s8 *)(D_004C2840 + 0x4C);
        switch (m) {
        case 4:
        case 5:
        case 6:
            *(s16 *)(p + 0xCC) = D_00442838[m];
            *(s32 *)(p + 0x84) = D_004C27E4;
            *(f32 *)(p + 0x3C) += -13.0f;
            break;
        default:
            *(s16 *)(p + 0xCC) = D_00442828[m];
            *(s32 *)(p + 0x84) = D_004C2804;
            break;
        }
    } else {
        u8 t = p[4];
        if (t == 0) {
            p[4] = t + 1;
            p[0x13C] = 1;
            *(s16 *)(p + 0xCC) = p[0x20] + 3;
            *(s32 *)(p + 0x84) = D_004C2804;
            *(V3 *)(p + 0x34) = D_00442780[p[0x20]];
        }
    }
}
