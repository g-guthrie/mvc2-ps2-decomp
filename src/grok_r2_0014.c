typedef unsigned char u8;
typedef signed short s16;
typedef signed int s32;
typedef float f32;
typedef void (*DispatchFn)(u8 *);

#define S(p, o) (*(s16 *)((u8 *)(p) + (o)))
#define F(p, o) (*(f32 *)((u8 *)(p) + (o)))
#define I(p, o) (*(s32 *)((u8 *)(p) + (o)))

typedef struct {
    s32 v;
} Word;

extern Word D_004F1CB0;
extern Word D_004F1CB4;
extern Word D_004F1CB8;
extern Word D_004F1CBC;
extern s32 D_00446BF0[];
extern char D_004F1D20[];
extern DispatchFn jtbl_00442A90[];
extern DispatchFn jtbl_004489E0[];

extern void func_0016B0C0(u8 *, s32, s32);
extern void func_0016D1C0(void);
extern void func_0016D2A0(void);
extern void func_0016D460(void);
extern void func_0011D8F8(void *, s32, s32);
extern void func_003DF850(s32, s32);
extern void func_003DF7B0(void);

void func_0016CF80(void) {
    volatile s32 *p = &D_004F1CB8.v;
    s32 t = *p;
    D_004F1CB0.v = 1;
    *p = t - 1;
}

void func_0016D010(void) {
    volatile s32 *p = &D_004F1CB8.v;
    s32 t = *p;
    D_004F1CB0.v = 2;
    *p = t - 1;
}

void func_0016D040(void) {
    volatile s32 *p = &D_004F1CB8.v;
    s32 t = *p;
    D_004F1CB0.v = 3;
    *p = t - 1;
}

s32 func_0016D130(void) {
    s32 v = D_004F1CB0.v;
    if (v) {
        return v;
    }
    return 0;
}

void func_00150520(u8 *p, f32 a, f32 b, f32 c) {
    F(p, 120) = a;
    F(p, 124) = b;
    F(p, 128) = c;
}

s32 func_00168780(u8 *p, s32 a1) {
    func_0016B0C0(p, a1, 0);
    return 0;
}

void func_0016CF40(void) {
    if (D_004F1CB4.v != 8) {
        D_004F1CBC.v = 0;
        D_004F1CB4.v = 9;
        D_004F1CB8.v = 180;
    }
}

void func_00176340(s32 a0, s32 a1) {
    D_00446BF0[a1] = a0;
}

void residual_00147560(u8 *p) {
    jtbl_00442A90[p[4]](p);
}

void func_00178D80(u8 *p, unsigned int a1) {
    jtbl_004489E0[a1 & 0xFF](p);
}

void func_0016D190(void) {
    func_0016D1C0();
    func_0016D2A0();
}

void func_00170D70(void) {
    func_003DF850(93, 1);
    func_003DF7B0();
}

void func_0016C370(u8 *p) {
    s16 v;
    p[316] = 0;
    v = *(s16 *)(p + 28) - 1;
    *(s16 *)(p + 28) = v;
    if (v == 0) {
        *(s16 *)(p + 28) = 1;
        p[4] += 1;
    }
}

void func_0014C030(u8 *a0, u8 *a1) {
    if (a1) {
        F(a1, 92) = F(a1, 52) - F(a0, 52);
        F(a1, 96) = F(a1, 56) - F(a0, 56);
        F(a1, 100) = F(a1, 60) - F(a0, 60);
        I(a1, 24) = (s32)a0;
    }
}

void func_0016D160(void) {
    func_0011D8F8(D_004F1D20, 0, 532);
    func_0016D460();
}
