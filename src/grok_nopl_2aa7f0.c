/* Metrowerks 3.0: ./try.sh src/grok_nopl_2aa7f0.c "-O3 -sdatathreshold 8" */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

extern u8 *D_004C2794;
extern f32 D_00458960[][4];
extern void func_0018C4B0(u8 *, int);
extern void func_00185490(u8 *);
extern void func_00394780(u8 *, int, int);
extern int func_001757E0(u8 *, int, int);

void func_002AA7F0(u8 *p)
{
    p[6]++;
    p[437] = p[439] ? 72 : 70;
    p[434] = *(u16 *)(p + 448) = 0;
    *(u32 *)(p + 472) = 0;
    ((s16 *)(D_004C2794 + 124))[p[2]]++;
    func_0018C4B0(p, 5);
    func_00185490(p);
    p[525] = 2;
    {
        f32 vx;
        if (p[486])
            vx = D_00458960[p[439]][0];
        else
            vx = -D_00458960[p[439]][0];
        *(f32 *)(p + 92) = vx;
    }
    {
        f32 vz;
        if (p[486])
            vz = D_00458960[p[439]][1];
        else
            vz = -D_00458960[p[439]][1];
        *(f32 *)(p + 104) = vz;
    }
    *(f32 *)(p + 96) = D_00458960[p[439]][2];
    *(f32 *)(p + 108) = D_00458960[p[439]][3];
    func_00394780(p, 9, 0);
    p[360] = p[439] ? 23 : 21;
    func_001757E0(p, 21, p[360]);
}
