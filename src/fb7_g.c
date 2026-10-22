typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y; } P2g;
typedef struct { f32 x, y, z; } P3g;

extern u8 D_004B1220[];
extern u8 D_004B1221[];
extern s8 D_0043F960[][8];
extern P2g D_0043F760[];
extern P3g D_0043F1C0[];
extern u8 *D_004C2924;
extern u8 *D_004C2830;

void func_00136DA0(s32 a) {
    extern u8 *func_003DA750(s32, s32, s32);
    extern void func_001371E0();
    extern void func_0032DE90(u8 *, s16, f32, f32);
    extern void func_001377F0(u8 *);
    extern s32 func_00417A40(void);
    extern void func_00137140(u8 *, s32);
    extern void func_001378C0(u8 *);
    extern void func_00137910(u8 *);
    extern void func_0013AEA0(u8 *);
    u8 *o;
    s32 idx, r;
    if (a >= 0x18 && a <= 0x1A) return;
    if ((o = func_003DA750(0, 6, 1)) == 0) return;
    if (a >= 0x1B) o[0x20] = a - 3;
    else o[0x20] = a;
    o[0x13C] = 1;
    *(void **)(o + 0x10) = (void *)func_001371E0;
    *(u8 **)(o + 0xC8) = D_004C2924 + 0x88;
    *(s16 *)(o + 0xCC) = o[0x20] + 0xA;
    *(u8 **)(o + 0x84) = D_004C2830;
    o[0x21] = a;
    *(s32 *)(o + 0xD0) = 0xC1F;
    idx = o[0x21] * 2;
    o[7] = D_0043F960[D_004B1221[idx]][D_004B1220[idx]];
    if (o[0x21] != o[7]) {
        if (o[7] >= 0x1B) o[0x20] = o[7] - 3;
        else o[0x20] = o[7];
        *(s16 *)(o + 0xCC) = o[0x20] + 0xA;
        *(u8 **)(o + 0x84) = D_004C2830;
        func_0032DE90(o, (s16)(o[0x20] + 0xA), D_0043F760[o[0x21]].x - D_0043F760[o[7]].x, D_0043F760[o[7]].y - D_0043F760[o[0x21]].y);
    }
    switch (o[0x21]) {
    case 0x27:
    case 0x21:
    case 0x25:
    case 0x26:
    case 0x20:
    case 0x23:
    case 0x24:
    case 0x3A:
    case 0x36:
    case 0x2E:
    case 0x33:
    case 0x34:
    case 0x2B:
    case 0x35:
    case 0x31:
    case 0x32:
        *(s16 *)(o + 0x26) = 1;
        break;
    default:
        *(s16 *)(o + 0x26) = 0;
        break;
    }
    if (D_0043F1C0[o[7]].x < 0.0f) *(f32 *)(o + 0x34) = D_0043F1C0[o[7]].x - 900.0f;
    else *(f32 *)(o + 0x34) = 900.0f + D_0043F1C0[o[7]].x;
    if (D_0043F1C0[o[7]].y >= 173.0f) *(f32 *)(o + 0x38) = 100.0f + D_0043F1C0[o[7]].y;
    else *(f32 *)(o + 0x38) = D_0043F1C0[o[7]].y - 100.0f;
    *(f32 *)(o + 0x3C) = 800.0f + D_0043F1C0[o[7]].z;
    func_001377F0(o);
    r = func_00417A40();
    *(s16 *)(o + 0x1C) += r & 3;
    *(s32 *)(o + 0x40) = 0;
    func_00137140(o, o[0x21]);
    *(s32 *)(o + 0x48) = 0;
    *(f32 *)(o + 0x78) = 1.0f;
    *(f32 *)(o + 0x7C) = 1.0f;
    *(f32 *)(o + 0x80) = 1.0f;
    *(f32 *)(o + 0x50) = 1.0f;
    *(f32 *)(o + 0x54) = 1.0f;
    *(f32 *)(o + 0x58) = 1.0f;
    *(s32 *)(o + 0xDC) = 0;
    o[0x22] = 0;
    if (*(u16 *)(o + 0x26) != 0) func_001378C0(o);
    else func_00137910(o);
    func_0013AEA0(o);
}
