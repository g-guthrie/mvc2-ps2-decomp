typedef float f32;
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern u8 *D_004C2840;
extern s32 D_004C27FC;
typedef struct { s8 b[24]; } R24;
extern R24 D_004F7D34[];
extern R24 D_004D1574[];

static void func_0014E770(u8 *p) {
    *(s32 *)(p + 0x20) = 0;
}

void func_0014E9B0(u8 *p) {
    func_0014E770(p);
    p[0x13C] = *(s8 *)(*(u8 **)(p + 0x18) + 0x13C);
    if (*(s8 *)(D_004C2840 + 4) == 0) {
        *(s16 *)(p + 0xCC) = D_004F7D34[*(s8 *)(D_004C2840 + 6) + *(s16 *)(p + 0x1E)].b[p[0x21]] + 0x31;
        *(s32 *)(p + 0x84) = D_004C27FC;
    } else {
        *(s16 *)(p + 0xCC) = D_004D1574[*(s8 *)(D_004C2840 + 6) + *(s16 *)(p + 0x1E)].b[p[0x21]] + 0x31;
        *(s32 *)(p + 0x84) = D_004C27FC;
    }
    *(f32 *)(p + 0x74) = *(f32 *)(*(u8 **)(p + 0x18) + 0x74);
}

extern u8 D_00451BD0[], D_00451BD4[], D_00451BD8[], D_00451BDC[];

void func_0022BA40(u8 *p) {
    extern s8 func_00175700();
    extern void func_001757E0();
    if (func_00175700(p) < 0) {
        u32 t = p[6];
        f32 z = 0.0f;
        f32 a, b;
        u32 k;
        p[6] = t + 1;
        k = p[0x1B7] << 4;
        a = *(f32 *)(D_00451BD0 + k);
        b = *(f32 *)(D_00451BD4 + k);
        *(f32 *)(p + 0x60) = *(f32 *)(D_00451BD8 + k);
        *(f32 *)(p + 0x6C) = *(f32 *)(D_00451BDC + k);
        if (!(*(f32 *)(p + 0x34) <= z)) {
            a = -a;
            b = -b;
        }
        *(f32 *)(p + 0x5C) = a;
        *(f32 *)(p + 0x68) = b;
        func_001757E0(p, 0xF, 5);
    }
}
