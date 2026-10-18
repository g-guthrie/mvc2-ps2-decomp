typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 *D_004C2840;
extern s16 D_004BF518[2];
extern void (*D_0045DB00[])(void *);

extern void func_001757E0(void *p, s32 a, s32 b);
extern s32 func_00175700(void *p);
extern void func_00175C00(void *p, s32 a);
extern void func_00184540(void *p);
extern s32 func_001864A0(void *p);
extern void func_001865B0(void *p);
extern u8 D_0045BA10[];
extern s32 func_00189310(void *p, void *a, void *b);
extern void func_00186A60(void *p, s32 a);

void func_00190A80(u8 *p) {
    s32 f;
    *(f32 *)(p + 0x34) += 1.666666627f * (f32)D_004BF518[*(u32 *)(D_004C2840 + 0x94) & 1];
    f = *(s8 *)(p + 0x1B4);
    if (!(f & 1)) {
        if (f & 2) {
            func_00175C00(p, 3);
        } else {
            func_00175C00(p, 1);
        }
    }
    if (*(s8 *)(p + 0x1B4) == 0) {
        func_00175C00(p, 1);
        p[0x295] = 0;
        p[0x31] = 0;
    }
}

s32 func_002F25E0(u8 *p) {
    if (func_00189310(p, D_0045BA10, p + 0x3A8) == 0) return 0;
    if (**(s8 **)(p + 0x420) == 0) return 0;
    if (p[0x20D] == 2 && p[0x210] == 0) {
        s32 v = *(s8 *)(p + 0x1E8);
        if (v != 0) return 0;
        p[0x1E8] = v + 1;
    }
    p[5] = 0;
    p[6] = 9;
    p[7] = 0;
    p[0x1FD] = 10;
    func_00186A60(p, 0x1D);
    return 1;
}

