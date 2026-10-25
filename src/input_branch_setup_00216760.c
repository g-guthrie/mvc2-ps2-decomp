typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { u8 pad[0x5C]; f32 f5c; } PS;

extern u8 *D_004C2794;
extern signed char D_004BFED0[3][4] __attribute__((section(".sdata")));

void func_00216760(u8 *p)
{
    extern void func_001E3210(u8 *, s32);
    extern int func_001757E0(u8 *, s32, s32);
    s32 x;
    s32 y;
    s32 z;
    u32 off;
    p[6] = 0;
    switch (p[0x1FC]) {
    case 0:
        x = 6;
        y = 0;
        *(signed char **)(p + 0x408) = &D_004BFED0[0][0];
        z = 0x1E;
        p[0x1BB] = 0;
        break;
    case 1:
        x = 7;
        y = 1;
        *(signed char **)(p + 0x408) = &D_004BFED0[1][0];
        z = 0x1F;
        p[0x1BB] = 1;
        break;
    case 2:
        *(signed char **)(p + 0x408) = &D_004BFED0[2][0];
        p[0x1BB] = 2;
        if ((*(u16 *)(p + 0x20E) & 0x800) != 0) {
            x = 0x12;
            p[6] = 1;
            y = 5;
            *(u32 *)(p + 0x5C) = 0;
            *(u32 *)(p + 0x60) = 0;
            *(u32 *)(p + 0x68) = 0;
            *(u32 *)(p + 0x6C) = 0;
        } else {
            *(u32 *)(p + 0x5C) = 0xC0A00000;
            y = 2;
            *(u32 *)(p + 0x68) = 0;
            x = 8;
            z = 0x20;
            if (p[0x1E6] != 0) {
                { PS *q = (PS *)p; f32 t = q->f5c; q->f5c = -t; }
            }
        }
        break;
    }
    p[0x1B5] = x;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(s32 *)(p + 0x1D8) = 0;
    off = p[2] * 2;
    off += (u32)D_004C2794;
    ++*(s16 *)(off + 0x7C);
    func_001757E0(p, 9, (u8)y);
    if (p[6] == 0) {
        func_001E3210(p, (u8)z);
    }
}
