/* ./try.sh src/grok_nopd_320750.c "-O3 -sdatathreshold 8" */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

extern u8 *D_004C2794;
extern void func_00185490(u8 *);
extern void func_00183D10(u8 *);
extern int func_001757E0(u8 *, int, int);

void func_00320750(u8 *p)
{
    p[6]++;
    p[525] = 1;
    *(f32 *)(p + 56) = *(f32 *)(p + 0x430);
    *(u32 *)(p + 0x5C) = 0;
    *(u32 *)(p + 0x60) = 0;
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x6C) = 0;
    p[0x1B5] = 99;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    ((s16 *)(D_004C2794 + 124))[p[2]]++;
    func_00185490(p);
    func_00183D10(p);
    func_001757E0(p, 21, 44);
}
