typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern u8 *D_004C2794 __attribute__((section(".sdata")));
extern u8 D_004BFED0 __attribute__((section(".sdata")));
extern u8 D_004BFED4 __attribute__((section(".sdata")));
extern u8 D_004BFED8 __attribute__((section(".sdata")));
extern void func_001E3210(u8 *, s32);
extern void func_001757E0(u8 *, s32, s32);

void func_00216670(u8 *p)
{
    s32 x;
    s32 y;
    s32 z;
    s32 two = 2;
    u8 v = p[0x1FC];

    if (v == two) {
        x = 2;
        y = 2;
        *(u8 **)(p + 0x408) = &D_004BFED8;
        z = 0x20;
        p[0x1BB] = 2;
    } else
    switch (v) {
    case 0:
        x = 0;
        y = 0;
        *(u8 **)(p + 0x408) = &D_004BFED0;
        z = 0x1E;
        p[0x1BB] = 0;
        break;
    case 1:
        p[0x20] = 0;
        x = 1;
        y = 1;
        *(u8 **)(p + 0x408) = &D_004BFED4;
        z = 0x1F;
        p[0x1BB] = 1;
        break;
    }
    p[0x1B5] = (u8)x;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    ((s16 *)(D_004C2794 + 0x7C))[p[2]]++;
    func_001E3210(p, (u8)z);
    func_001757E0(p, 7, (u8)y);
}
