typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;

extern void func_0018C4B0(u8 *, int);
extern void func_0022F190(u8 *);
extern void func_0022FB80(u8 *, u8 *);
extern void func_0022FBA0(u8 *, u8 *);
extern u8 *D_004C2794;

void residual_0022FBC0(u8 *p, u8 *q)
{
    p[6]++;
    func_0018C4B0(p, 5);
    p[0x1B5] = 0x30;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    ((s16 *)(D_004C2794 + 124))[p[2]]++;
    func_0022F190(p);
    if (q[14])
        func_0022FB80(p, q);
    else {
        p[6]++;
        func_0022FBA0(p, q);
    }
}
