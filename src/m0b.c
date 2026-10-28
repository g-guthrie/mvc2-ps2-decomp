typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
extern s32 func_00185980(void *p);
extern void (*D_0044EE60[])(u8 *, u8 *);
extern s32 func_00175700(void *p);
extern void func_001757E0(void *p, s32 a, s32 b);
extern s32 func_00189660(void *p, void *a, void *b);
extern void func_00186A60(void *p, s32 a);
extern u8 D_00450AB0[];
extern u8 *D_004C2794;
extern void func_0036A930(void *p, s32 a, s32 b, s32 c);
extern s32 func_001843A0(void *p);
extern void *func_003996C0(void *p, u8 a);
extern void func_0019B110(void *p, s32 a);
extern void func_001CEA00(void *p, s32 a);
typedef struct { f32 x, y, z; } V3;
extern int func_00174170(void);
extern s32 func_003D92F0(void *p);
extern void func_002F1DF0(void *p);
extern u8 D_004C1248[8];
extern void func_00178F20(void *a, void *b);
extern void func_001E3710(void *a, s32 b);
extern u8 D_004F20B4, D_004F20B5, D_004F20B6, D_004F20B7, D_004F2294, D_004F2295, D_004F2298, D_004F2299;
extern u8 D_004F266C, D_004F266D, D_004F266E, D_004F266F, D_004F284C, D_004F284D, D_004F2850, D_004F2851;
extern f32 D_004F7FD4;
extern void func_003DAA40();
extern u8 *func_003DA750(s32 a, s32 b, s32 c);
extern void func_0033D0D0();
extern u32 D_004C283C;
extern V3 D_0045EE98;
extern void func_0039F480();
extern s32 func_00189310(void *p, void *a, void *b);
extern u8 D_0045BD80[];
extern int func_00174470(const void *);
extern void func_0034FA60(void *p);
extern void func_001E7F60(void *p);
extern u8 D_0045BD90[];
extern void (*D_0044F420[])(u8 *, u8 *);
extern void func_001BFCA0(void *p, s32 a);
extern u8 D_0045D6C0[];
extern void func_0018A990();
extern V3 D_004B82B0[];
extern void func_00341170();
extern void func_00184540();

u8 *func_0035EF40(u8 *p) {
    if (!func_00185980(p)) return 0;
    if ((*(u8 **)(p + 0x1C4))[0x1B6] != 0x37) return 0;
    return *(u8 **)(p + 0x1C4);
}

s32 func_002F6FA0(u8 *p) {
    if (p[0x2CE]) return 0;
    if (!func_00189310(p, D_0045BD80, p + 0x3B0)) return 0;
    if (!*(s8 *)(*(u8 **)(p + 0x420))) return 0;
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    p[0x1FD] = 0xB;
    func_00186A60(p, 0x1D);
    return 1;
}

s32 func_002F7030(u8 *p) {
    if (p[0x2CE]) return 0;
    if (!func_00189310(p, D_0045BD90, p + 0x3C0)) return 0;
    if (!*(s8 *)(*(u8 **)(p + 0x420))) return 0;
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    p[0x1FD] = 0xD;
    func_00186A60(p, 0x1D);
    return 1;
}

s32 func_00316E40(u8 *p) {
    if (!func_00189310(p, D_0045D6C0, p + 0x378)) return 0;
    if (!*(s8 *)(*(u8 **)(p + 0x420))) return 0;
    if (*(s8 *)(p + 0x2BF)) return 0;
    func_0018A990(p, p + 0x378);
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    p[0x1FD] = 0;
    func_00186A60(p, 0x1D);
    return 1;
}
s32 func_00210940(u8 *p) {
    if (!func_00189660(p, D_00450AB0, p + 0x3A8)) return 0;
    p[0x1FD] = 9;
    p[5] = 0;
    func_00186A60(p, 0x15);
    p[7] = 0;
    p[6] = 0;
    return 1;
}
