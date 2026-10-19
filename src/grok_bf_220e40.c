typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

typedef struct { u8 pad[0x7C]; s16 t7c[1]; } G2;
extern G2 *D_004C2794;
extern u8 D_004B7230[];
extern u8 D_004B71F0[];
extern u8 D_004B71C0[];
extern u8 D_004B71D0[];
extern void func_001757E0(u8 *, int, int);
extern void func_00222730(u8 *, int, f32 *, f32 *);

void func_00220E40(u8 *p)
{
    u8 *sub = p + 0x2B8;
    u8 saved;
    f32 a, b;

    p[0x1B5] = D_004B7230[*(u16 *)(p + 0x2D4)];
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    D_004C2794->t7c[p[2]]++;
    func_001757E0(p, 0x15, D_004B71F0[*(u16 *)(p + 0x2D4) * 4]);
    p[0x22] = D_004B71C0[*(u16 *)(sub + 0x1C)];
    saved = p[0x22];
    p[0x22] = D_004B71D0[*(u16 *)(sub + 0x1C)];
    func_00222730(p, 1000, &a, &b);
    p[0x22] = saved;
    if (p[0x1E6])
        a = -a;
    *(f32 *)(p + 0x5C) = a;
    *(f32 *)(p + 0x60) = b;
}
