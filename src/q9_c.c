typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 D_004D18A0;
extern u8 D_004D18A3;
extern s8 D_004D18DE;
extern s32 D_004D18A8;
typedef struct {
    u8 p0[5]; u8 f5; u8 p6[0x16]; s16 f1c; u8 p1e[2]; u8 f20;
} P_0;
extern void func_001345B0(u8 *a, u8 *b);
s32 func_00134230(P_0 *a, u8 *b) {
    if (D_004D18A0 != 5) return 1;
    if (D_004D18A3 == 0 && D_004D18DE == b[2] && D_004D18A8 != 0) {
        func_001345B0((u8 *)a, b);
    }
    func_001345B0((u8 *)a, b);
    a->f5 = 0;
    a->f1c = 0;
    a->f20 = 5;
    return 0;
}


extern s32 func_00189310();
extern void func_0018A990();
extern void func_00186A60();
extern u8 D_0045BA40[];
typedef struct {
    u8 p0[5]; u8 f5, f6, f7; u8 p8[0x1E0]; s8 f1e8; u8 p1e9[0xE]; u8 f1f7; u8 p1f8[5]; u8 f1fd; u8 p1fe[0xA]; u8 f208; u8 p209[7]; u8 f210;
} Z_1;
typedef struct {
    u8 p0[5]; u8 f5, f6, f7; u8 p8[0x1E0]; s8 f1e8; u8 p1e9[0xCE]; u8 f1b7_;
} Y_1;
s32 func_002F2390(u8 *a) {
    s8 t;
    if (func_00189310(a, D_0045BA40, a + 0x388) == 0) return 0;
    if (a[0x210] == 0) {
        t = a[0x1E8];
        if (t != 0) return 0;
        a[0x1E8] = t + 1;
    }
    func_0018A990(a, a + 0x388);
    a[0x1B7] = (a[0x1B7] == 1) ? 3 : 2;
    a[5] = 0;
    a[7] = 0;
    a[6] = 0;
    a[0x1FD] = 3;
    func_00186A60(a, 0x15);
    return 1;
}

