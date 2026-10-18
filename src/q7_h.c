typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;


typedef struct { u8 pad[0x7C]; s16 h7c[1]; } G1;
extern G1 *D_004C2794;
extern u8 D_004C0318[4];
extern u8 D_004C031C[4];
extern u8 D_004C0320[4];

void func_00243FA0(u8 *p) {
    extern void func_001E3710();
    extern void func_001757E0();
    switch (p[0x1FC]) {
    case 0:
        p[0x168] = 0;
        p[0x1B5] = 0;
        *(u8 **)(p + 0x408) = D_004C0318;
        p[0x1BB] = 0;
        func_001E3710(p, 0x14);
        break;
    case 1:
        p[0x168] = 1;
        p[0x1B5] = 1;
        *(u8 **)(p + 0x408) = D_004C031C;
        p[0x1BB] = 1;
        func_001E3710(p, 0x15);
        break;
    case 2:
        p[0x168] = 2;
        p[0x1B5] = 2;
        *(u8 **)(p + 0x408) = D_004C0320;
        p[0x1BB] = 2;
        break;
    }
    p[0x1B5] = *(volatile u8 *)(p + 0x1B5);
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    D_004C2794->h7c[p[2]]++;
    func_001757E0(p, 7, p[0x168]);
}

extern u8 data_s8_004C0B50[4];
extern u8 D_004C0B54[4];
extern u8 D_004C0B58[4];

void func_002A14E0(u8 *p) {
    extern void func_001E3710();
    extern void func_001757E0();
    switch (p[0x1FC]) {
    case 0:
        p[0x168] = 3;
        p[0x1B5] = 0x12;
        func_001E3710(p, 0x14);
        *(u8 **)(p + 0x408) = data_s8_004C0B50;
        p[0x1BB] = 0;
        break;
    case 1:
        p[0x168] = 4;
        p[0x1B5] = 0x13;
        func_001E3710(p, 0x15);
        *(u8 **)(p + 0x408) = D_004C0B54;
        p[0x1BB] = 1;
        break;
    case 2:
        { u32 t = p[6]; p[6] = t + 1; }
        p[0x168] = 5;
        p[0x1B5] = 0x14;
        func_001E3710(p, 0x15);
        *(u8 **)(p + 0x408) = D_004C0B58;
        p[0x1BB] = 2;
        break;
    }
    p[0x1B5] = *(volatile u8 *)(p + 0x1B5);
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    D_004C2794->h7c[p[2]]++;
    func_001757E0(p, 7, p[0x168]);
}
