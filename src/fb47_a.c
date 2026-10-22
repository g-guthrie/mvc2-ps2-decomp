typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 *t; s32 b, c; } R3A3620;
extern R3A3620 D_004D18B8[];

void func_003A3620(u8 *p, u8 *q)
{
    extern void func_003A3880(u8 *, u8 *);
    extern s32 func_001748C0(f32 *, f32 *);
    extern void func_00174910(u8 *, s32);
    extern void func_00178F20(u8 *, u8 *);
    extern void func_00175700(u8 *);
    extern s32 func_00182D30(u8 *);
    u8 *s0;
    u8 *t;
    f32 v[6];
    s32 k;
    q[0x1FE] = 1;
    s0 = *(u8 **)(p + 0x1DC);
    if (*(u8 **)(*(u8 **)(p + 0x1E0) + 0x1E0) != p) {
        func_003A3880(p, q);
        return;
    }
    if (*(s16 *)(s0 + 0x434) == 0 || (*(s8 *)(s0 + 0x1B3) != 0 && s0[5] == 3)) {
        q[0x1FE] = 0;
        func_003A3880(p, q);
        return;
    }
    {
        s16 h = *(s16 *)(p + 0x1C) - 1;
        *(s16 *)(p + 0x1C) = h;
        if (h < 0) {
            p[5]++;
        } else if (*(s16 *)(s0 + 0x270) != 0) {
            if (func_00182D30(s0) != 0)
                *(s16 *)(s0 + 0x270) = 0;
        } else {
            p[5]++;
        }
    }
    {
        s16 h = *(s16 *)(p + 0x1E) - 1;
        *(s16 *)(p + 0x1E) = h;
        if (h < 0) {
            *(s16 *)(p + 0x1E) = 4;
            t = D_004D18B8[q[2]].t;
            k = 0x40;
            if (*(s16 *)(q + 0x140) == 0)
                k = -0x40;
            v[0] = *(f32 *)(p + 0x34);
            v[1] = *(f32 *)(p + 0x38);
            v[3] = *(f32 *)(t + 0x34) + 1.6666666f * (f32)k;
            v[4] = 171.4285583f + *(f32 *)(t + 0x38);
            p[0x22] = ((u8)func_001748C0(v, v + 3)) >> 3;
        }
    }
    func_00174910(p, *(s16 *)(p + 0xD4));
    func_00178F20(p, s0);
    func_00175700(p);
}
