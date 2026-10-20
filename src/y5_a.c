typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

static void func_00193180(u8 *p) {
    u8 *q = *(u8 **)(p + 0x18);
    f32 f;
    *(f32 *)(p + 0x34) = *(f32 *)(q + 0x34);
    *(f32 *)(p + 0x38) = *(f32 *)(q + 0x430);
    switch (p[0x20]) {
    case 0:
        f = 0.0f;
        break;
    case 1:
        f = 80.0f;
        break;
    case 2: {
        s16 v = *(s16 *)(p + 0x140) ^ 1;
        f = 80.0f;
        *(s16 *)(p + 0x140) = v;
        break;
    }
    }
    if (*(s16 *)(p + 0x140)) f = -f;
    *(f32 *)(p + 0x34) += f;
}

void func_00193320(u8 *p)
{
    extern void func_00193380();
    extern void func_00175700();
    u8 *q;
    func_00193180(p);
    q = *(u8 **)(p + 0x18);
    if (q[0x169] != 0x16 || q[0x168] != 1) {
        func_00193380(p);
    } else {
        func_00175700(p);
    }
}

s32 func_00169180(u8 *p, s32 n)
{
    extern s32 func_0016A1F0();
    extern s32 func_0016A130();
    if (n > 3) return 0;
    if (p[0x215] != 0) return func_0016A1F0(p, 7);
    if (p[5] == p[0x497]) return 1;
    if (p[0x497] == 3 && p[0x20D] != 2) return func_0016A130(p, 7, 3);
    return func_0016A1F0(p, 7);
}

extern s32 D_00444950[];
typedef struct { s16 a, b; } S4_53eb;
extern S4_53eb *D_00444940[];
extern u32 D_004C2838;

void func_00153EB0(u8 *p)
{
    extern void func_003DAA40();
    s16 v = *(s16 *)(p + 0x1E) + 1;
    *(s16 *)(p + 0x1E) = v;
    if (v % 4 == 0) {
        s16 w = *(s16 *)(p + 0x1C) + 1;
        *(s16 *)(p + 0x1C) = w;
        if (w >= D_00444950[0]) {
            func_003DAA40(p);
            return;
        }
        *(s16 *)(p + 0xCC) = D_00444940[0][*(s16 *)(p + 0x1C)].a;
        *(u32 *)(p + 0x84) = D_004C2838;
    }
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x3C) += *(f32 *)(p + 0x64);
}

void func_003D7220(u8 *p)
{
    { s32 v = p[7]; s32 h = v >> 4; s32 t = h * 10; v &= 0xF; p[7] = t + v; }
    { s32 v = p[6]; s32 h = v >> 4; s32 t = h * 10; v &= 0xF; p[6] = t + v; }
    { s32 v = p[5]; s32 h = v >> 4; s32 t = h * 10; v &= 0xF; p[5] = t + v; }
    { s32 v = p[3]; s32 h = v >> 4; s32 t = h * 10; v &= 0xF; p[3] = t + v; }
    { s32 v = p[2]; s32 h = v >> 4; s32 t = h * 10; v &= 0xF; p[2] = t + v; }
    { s32 v = p[1]; s32 h = v >> 4; s32 t = h * 10; v &= 0xF; p[1] = t + v; }
}

extern u8 D_004D18A1[];
extern u8 D_00445E20[];
extern s32 (*const D_00446120[])(u8 *, s32);

extern u8 D_004531B0[];

extern u8 D_004D18A1[];
extern u8 D_00445E20[];
extern s32 (*const D_00446120[])(u8 *, s32);

s32 func_00168D90(u8 *p)
{
    extern s32 func_0016A210();
    u8 *s;
    s32 r;
    if (D_004D18A1[0] & 4) return 0;
    if (p[5] > 1) return 2;
    if (p[0x496] != 0) return 0;
    if (p[0x450] == 0xD) return 0;
    if (func_0016A210(p, 0xF) == 0) return 0;
    s = D_00445E20;
    do {
        r = D_00446120[*s++](p, p[0x4A8]);
        r = (*s == 0xFF) ? 0 : r;
    } while (r == 1);
    return r;
}

typedef struct { u8 pad[0x7C]; s16 f7c[16]; } G_y5g;
extern G_y5g *D_004C2794;

void func_0029FA40(u8 *p)
{
    extern void func_0018C4B0();
    extern void func_001757E0();
    extern void func_0029D5E0();
    extern void func_00390300();
    extern void func_0029FA00();
    extern s8 func_00175700();
    extern void func_0029B130();
    u32 t = p[6];
    if (t == 0) {
        p[6] = t + 1;
        func_0018C4B0(p, 5);
        p[0x1B5] = 0x30;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(u32 *)(p + 0x1D8) = 0;
        D_004C2794->f7c[p[2]]++;
        func_001757E0(p, 0x15, 0);
        func_0029D5E0(p);
        return;
    }
    if ((*(s8 *)(p + 0x151) & 0x80) != 0) {
        p[0x28F] = 0;
        p[0x28E] = 0x10;
        p[0x151] = *(s8 *)(p + 0x151) & 0x7F;
        func_00390300(p, p[0x1B7]);
    }
    func_0029FA00(p);
    if (func_00175700(p) < 0) func_0029B130(p);
}
