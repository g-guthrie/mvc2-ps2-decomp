/* ./try.sh src/grok_gh_00310220.c "-O4,p -sdatathreshold 8" */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef signed int s32;
typedef unsigned int u32;
typedef signed char s8;
typedef float f32;

typedef struct G { u8 pad[0x7C]; s16 t[2]; } G;
extern G *D_004C2794;
extern u32 D_004C1680;
extern void func_001E3710(u8 *, s32);
extern void func_001757E0(u8 *, s32, s32);

void func_00310220(u8 *p)
{
    switch (p[0x1FC]) {
    case 0:
        p[0x168] = 0;
        p[0x1B5] = 3;
        func_001E3710(p, 0x14);
        *(u32 *)(p + 0x408) = (u32)(&D_004C1680 + 1);
        p[0x1BB] = 0;
        break;
    case 1:
        p[0x168] = 1;
        p[0x1B5] = 4;
        *(u32 *)(p + 0x408) = (u32)(&D_004C1680 + 2);
        p[0x1BB] = 1;
        p[6] = 0;
        break;
    case 2:
        p[0x168] = 2;
        p[0x1B5] = 5;
        *(u32 *)(p + 0x408) = (u32)(&D_004C1680 + 3);
        p[0x1BB] = 2;
        func_001E3710(p, 0x16);
        *(u32 *)(p + 0x5C) = 0xC0C80000;
        *(u32 *)(p + 0x68) = 0x3DD55555;
        *(u32 *)(p + 0x60) = 0x41A2DB6D;
        *(u32 *)(p + 0x6C) = 0xBF84DB6D;
        if (*(s16 *)(p + 0x140)) {
            *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
            *(f32 *)(p + 0x68) = -*(f32 *)(p + 0x68);
        }
        p[6] = 0;
        break;
    }
    p[0x1B5] = (s8)p[0x1B5];
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(s32 *)(p + 0x1D8) = 0;
    D_004C2794->t[p[2]]++;
    func_001757E0(p, 8, p[0x168]);
}
