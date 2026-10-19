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

extern f32 D_004535C0[];

void residual_0025B130(u8 *p)
{
    f32 *g;
    unsigned int offset;

    p[6]++;
    p[0x1B5] = 0x56;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    offset = p[2] * 2;
    offset += (unsigned int)D_004C2794;
    ++*(s16 *)(offset + 0x7C);
    func_0018C4B0(p, 5);
    func_00185490(p);
    func_00183D10(p);
    {
        u8 idx = p[0x1B7];
        u8 face;
        g = D_004535C0;
        face = p[0x1E6];
        g = (f32 *)((char *)g + (idx << 4));
        *(f32 *)(p + 0x5C) = face ? -g[0] : g[0];
        *(f32 *)(p + 0x68) = p[0x1E6] ? -g[1] : g[1];
        *(f32 *)(p + 0x60) = g[2];
        *(f32 *)(p + 0x6C) = g[3];
    }
    func_001757E0(p, 0x15, 6);
}
