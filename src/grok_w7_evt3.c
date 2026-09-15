/* Remaining unmatched func_003DA750 wrappers that copy floats via lwc1/swc1. */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed int s32;
typedef float f32;

extern u8 *func_003DA750(s32, s32, s32);
extern void func_00156E10(void);
extern void func_00157740(void);
extern void func_00158170(void);
extern void func_003B75E0(void);
extern void func_0034A1B0(void);
extern void func_001DB410(void);
extern void func_0033D5F0(void);
extern void func_001D4650(void);
extern void func_00373B10(void);
extern void func_0019A0F0(void);
extern void func_0019A540(void);
extern void func_003A1660(void);
extern void func_003A1E30(void);
extern void func_00372E70(void);
extern void func_0039FD90(void);

typedef struct Vec3 {
    f32 x;
    f32 y;
    f32 z;
} Vec3;

#define F(p, o) (*(f32 *)((u8 *)(p) + (o)))
#define V3(p, o) (*(Vec3 *)((u8 *)(p) + (o)))
#define P(p, o) (*(void **)((u8 *)(p) + (o)))
#define I(p, o) (*(s32 *)((u8 *)(p) + (o)))
#define S(p, o) (*(u16 *)((u8 *)(p) + (o)))

void func_00156E80(f32 *src)
{
    u8 *p = func_003DA750(0, 8, 1);
    if (p != 0) {
        p[316] = 0;
        P(p, 16) = func_00156E10;
        V3(p, 52) = *(Vec3 *)src;
    }
}

void func_00157830(f32 *src)
{
    u8 *p = func_003DA750(0, 9, 1);
    if (p != 0) {
        p[316] = 0;
        P(p, 16) = func_00157740;
        V3(p, 52) = *(Vec3 *)src;
    }
}

void func_00158220(f32 *src)
{
    u8 *p = func_003DA750(0, 9, 1);
    if (p != 0) {
        p[316] = 0;
        P(p, 16) = func_00158170;
        V3(p, 52) = *(Vec3 *)src;
    }
}

void func_003B7570(u8 *src)
{
    u8 *p = func_003DA750(0, 1, 0);
    if (p != 0) {
        P(p, 16) = func_003B75E0;
        F(p, 52) = F(src, 52);
        F(p, 56) = F(src, 56);
        P(p, 24) = src;
        p[1] = src[1];
        S(p, 38) = 0x3500;
    }
}

void func_0034A0D0(u8 *src)
{
    u8 *p = func_003DA750(0, 1, 0);
    if (p != 0) {
        P(p, 16) = func_0034A1B0;
        P(p, 24) = src;
        P(p, 20) = src;
        p[1] = src[1];
        p[32] = 0;
        p[33] = 0;
        S(p, 38) = 0x302;
        F(p, 92) = F(src, 52);
    }
}

void func_001DB320(u8 *src)
{
    u8 *p = func_003DA750(0, 3, 0);
    if (p != 0) {
        P(p, 16) = func_001DB410;
        P(p, 24) = src;
        p[1] = src[1];
        p[32] = 0;
        p[33] = 0;
        S(p, 38) = 0x3501;
        F(p, 52) = F(src, 52);
        F(p, 56) = F(src, 56);
    }
}

void func_0033D580(u8 *src)
{
    u8 *p = func_003DA750(0, 6, 1);
    if (p != 0) {
        p[316] = 1;
        P(p, 16) = func_0033D5F0;
        V3(p, 52) = V3(src, 52);
        I(p, 208) = 0x821;
        p[32] = src[32];
    }
}

void func_0034A140(u8 *src)
{
    u8 *p = func_003DA750((s32)src, 1, 2);
    if (p != 0) {
        P(p, 16) = func_0034A1B0;
        P(p, 24) = P(src, 24);
        P(p, 20) = src;
        p[1] = src[1];
        p[32] = (u8)(*(s8 *)(src + 32) + 1);
        p[33] = 0;
        S(p, 38) = 0x302;
        F(p, 92) = F(src, 52);
    }
}

void func_001D45D0(u8 *src, u8 mode)
{
    u8 *p = func_003DA750(0, 3, 1);
    if (p != 0) {
        S(p, 38) = 0x2d00;
        p[32] = mode;
        V3(p, 52) = V3(src, 52);
        P(p, 16) = func_001D4650;
        P(p, 24) = src;
    }
}

void func_00373A90(u8 *src, u8 mode)
{
    u8 *p = func_003DA750(0, 1, 0);
    if (p != 0) {
        P(p, 16) = func_00373B10;
        p[32] = mode;
        P(p, 24) = src;
        p[1] = src[1];
        S(p, 38) = 0x1402;
        S(p, 208) = S(src, 360);
        F(p, 212) = F(src, 1072);
    }
}

void func_0019A070(u8 *src, u8 mode)
{
    u8 *p = func_003DA750((s32)src, 3, 2);
    if (p != 0) {
        P(p, 16) = func_0019A0F0;
        P(p, 24) = P(src, 24);
        P(p, 20) = src;
        V3(p, 52) = V3(src, 52);
        p[32] = mode;
        S(p, 38) = 0x600;
    }
}

void func_0019A440(u8 *src, u8 mode)
{
    u8 *p = func_003DA750((s32)src, 3, 2);
    if (p != 0) {
        P(p, 16) = func_0019A540;
        P(p, 24) = P(src, 24);
        P(p, 20) = src;
        V3(p, 52) = V3(src, 52);
        p[32] = mode;
        S(p, 38) = 0x601;
    }
}

void func_003A15E0(u8 *src, u8 mode)
{
    u8 *p = func_003DA750(0, 1, 0);
    if (p != 0) {
        P(p, 16) = func_003A1660;
        p[32] = mode;
        p[33] = 0;
        P(p, 24) = src;
        p[1] = src[1];
        F(p, 52) = F(src, 52);
        F(p, 56) = F(src, 56);
        S(p, 38) = 0x2c00;
    }
}

void func_003A1DB0(u8 *src, u8 mode)
{
    u8 *p = func_003DA750(0, 1, 0);
    if (p != 0) {
        P(p, 16) = func_003A1E30;
        p[32] = mode;
        p[33] = 0;
        P(p, 24) = src;
        p[1] = src[1];
        F(p, 52) = F(src, 52);
        F(p, 56) = F(src, 56);
        S(p, 38) = 0x2c01;
    }
}

void func_00372BE0(u8 *src, u8 mode)
{
    u8 *p = func_003DA750(0, 1, 0);
    if (p != 0) {
        P(p, 16) = func_00372E70;
        p[1] = src[1];
        S(p, 38) = 0x1401;
        p[32] = mode;
        P(p, 24) = src;
        S(p, 208) = S(src, 360);
        F(p, 212) = F(src, 1072);
        S(p, 30) = 0;
    }
}

void func_0039FD10(u8 *src)
{
    u8 *p = func_003DA750(0, 1, 0);
    if (p != 0) {
        P(p, 16) = func_0039FD90;
        P(p, 24) = P(src, 24);
        F(p, 52) = F(src, 52);
        F(p, 56) = F(src, 56);
        p[7] = 1;
        p[32] = src[32];
        p[1] = src[1];
        S(p, 38) = 0x2a02;
    }
}
