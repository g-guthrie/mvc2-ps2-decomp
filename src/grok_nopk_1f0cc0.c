/* Metrowerks 3.0: ./try.sh src/grok_nopk_1f0cc0.c "-O3 -sdatathreshold 8" */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;

extern u8 *D_004C2794;
extern void func_0018C4B0(u8 *, int);
extern void func_001F0420(u8 *);
extern int func_001757E0(u8 *, int, int);

void func_001F0CC0(u8 *p)
{
    p[6]++;
    p[437] = 48;
    p[434] = *(u16 *)(p + 448) = 0;
    *(u32 *)(p + 472) = 0;
    ((s16 *)(D_004C2794 + 124))[p[2]]++;
    func_0018C4B0(p, 6);
    func_001F0420(p);
    func_001757E0(p, 21, (u8)(p[439] + 4));
}
