typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;

typedef struct G { u8 pad[0x7C]; s16 t[8]; } G;
extern G *D_004C2794 __attribute__((section(".sdata")));
extern void func_00183D10(u8 *);
extern void func_002C25A0(u8 *);
extern void func_001E3210(u8 *, int);
extern void func_0018C4B0(u8 *, int);
extern void func_00185490(u8 *);
extern void func_001757E0(u8 *, int, int);

void residual_002C2850(u8 *p)
{
    p[6]++;
    func_00183D10(p);
    func_002C25A0(p);
    func_001E3210(p, 0x16);
    if (p[0x1B7] == 0) {
        p[0x1B5] = 0x45;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(u32 *)(p + 0x1D8) = 0;
        D_004C2794->t[p[2]]++;
    } else {
        p[0x1B5] = 0x4F;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(u32 *)(p + 0x1D8) = 0;
        D_004C2794->t[p[2]]++;
    }
    func_0018C4B0(p, 0xA);
    func_00185490(p);
    p[0x168] = (u8)(*(s8 *)(p + 0x1B7) + 1);
    func_001757E0(p, 0x15, p[0x168]);
}
