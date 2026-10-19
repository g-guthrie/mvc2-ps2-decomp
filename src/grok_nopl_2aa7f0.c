/* Metrowerks 3.0: ./try.sh src/grok_nopl_2aa7f0.c "-O3 -sdatathreshold 8" */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed char s8;
typedef float f32;

extern u8 *D_004C2794;
extern f32 D_00458960[][4];
/* Column views over the existing eight-word raw motion tables at 004500C0 and 004500F0. */
extern f32 D_004500C0[][4];
extern f32 D_004500C4[][4];
extern f32 D_004500C8[][4];
extern f32 D_004500CC[][4];
extern f32 D_004500F0[][4];
extern f32 D_004500F4[][4];
extern f32 D_004500F8[][4];
extern f32 D_004500FC[][4];
extern void func_0018C4B0(u8 *, int);
extern void func_00185490(u8 *);
extern void func_001FED30(u8 *);
extern void func_00183D10(u8 *);
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

void func_001FF620(u8 *p)
{
    p[7]++;
    p[0x1B5] = p[0x1B7] + 52;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    ((s16 *)(D_004C2794 + 124))[p[2]]++;
    func_0018C4B0(p, 5);
    func_00185490(p);
    p[0x20D] = 2;
    *(u32 *)(p + 0x5C) = 0;
    *(u32 *)(p + 0x60) = 0;
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x6C) = 0;
    {
        f32 vx;
        if (p[0x1E6])
            vx = D_004500F0[p[0x1B7]][0];
        else
            vx = -D_004500F0[p[0x1B7]][0];
        *(f32 *)(p + 92) = vx;
    }
    {
        f32 vz;
        if (p[0x1E6])
            vz = D_004500F4[p[0x1B7]][0];
        else
            vz = -D_004500F4[p[0x1B7]][0];
        *(f32 *)(p + 104) = vz;
    }
    *(f32 *)(p + 96) = D_004500F8[p[0x1B7]][0];
    *(f32 *)(p + 108) = D_004500FC[p[0x1B7]][0];
    func_001757E0(p, 21, (u8)(p[0x1B7] + 7));
}

void func_001FF1E0(u8 *p)
{
    p[7]++;
    if (p[0x269] == 3) {
        p[0x1B5] = 49;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(u32 *)(p + 0x1D8) = 0;
        ((s16 *)(D_004C2794 + 124))[p[2]]++;
    } else {
        p[0x1B5] = (s8)p[0x1B7] + 48;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(u32 *)(p + 0x1D8) = 0;
        ((s16 *)(D_004C2794 + 124))[p[2]]++;
    }
    func_0018C4B0(p, 5);
    func_001FED30(p);
    func_00183D10(p);
    {
        f32 vx;
        if (p[0x1E6])
            vx = D_004500C0[p[0x1B7]][0];
        else
            vx = -D_004500C0[p[0x1B7]][0];
        *(f32 *)(p + 92) = vx;
    }
    {
        f32 vz;
        if (p[0x1E6])
            vz = D_004500C4[p[0x1B7]][0];
        else
            vz = -D_004500C4[p[0x1B7]][0];
        *(f32 *)(p + 104) = vz;
    }
    *(f32 *)(p + 96) = D_004500C8[p[0x1B7]][0];
    *(f32 *)(p + 108) = D_004500CC[p[0x1B7]][0];
    p[0x168] = (s8)p[0x1B7] + 5;
    func_001757E0(p, 21, p[0x168]);
}
