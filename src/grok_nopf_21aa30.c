/* Metrowerks 3.0: ./try.sh src/grok_nopf_21aa30.c "-O3 -sdatathreshold 8" */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;

extern u8 *D_004C2794;
extern void func_00183D10(u8 *);
extern void func_00185490(u8 *);
extern void func_001757E0(u8 *, int, int);

void residual_0021AA30(u8 *p)
{
    int anim;

    if (p[617] == 6) {
        p[1028] = 255;
        p[1029] = 16;
    }
    p[7]++;
    *(u32 *)(p + 92) = 0;
    *(u32 *)(p + 96) = 0;
    *(u32 *)(p + 104) = 0;
    *(u32 *)(p + 108) = 0;
    p[437] = 68;
    p[434] = *(u16 *)(p + 448) = 0;
    *(u32 *)(p + 472) = 0;
    ((s16 *)(D_004C2794 + 124))[p[2]]++;
    anim = 11;
    if (p[525] == 2) {
        *(u32 *)(p + 96) = 0x41092492;
        *(u32 *)(p + 108) = 0xBF2B6DB6;
        anim = anim + 1;
    } else {
        func_00183D10(p);
    }
    func_00185490(p);
    func_001757E0(p, 22, (u8)anim);
}
