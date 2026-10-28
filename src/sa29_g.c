typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef double f64;

typedef struct { f32 x, y, z, w; } V2;

extern u8 *D_004C2794;
extern s8 *D_004C2960;
extern u8 D_00462540[];

extern f64 func_00119058(f32);
extern f64 func_00119858(f64, f64);
extern f32 func_00119C90(f64);

void func_00351870(u8 *p) {
    extern void func_003519E0(u8 *);
    extern s32 func_001748C0(u8 *, V2 *);
    extern void func_001757E0(u8 *, s32, s32);
    u8 *o;
    u8 *t;
    u32 ca;
    V2 v;
    s32 ang;
    u8 d;
    u8 b;
    o = *(u8 **)(p + 0x18);
    t = *(u8 **)(o + 0x1DC);
    *(s16 *)(p + 0x1C) = 16;
    p[0x1B5] = (p[0x20] & 1) ? 0x53 : 0x49;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    ca = p[2] * 2;
    ca += (u32)D_004C2794;
    ca += 0x7C;
    ++*(s16 *)ca;
    func_003519E0(p);
    *(f32 *)(p + 0x5C) = (f32)((f64)(*(f32 *)(t + 0x34) - *(f32 *)(p + 0x34)) / 16.0);
    *(f32 *)(p + 0x60) = (f32)((f64)((120.0f + *(f32 *)(t + 0x38)) - *(f32 *)(p + 0x38)) / 16.0);
    v.x = *(f32 *)(t + 0x34);
    v.y = 120.0f + *(f32 *)(t + 0x38);
    ang = func_001748C0(p + 0x34, &v);
    d = (ang & 0xFF) >> 4;
    p[0x22] = d;
    if (*(s16 *)(p + 0x140) != 0) {
        d ^= 0xF;
        d += 1;
        d &= 0xF;
    }
    b = D_00462540[d];
    *D_004C2960 = (s8)b - 6;
    func_001757E0(p, 0x16, b);
}
