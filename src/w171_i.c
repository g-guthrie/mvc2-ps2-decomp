typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 *D_004C2794;
extern u8 D_004BFED0;
extern u8 D_004BFED4;
extern u8 D_004BFED8;

void func_00216B30(u8 *p)
{
    extern void func_001E3210(u8 *, s32);
    extern void func_001757E0(u8 *, s32, s32);
    s32 x;
    s32 y;
    s32 z;
    u32 off;
    s8 t;
    switch (p[0x1FC]) {
    case 0:
        x = 0xC;
        y = 0;
        *(u8 **)(p + 0x408) = &D_004BFED0;
        z = 0x1E;
        p[0x1BB] = 0;
        break;
    case 1:
        x = 0xD;
        y = 1;
        *(u8 **)(p + 0x408) = &D_004BFED4;
        z = 0x1F;
        p[0x1BB] = 1;
        break;
    case 2:
        x = 0xE;
        y = 2;
        *(u8 **)(p + 0x408) = &D_004BFED8;
        z = 0x20;
        p[0x1BB] = 2;
        break;
    }
    p[0x1B5] = x;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(s32 *)(p + 0x1D8) = 0;
    off = p[2] * 2;
    off += (u32)D_004C2794;
    ++*(s16 *)(off + 0x7C);
    func_001E3210(p, (u8)z);
    func_001757E0(p, 0xB, (u8)y);
    t = *(s8 *)(p + 0x1EA);
    if ((t & 0xF) != 0) {
        p[0x1EA] = t - 1;
    }
}

extern u32 data_u32_004C01B0[3] __attribute__((section(".sdata")));
void func_002340F0(u8 *p)
{
    extern void func_001E3710(u8 *, s32);
    extern void func_001757E0(u8 *, s32, s32);
    s32 x;
    s32 y;
    s32 z;
    u32 off;
    s8 t;
    switch (p[0x1FC]) {
    case 0:
        x = 0xC;
        y = 0;
        *(u8 **)(p + 0x408) = (u8 *)&data_u32_004C01B0[0];
        z = 0x14;
        p[0x1BB] = 0;
        break;
    case 1:
        x = 0xD;
        y = 1;
        *(u8 **)(p + 0x408) = (u8 *)&data_u32_004C01B0[1];
        z = 0x15;
        p[0x1BB] = 1;
        break;
    case 2:
        x = 0xE;
        y = 2;
        *(u8 **)(p + 0x408) = (u8 *)&data_u32_004C01B0[2];
        z = 0x16;
        p[0x1BB] = 2;
        break;
    }
    p[0x1B5] = x;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(s32 *)(p + 0x1D8) = 0;
    off = p[2] * 2;
    off += (u32)D_004C2794;
    ++*(s16 *)(off + 0x7C);
    func_001E3710(p, (u8)z);
    func_001757E0(p, 0xB, (u8)y);
    t = *(s8 *)(p + 0x1EA);
    if ((t & 0xF) != 0) {
        p[0x1EA] = t - 1;
    }
}
