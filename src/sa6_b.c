typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;
typedef struct { u8 pad[0x7C]; s16 f7c[1]; } G_b;
extern G_b *D_004C2794;
extern s16 D_00473160[];
extern s16 D_00473162[];

void func_003AA0D0(u8 *p)
{
    extern void func_00175910(u8 *, s32, s32, s32);
    extern void func_001E7F60(u8 *);
    u8 *o = *(u8 **)(p + 0x18);
    u8 v;
    f32 k, d;
    p[0x13C] = 0;
    if (*(u16 *)(p + 0x1C) != *(u16 *)(o + 0x168)) {
        p[4] = 2;
        return;
    }
    v = o[0x161];
    if ((s8)v < 0) return;
    if (p[0x22] != v) {
        p[0x22] = v;
        func_00175910(p, 0x17, 0, p[0x22]);
        p[0x1B5] = p[0x15B];
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(s32 *)(p + 0x1D8) = 0;
        D_004C2794->f7c[p[2]]++;
    }
    *(V3 *)(p + 0x34) = *(V3 *)(o + 0x34);
    k = 1.6666666269302368f;
    d = k * (f32)*(s16 *)((u8 *)D_00473160 + o[0x15B] * 8 + p[0x20] * 4);
    if (*(s16 *)(o + 0x140) != 0) d = -d;
    *(f32 *)(p + 0x34) += d;
    k = 2.142857074737549f;
    *(f32 *)(p + 0x38) += k * (f32)*(s16 *)((u8 *)D_00473162 + o[0x15B] * 8 + p[0x20] * 4);
    p[0x13C] = 1;
    func_001E7F60(p);
}
