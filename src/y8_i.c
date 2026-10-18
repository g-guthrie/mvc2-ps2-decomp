typedef float f32;
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
extern u8 *D_004C2840;
extern f32 D_004F1FD0;
extern f32 D_004643BC[];
extern void (*D_00455458[])(u8 *);
extern void (*D_00463DB0[])(u8 *, u8 *, u8 *);

typedef struct { u8 pad[0x7C]; s16 f7c[4]; } G_93B80;
extern G_93B80 *D_004C2794;
extern u8 D_004BFD0C[4], D_004BFCF4[4];
void func_00201F30(u8 *p) {
    extern void func_001E3710();
    extern void func_001757E0();
    u32 t;
    s8 c;
    p[0x2C7] = 0;
    t = p[6];
    p[6] = t + 1;
    p[0x210] = 0;
    p[0x168] = 4;
    p[0x1B5] = 0x17;
    *(u32 *)(p + 0x68) = 0;
    *(f32 *)(p + 0x60) /= 2.0f;
    *(u32 *)(p + 0x6C) = 0xBECDB6DB;
    func_001E3710(p, 0x16, 0x17, 4);
    if (p[0x210] == 0) {
        *(u8 **)(p + 0x408) = D_004BFCF4;
    } else {
        *(u8 **)(p + 0x408) = D_004BFD0C;
    }
    p[0x1BB] = 2;
    t = p[0x1B5];
    p[0x1B5] = t;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(s32 *)(p + 0x1D8) = 0;
    D_004C2794->f7c[p[2]]++;
    func_001757E0(p, 0xC, p[0x168]);
    c = *(s8 *)(p + 0x1EA);
    if ((c & 0xF0) != 0) *(s8 *)(p + 0x1EA) = c - 0x10;
}
