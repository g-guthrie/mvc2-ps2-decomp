/* residual_002AF720: ./try.sh src/gr18_a.c "-O3 -sdatathreshold 8" */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef int s32;
typedef float f32;
extern u8 *D_004C2794;
extern u16 D_004C0C60[][2] __attribute__((section(".sdata")));
extern u8 D_004C0C90[] __attribute__((section(".sdata")));
extern u8 D_004C0C94[] __attribute__((section(".sdata")));

void residual_002AF720(u8 *p)
{
    extern void func_00185490(u8 *);
    extern void func_00175C00(u8 *, s32);
    extern void func_00183D10(u8 *);
    extern void func_0018C4B0(u8 *, s32);
    extern void func_001757E0(u8 *, s32, s32);
    u32 t = p[6];
    s32 i;
    s32 d;
    u32 b;
    p[6] = t + 1;
    p[0x20D] = 0;
    func_00185490(p);
    func_00175C00(p, 0);
    func_00183D10(p);
    func_0018C4B0(p, 8);
    *(f32 *)(p + 0x5C) = 0;
    *(f32 *)(p + 0x60) = 0;
    *(f32 *)(p + 0x68) = 0;
    *(f32 *)(p + 0x6C) = 0;
    d = *(s32 *)(p + 0xD0);
    i = ((d & 1) * 2) + (b = p[0x1B7]);
    *(u16 *)(p + 0x1C) = D_004C0C60[d][b];
    p[0x1B5] = D_004C0C90[i];
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    { u32 a = p[2] * 2; a += (u32)D_004C2794; a += 0x7C; ++*(s16 *)a; }
    func_001757E0(p, 21, D_004C0C94[i]);
}
