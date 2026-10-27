typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x7C]; s16 f7c[1]; } G21;
extern G21 *D_004C2794;
extern s32 D_004BFC6C, D_004BFC70, D_004BFC74, D_004BFC84, D_004BFC88, D_004BFC8C;

void func_001F82C0(u8 *p) {
    extern void func_001E3710(u8 *, s32);
    extern void func_001757E0(u8 *, s32, s32);
    u8 t;
    switch (p[0x1FC]) {
    case 0:
        if (*(u16 *)(p + 0x20E) & 0x2000) {
            p[0x168] = 0;
            p[0x1B5] = 0xF;
        } else {
            p[0x168] = 3;
            p[0x1B5] = 0xF;
        }
        func_001E3710(p, 0x14);
        if (p[0x210] == 0) {
            *(s32 **)(p + 0x408) = &D_004BFC6C;
        } else {
            *(s32 **)(p + 0x408) = &D_004BFC84;
        }
        p[0x1BB] = 0;
        break;
    case 1:
        if (*(u16 *)(p + 0x20E) & 0x2000) {
            p[0x168] = 4;
            p[0x1B5] = 0x10;
        } else {
            p[0x168] = 1;
            p[0x1B5] = 0x10;
        }
        func_001E3710(p, 0x15);
        if (p[0x210] == 0) {
            *(s32 **)(p + 0x408) = &D_004BFC70;
        } else {
            *(s32 **)(p + 0x408) = &D_004BFC88;
        }
        p[0x1BB] = 1;
        break;
    case 2:
        if (*(u16 *)(p + 0x20E) & 0x2000) {
            p[0x168] = 5;
            p[0x1B5] = 0x11;
        } else {
            p[0x168] = 2;
            p[0x1B5] = 0x11;
        }
        func_001E3710(p, 0x16);
        if (p[0x210] == 0) {
            *(s32 **)(p + 0x408) = &D_004BFC74;
        } else {
            *(s32 **)(p + 0x408) = &D_004BFC8C;
        }
        p[0x1BB] = 2;
        break;
    default:
        break;
    }
    t = *(u8 *)(p + 0x1B5);
    p[0x1B5] = t;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(s32 *)(p + 0x1D8) = 0;
    D_004C2794->f7c[p[2]]++;
    func_001757E0(p, 0xC, p[0x168]);
    {
        s8 a = *(s8 *)(p + 0x1EA);
        if (a & 0xF0) {
            *(s8 *)((s32)p + 0x1EA) = a - 0x10;
        }
    }
}
