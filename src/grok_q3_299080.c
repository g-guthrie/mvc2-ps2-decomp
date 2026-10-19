/* Metrowerks 3.0: ./try.sh src/grok_q3_299080.c "-O3 -sdatathreshold 8" */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

extern u8 *D_004C2794;
extern void func_00185490(u8 *);
extern void func_00183D10(u8 *);
extern void func_001757E0(u8 *, int, int);

void residual_00299080(u8 *p)
{
    p[6]++;
    if (p[617] == 6) {
        p[1028] = 255;
        p[1029] = 16;
    }
    func_00185490(p);
    func_00183D10(p);
    *(f32 *)(p + 56) = *(f32 *)(p + 1072);
    p[525] = 0;
    p[437] = 79;
    p[434] = *(u16 *)(p + 448) = 0;
    *(u32 *)(p + 472) = 0;
    ((s16 *)(D_004C2794 + 124))[p[2]]++;
    func_001757E0(p, 22, 0);
}
