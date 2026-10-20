/* Metrowerks 3.0: ./try.sh src/grok_jl_002eeb40.c "-O4,p -sdatathreshold 8" */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

extern u8 *D_004C2794;
extern int func_00175700(u8 *);
extern int func_001853E0(u8 *);
extern int func_00186030(u8 *);
extern void func_001757E0(u8 *, int, int);
extern void func_002F1DF0(u8 *);
extern void func_002F1D90(u8 *);

void func_002EEB40(u8 *p)
{
    if ((s8)func_00175700(p) < 0) {
        func_002F1DF0(p);
        return;
    }
    if (*(s8 *)(p + 0x151) == 0)
        return;
    if (func_001853E0(p) != 0)
        return;
    if (func_00186030(p) != 0)
        return;
    if (((*(u16 *)(p + 0x362) | *(u16 *)(p + 0x366)) & 0x100) == 0)
        return;
    {
        f32 d = 160.0f;
        *(u16 *)(p + 0x366) = 0;
        if (p[0x1E6] == 0)
            d = -d;
        *(f32 *)(p + 0x34) += d;
        p[0x1B5] = 27;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(u32 *)(p + 0x1D8) = 0;
        ((s16 *)(D_004C2794 + 124))[p[2]]++;
        func_001757E0(p, 7, 4);
        func_002F1D90(p);
    }
}
