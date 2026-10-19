/* ./try.sh src/grok_as_00310370.c "-O3 -sdatathreshold 8" */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef signed int s32;
typedef unsigned int u32;
typedef signed char s8;

typedef struct G { u8 pad[0x7C]; s16 t[2]; } G;
extern G *D_004C2794;
extern u32 D_004C1680, D_004C1688, D_004C168C;
extern void func_001E3710(u8 *, s32);
extern void func_001E3210(u8 *, s32);
extern void func_001757E0(u8 *, s32, s32);

void func_00310370(u8 *p)
{
    switch (p[0x1FC]) {
    case 0:
        p[0x168] = 0;
        p[0x1B5] = 9;
        func_001E3710(p, 0x14);
        *(u32 *)(p + 0x408) = (u32)(&D_004C1680 + 1);
        p[0x1BB] = 0;
        break;
    case 1:
        p[0x168] = 1;
        p[0x1B5] = 10;
        *(u32 *)(p + 0x408) = (u32)&D_004C1688;
        p[0x1BB] = 1;
        p[6] = 0;
        break;
    case 2:
        p[0x168] = 2;
        p[0x1B5] = 11;
        *(u32 *)(p + 0x408) = (u32)&D_004C168C;
        p[0x1BB] = 2;
        p[6] = 0;
        func_001E3210(p, 0x1C);
        func_001E3710(p, 0x16);
        break;
    }
    p[0x1B5] = (s8)p[0x1B5];
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(s32 *)(p + 0x1D8) = 0;
    D_004C2794->t[p[2]]++;
    func_001757E0(p, 10, p[0x168]);
}
