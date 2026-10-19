typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef signed int s32;
typedef unsigned int u32;
typedef float f32;

typedef struct G { u8 pad[0x7C]; s16 t[2]; } G;
extern G *D_004C2794;
extern u32 D_004548D0[];
extern f32 D_004F1F4C;
extern void func_0018C4B0(u8 *, s32);
extern void func_00185490(u8 *);
extern void func_00270B10(u8 *);
extern s32 func_00119058(f32);
extern s32 func_00119568(s32, s32);
extern s32 dpadd(s32, s32);
extern f32 func_00119C90(s32);
extern void func_00183D10(u8 *);
extern void func_001757E0(u8 *, s32, s32);

void residual_00270F80(u8 *p)
{
    f32 tmp[4];
    s32 v;
    *(u32 *)&tmp[0] = D_004548D0[0];
    *(u32 *)&tmp[1] = D_004548D0[1];
    *(u32 *)&tmp[2] = D_004548D0[2];
    *(u32 *)&tmp[3] = D_004548D0[3];
    p[6]++;
    p[0x1B5] = (u8)(*(s8 *)(p + 0x1B7) + 0x36);
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(s32 *)(p + 0x1D8) = 0;
    D_004C2794->t[p[2]]++;
    func_0018C4B0(p, 5);
    func_00185490(p);
    func_00270B10(p);
    if (p[0x1E6])
        v = func_00119568(func_00119058(D_004F1F4C), 0x40740000);
    else
        v = dpadd(0x40740000, func_00119058(D_004F1F4C));
    *(f32 *)(p + 0x5C) = (func_00119C90(v) - *(f32 *)(p + 0x34)) / 32.0f;
    *(s32 *)(p + 0x68) = 0;
    *(f32 *)(p + 0x60) = tmp[p[0x1B7] * 2];
    *(f32 *)(p + 0x6C) = tmp[p[0x1B7] * 2 + 1];
    func_00183D10(p);
    func_001757E0(p, 0x15, (u8)(p[0x1B7] + 0xC));
}
