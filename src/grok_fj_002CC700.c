typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct { u8 pad[0x7C]; s16 f7c[2]; } G;
extern G *D_004C2794;
extern s8 D_004C0EC4[4];
extern s8 D_004C0EC8[4];
extern s8 D_004C0ECC[4];

void func_002CC700(u8 *p) {
    extern void func_001E3710();
    extern void func_001757E0(u8 *, s32, s32);
    p[0x169] = 8;
    switch (p[0x1FC]) {
    case 0:
        p[0x168] = 0;
        p[0x1B5] = 3;
        func_001E3710(p, 0x14);
        *(s8 **)(p + 0x408) = D_004C0EC4;
        p[0x1BB] = 0;
        break;
    case 1:
        p[0x168] = 1;
        p[0x1B5] = 4;
        func_001E3710(p, 0x15);
        *(s8 **)(p + 0x408) = D_004C0EC8;
        p[0x1BB] = 1;
        break;
    case 2:
        p[0x168] = 2;
        p[0x1B5] = 5;
        p[6] = 0;
        if (*(u16 *)(p + 0x20E) & 0x800) {
            p[6] = 1;
            p[0x169] = 0x14;
            p[0x168] = 0;
            p[0x1B5] = 0x12;
        }
        func_001E3710(p, 0x16);
        *(s8 **)(p + 0x408) = D_004C0ECC;
        p[0x1BB] = 2;
        break;
    }
    p[0x1B5] = *(u8 *)(p + 0x1B5);
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(s32 *)(p + 0x1D8) = 0;
    D_004C2794->f7c[p[2]]++;
    func_001757E0(p, p[0x169], p[0x168]);
}
