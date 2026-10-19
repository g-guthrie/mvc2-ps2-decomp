/* Metrowerks 3.0: ./try.sh src/grok_nopm_311690.c "-O3 -sdatathreshold 8" */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;

extern u8 *D_004C2794;
extern void func_001861B0(u8 *);
extern void func_0018C4B0(u8 *, int);
extern void func_001757E0(u8 *, int, int);
extern void func_001E3710(u8 *, int);

void residual_00311690(u8 *p)
{
    func_001861B0(p);
    func_0018C4B0(p, 5);
    if (p[530] == 0) {
        p[6] = 1;
        p[525] = 0;
        func_001757E0(p, 20, 9);
        p[437] = 21;
        p[434] = *(u16 *)(p + 448) = 0;
        *(u32 *)(p + 472) = 0;
        ((s16 *)(D_004C2794 + 124))[p[2]]++;
        func_001E3710(p, 21);
    } else {
        p[6] = 2;
        p[7] = 0;
        p[525] = 1;
        func_001757E0(p, 20, 10);
        p[437] = 22;
        p[434] = *(u16 *)(p + 448) = 0;
        *(u32 *)(p + 472) = 0;
        ((s16 *)(D_004C2794 + 124))[p[2]]++;
    }
}
