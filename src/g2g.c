typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern void func_00123090();
extern void func_00151A20();
extern void func_001520E0();
extern void func_00122FE0();
extern void func_003DF850();
extern u8 *D_004C2840;
void func_00152720(void) {
    func_00123090();
    func_00151A20(0xD);
    func_001520E0(0xD);
    if (*(s8 *)(D_004C2840 + 0x92) < 2) {
        func_00122FE0();
        func_00151A20(6);
        func_003DF850(0x62, 0);
        func_001520E0(6);
    }
}
extern void func_003DAA40();
extern s16 D_00445690[][2];
extern f32 D_004456F0[];
extern s32 D_004C2838;
void func_00160F90(u8 *a) {
    s16 i = *(s16 *)(a + 0x1C);
    if (i >= 0x16) {
        func_003DAA40();
    } else {
        *(s16 *)(a + 0xCC) = D_00445690[i][0];
        *(s32 *)(a + 0x84) = D_004C2838;
        *(f32 *)(a + 0x74) = D_004456F0[*(s16 *)(a + 0x1C)];
        *(s16 *)(a + 0x1C) = *(s16 *)(a + 0x1C) + 1;
    }
}
extern void (*D_004C1DC0[2])(u8 *, u8 *);
void func_0038A300(u8 *a) {
    u8 *b = *(u8 **)(a + 0x18);
    if (b[4] >= 2) {
        u32 t = a[4];
        a[4] = t + 1;
        a[0x13C] = 0;
    } else {
        if (b[0x1E4] == 0x1D) {
            *(s8 *)(a + 0x13D) = *(s8 *)(b + 0x13D);
            *(s16 *)(a + 0x13E) = *(s16 *)(b + 0x13E);
        }
        D_004C1DC0[a[5]](a, b);
    }
}
extern s32 func_003D92F0();
extern void func_001843A0();
extern void func_0019DE50();
extern u8 *D_004C2840;
extern void (*D_00451E98[])(u8 *);
void func_0022F020(u8 *a) {
    if (func_003D92F0(a) != 0) {
        func_001843A0(a);
    } else {
        if ((*(u32 *)(D_004C2840 + 0x1C) & 7) == 0) func_0019DE50(a, 2, 0);
        D_00451E98[a[7]](a);
    }
}
extern u8 *func_003DA750();
extern void func_0037B9C0();
extern u16 *D_004C2994;
u8 *func_0037B930(u8 *a) {
    u8 *r = func_003DA750(0, 1, 0);
    if (r == 0) return 0;
    *(void **)(r + 0x10) = (void *)func_0037B9C0;
    *(u8 **)(r + 0x18) = a;
    *(s16 *)(r + 0x26) = 0x1702;
    *(s16 *)(r + 0x140) = *(s16 *)(*(u8 **)(r + 0x18) + 0x140);
    r[7] = (*(u8 **)(r + 0x18))[0x1B7];
    D_004C2994 = (u16 *)(r + 0xD0);
    *D_004C2994 = *(u16 *)(*(u8 **)(r + 0x18) + 0x168);
    return r;
}
extern void func_00176230();
extern void func_00415020();
extern s32 D_004C28B4;
extern u8 *D_004C28B0;
void func_0016F3C0(void) {
    s32 *q;
    u8 *base;
    s32 i;
    func_00176230(D_004C28B4 + 0x2EA00, D_004C28B0);
    base = D_004C28B0;
    i = 0;
    while (*(s32 *)(base + i + 8) > 0) {
        q = (s32 *)(base + i + 8); i += 0x10; *q += (s32)D_004C28B0;
    }
    func_00415020(0xD, D_004C28B0);
}
