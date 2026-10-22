typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern u8 *D_004C2794;
extern s32 D_0045D680[][3];
extern void func_001861B0(u8 *);
extern void func_001757E0(u8 *, u8, s32);
extern void func_001E3710(u8 *, u8);

void func_00317460(u8 *p)
{
    u32 off;
    u8 a;
    func_001861B0(p);
    *(u8 **)(p + 0x408) = (u8 *)D_0045D680 + (p[0x1FC] * 4 + p[0x212] * 12);
    p[0x1BB] = p[0x1FC];
    a = p[0x212];
    if (a != 0 && p[0x1FC] == 2 && p[0x20D] == 0) {
        p[0x1B5] = 0x19;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(u32 *)(p + 0x1D8) = 0;
        off = p[2] * 2;
        off += (u32)D_004C2794;
        ++*(s16 *)(off + 0x7C);
    } else {
        p[0x1B5] = (s8)p[0x1FC] + ((s8)p[0x20D] * 6 + (s8)a * 3);
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(u32 *)(p + 0x1D8) = 0;
        off = p[2] * 2;
        off += (u32)D_004C2794;
        ++*(s16 *)(off + 0x7C);
    }
    {u32 x = p[0x20D] * 2 + 7; func_001757E0(p, x + p[0x212], p[0x1FC]);}
    if (p[0x212] != 0 || p[0x1FC] != 2)
        func_001E3710(p, p[0x1FC] + 0x14);
}
