typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 *D_004C2794;
extern void func_00175C00(u8 *, s32);
extern void func_001E3710(u8 *, s32);
extern int func_001757E0(u8 *, s32, s32);
extern void func_0029BAF0(u8 *);

void func_0029BA00(u8 *p)
{
    func_00175C00(p, 0);
    if (p[0x212] == 0 && p[0x20D] == 0 && p[0x1FC] == 2 && (*(u16 *)(p + 0x20E) & 0xC00)) {
        func_001E3710(p, 0x16);
        *(f32 *)(p + 0x68) *= 2.0f;
        p[0x1BB] = 2;
        *(u32 *)(p + 0x408) = 0;
        p[6] = 2;
        p[0x20D] = 2;
        p[0x1B5] = 0x15;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(u32 *)(p + 0x1D8) = 0;
        ((s16 *)(D_004C2794 + 124))[p[2]]++;
        func_001757E0(p, 0x14, 5);
        return;
    }
    func_0029BAF0(p);
}
