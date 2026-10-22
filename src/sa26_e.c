typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;
typedef struct { u8 pad0[4]; u8 b4; u8 pad5[0x20 - 5]; u8 b20; } Q1462;

extern s32 D_004C27E4;
extern s32 D_004C2804;
extern V3 D_004425C0[];
extern V3 D_00442630[];
extern s8 D_004F8010[];
extern s8 D_004F8014[];

void func_001462B0(u8 *p) {
    extern void func_003DAA40();
    u32 t;
    t = p[4];
    if (t == 0) {
        if (p[0x20] == 4) {
            func_003DAA40(p);
            return;
        }
        p[4] = t + 1;
        p[0x13C] = 1;
        switch (p[0x20]) {
        case 4:
        case 5:
            *(s16 *)(p + 0xCC) = 6;
            *(s32 *)(p + 0x84) = D_004C27E4;
            break;
        case 6:
            *(s16 *)(p + 0xCC) = 1;
            *(s32 *)(p + 0x84) = D_004C27E4;
            break;
        case 7:
            *(s16 *)(p + 0xCC) = 2;
            *(s32 *)(p + 0x84) = D_004C27E4;
            break;
        case 8:
            *(s16 *)(p + 0xCC) = 3;
            *(s32 *)(p + 0x84) = D_004C27E4;
            break;
        default:
            *(s16 *)(p + 0xCC) = p[0x20] + 8;
            *(s32 *)(p + 0x84) = D_004C2804;
            break;
        }
        *(V3 *)(p + 0x34) = D_004425C0[p[0x20]];
        *(V3 *)(p + 0x50) = D_00442630[p[0x20]];
    }
    if (p[0x20] == 1) {
        if (D_004F8010[0] == 0 || D_004F8014[0] == 0) {
            *(u32 *)(p + 0x80) = 0x3F19999A;
            *(u32 *)(p + 0x7C) = 0x3F19999A;
            *(u32 *)(p + 0x78) = 0x3F19999A;
        } else {
            *(u32 *)(p + 0x80) = 0x3F800000;
            *(u32 *)(p + 0x7C) = 0x3F800000;
            *(u32 *)(p + 0x78) = 0x3F800000;
        }
    }
}
