typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x7C]; s16 f7c[1]; } G10a;
extern G10a *D_004C2794;

void func_00213A70(u8 *p) {
    extern void func_00186A20(u8 *);
    extern void func_00175C00(u8 *, s32);
    extern void func_00185490(u8 *);
    extern void func_0018C4B0(u8 *, s32);
    extern void func_00183D10(u8 *);
    extern s32 func_001757E0(u8 *, s32, s32);
    u32 t = p[6];
    u8 v;
    p[6] = t + 1;
    func_00186A20(p);
    func_00175C00(p, 0);
    func_00185490(p);
    func_0018C4B0(p, 5);
    func_00183D10(p);
    *(f32 *)(p + 0x60) = 8.571428298950195f;
    *(f32 *)(p + 0x6C) = -1.2053570747375488f;
    *(f32 *)(p + 0x5C) = -7.5f;
    *(f32 *)(p + 0x68) = 0;
    if (p[0x1E6] != 0) {
        *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
    }
    v = 0x3F;
    if (p[0x269] == 3) v = 0x46;
    p[0x1B5] = v;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(s32 *)(p + 0x1D8) = 0;
    D_004C2794->f7c[p[2]]++;
    func_001757E0(p, 0x15, 0x2D);
}

extern f32 D_00450CA0[];
extern f32 D_00450CA4[];

void residual_00213350(u8 *p) {
    extern void func_00175C00(u8 *, s32);
    extern void func_00185490(u8 *);
    extern void func_0018C4B0(u8 *, s32);
    extern void func_00183D10(u8 *);
    extern s32 func_001757E0(u8 *, s32, s32);
    u32 t = p[6];
    u8 v;
    f32 a, b, zero;
    s32 i;
    p[6] = t + 1;
    func_00175C00(p, 0);
    func_00185490(p);
    func_00183D10(p);
    func_0018C4B0(p, 10);
    *(s16 *)(p + 0x1C) = p[0x1B7] * 2 + 1;
    *(s16 *)(p + 0x366) = 0;
    i = p[0x1B7] * 2;
    a = D_00450CA0[i];
    *(f32 *)(p + 0x60) = D_00450CA4[i];
    *(f32 *)(p + 0x6C) = -1.2053570747375488f;
    zero = 0;
    if (p[0x1E6] == 0) {
        *(f32 *)(p + 0x5C) -= a;
        if (!(*(f32 *)(p + 0x68) < zero)) {
            *(f32 *)(p + 0x68) -= -0.8333333134651184f;
        } else {
            *(f32 *)(p + 0x68) = -0.8333333134651184f;
        }
    } else {
        *(f32 *)(p + 0x5C) += a;
        if (*(f32 *)(p + 0x68) < zero) {
            *(f32 *)(p + 0x68) += -0.8333333134651184f;
        } else {
            *(f32 *)(p + 0x68) = -0.8333333134651184f;
        }
    }
    v = 0x30;
    if (p[0x269] == 3) v = 0x48;
    p[0x1B5] = v;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(s32 *)(p + 0x1D8) = 0;
    D_004C2794->f7c[p[2]]++;
    func_001757E0(p, 0x14, 2);
}
