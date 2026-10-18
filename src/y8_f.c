typedef float f32;
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
extern f32 D_004F1FD0;
extern f32 D_004643BC[];
extern void (*D_00455458[])(u8 *);
extern void (*D_00463DB0[])(u8 *, u8 *, u8 *);

typedef struct { u8 pad[0x7C]; s16 f7c[4]; } G_93B80;
extern G_93B80 *D_004C2794;
extern u8 D_00456EE0[];
void func_00293B80(u8 *p) {
    extern s8 func_00175700();
    extern void func_00294B20();
    extern void func_003D7770();
    extern void func_001E3710();
    extern void func_001757E0();
    u8 *q = p + 0x2B8;
    u32 t;
    p[0x40C] = 2;
    p[0x33C] = 5;
    if (func_00175700(p) < 0) {
        t = p[6] + 1;
        p[6] = t;
        *(s16 *)(p + 0x1E) = 0x12;
        p[7] = 0;
        q[0xC] = 0;
        *(s16 *)(p + 0x1C) = 0x3C;
        func_00294B20(p, D_00456EE0, t);
        p[0x1B5] = 0x44;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(s32 *)(p + 0x1D8) = 0;
        D_004C2794->f7c[p[2]]++;
        func_003D7770(p);
        func_001E3710(p, 0x48);
        func_001757E0(p, 0x16, 3);
    }
}

extern u8 D_004C0208[4], D_004C020C[4], D_004C0210[4];
void func_0023A760(u8 *p) {
    extern void func_001E3710();
    extern void func_001757E0();
    u32 t;
    switch (p[0x1FC]) {
    case 0:
        p[0x168] = 0;
        p[0x1B5] = 6;
        *(u8 **)(p + 0x408) = D_004C0208;
        p[0x1BB] = 0;
        func_001E3710(p, 0x14);
        break;
    case 1:
        p[0x168] = 1;
        p[0x1B5] = 7;
        *(u8 **)(p + 0x408) = D_004C020C;
        p[0x1BB] = 1;
        break;
    case 2:
        p[0x168] = 2;
        p[0x1B5] = 8;
        *(u8 **)(p + 0x408) = D_004C0210;
        p[0x1BB] = 2;
        break;
    }
    t = p[0x1B5];
    p[0x1B5] = t;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(s32 *)(p + 0x1D8) = 0;
    D_004C2794->f7c[p[2]]++;
    func_001757E0(p, 9, p[0x168]);
}
