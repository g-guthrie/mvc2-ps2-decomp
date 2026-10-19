/* Metrowerks 3.0: ./try.sh src/grok_nopm_2d5190.c "-O3 -sdatathreshold 8" */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;

extern u8 *D_004C2794;
extern void func_001757E0(u8 *, int, int);

void residual_002D5190(u8 *p)
{
    p[6]++;
    func_001757E0(p, 21, 21);
    if (p[617] == 3) {
        p[437] = 76;
        p[434] = *(u16 *)(p + 448) = 0;
        *(u32 *)(p + 472) = 0;
        ((s16 *)(D_004C2794 + 124))[p[2]]++;
    } else {
        p[437] = 8;
        p[434] = *(u16 *)(p + 448) = 0;
        *(u32 *)(p + 472) = 0;
        ((s16 *)(D_004C2794 + 124))[p[2]]++;
    }
}
