/* Metrowerks 3.0: ./try.sh src/grok_nopg_270bf0.c "-O3 -sdatathreshold 8" */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

extern u8 *D_004C2794;
extern void func_0018C4B0(u8 *, int);
extern void func_00185490(u8 *);
extern void func_001757E0(u8 *, int, int);
extern void func_00270B10(u8 *);
extern void func_00270D30(u8 *);

void residual_00270BF0(u8 *p)
{
    p[6]++;
    p[437] = 48;
    p[434] = *(u16 *)(p + 448) = 0;
    *(u32 *)(p + 472) = 0;
    ((s16 *)(D_004C2794 + 124))[p[2]]++;
    func_0018C4B0(p, 5);
    func_00185490(p);
    *(f32 *)(p + 92) = *(f32 *)(p + 92) / 16.0f;
    *(f32 *)(p + 96) = *(f32 *)(p + 96) / 8.0f;
    *(f32 *)(p + 108) = *(f32 *)(p + 108) / 64.0f;
    *(u32 *)(p + 104) = 0;
    if (p[525] == 2) {
        if (!p[439])
            func_001757E0(p, 21, 2);
        else
            func_001757E0(p, 21, 3);
    } else {
        func_00270B10(p);
        if (!p[439])
            func_001757E0(p, 21, 0);
        else
            func_001757E0(p, 21, 1);
    }
    func_00270D30(p);
}
