typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { s8 f0; s8 f1; s8 f2; } G_c;
typedef struct { u8 pad[0x7C]; s16 f7c[1]; } H_c;
extern G_c *D_004C29FC;
extern H_c *D_004C2794;
extern u8 D_004531D0[];
void func_00252690(u8 *p, u8 *q)
{
    extern s32 func_00189310(u8 *, u8 *, u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_00183D10(u8 *);
    if (*(s8 *)(q + 0xB) < 0) {
        p[6] = 0xF;
        func_001757E0(p, 0x16, 0xD);
        return;
    }
    switch (*(s8 *)(p + 0x539)) {
    default:
        if (p[0x212] != 0) break;
    case 0:
        if (func_00189310(p, D_004531D0, p + 0x3C8) == 0) return;
    }
    if (**(s8 **)(p + 0x420) == 0) return;
    {
        u32 t = p[6];
        p[6] = t + 1;
    }
    p[0x1B5] = 0x40;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(s32 *)(p + 0x1D8) = 0;
    D_004C2794->f7c[p[2]]++;
    q[0xC] = 1;
    func_001757E0(p, 0x16, 0xC);
    func_00183D10(p);
}
