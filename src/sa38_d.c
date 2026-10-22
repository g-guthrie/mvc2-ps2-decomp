typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { u8 pad[0x1C]; u32 f1c; } GA;
typedef struct { u8 pad[0x7C]; s16 f7c[8]; } GB;
extern GA *D_004C2840;
extern GB *D_004C2794;
extern f32 D_00474700[], D_00474704[];
void func_003BC870(u8 *p)
{
    extern void func_003BD840(u8 *);
    extern s32 func_00174170();
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_003BCE40(u8 *);
    u8 *s0;
    f32 f, g;
    u32 t = p[4];
    p[4] = t + 1;
    s0 = *(u8 **)(p + 0x18);
    func_003BD840(p);
    p[0x1B0] = 0x44;
    p[0x1B1] = 0x44;
    if (D_004C2840->f1c & 1) {
        p[0x1B5] = 0x27;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(u32 *)(p + 0x1D8) = 0;
        D_004C2794->f7c[p[2]]++;
    } else {
        p[0x1B5] = 0x29;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(u32 *)(p + 0x1D8) = 0;
        D_004C2794->f7c[p[2]]++;
    }
    *(f32 *)(p + 0x34) = *(f32 *)(s0 + 0x34);
    *(f32 *)(p + 0x38) = 240.0f + *(f32 *)(s0 + 0x38);
    *(s16 *)(p + 0x1C) = 0x30;
    func_001757E0(p, 0x19, 0x1B);
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x6C) = 0;
    f = D_00474700[(func_00174170() & 7) * 2];
    if (*(s16 *)(p + 0x140) == 0) f = -f;
    *(f32 *)(p + 0x5C) = f;
    g = D_00474704[(func_00174170() & 7) * 2];
    if (func_00174170() & 1) g = -g;
    *(f32 *)(p + 0x60) = g;
    func_003BCE40(p);
}
