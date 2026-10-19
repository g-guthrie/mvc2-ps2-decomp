/* Metrowerks 3.0: ./try.sh src/grok_nopg_246300.c "-O3 -sdatathreshold 8" */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

extern u8 *D_004C2794;
extern void func_0018C4B0(u8 *, int);
extern void func_00185490(u8 *);
extern void func_00175C00(u8 *, int);
extern void func_001757E0(u8 *, int, int);
extern void func_00246400(u8 *, int);

void residual_00246300(u8 *p, int a1)
{
    p[7]++;
    func_0018C4B0(p, 5);
    func_00185490(p);
    p[525] = 2;
    func_00175C00(p, 0);
    *(f32 *)(p + 92) = *(f32 *)(p + 92) / 16.0f;
    *(f32 *)(p + 96) = *(f32 *)(p + 96) / 8.0f;
    *(f32 *)(p + 108) = *(f32 *)(p + 108) / 64.0f;
    *(u32 *)(p + 104) = 0;
    p[437] = (signed char)p[439] + 48;
    p[434] = *(u16 *)(p + 448) = 0;
    *(u32 *)(p + 472) = 0;
    ((s16 *)(D_004C2794 + 124))[p[2]]++;
    func_001757E0(p, 21, 4);
    func_00246400(p, a1);
}
