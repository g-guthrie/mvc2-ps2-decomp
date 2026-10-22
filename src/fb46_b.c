typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { s8 f0; s8 f1; s8 f2; } G_c;
typedef struct { u8 pad[0x7C]; s16 f7c[1]; } H_c;
extern G_c *D_004C29FC;
extern H_c *D_004C2794;

void func_00399FD0(u8 *p)
{
    extern void func_0039A210(u8 *);
    extern void func_001E7F60(u8 *);
    extern void func_00175700(u8 *);
    extern f32 func_00417500(s32);
    extern f32 func_00417440(s32);
    s8 v;
    u32 n;
    s16 h;
    f32 x;

    p[0x24] = 0;
    if ((*(u8 **)(p + 0x18))[5] != 0) func_0039A210(p);
    v = D_004C29FC->f2 - 1;
    D_004C29FC->f2 = v;
    if (v < 0) {
        D_004C29FC->f2 = 3;
        n = p[0x22]; n = n + 1;
        p[0x22] = n;
        p[0x22] = ((s8)(n & 0xFF)) & 0x1F;
    }
    x = func_00417500(((0x28 - p[0x22]) & 0x1F) << 11);
    *(f32 *)(p + 0x5C) = 1.6666666269302368f * x;
    x = func_00417440(((0x28 - p[0x22]) & 0x1F) << 11);
    *(f32 *)(p + 0x60) = 2.142857074737549f * x;
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_00175700(p);
    h = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = h;
    if (h == 0) func_0039A210(p);
    if (*(s8 *)(p + 0x1B2) != 0) {
        v = D_004C29FC->f1 - 1;
        D_004C29FC->f1 = v;
        if (v < 0) {
            h = *(s16 *)(p + 0x1E) - 1;
            *(s16 *)(p + 0x1E) = h;
            if (h < 0) func_0039A210(p);
            D_004C29FC->f1 = 6;
            p[0x1B5] = 0x26;
            p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
            *(s32 *)(p + 0x1D8) = 0;
            D_004C2794->f7c[p[2]] += 1;
        }
    }
    func_001E7F60(p);
}

typedef struct { f32 x, y, z; } V3;
extern s16 D_00444FE0[];
extern s32 D_004C2838;

void func_0015A720(s32 unused, V3 *pos, s32 n, s32 k, u16 flags, f32 sc) {
    extern u8 *func_003DA750(s32, s32, s32);
    extern void func_0015A500();
    extern f32 func_00417F60();
    u8 *o;
    s32 i, j;
    if (flags & 0x40) {
        if (n > 1) {
            if (k % 2 == 0) return;
        }
        for (i = 0; i < 4; i++) {
            for (j = 0; j < 4; j++) {
                if (flags & 0x200) {
                    if ((o = func_003DA750(0, 0x28, 1)) == 0) return;
                } else {
                    if ((o = func_003DA750(0, 0x29, 1)) == 0) return;
                }
                o[0x13C] = 0;
                *(s32 *)(o + 0x10) = (s32)func_0015A500;
                *(s32 *)(o + 0xD0) = 0x800431;
                *(V3 *)(o + 0x34) = *pos;
                *(s16 *)(o + 0x1C) = 4;
                *(s32 *)(o + 0x74) = 0;
                *(f32 *)(o + 0x78) = 1.0f;
                *(s32 *)(o + 0x7C) = 0;
                *(s32 *)(o + 0x80) = 0;
                *(s16 *)(o + 0xCC) = *(s16 *)((u8 *)D_00444FE0 + i * 4);
                *(s32 *)(o + 0x84) = D_004C2838;
                *(f32 *)(o + 0x5C) = 30.0f * (func_00417F60() - 0.5f);
                *(f32 *)(o + 0x60) = 30.0f * (func_00417F60() - 0.5f);
                *(f32 *)(o + 0x64) = 30.0f * (0.5f * func_00417F60());
                *(f32 *)(o + 0x68) = -*(f32 *)(o + 0x5C) / 14.0f;
                *(f32 *)(o + 0x6C) = -*(f32 *)(o + 0x60) / 14.0f;
                *(f32 *)(o + 0x70) = -*(f32 *)(o + 0x64) / 14.0f;
                *(f32 *)(o + 0x50) = sc;
                *(f32 *)(o + 0x54) = sc;
                *(f32 *)(o + 0x58) = sc;
                o[0x23] = k;
                *(s32 *)(o + 0xD4) = k << 3;
            }
        }
    }
}
