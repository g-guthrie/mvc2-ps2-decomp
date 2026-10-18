typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x2B8]; u8 b[4]; } S2B8;
typedef struct { u8 pad[0x7C]; s16 h7c[1]; } G2794;
extern G2794 *D_004C2794;
extern u8 D_004C0E24[2], D_004C0E28[2], D_004C0E2C[2];

void func_002C60A0(u8 *p) {
    extern void func_001E3710();
    extern void func_001757E0(u8 *, s32, s32);
    u8 *s0;
    u32 v;
    s0 = ((S2B8 *)p)->b;
    switch (p[0x1FC]) {
    case 0:
        p[0x168] = 0;
        p[0x1B5] = 3;
        func_001E3710(p, 0x14);
        *(u32 *)(p + 0x408) = (u32)D_004C0E24;
        p[0x1BB] = 0;
        break;
    case 1:
        p[0x168] = 1;
        p[0x1B5] = 4;
        func_001E3710(p, 0x15);
        *(u32 *)(p + 0x408) = (u32)D_004C0E28;
        p[0x1BB] = 1;
        break;
    case 2:
        p[0x168] = 2;
        p[0x1B5] = 5;
        func_001E3710(p, 0x16);
        *(u32 *)(p + 0x408) = (u32)D_004C0E2C;
        p[0x1BB] = 2;
        s0[2] = 0;
        break;
    }
    v = p[0x1B5];
    p[0x1B5] = v;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    D_004C2794->h7c[p[2]]++;
    func_001757E0(p, 8, p[0x168]);
}
