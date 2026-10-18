typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 *D_004C2840;
extern u8 D_004D1580[];
extern u8 D_004D1584[];
extern u8 D_004F7D40[];
extern u8 D_004F7D44[];

s32 func_001503E0(u8 *a, s32 b) {
    u8 *g;
    u8 *tab;
    s32 m;
    u32 e;
    s32 idx;
    if (b >= 8) {
        g = D_004C2840;
        m = -1;
        if (*(s8 *)(g + 4) != 0) {
            idx = *(s8 *)(g + 6) + *(s16 *)(a + 0x1E);
            e = *(u32 *)(D_004D1584 + idx * 24);
        } else {
            idx = *(s8 *)(g + 6) + *(s16 *)(a + 0x1E);
            e = *(u32 *)(D_004F7D44 + idx * 24);
        }
        m = m << ((b - 8) * 4);
        if ((e & m) != 0) return 1;
        return 0;
    } else {
        g = D_004C2840;
        m = -1;
        if (*(s8 *)(g + 4) != 0) {
            idx = *(s8 *)(g + 6) + *(s16 *)(a + 0x1E);
            e = *(u32 *)(D_004D1580 + idx * 24);
        } else {
            idx = *(s8 *)(g + 6) + *(s16 *)(a + 0x1E);
            e = *(u32 *)(D_004F7D40 + idx * 24);
        }
        m = m << (b * 4);
        if ((e & m) != 0) return 1;
        return func_001503E0(a, 8) != 0;
    }
}
