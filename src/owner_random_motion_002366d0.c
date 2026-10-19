/* MWCCPS2 3.0.3: -O3 -sdatathreshold 8 */
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef unsigned int u32;
typedef float f32;

extern u8 *D_004C2794;
extern u8 D_004C01C8[] __attribute__((section(".sdata")));
extern void func_00185490(u8 *);
extern void func_00183D10(u8 *);
extern int func_001757E0(u8 *, int, int);

void func_002366D0(u8 *p, void *context)
{
    p[6]++;
    p[0x20D] = 0;
    *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
    p[0x210] = 0;
    ((u8 *)context)[7] = 0;
    func_00185490(p);
    func_00183D10(p);
    p[0x22] = D_004C01C8[p[0x1B7]];
    p[0x1B5] = p[0x1B7] + 66;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    ((s16 *)(D_004C2794 + 0x7C))[p[2]]++;
    func_001757E0(p, 21, (u8)(p[0x1B7] + 18));
}
