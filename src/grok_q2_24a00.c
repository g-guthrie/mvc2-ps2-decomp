/* Metrowerks 3.0: ./try.sh src/grok_q2_24a00.c "-O3 -sdatathreshold 8" */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef float f32;

extern u8 *D_004C2794;
extern void func_00185490(u8 *);
extern void func_00183D10(u8 *);
extern void func_0018C4B0(u8 *, int);
extern int func_001757E0(u8 *, int, int);
extern void func_00224AC0(u8 *);

void func_00224A00(u8 *p)
{
    p[6]++;
    func_00185490(p);
    *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
    p[0x20D] = 0;
    func_00183D10(p);
    p[0x1B5] = (s8)p[0x1B7] + 0x34;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    ((s16 *)(D_004C2794 + 124))[p[2]]++;
    func_0018C4B0(p, 5);
    func_001757E0(p, 21, (u8)(p[0x1B7] + 6));
    *(s16 *)(p + 0x1C) = 0x28;
    *(u32 *)(p + 0x5C) = 0;
    *(u32 *)(p + 0x60) = 0;
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x6C) = 0;
    func_00224AC0(p);
}
