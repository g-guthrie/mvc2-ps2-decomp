typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { u16 h0; u16 h2; f32 f4; f32 f8; } Gd;
typedef struct { f32 a, b; } F2d;

extern Gd *D_004C29D0;
extern u8 *D_004C29D4;
extern F2d D_00471E10[];
extern F2d D_00471E14[];
extern f32 D_004F1F4C[];

static s32 func_00393390(u8 **p) { return p[6][1061] != 0; }

void residual_00393BA0(u8 *p)
{
    extern void func_00394760();
    extern void func_0015E630(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    u8 *q;
    s8 c;
    f32 f;
    double k;
    q = *(u8 **)(p + 0x18);
    if (D_004C29D0->h0 != *(u16 *)(q + 0x168)) {
        func_00394760();
        return;
    }
    if (func_00393390((u8 **)p) != 0) {
        func_00394760();
        return;
    }
    if ((c = D_004C29D4[8]) == 0) return;
    if (c != 1) { func_00394760(); return; }
    q = *(u8 **)(q + 0x1DC);
    p[5]++;
    p[0x13C] = 1;
    p[0x14E] = 0x30;
    p[0x14F] = 0x30;
    if (*(s16 *)(p + 0x140) != 0) {
        f = D_00471E10[q[1]].a;
    } else {
        f = -D_00471E10[q[1]].a;
    }
    D_004C29D0->f4 = *(f32 *)(q + 0x34) + f;
    D_004C29D0->f8 = *(f32 *)(q + 0x38) + D_00471E14[q[1]].a;
    if (*(s16 *)(p + 0x140) != 0) {
        k = -400.0;
    } else {
        k = 400.0;
    }
    *(f32 *)(p + 0x34) = (f32)((double)D_004F1F4C[0] + k);
    *(f32 *)(p + 0x38) = D_004C29D0->f8;
    *(f32 *)(p + 0x5C) = (f32)((double)(D_004C29D0->f4 - *(f32 *)(p + 0x34)) / 16.0);
    *(u32 *)(p + 0x68) = 0;
    *(f32 *)(p + 0x60) = 8.571428298950195f;
    *(f32 *)(p + 0x6C) = -1.0714285373687744f;
    *(s16 *)(p + 0x1C) = 0x10;
    func_0015E630(p);
    p[0] = 1;
    func_001757E0(p, 0x17, 6);
}
extern F2d D_00471FF0[];
extern F2d D_00471FF4[];
extern f32 D_004F1F50[];
void residual_00394200(u8 *p)
{
    extern void func_00394760();
    extern void func_0015E630(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    u8 *q;
    s8 c;
    f32 f;
    f32 k;
    q = *(u8 **)(p + 0x18);
    if (D_004C29D0->h0 != *(u16 *)(q + 0x168)) {
        func_00394760();
        return;
    }
    if (func_00393390((u8 **)p) != 0) {
        func_00394760();
        return;
    }
    if ((c = D_004C29D4[8]) == 0) return;
    if (c != 1) { func_00394760(); return; }
    q = *(u8 **)(q + 0x1DC);
    p[5]++;
    p[0x13C] = 1;
    p[0x14C] = 0x10;
    p[0x14D] = 0x78;
    if (*(s16 *)(p + 0x140) != 0) {
        f = D_00471FF0[q[1]].a;
    } else {
        f = -D_00471FF0[q[1]].a;
    }
    D_004C29D0->f4 = *(f32 *)(q + 0x34) + f;
    D_004C29D0->f8 = *(f32 *)(q + 0x38) + D_00471FF4[q[1]].a;
    if (*(s16 *)(p + 0x140) != 0) {
        k = 80.0f;
    } else {
        k = -80.0f;
    }
    *(f32 *)(p + 0x34) = D_004C29D0->f4 + k;
    *(f32 *)(p + 0x38) = 342.85711669921875f + D_004F1F50[0];
    *(f32 *)(p + 0x5C) = (f32)((double)(D_004C29D0->f4 - *(f32 *)(p + 0x34)) / 16.0);
    *(u32 *)(p + 0x68) = 0;
    *(f32 *)(p + 0x60) = (f32)((double)(D_004C29D0->f8 - *(f32 *)(p + 0x38)) / 16.0);
    *(u32 *)(p + 0x6C) = 0;
    *(s16 *)(p + 0x1C) = 0x10;
    func_0015E630(p);
    p[0] = 1;
    func_001757E0(p, 0x17, 7);
}
