typedef unsigned char u8;
typedef signed short s16;
typedef signed int s32;
typedef float f32;

extern u8 *D_004C2840;
extern s32 D_004C2848;

extern void func_00163DC0(u8 *, s32);
extern void func_00163E60(u8 *, s32);
extern void func_001632A0(u8 *);
extern void func_00163410(u8 *);
extern void func_00163580(u8 *);
extern void func_001636F0(u8 *);
extern void func_00163880(u8 *);
extern void func_00163B00(u8 *);
extern void func_00163CD0(u8 *);
extern void func_00418030(void);
extern void func_001E74C0(void);
extern void func_00174170(u8 *);
extern void func_0016D260(void);
extern void func_0016B0C0(u8 *, s32, s32);
extern void func_00166C80(u8 *, s32, s32);
extern void func_003DAA40(u8 *);
void func_00169C90(u8 *p);

s32 func_00167270(u8 *p)
{
    p[0x450] = 1;
    p[0x451] = 0;
    p[0x452] = 0;
    p[0x453] = 0;
    p[0x4a8] = 1;
    func_00169C90(p);
    return 1;
}

s32 func_00168B40(u8 *p)
{
    if (p[6] == 5) {
        if (*(s32 *)(D_004C2840 + 0x1c) & 1) {
            *(s16 *)(p + 0x4f0) = 0x1100;
        }
    }
    return 0;
}

s32 func_00168B80(u8 *p)
{
    if (p[6] == 5) {
        if (*(s32 *)(D_004C2840 + 0x1c) & 1) {
            *(s16 *)(p + 0x4f0) = 0x2100;
        }
    }
    return 0;
}

void func_00163F00(u8 *p, s32 a1)
{
    func_00163DC0(p, a1);
    func_00163E60(p, a1);
}

void residual_00163260(u8 *p)
{
    if (*(s32 *)(p + 0xd4) != 0) {
        (*(s32 *)(p + 0xd4))--;
    } else {
        p[4]++;
        func_001632A0(p);
    }
}

void residual_001633D0(u8 *p)
{
    if (*(s32 *)(p + 0xd4) != 0) {
        (*(s32 *)(p + 0xd4))--;
    } else {
        p[4]++;
        func_00163410(p);
    }
}

void residual_00163540(u8 *p)
{
    if (*(s32 *)(p + 0xd4) != 0) {
        (*(s32 *)(p + 0xd4))--;
    } else {
        p[4]++;
        func_00163580(p);
    }
}

void residual_001636B0(u8 *p)
{
    if (*(s32 *)(p + 0xd4) != 0) {
        (*(s32 *)(p + 0xd4))--;
    } else {
        p[4]++;
        func_001636F0(p);
    }
}

void residual_00163840(u8 *p)
{
    if (*(s32 *)(p + 0xd4) != 0) {
        (*(s32 *)(p + 0xd4))--;
    } else {
        p[4]++;
        func_00163880(p);
    }
}

void residual_00163AC0(u8 *p)
{
    if (*(s32 *)(p + 0xd4) != 0) {
        (*(s32 *)(p + 0xd4))--;
    } else {
        p[4]++;
        func_00163B00(p);
    }
}

void residual_00163C90(u8 *p)
{
    if (*(s32 *)(p + 0xd4) != 0) {
        (*(s32 *)(p + 0xd4))--;
    } else {
        p[4]++;
        func_00163CD0(p);
    }
}

void residual_0016C520(u8 *p)
{
    p[4]++;
    *(s16 *)(p + 0x1c) = 0x20;
    *(s16 *)(p + 0x1e) = 0x278;
    *(s32 *)(p + 0x104) = 0;
    *(f32 *)(p + 0x10c) = 0.9375f;
    *(s32 *)(p + 0x108) = 0;
    *(f32 *)(p + 0x110) = 1.0f;
    *(s32 *)(p + 0x118) = 0;
}

void residual_0016C7F0(u8 *p)
{
    p[4]++;
    *(s16 *)(p + 0x1c) = 0x10;
    *(s16 *)(p + 0x1e) = 0x168;
    *(s32 *)(p + 0x104) = 0;
    *(f32 *)(p + 0x10c) = 0.9375f;
    *(s32 *)(p + 0x108) = 0;
    *(f32 *)(p + 0x110) = 1.0f;
    *(s32 *)(p + 0x118) = 0;
}

void residual_0016C8B0(u8 *p)
{
    p[4]++;
    *(s16 *)(p + 0x1c) = 0x10;
    *(s16 *)(p + 0x1e) = 0x168;
    *(s32 *)(p + 0x104) = 0;
    *(f32 *)(p + 0x10c) = 0.9375f;
    *(s32 *)(p + 0x108) = 0;
    *(f32 *)(p + 0x110) = 0.9375f;
    *(s32 *)(p + 0x118) = 0;
}

void residual_0016C970(u8 *p)
{
    p[4]++;
    *(s16 *)(p + 0x1c) = 0x10;
    *(s16 *)(p + 0x1e) = 0x168;
    *(s32 *)(p + 0x104) = 0;
    *(f32 *)(p + 0x10c) = 0.9375f;
    *(f32 *)(p + 0x108) = 0.0625f;
    *(f32 *)(p + 0x110) = 1.0f;
    *(s32 *)(p + 0x118) = 0;
}

s32 func_0016ECC0(void)
{
    D_004C2848 = 1;
    func_00418030();
    func_0016D260();
    func_001E74C0();
    return 0;
}

void func_00169C90(u8 *p)
{
    p[0x472] = 0;
    p[0x4b8] = 0;
    *(s32 *)(p + 0x4c4) = 0;
    p[0x4a9] = 0;
    p[0x4aa] = 0;
    p[0x4ab] = 0;
    p[0x215] = 0;
    p[0x496] = 0;
    p[0x494] = 0;
    p[0x4ba] = 0;
    p[0x473] = 0;
    p[0x4bb] = 0;
    p[0x45a] = 0;
    p[0x45b] = 0;
    *(s16 *)(p + 0x456) = 0;
    p[0x455] = 0;
}

s32 func_00166DF0(u8 *p)
{
    p[0x450] = 0;
    p[0x451] = 1;
    p[0x452] = 0;
    p[0x453] = 0;
    p[0x4a8] = 0;
    func_00169C90(p);
    p[0x4b4] = 0xff;
    return 2;
}

void func_00161A70(u8 *p)
{
    if (*(s32 *)(p + 0xdc) != 0) {
        (*(s32 *)(p + 0xdc))--;
        *(f32 *)(p + 0x78) += *(f32 *)(p + 0x5c);
        *(f32 *)(p + 0x7c) += *(f32 *)(p + 0x60);
        *(f32 *)(p + 0x80) += *(f32 *)(p + 0x68);
    } else {
        p[0x23] = 0;
    }
}

void residual_001620A0(u8 *p)
{
    p[0x13c] = 1;
    p[4]++;
    func_00174170(p);
    *(s32 *)(p + 0x64) = 0xc2c80000;
    *(s32 *)(p + 0x70) = 0xc1200000;
}

void func_001683F0(u8 *p, s32 a1)
{
    func_0016B0C0(p, a1, 0);
    func_0016B0C0(p, a1, 2);
    func_00166C80(p, a1, 0);
}

void func_00168450(u8 *p, s32 a1)
{
    func_0016B0C0(p, a1, 0);
    func_0016B0C0(p, a1, 2);
    func_00166C80(p, a1, 0);
}

void func_0016C430(u8 *p)
{
    s16 t;
    *(f32 *)(p + 0x118) += 0.0625f;
    t = *(s16 *)(p + 0x1c) - 1;
    *(s16 *)(p + 0x1c) = t;
    if (t == 0) {
        p[4]++;
        *(s16 *)(p + 0x1c) = 0x4b0;
    }
}

void func_0016CAB0(u8 *p)
{
    s16 t;
    *(f32 *)(p + 0x118) += 0.0625f;
    t = *(s16 *)(p + 0x1c) - 1;
    *(s16 *)(p + 0x1c) = t;
    if (t == 0) {
        p[4]++;
        *(s16 *)(p + 0x1c) = 1;
    }
}

void func_0016C4B0(u8 *p)
{
    s16 t;
    *(f32 *)(p + 0x118) -= 0.03125f;
    t = *(s16 *)(p + 0x1c) - 1;
    *(s16 *)(p + 0x1c) = t;
    if (t == 0) {
        func_003DAA40(p);
    }
}

void func_0016CB00(u8 *p)
{
    s16 t;
    *(f32 *)(p + 0x118) -= 0.0625f;
    t = *(s16 *)(p + 0x1c) - 1;
    *(s16 *)(p + 0x1c) = t;
    if (t == 0) {
        func_003DAA40(p);
    }
}

s32 func_00168AF0(u8 *p)
{
    if (p[6] == 5) {
        if (*(s32 *)(D_004C2840 + 0x1c) & 1) {
            *(s16 *)(p + 0x4f0) = (s16)(((p[0x1e6] * 3) << 10) ^ 0x500);
        }
    }
    return 0;
}

s32 func_00168BC0(u8 *p)
{
    if (p[6] == 5) {
        if (*(s32 *)(D_004C2840 + 0x1c) & 1) {
            *(s16 *)(p + 0x4f0) = (s16)(((p[0x1e6] * 3) << 10) ^ 0x2500);
        }
    }
    return 0;
}


