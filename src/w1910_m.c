typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
extern volatile s32 D_00633E20;
extern u8 D_00633E30[];
extern s8 D_00633E34[];
extern s8 D_00633E35[];
extern s16 D_00633E36[];

s32 func_004230B0(u32 a, s8 b, s8 c, s16 d)
{
    s32 w, f0, f1, f2, n; s8 fl; u8 *e; s32 off;
    off = D_00633E20 * 8;
    e = (u8 *)((s32)D_00633E30 + off);
    w = *(s32 *)e;
    if (w < 0) {} else return -1;
    f1 = (c >= 0) ? 1 : 0;
    f0 = (b >= 0) ? 1 : 0;
    f2 = (d >= 0) ? 1 : 0;
    fl = ((f2 & 1) << 2) | ((f0 & 1) | 8 | ((f1 & 1) << 1));
    if (fl == 8) return 1;
    *(s32 *)e = (fl << 24) | (a & 0xFFFFFF);
    *(s8 *)((u8 *)D_00633E34 + off) = b;
    *(s8 *)((u8 *)D_00633E35 + off) = c;
    *(s16 *)((u8 *)D_00633E36 + off) = d;
    n = D_00633E20 + 1;
    D_00633E20 = n;
    D_00633E20 = n % 64;
    return 0;
}
