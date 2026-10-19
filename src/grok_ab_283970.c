typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef signed int s32;
typedef float f32;

typedef struct G { u8 pad[0x7C]; s16 t[2]; } G;
extern G *D_004C2794;
extern f32 D_00455AF0[];
extern void func_0018C4B0(u8 *, s32);
extern void func_00185490(u8 *);
extern void func_00183D10(u8 *);
extern void func_00383B80(u8 *, s32, s32);
extern void func_001757E0(u8 *, s32, s32);

void residual_00283970(u8 *p)
{
    p[6]++;
    p[0x1B5] = p[0x1B7] ? 0x3B : 0x39;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(s32 *)(p + 0x1D8) = 0;
    D_004C2794->t[p[2]]++;
    func_0018C4B0(p, 0xC);
    func_00185490(p);
    p[0x20D] = 0;
    *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
    *(s32 *)(p + 0x5C) = 0;
    *(s32 *)(p + 0x60) = 0;
    *(s32 *)(p + 0x68) = 0;
    *(s32 *)(p + 0x6C) = 0;
    *(s16 *)(p + 0x1E) = 0;
    if (p[0x1E6])
        *(f32 *)(p + 0x5C) = D_00455AF0[p[0x1B7] * 2];
    else
        *(f32 *)(p + 0x5C) = -D_00455AF0[p[0x1B7] * 2];
    *(f32 *)(p + 0x60) = D_00455AF0[p[0x1B7] * 2 + 1];
    *(s32 *)(p + 0x6C) = 0xC0092492;
    func_00183D10(p);
    func_00383B80(p, 4, 1);
    p[0x168] = p[0x1B7] ? 6 : 4;
    func_001757E0(p, 0x15, p[0x168]);
}
