typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;
extern u8 *D_004D18C8[];
extern u8 D_004D18A0[];
extern f32 D_004F1FD4[];
extern V3 D_004B38E0[];
extern f32 D_004F1FC8[];
extern f32 D_004F1FCC[];

void func_001F4FD0(u8 *p)
{
    extern void func_00175700(u8 *);
    extern void func_0015D010(u8 *, f32 *, s32, s32);
    extern void func_001E3210(u8 *, s32);
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_00185870(u8 *, u8 *);
    u8 *o;
    f32 v[4];
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_00175700(p);
    o = *(u8 **)(p + 0x1DC);
    if (*(f32 *)(o + 0x38) - *(f32 *)(p + 0x38) - 17.14285659790039f < -68.57142639160156f) {
        u32 u = p[7];
        p[7] = u + 1;
        p[0x20B] = 0xCD;
        *(u32 *)&v[0] = 0xC312AAAA;
        *(u32 *)&v[1] = 0x432B6DB6;
        func_0015D010(p, v, 0xCD, u + 1);
        func_001E3210(p, 5);
        func_001757E0(p, 0xF, 0x1D);
        func_00185870(p, o);
    }
}

void func_0015C020(u8 *p)
{
    u8 *o;
    u32 c;
    o = D_004D18C8[0];
    p[0x13C] = 0;
    if (o[0] != 0 && o[0x269] == 8 && D_004D18A0[0] == 4 && *(s8 *)(o + 0x13C) != 0)
        p[0x13C] = 1;
    *(V3 *)(p + 0x34) = *(V3 *)(o + 0x34);
    c = o[0x14C];
    *(f32 *)(p + 0x38) += 2.142857f * (f32)c * *(f32 *)(o + 0x54);
    *(f32 *)(p + 0x38) += 100.0f;
    *(f32 *)(p + 0x3C) += 1.0f;
    if (*(f32 *)(p + 0x38) <= 100.0f + D_004F1FD4[0])
        *(f32 *)(p + 0x38) = 100.0f + D_004F1FD4[0];
}

void func_0014F490(u8 *p, s32 b, s32 flag)
{
    extern u8 *func_003DA750(s32, s32, s32);
    extern void func_0014F5A0(void);
    extern void func_00150520(u8 *, f32, f32, f32);
    u8 *o;
    if ((o = func_003DA750(0, 0xD, 1)) != 0) {
        o[0x13C] = 1;
        *(void (**)(void))(o + 0x10) = func_0014F5A0;
        *(s32 *)(o + 0xD0) = 0x431;
        *(s16 *)(o + 0x1E) = b;
        o[0x23] = flag;
        if (flag != 0)
            *(u32 *)(o + 0x34) = 0x40C851EC;
        else
            *(u32 *)(o + 0x34) = 0x40DB851F;
        *(u32 *)(o + 0x38) = 0xBF7D70A4;
        *(u32 *)(o + 0x3C) = 0x3D8F5C29;
        *(V3 *)(o + 0x50) = D_004B38E0[0];
        func_00150520(o, 1.0f, 0.37439998984336853f, 0.6825000047683716f);
        *(u8 **)(o + 0xC8) = p + 0x88;
        *(u8 **)(o + 0x18) = p;
    }
}

void func_00311E90(u8 *p, u8 *q)
{
    extern s16 func_00118FA8(f32);
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_001DD8A0(u8 *, s32, s32);
    u32 t = p[6];
    p[6] = t + 1;
    *(s16 *)(q + 4) = func_00118FA8(*(f32 *)(p + 0x34));
    q[6] = 1;
    p[0x13C] = 1;
    if (*(s16 *)(p + 0x140) == 0)
        *(f32 *)(p + 0x34) += 173.33332824707031f;
    else
        *(f32 *)(p + 0x34) -= 173.33332824707031f;
    *(f32 *)(p + 0x38) += 480.0f;
    *(u32 *)(p + 0x5C) = 0;
    *(u32 *)(p + 0x60) = 0;
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x6C) = 0;
    *(u32 *)(p + 0x5C) = 0xC08F5555;
    *(u32 *)(p + 0x60) = 0xC0AB6DB6;
    if (*(s16 *)(p + 0x140) != 0)
        *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
    func_001757E0(p, 0x12, 0);
    func_001DD8A0(p, 0, 0);
}

void func_0034EFE0(u8 *p)
{
    extern void func_00175700(u8 *);
    extern s32 func_00174470(u8 *);
    extern void func_0034FA60(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_0034F330(u8 *);
    extern void func_0034F3B0(u8 *);
    extern void func_001E7F60(u8 *);
    func_00175700(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (func_00174470(p) == 0) {
        func_0034FA60(p);
        return;
    }
    if (*(f32 *)(p + 0x38) <= *(f32 *)(*(u8 **)(p + 0x18) + 0x430)) {
        u32 t = p[5];
        p[5] = t + 1;
        *(f32 *)(p + 0x38) = *(f32 *)(*(u8 **)(p + 0x18) + 0x430);
        func_001757E0(p, 0x17, 0x12);
    }
    if (*(s8 *)(p + 0x1B3) != 0) {
        func_0034F330(p);
    } else if (*(s8 *)(p + 0x1B2) != 0) {
        func_0034F3B0(p);
    } else {
        func_001E7F60(p);
    }
}

void func_00359EC0(u8 *p, u8 *q)
{
    extern void func_0035AE70(u8 *);
    extern void func_0035ACA0(u8 *, u8 *);
    extern void func_00175700(u8 *);
    extern void func_0035A7B0(u8 *, u8 *);
    s16 t = *(s16 *)(p + 0x1C);
    if (t > 0) {
        *(s16 *)(p + 0x1C) = t - 1;
        return;
    }
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (D_004F1FC8[0] - 160.0f > *(f32 *)(p + 0x34)) {
        *(f32 *)(p + 0x34) = D_004F1FC8[0];
        p[0x21] = 7;
        func_0035AE70(p);
    } else if (160.0f + D_004F1FCC[0] < *(f32 *)(p + 0x34)) {
        *(f32 *)(p + 0x34) = D_004F1FCC[0];
        p[0x21] = 7;
        func_0035AE70(p);
    }
    func_0035ACA0(p, q);
    func_00175700(p);
    func_0035A7B0(p, q);
}
