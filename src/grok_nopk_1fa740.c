/*
 * func_001FA720 dispatches this state through jtbl_004BFCB8[0] with actor p.
 * The callback uses only that actor record.
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;

extern u8 *D_004C2794;
extern void func_001F9490(u8 *);
extern void func_00183D10(u8 *);
extern void func_001757E0(u8 *, int, int);

void func_001FA740(u8 *p)
{
    p[6]++;
    func_001F9490(p);
    func_00183D10(p);
    p[437] = 64;
    p[434] = *(u16 *)(p + 448) = 0;
    *(u32 *)(p + 472) = 0;
    ((s16 *)(D_004C2794 + 124))[p[2]]++;
    func_001757E0(p, 21, 5);
}
