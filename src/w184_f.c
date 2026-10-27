typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x7C]; s16 f7c[8]; } G;
extern G *D_004C2794;
extern s32 D_004C08A4[1];
extern s32 D_004C08A8[1];
extern s32 D_004C08AC[1];

void func_00281DD0(u8 *p)
{
    extern void func_001E3710(u8 *, s32);
    extern void func_001757E0(u8 *, s32, s32);
    u8 t;
    switch (p[0x1FC]) {
    case 0:
        p[0x168] = 0;
        p[0x1B5] = 9;
        func_001E3710(p, 0x14);
        *(s32 **)(p + 0x408) = D_004C08A4;
        p[0x1BB] = 0;
        break;
    case 1:
        p[0x168] = 1;
        p[0x1B5] = 0xA;
        func_001E3710(p, 0x15);
        *(s32 **)(p + 0x408) = D_004C08A8;
        p[0x1BB] = 1;
        break;
    case 2:
        *(s32 **)(p + 0x408) = D_004C08AC;
        p[0x1BB] = 2;
        if (*(s8 *)(p + 0x539) == 0 && (*(u16 *)(p + 0x20E) & 0x400) != 0) {
            p[6]++;
            p[0x1B5] = 0x12;
            p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
            *(s32 *)(p + 0x1D8) = 0;
            D_004C2794->f7c[p[2]]++;
            func_001757E0(p, 0xA, 3);
            return;
        }
        p[0x168] = 2;
        p[0x1B5] = 0xB;
        func_001E3710(p, 0x16);
        break;
    default:
        break;
    }
    t = *(u8 *)(p + 0x1B5);
    p[0x1B5] = t;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(s32 *)(p + 0x1D8) = 0;
    D_004C2794->f7c[p[2]]++;
    func_001757E0(p, 0xA, p[0x168]);
}
