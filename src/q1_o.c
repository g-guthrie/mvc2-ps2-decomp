typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;
typedef struct { u8 b[28]; } E28;
typedef struct { u8 pad[0x184]; E28 *tab; } T184;

extern void func_001A7990();

void func_001A86D0(u8 *p, u8 *q)
{
    extern u8 *func_003DA750();
    extern f32 func_001A8CB0();
    extern void func_001A87F0();
    u8 *a3;
    u8 *o;
    f32 c;
    a3 = *(u8 **)(p + 8);
    p[5]++;
    if (a3[0x20] == 10) c = -53.33333206f; else c = -80.0f;
    if (*(s16 *)(p + 0x140) != 0) c = -c;
    *(f32 *)(p + 0x34) = *(f32 *)(a3 + 0x34) + c;
    *(f32 *)(p + 0x38) = *(f32 *)(a3 + 0x38);
    if ((o = func_003DA750(p, 4, 2)) != 0) {
        *(u32 *)(o + 0x10) = (u32)func_001A7990;
        *(u8 **)(o + 0x18) = q;
        *(s16 *)(o + 0x1E) = *(s16 *)(p + 0x1E) - 1;
        if (*(s16 *)(p + 0x1E) == 0) goto l12;
        if (!(func_001A8CB0(p) < 53.33333206f)) {
            o[0x20] = 0xB;
        } else {
l12:
            o[0x20] = 0xC;
        }
    }
    func_001A87F0(p, q);
}

extern u16 D_004D18DC;
extern u8 D_004D18DB;
extern void (*D_00473DD0[])();

void func_003B3140(u8 *p, u8 *q)
{
    extern void func_003B3810();
    if (q[0x169] != 0x16) {
        p[4]++;
        func_003B3810(p);
        return;
    }
    if (q[5] != 0) {
        p[4]++;
        func_003B3810(p);
    } else {
        p[0x24] = *(s8 *)(q + 0x24);
        *(f32 *)(p + 0x34) = *(f32 *)(q + 0x34);
        *(f32 *)(p + 0x38) = *(f32 *)(q + 0x38);
        *(f32 *)(p + 0x3C) = *(f32 *)(q + 0x3C);
        if (*(s16 *)(p + 0x140) == 0) {
            *(f32 *)(p + 0x34) += -178.3333282f;
        } else {
            *(f32 *)(p + 0x34) += 178.3333282f;
        }
        *(f32 *)(p + 0x38) += 203.5714264f;
        if ((D_004D18DC & (1 << D_004D18DB)) == 0) {
            D_00473DD0[p[5]](p, q);
        }
    }
}

extern void func_003A9730();

void func_003A9600(u8 *p, u8 *q)
{
    extern u8 *func_003DA750();
    extern u32 func_00174170();
    u8 *o;
    f32 dx;
    f32 y;
    if ((o = func_003DA750(0, 1, 0)) != 0) {
        dx = 0.0f;
        *(u32 *)(o + 0x10) = (u32)func_003A9730;
        *(u8 **)(o + 0x18) = q;
        *(s16 *)(o + 0x26) = 0x2F04;
        o[0x20] = p[0x20];
        y = *(f32 *)(p + 0x38) - 34.2857131958f;
        if (y < *(f32 *)(q + 0x430)) {
            dx = 33.3333320618f;
            if (p[0x20] != 0) dx = -dx;
            y = *(f32 *)(q + 0x430) + 2.1428570747f * (f32)(func_00174170() & 7);
            o[0x21] = 1;
        }
        *(f32 *)(o + 0x34) = *(f32 *)(p + 0x34) + dx;
        *(f32 *)(o + 0x38) = y;
    }
}

void func_00388780(u8 *p, u8 *q)
{
    extern f32 func_00417500(s32);
    extern f32 func_00417440(s32);
    s16 a;
    p[0x24] = *(s8 *)(q + 0x24);
    *(f32 *)(p + 0x34) = *(f32 *)(q + 0x34);
    *(f32 *)(p + 0x38) = *(f32 *)(q + 0x38);
    a = ((0x48 - *(s16 *)(p + 0x1E)) & 0x3F) << 10;
    *(f32 *)(p + 0x34) += 1.6666666269f * (998400.0f * (1000.0f * func_00417500(a)) / 100000.0f / 256.0f);
    *(f32 *)(p + 0x38) += 2.1428570747f * (998400.0f * (1000.0f * func_00417440(a)) / 125000.0f / 256.0f);
    *(s16 *)(p + 0x1E) = *(s16 *)(p + 0x1E) + 1;
    *(s16 *)(p + 0x1E) = *(s16 *)(p + 0x1E) & 0x3F;
}
