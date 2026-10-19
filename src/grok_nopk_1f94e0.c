/* Metrowerks 3.0: ./try.sh src/grok_nopk_1f94e0.c "-O3 -sdatathreshold 8" */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;

extern u8 *D_004C2794;
extern void func_001F9490(u8 *);
extern void func_00183D10(u8 *);
extern void func_0018C4B0(u8 *, int);
extern void func_00185490(u8 *);
extern void func_001E3210(u8 *, int);
extern void func_001757E0(u8 *, int, int);
extern void func_001F9590(u8 *);

void residual_001F94E0(u8 *p)
{
    p[6]++;
    func_001F9490(p);
    func_00183D10(p);
    p[437] = 48;
    p[434] = *(u16 *)(p + 448) = 0;
    *(u32 *)(p + 472) = 0;
    ((s16 *)(D_004C2794 + 124))[p[2]]++;
    func_0018C4B0(p, 5);
    func_00185490(p);
    func_001E3210(p, 20);
    func_001757E0(p, 21, p[439]);
    func_001F9590(p);
}
