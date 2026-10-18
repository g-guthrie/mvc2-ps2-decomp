typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef long long s64;

extern void func_0037F2C0(u8 *p);
extern u32 D_004C1D40[2];
void func_0037F780(u8 *p) {
    ((void (*)(u8 *))D_004C1D40[p[5]])(p);
    func_0037F2C0(p);
}

extern u8 *D_004C2840;
extern u8 D_004F20B0[];
extern u8 D_004F2668[];
extern void func_00171110(u8 *a);
void func_001710C0(void) {
    u8 *a = D_004C2840;
    if (*(s8 *)(a + 0x8F) == 0) {
        u8 *arg = D_004F20B0;
        if (*(s8 *)(a + 0x88) == 2) arg = D_004F2668;
        func_00171110(arg);
    }
}

extern s8 D_004C2868;
extern s32 func_0012ABC0(s32 a, s32 b);
extern s8 func_0012A990(s32 a, s32 b, s32 c, s32 d);
void func_0012A0D0(s8 *p) {
    D_004C2868 = func_0012A990(func_0012ABC0(3, 0), D_004C2868, 7, 2);
    *p = D_004C2868;
}

extern s32 D_004C284C;
extern s32 D_004C2850;
extern u8 D_004C27BC;
extern void func_00402498(void);
extern void func_0012F0B0(void);
s32 func_0012F460(void) {
    *(s32 *)(D_004C2840 + 0x10) += 1;
    D_004C284C += 1;
    if (D_004C2850 != 0) D_004C2850 -= 1;
    D_004C27BC = 0;
    func_00402498();
    func_0012F0B0();
    return 0;
}

extern s32 D_004C2838;
typedef struct { float x, y, z; } V3;
extern V3 D_00444A88;


extern u8 *D_004C2938;
void func_00345EE0(u8 *p) {
    float k = 1.5f;
    float v;
    u8 *q = *(u8 **)(p + 0x18);
    *(float *)(p + 0x34) = *(float *)(q + 0x34);
    *(float *)(p + 0x38) = *(float *)(*(u8 **)(p + 0x18) + 0x38);
    v = k * (float)((s32)D_004C2938[6] << 5);
    if (*(s16 *)(p + 0x140) == 0) v = -v;
    *(float *)(p + 0x34) = *(float *)(p + 0x34) + v;
}
