typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;

extern u8 *D_004C2794;
extern void func_0018C4B0(u8 *, int);
extern int func_001757E0(u8 *, int, int);
extern void func_00275A80(u8 *);
extern void func_001E3210(u8 *, int);
extern void func_00276FE0(u8 *);

void func_00276F00(u8 *p)
{
    p[6]++;
    if (p[0x269] != 3)
        func_0018C4B0(p, 5);
    func_001757E0(p, 21, 18);
    func_00275A80(p);
    func_001E3210(p, 3);
    if (p[0x1B7]) {
        p[0x1B5] = 75;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(u32 *)(p + 0x1D8) = 0;
        ((s16 *)(D_004C2794 + 124))[p[2]]++;
    } else {
        p[0x1B5] = 51;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(u32 *)(p + 0x1D8) = 0;
        ((s16 *)(D_004C2794 + 124))[p[2]]++;
    }
    func_00276FE0(p);
}
