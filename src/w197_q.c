typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef struct { u8 pad[0x7C]; s16 f7c[1]; } G197n;
extern G197n *D_004C2794;

void func_003D7B50(u8 *p, u8 *q) {
    extern void func_003D7D50(u8 *, u8 *);
    extern void func_003D7CC0(u8 *, u8 *);
    extern s32 func_00174470(u8 *);
    extern void func_001E7F60(u8 *);
    u8 *a = *(u8 **)(p + 0x14);
    u8 *b = *(u8 **)(p + 0x8);
    u32 t;
    if (a[4] >= 2) {
        p[4] = 3;
        p[0x13C] = 0;
        return;
    }
    if (b[4] >= 2) {
        p[4] = 3;
        p[0x13C] = 0;
        return;
    }
    func_003D7D50(p, q);
    func_003D7CC0(p, a);
    t = p[0x20];
    p[0x20] = t + 1;
    if (func_00174470(p) == 0) {
        p[4] = 3;
        p[0x13C] = 0;
        return;
    }
    if (*(s8 *)(p + 0x1B3) != 0) {
        p[0x1B3] = 0;
        *(s32 *)(p + 0xD4) = 0;
        return;
    }
    if (*(s8 *)(p + 0x1B2) != 0) {
        p[0x1B2] = 0;
        *(s32 *)(p + 0xD4) = 0;
        return;
    }
    p[0x1B0] = 0x42;
    if (*(s32 *)(p + 0xD0) == 0 && *(s32 *)(p + 0xD4) == 0) {
        p[0x1B0] = 0;
    }
    p[0x1B5] = q[0x1B5];
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(s32 *)(p + 0x1D8) = 0;
    D_004C2794->f7c[p[2]]++;
    func_001E7F60(p);
}
