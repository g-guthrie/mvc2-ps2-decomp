/* Metrowerks 3.0: ./try.sh src/grok_nopg_2a0100.c "-O3 -sdatathreshold 8" */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

extern u8 *D_004C2794;
extern void func_001E3210(u8 *, int);
extern void func_00185490(u8 *);
extern void func_001757E0(u8 *, int, int);

void residual_002A0100(u8 *p)
{
    p[6]++;
    func_001E3210(p, 43);
    *(u32 *)(p + 92) = 0;
    *(u32 *)(p + 96) = 0;
    *(u32 *)(p + 104) = 0;
    *(u32 *)(p + 108) = 0;
    p[525] = 0;
    *(f32 *)(p + 56) = *(f32 *)(p + 1072);
    *(u32 *)(p + 92) = 0xC1200000;
    *(u32 *)(p + 104) = 0x3E200000;
    if (p[486]) {
        *(f32 *)(p + 92) = -*(f32 *)(p + 92);
        *(f32 *)(p + 104) = -*(f32 *)(p + 104);
    }
    func_00185490(p);
    p[437] = 65;
    p[434] = *(u16 *)(p + 448) = 0;
    *(u32 *)(p + 472) = 0;
    ((s16 *)(D_004C2794 + 124))[p[2]]++;
    func_001757E0(p, 20, 2);
}
