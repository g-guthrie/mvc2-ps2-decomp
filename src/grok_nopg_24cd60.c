/* Metrowerks 3.0: ./try.sh src/grok_nopg_24cd60.c "-O3 -sdatathreshold 8" */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

extern u8 *D_004C2794;
extern void func_00185490(u8 *);
extern void func_00175C00(u8 *, int);
extern int func_001757E0(u8 *, int, int);
extern void func_0024CE20(u8 *);

void func_0024CD60(u8 *p)
{
    p[6]++;
    func_00185490(p);
    func_00175C00(p, 0);
    *(u32 *)(p + 92) = 0;
    *(u32 *)(p + 96) = 0;
    *(u32 *)(p + 104) = 0;
    *(u32 *)(p + 108) = 0;
    *(f32 *)(p + 56) = *(f32 *)(p + 1072);
    p[528] = 0;
    p[525] = 0;
    *(s16 *)(p + 28) = 1;
    *(s16 *)(p + 30) = 0;
    p[437] = 60;
    p[434] = *(u16 *)(p + 448) = 0;
    *(u32 *)(p + 472) = 0;
    ((s16 *)(D_004C2794 + 124))[p[2]]++;
    func_001757E0(p, 21, 9);
    func_0024CE20(p);
}
