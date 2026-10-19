/* Metrowerks 3.0: ./try.sh src/grok_noph_2d3720.c "-O3 -sdatathreshold 8" */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;

extern u8 *D_004C2794;
extern void func_00185490(u8 *);
extern int func_001757E0(u8 *, int, int);
extern u8 *func_0039C5B0(u8 *, int);
extern void func_0018C4B0(u8 *, int);
extern void func_00183D10(u8 *);

void func_002D3720(u8 *p)
{
    u8 *q;

    p[6]++;
    func_00185490(p);
    p[696] = 0;
    *(s16 *)(p + 28) = 0;
    p[437] = 48;
    p[434] = *(u16 *)(p + 448) = 0;
    *(u32 *)(p + 472) = 0;
    ((s16 *)(D_004C2794 + 124))[p[2]]++;
    if (p[439] == 0)
        func_001757E0(p, 21, 6);
    else
        func_001757E0(p, 21, 8);
    q = func_0039C5B0(p, 2);
    if (q)
        q[149] = 2;
    func_0018C4B0(p, 5);
    func_00183D10(p);
}
