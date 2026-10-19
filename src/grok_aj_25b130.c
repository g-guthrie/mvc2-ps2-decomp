typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

extern u8 *D_004C2794 __attribute__((section(".sdata")));
extern void func_0018C4B0(u8 *, int);
extern void func_00185490(u8 *);
extern void func_00183D10(u8 *);
extern void func_001757E0(u8 *, int, int);

typedef struct { f32 a, b, c, d; } F4;
extern F4 D_004535C0[];

void residual_0025B130(u8 *p)
{
    F4 *t;

    p[6]++;
    p[0x1B5] = 0x56;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    ((s16 *)(D_004C2794 + 0x7C))[p[2]]++;
    func_0018C4B0(p, 5);
    func_00185490(p);
    func_00183D10(p);
    {
        u8 face = p[0x1E6];
        u8 idx = p[0x1B7];
        f32 *g = (f32 *)((char *)D_004535C0 + (idx << 4));
        *(f32 *)(p + 0x5C) = face ? -g[0] : g[0];
        *(f32 *)(p + 0x68) = p[0x1E6] ? -g[1] : g[1];
        *(f32 *)(p + 0x60) = g[2];
        *(f32 *)(p + 0x6C) = g[3];
    }
    func_001757E0(p, 0x15, 6);
}
