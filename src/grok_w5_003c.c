typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef unsigned int u32;
typedef float f32;

#define F(p, o) (*(f32 *)((u8 *)(p) + (o)))
#define S(p, o) (*(s16 *)((u8 *)(p) + (o)))
#define I(p, o) (*(s32 *)((u8 *)(p) + (o)))
#define P(p, o) (*(u8 **)((u8 *)(p) + (o)))

extern u8 D_004D18A6;
extern f32 D_004762F0[];
extern u8 D_0058EFD0[];
extern u8 D_0058EC40[];
extern u8 D_00152930[];
extern u8 D_005BF280[];
extern u8 D_0058F280[];

extern void func_003D14F0(void);
extern void func_003D1190(void);
extern void func_00172760(void);
extern void func_003D26F0(void);
extern void func_003D26E0(void);
extern void func_003DC9C0(void);
extern void func_003DB9F0(void);
extern void func_003F0310(void);
extern void func_003DAA40(void);
extern void func_00130040(void);
extern void func_00130820(void);
extern void func_003DA6F0(s32);
extern void func_003D7310(void *);
extern void func_003DAC50(void *, s32);
extern void func_003DDA70(void *);
extern void func_003DE320(u8 *, void *);
extern void func_003CDC70(u8 *, u8 *);
extern void func_003CDEE0(u8 *, u8 *);
extern void func_003D79B0(u8 *, u8 *);
extern void func_003D7B50(u8 *, u8 *);
extern void func_003C9370(u8 *);
extern void func_003C9A20(u8 *, u8 *, u8 *);
extern s32 func_003DB9B0(u8 *);
extern s16 *func_003DD030(void);
extern s32 func_003DA750(s32, s32, s32);
extern void func_00175910(u8 *, s32, s32, s32);
extern s32 func_00118FA8(f32);
extern void func_003F0B70(void *, void *, s32, u8 *, u8 *, u8 *, s32);
extern void func_003D77C0(void);

void func_003DD040(void);

void func_003D0F70(void)
{
    func_003D14F0();
    func_003D1190();
}

void func_003D1F60(void)
{
    func_00172760();
    func_003D26F0();
    func_003D26E0();
}

void func_003DD040(void)
{
    func_003DC9C0();
    func_003DB9F0();
    func_003F0310();
}

void func_003C9210(void)
{
    if (!D_004D18A6)
        func_003DAA40();
}

void func_003D24A0(void)
{
    func_00130040();
    func_003DA6F0(13);
    func_003D7310(D_00152930);
}

void func_003D24D0(void)
{
    func_00130820();
    func_003DA6F0(13);
    func_003D7310(D_00152930);
}

void func_003DADD0(void)
{
    func_003DAC50(D_0058EFD0, 0x2a8);
    func_003DAC50(D_0058EC40, 0x2a8);
}

void func_003DDB20(u8 *p)
{
    u8 tmp[64];
    func_003DDA70(tmp);
    func_003DE320(p, tmp);
}

void func_003CDC30(u8 *p)
{
    if (!p[0x20])
        func_003CDC70(p, P(p, 24));
    else
        func_003CDEE0(p, P(p, 24));
}

void func_003D7970(u8 *p)
{
    u8 *q = P(p, 24);
    if (!p[0x20])
        func_003D79B0(p, q);
    else
        func_003D7B50(p, q);
}

void func_003C9330(u8 *p)
{
    if (!p[0x20])
        func_003C9370(p);
    else
        func_003C9A20(p, P(p, 24), P(p, 8));
}

void func_003DCFE0(u8 *p)
{
    if (!func_003DB9B0(p)) {
        func_003DD040();
        func_003DB9B0(p);
    }
}

s32 func_003DEC90(void)
{
    s16 *p = func_003DD030();
    if (p)
        return p[1];
    return 0;
}

void func_003C9850(u8 *p)
{
    f32 *t = D_004762F0 + p[0x22] * 2;
    f32 x = t[0];
    f32 y = t[1];
    if (S(p, 0x140))
        x = -x;
    F(p, 0x5c) = x;
    F(p, 0x60) = y;
}

void func_003DD260(u32 *m)
{
    m[0] = 0x3F800000;
    m[1] = 0;
    m[2] = 0;
    m[3] = 0;
    m[4] = 0;
    m[5] = 0x3F800000;
    m[6] = 0;
    m[7] = 0;
    m[8] = 0;
    m[9] = 0;
    m[10] = 0x3F800000;
    m[11] = 0;
    m[12] = 0;
    m[13] = 0;
    m[14] = 0;
    m[15] = 0x3F800000;
}

void func_003DDAD0(u32 *m, f32 x, f32 y, f32 z)
{
    m[0] = 0x3F800000;
    m[1] = 0;
    m[2] = 0;
    m[3] = 0;
    m[4] = 0;
    m[5] = 0x3F800000;
    m[6] = 0;
    m[7] = 0;
    m[8] = 0;
    m[9] = 0;
    m[10] = 0x3F800000;
    m[11] = 0;
    ((f32 *)m)[12] = x;
    ((f32 *)m)[13] = y;
    ((f32 *)m)[14] = z;
    m[15] = 0x3F800000;
}

void func_003D7CC0(u8 *p, u8 *q)
{
    if (I(p, 0xd0))
        func_00175910(p, 22, 42, *(s8 *)(q + 0x151) & 1);
    else
        func_00175910(p, 22, 41, *(s8 *)(q + 0x151));
}

void func_003C15B0(u8 *p)
{
    S(p, 0xd0) = (s16)func_00118FA8((f32)S(p, 0xd0) + F(p, 0x5c));
}

void func_003C3D60(u8 *p)
{
    S(p, 0xd0) = (s16)func_00118FA8((f32)S(p, 0xd0) + F(p, 0x5c));
}

void func_003DB980(u8 *a, u8 *b, u8 *c)
{
    func_003F0B70(D_005BF280, D_0058F280, 0x3000, a, b, c, 1);
}

void func_003D7770(u8 *p)
{
    u8 *q = (u8 *)func_003DA750(0, 1, 0);
    if (q) {
        I(q, 0x10) = (s32)func_003D77C0;
        I(q, 0x18) = (s32)p;
        q[0x20] = 0;
    }
}
