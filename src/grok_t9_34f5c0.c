typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

extern void func_0034E880(u8 *);
extern int func_00175700(void);
extern void func_001757E0(u8 *, int, int);
extern void func_001E3210(u8 *, int);
extern void func_0034F7D0(u8 *);
extern u8 *D_004C294C;
extern u8 *D_004C2794;

void residual_0034F5C0(u8 *p)
{
    f32 vx;
    u8 *g;
    u8 *parent;
    func_0034E880(p);
    func_00175700();
    g = D_004C294C;
    if (g[2]) {
        p[5]++;
        D_004C294C[2] = 1;
        p[0x1B5] = 0x48;
        *(s16 *)(p + 0x1C0) = 0;
        p[0x1B2] = (u8)(0 & 0xFFFF);
        *(u32 *)(p + 0x1D8) = 0;
        ((s16 *)(D_004C2794 + 0x7C))[p[2]]++;
        if (*(s16 *)(p + 0x140))
            vx = 15.20833301544189453125f;
        else
            vx = -15.20833301544189453125f;
        *(f32 *)(p + 0x5C) = vx;
        func_001757E0(p, 0x17, 0x17);
        func_001E3210(p, 0x21);
    } else {
        parent = *(u8 **)(p + 0x18);
        if ((s8)parent[0x13C] == 0)
            func_0034F7D0(p);
        else if (*(s16 *)(parent + 0x434) == 0)
            func_0034F7D0(p);
        else if ((s8)g[1] == 0)
            func_0034F7D0(p);
        else
            ;
    }
}
