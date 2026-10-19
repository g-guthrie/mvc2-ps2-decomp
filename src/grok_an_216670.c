typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern u8 *D_004C2794;
extern u8 D_004BFED0;
extern u8 D_004BFED4;
extern u8 D_004BFED8;

void func_00216670(u8 *p)
{
    extern void func_001E3210(u8 *, s32);
    extern void func_001757E0(u8 *, s32, s32);
    s32 x;
    s32 y;
    s32 z;
    u32 off;
    u8 v = p[0x1FC];
    if (v == 2) {
        x = 2;
        y = 2;
        *(u8 **)(p + 0x408) = &D_004BFED8;
        z = 0x20;
        p[0x1BB] = 2;
    } else if (v == 1) {
        p[0x20] = 0;
        x = 1;
        y = 1;
        *(u8 **)(p + 0x408) = &D_004BFED4;
        z = 0x1F;
        p[0x1BB] = 1;
    } else if (v == 0) {
        x = 0;
        y = 0;
        *(u8 **)(p + 0x408) = &D_004BFED0;
        z = 0x1E;
        p[0x1BB] = 0;
    } else {
        p[0x1B5] = (u8)(u32)p;
        y = 0;
        z = 0;
        goto rest;
    }
    p[0x1B5] = x;
rest:
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(s32 *)(p + 0x1D8) = 0;
    off = p[2] * 2;
    off += (u32)D_004C2794;
    ++*(s16 *)(off + 0x7C);
    func_001E3210(p, (u8)z);
    func_001757E0(p, 7, (u8)y);
}
