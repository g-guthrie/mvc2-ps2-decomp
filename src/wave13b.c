typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef float f32;
typedef unsigned short u16;
extern s32 D_004C28AC;
extern s32 D_004C28B8;
extern u8 *D_004C2840;
extern s8 D_004F7F5C[];
extern s8 D_004C285C;
extern u8 *D_004C2794;
extern u32 D_004BFE40[2];
extern s16 D_004BF508[4];
extern u8 *D_004C2B50;
extern u32 D_004C1B60[2];
extern u32 D_004C2158[2];
extern void func_0011D740(s32, s32, s32);
extern void func_0016F720(void);
extern void func_003D3750(void);
extern void func_0016DCB0(s32, s32);
extern u8 *func_0012ABC0(s32, s32);
extern s32 func_0012A990(u8 *, s32, s32, s32);
extern void func_0020D2A0(void);
extern void func_001757E0(u8 *, s32, s32);
extern void func_0018C4B0(u8 *, s16);
extern void func_001E5F30(void);
extern s32 func_00401920(void);
extern void func_00401868(u8 *);
extern void func_0035D340(u8 *);



void func_003D3DD0(void) {
    func_003D3750();
    if (D_004F7F5C[0] != 0) func_0016DCB0(0xD, *(s8 *)(D_004C2840 + 0xB5) + 0xD);
}

void func_0012A1C0(u8 *p) {
    D_004C285C = func_0012A990(func_0012ABC0(3, 0), D_004C285C, 2, 2);
    p[3] = D_004C285C;
}

void func_0020C460(u8 *a, u8 *b) {
    if (b[9] != 0) func_0020D2A0();
    else ((void (*)(void))D_004BFE40[a[7]])();
}

void func_0034B310(u8 *p) {
    *(s16 *)(p + 0x140) ^= 1;
    p[0x1B5] = 0x43;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(s32 *)(p + 0x1D8) = 0;
    ((s16 *)(D_004C2794 + 0x7C))[p[2]] += 1;
    func_001757E0(p, 0x16, 0xE);
}

void func_001855D0(u8 *p) {
    s16 v = D_004BF508[p[0x1BB]];
    if (p[0x214] != 0) {
        if ((*(u32 *)(p + 0x428) & 0x480) | (*(u32 *)(p + 0x42C) & 0x2020000)) v = v >> 1;
    }
    p[0x424] = v;
    func_0018C4B0(p, v);
}

void func_0035D240(u8 *a, u8 *b) {
    if (b[0x169] != 0x16) { a[4]++; func_0035D340(a); }
    else ((void (*)(void))D_004C1B60[a[5]])();
}
