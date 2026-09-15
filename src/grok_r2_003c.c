typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

#define F(p, o) (*(f32 *)((u8 *)(p) + (o)))
#define I(p, o) (*(s32 *)((u8 *)(p) + (o)))
#define S(p, o) (*(s16 *)((u8 *)(p) + (o)))

extern u8 D_004D18D3;
extern u8 D_004D1901;
extern u8 D_004F1F40;
extern u8 D_004F1F47;
extern u8 D_004F1F48;
extern s16 D_004F7D1E[];
extern s16 D_004F7D2E;
extern s16 D_004F7F7A;
extern s16 D_004F7F7C;
extern s16 D_0062C500[];
extern s16 D_0062C502[];
extern s16 D_0062C504[];

extern void func_001757E0(u8 *, s32, s32);
extern void func_003C5780(u8 *);
extern void func_003F59C0(u8 *, void *);
extern s32 func_00175700(u8 *);
extern void func_003CAB20(u8 *, u8 *, s32);
extern void func_001E3210(s32, s32);
extern void func_0018D930(u8 *);

void func_003D9080(void) {
    D_004D18D3 = 0;
    D_004D1901 = 0;
}

s32 func_003F0A20(u8 *p, s32 i, s32 *out) {
    out[0] = *(s32 *)((i << 2) + (s32)p + 12);
    out[1] = i;
    return 1;
}

s32 func_003F7C18(u8 *p, s32 unused, s32 d) {
    s32 a = I(p, 0x8C);
    s32 b = I(p, 0x88);
    a += d;
    b += d;
    I(p, 0x8C) = a;
    I(p, 0x88) = b;
    return a;
}

void func_003D2020(void) {
    D_004F1F47 = 0;
    D_004F1F48 = 0;
    D_004F1F40 = 1;
}

void func_003D6AC0(void) {
    D_004F7F7C = 0;
    D_004F7D1E[0] = 0;
    D_004F7D2E = 0;
    D_004F7F7A = 0;
}

void func_003C3910(u8 *p) {
    s16 t = S(p, 0x1C);
    S(p, 0x1C) = t - 1;
    if (t == 0) {
        u32 v = p[5];
        v += 1;
        p[5] = v;
        p[0x13C] = 1;
    }
}

void func_003D6820(s32 idx) {
    s16 v = *(s16 *)((u8 *)D_004F7D1E + ((u8)idx * 16));
    if (v != 0)
        D_004F7F7A = 0;
}

void func_003C15F0(u8 *p) {
    s16 flag = S(p, 0x140);
    s16 x = S(p, 0xD0);
    s16 *q = (s16 *)(p + 0xD0);
    if (flag == 0)
        x = -x;
    F(p, 0x34) = (f32)(x + q[1]);
}

void func_003C3DA0(u8 *p) {
    s16 flag = S(p, 0x140);
    s16 x = S(p, 0xD0);
    s16 *q = (s16 *)(p + 0xD0);
    if (flag == 0)
        x = -x;
    F(p, 0x34) = (f32)(x + q[1]);
}

void func_003ED8E0(s32 i, s16 a, s16 b, s16 c) {
    s32 o = i << 2;
    D_0062C500[o] = a;
    D_0062C502[o] = b;
    D_0062C504[o] = c;
}

void func_003C64C0(u8 *p) {
    p[5] = 4;
    func_001757E0(p, 0x15, 0x1E);
    func_003C5780(p);
}

void func_003C7C10(u8 *p) {
    s16 t = S(p, 0x1C);
    t = t - 1;
    S(p, 0x1C) = t;
    if (t < 0) {
        u32 v = p[5];
        v += 1;
        p[5] = v;
        func_001757E0(p, 0x14, 0x15);
    }
}

void func_003C57E0(u8 *p) {
    p[5] = 3;
    func_001E3210(I(p, 0x18), 1);
    func_001757E0(p, 0x14, 3);
    func_0018D930(p);
    func_003C5780(p);
}

void func_003CC880(u8 *p, u8 *q) {
    s8 r = (s8)func_00175700(p);
    if (r < 0)
        func_003CAB20(p, q, 0xB);
}

void func_003F5C00(u8 *p, s16 a, s16 b, s32 c) {
    struct {
        s16 a;
        s16 b;
        s32 c;
    } t;
    t.a = a;
    t.b = b;
    t.c = c;
    func_003F59C0(p, &t);
}
