typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;

extern u8 *D_004C2794;
extern u16 D_004C0C60[];
extern u8 D_004C0C90[];
extern u8 D_004C0C94[];
extern void func_00185490(u8 *);
extern void func_00175C00(u8 *, int);
extern void func_00183D10(u8 *);
extern void func_0018C4B0(u8 *, int);
extern void func_001757E0(u8 *, int, int);

void residual_002AF720(u8 *p)
{
    p[6]++;
    p[0x20D] = 0;
    func_00185490(p);
    func_00175C00(p, 0);
    func_00183D10(p);
    func_0018C4B0(p, 8);
    *(u32 *)(p + 0x5C) = 0;
    *(u32 *)(p + 0x60) = 0;
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x6C) = 0;
    {
        u32 w = *(u32 *)(p + 0xD0);
        u8 k = p[0x1B7];
        u32 bit = w & 1;
        *(s16 *)(p + 0x1C) = *(u16 *)((u8 *)D_004C0C60 + (w << 2) + (k << 1));
        p[0x1B5] = D_004C0C90[(bit << 1) + k];
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(u32 *)(p + 0x1D8) = 0;
        ((s16 *)(D_004C2794 + 124))[p[2]]++;
        func_001757E0(p, 21, D_004C0C94[(bit << 1) + k]);
    }
}
