typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x7C]; s16 f7c[1]; } G95;
extern G95 *D_004C2794;
extern s32 D_004C1128[1];
extern s32 D_004C112C[1];
extern s32 D_004C1130[1];

void func_002E95E0(u8 *p) {
    extern void func_001E3710(u8 *, s32);
    extern void func_001757E0(u8 *, s32, s32);
    u8 *q;
    s32 t;
    q = p + 0x2B8;
    switch (p[0x1FC]) {
    case 0:
        p[0x168] = 0;
        p[0x1B5] = 6;
        *(s32 **)(p + 0x408) = D_004C1128;
        p[0x1BB] = 0;
        func_001E3710(p, 0x14);
        t = *(u8 *)(p + 0x1B5);
        p[0x1B5] = t;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(s32 *)(p + 0x1D8) = 0;
        D_004C2794->f7c[p[2]]++;
        func_001757E0(p, 9, p[0x168]);
        break;
    case 1:
        p[0x168] = 1;
        p[0x1B5] = 7;
        *(s32 **)(p + 0x408) = D_004C112C;
        p[0x1BB] = 1;
        func_001E3710(p, 0x15);
        t = *(u8 *)(p + 0x1B5);
        p[0x1B5] = t;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(s32 *)(p + 0x1D8) = 0;
        D_004C2794->f7c[p[2]]++;
        func_001757E0(p, 9, p[0x168]);
        break;
    case 2:
        p[0x168] = 2;
        p[0x1B5] = 8;
        *(s32 **)(p + 0x408) = D_004C1130;
        p[0x1BB] = 2;
        p[0x1B5] = 0x35;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(s32 *)(p + 0x1D8) = 0;
        D_004C2794->f7c[p[2]]++;
        func_001757E0(p, 9, p[0x168]);
        p[7] = 0;
        *q = 0;
        *(s16 *)(p + 0x1E) = *(s8 *)(p + 0x151);
        p[0x151] = 0;
        break;
    }
}
