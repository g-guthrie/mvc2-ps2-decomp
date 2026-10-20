/* ./try.sh src/grok_hi_00320f60.c "-O4,p -sdatathreshold 8" */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef signed int s32;
typedef unsigned int u32;
typedef float f32;

extern u8 *D_004C2794;
extern void func_001757E0(u8 *, int, int);

void residual_00320F60(u8 *p)
{
    p[6]++;
    p[0x20D] = 2;
    *(u32 *)(p + 0x5C) = 0x41F00000u;
    if (p[0x1E6] == 0)
        *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x60) = 0x40892492u;
    *(u32 *)(p + 0x6C) = 0xBF4DB6DBu;
    p[0x1B5] = 0x4A;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(s32 *)(p + 0x1D8) = 0;
    ((s16 *)(D_004C2794 + 0x7C))[p[2]]++;
    func_001757E0(p, 0x15, 0x22);
}
