typedef unsigned char u8;

extern u8 *D_004C2804;
extern u8 *D_004C27F8;
extern u8 *D_004C27FC;
extern void func_00146710(u8 *, u8 *, int);
extern void func_001467E0(u8 *, u8 *, int);
extern void func_003DAA40(u8 *, u8 *, int);

void func_00146AE0(u8 *p)
{
    u8 *tbl;
    unsigned idx = p[0x21];
    int off;

    if (idx < 4)
        tbl = D_004C2804;
    else if (idx == 8)
        tbl = D_004C27F8;
    else if (idx == 9)
        tbl = D_004C2804;
    else
        tbl = D_004C27FC;
    off = p[0x20] << 1;
    if (!p[4])
        func_00146710(p, tbl, off);
    else if (p[4] == 1)
        func_001467E0(p, tbl, off);
    else
        func_003DAA40(p, tbl, off);
}
