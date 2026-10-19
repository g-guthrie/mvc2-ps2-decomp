typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef void (*Callback)(u8 *, u8 *);

extern const unsigned int jtbl_0045BBE0[12];
extern u8 D_004C12D8[4], D_004C12DC[4];
extern u8 *D_004C2794;
extern void func_002F3DE0(u8 *);
extern void func_0018C4B0(u8 *, int);
extern void func_00183D10(u8 *);
extern int func_001757E0(u8 *, int, int);

void func_002F4010(u8 *p)
{
    p[0x1B0] = 0;
    p[0x200] = 3;
    p[0x206] = 0;
    ((Callback *)jtbl_0045BBE0)[p[6]](p, p + 0x2B8);
}

void func_002F4050(u8 *p, u8 *context)
{
    p[6]++;
    func_002F3DE0(p);
    p[0x1E9] = 0;
    *(s16 *)context = p[0x1B7];
    func_001757E0(p, 21, D_004C12D8[p[0x1B7]]);
    p[0x1B5] = D_004C12DC[p[0x1B7]];
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    ((s16 *)(D_004C2794 + 0x7C))[p[2]]++;
    *(s16 *)(p + 0x366) = 0;
    func_0018C4B0(p, 5);
    func_00183D10(p);
}
