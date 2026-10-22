typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x7C]; s16 f7c[1]; } G36a;
extern G36a *D_004C2794;
extern u8 D_004C0354[4];
extern u8 D_004C033C[4];
extern u8 D_004C0358[4];
extern u8 D_004C0340[4];
extern u8 D_004C035C[4];
extern u8 D_004C0344[4];

void func_002445A0(u8 *p) {
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_001E3710(u8 *, s32);
    switch (p[0x1FC]) {
    case 0:
        func_001757E0(p, 0xC, 0);
        p[0x1B5] = 0xF;
        func_001E3710(p, 0x14);
        if (p[0x210] == 0) *(u8 **)(p + 0x408) = D_004C033C;
        else *(u8 **)(p + 0x408) = D_004C0354;
        p[0x1BB] = 0;
        break;
    case 1:
        func_001757E0(p, 0xC, 1);
        p[0x1B5] = 0x10;
        func_001E3710(p, 0x15);
        if (p[0x210] == 0) *(u8 **)(p + 0x408) = D_004C0340;
        else *(u8 **)(p + 0x408) = D_004C0358;
        p[0x1BB] = 1;
        break;
    case 2:
        if (p[0x210] == 0) *(u8 **)(p + 0x408) = D_004C0344;
        else *(u8 **)(p + 0x408) = D_004C035C;
        p[0x1BB] = 2;
        p[0x215] = 0;
        p[0x210] = 0;
        p[0x1EA] = p[0x1EA] & 0xF;
        if ((*(u16 *)(p + 0x20E) & 0x1000) != 0 &&
            (*(f32 *)(p + 0x430) + 137.1428528f < *(f32 *)(p + 0x38))) {
            func_001757E0(p, 0xC, 2);
            p[0x1B5] = 0x11;
            *(s32 *)(p + 0x5C) = 0;
            *(s32 *)(p + 0x60) = 0;
            *(s32 *)(p + 0x68) = 0;
            *(s32 *)(p + 0x6C) = 0;
            p[6] = 2;
            p[7] = 0;
        } else {
            func_001757E0(p, 0x14, 3);
            p[0x1B5] = 0x12;
            *(s32 *)(p + 0x5C) = 0;
            *(s32 *)(p + 0x60) = 0;
            *(s32 *)(p + 0x68) = 0;
            *(s32 *)(p + 0x6C) = 0;
            p[6] = 1;
            p[7] = 0;
        }
        break;
    }
    {
        u32 t = p[0x1B5];
        p[0x1B5] = t;
    }
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(s32 *)(p + 0x1D8) = 0;
    D_004C2794->f7c[p[2]]++;
    {
        s32 q = *(s8 *)(p + 0x1EA);
        if ((q & 0xF0) != 0) p[0x1EA] = q - 0x10;
    }
}
