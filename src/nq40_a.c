typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef int s32;
typedef float f32;
extern u8 *D_004C2794;

void func_00312980(u8 *p, u8 *w)
{
    extern void func_0018C4B0(u8 *, s32);
    extern void func_00185490(u8 *);
    extern void func_00175C00(u8 *, s32);
    extern void func_00183D10(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_00312A70(u8 *, u8 *);
    u32 t = p[6];
    p[6] = t + 1;
    func_0018C4B0(p, 5);
    func_00185490(p);
    func_00175C00(p, 0);
    func_00183D10(p);
    *(f32 *)(p + 0x5C) = 0;
    *(f32 *)(p + 0x60) = 0;
    *(f32 *)(p + 0x68) = 0;
    *(f32 *)(p + 0x6C) = 0;
    p[0x20D] = 0;
    *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
    w[1] = 0;
    w[0] = 0;
    w[2] = 0;
    w[3] = 0;
    p[0x1B5] = *(s8 *)(p + 0x1B7) * 2 + 0x30;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    { u32 a = p[2] * 2; a += (u32)D_004C2794; a += 0x7C; ++*(s16 *)a; }
    func_001757E0(p, 21, p[0x1B7]);
    *(s16 *)(p + 0x1C) = *(s8 *)(p + 0x151);
    func_00312A70(p, w);
}
