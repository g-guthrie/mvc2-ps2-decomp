typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s8 *D_004C2938;
extern s8 *D_004C2934;
void func_001757E0(void *, s32, s32);
void func_00346110(void *a0) {
    s8 *a = D_004C2938;
    s8 *c = D_004C2934;
    if (*a != *c) {
        u32 x = 0;
        u8 *b;
        u32 k;s32 m;
        *a = *c;
        b = (u8 *)D_004C2938;
        m = (s8)b[0]; k = (m * 3) & 0xFF;
        if (b[6]) x = b[1];
        func_001757E0(a0, 0x19, (x + k) & 0xFF);
    }
}

typedef struct { f32 x, y, z; } V3;
extern u8 *D_004C2794;
extern u8 *D_004C2840;
extern u32 D_00449000[][32];
s32 func_00174170(void);
s32 func_0018ABB0(u8 *a0) {
    u32 b;
    if (a0[0x425]) return 0;
    if (*D_004C2794 != 4) return 0;
    b = 1 << (func_00174170() & 0x1F);
    return (b & D_00449000[*(s8 *)(D_004C2840 + 0x87)][0]) != 0;
}

extern void (*D_004BF590[2])(void *, void *);
s32 func_00197810(void *);
void func_00196C70(u8 *a0, u8 *a1) {
    u8 *s0 = a0 + 0x88;
    u8 *s1 = a1 + 0x2B8;
    if (func_00197810(a0)) {
        if (a1[0x1E4] != 0x16) s1[0xC] = 0;
        s0[0] = 0;
    }
    D_004BF590[a0[5]](a0, a1);
}

extern s16 D_004BF9D8[4];
void func_001C1BC0(u8 *a0, u8 *a1) {
    if (*(s16 *)(a1 + 0x140) == 0) {
        *(f32 *)(a0 + 0x34) = -11.666666f + *(f32 *)(a1 + 0x34);
    } else {
        *(f32 *)(a0 + 0x34) = *(f32 *)(a1 + 0x34) - -11.666666f;
    }
    *(f32 *)(a0 + 0x38) = *(f32 *)(a1 + 0x38) + 2.1428571f * (f32)D_004BF9D8[a1[0x20D]];
}

extern u8 D_004F1CD8[];
extern f32 D_004F1CE0[];
extern u8 D_004C27D0;
extern u8 D_00477130[];
extern u8 D_0047713C[];
void func_0011D8F8(void *, s32, s32);
void func_0016F090(void *);
void func_0016F0C0(f32);
void func_003D14F0(void);
void func_003D1040(void);
void func_003D0FA0(void);
void func_003D0EE0(void) {
    func_0011D8F8(D_004F1CD8, 0, 12);
    D_004F1CE0[0] = 1.0f;
    if (D_004C27D0 == 0 || D_004C27D0 == 9) {
        func_0016F090(D_00477130);
    } else {
        func_0016F090(D_0047713C);
    }
    func_0016F0C0(1.0f);
    func_003D14F0();
    func_003D1040();
    func_003D0FA0();
}

extern f32 D_00440110[];
extern f32 D_00440114[];
extern s8 D_00440180[][3];
void func_0032DE90(void *, s32, f32, f32);
void func_0013AE00(u8 *a0) {
    s32 i = D_00440180[a0[1]][a0[0x21]];
    f32 x = D_00440110[i * 2] - D_00440110[0];
    f32 y = D_00440114[0] - D_00440114[i * 2];
    if (*(s8 *)(D_004C2840 + 0x29)) {
        func_0032DE90(a0, 0x6D, x, y);
    } else {
        func_0032DE90(a0, 0x67, x, y);
    }
}
