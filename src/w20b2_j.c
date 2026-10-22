typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

/* Metrowerks: ./try.sh src/w20b2_j.c "-O3 -Op -sdatathreshold 8" */
typedef struct { u8 pad0[0x7C]; s16 h7c[1]; } G_j;
extern G_j *D_004C2794;
extern s32 data_s8_004C174C;
extern s32 D_004C1750;
extern s32 D_004C1754;
typedef struct {
    u8 pad0[0x2];
    u8 b2;
    u8 pad3[0x3];
    u8 b6;
    u8 pad7[0x31];
    f32 f38;
    u8 pad3C[0x20];
    f32 f5c;
    f32 f60;
    u8 pad64[0x4];
    f32 f68;
    f32 f6c;
    u8 pad70[0x142];
    u8 b1b2;
    u8 pad1B3[0x2];
    u8 b1b5;
    u8 pad1B6[0x5];
    u8 b1bb;
    u8 pad1BC[0x4];
    u16 h1c0;
    u8 pad1C2[0x16];
    s32 w1d8;
    u8 pad1DC[0xE];
    s8 b1ea;
    u8 pad1EB[0x11];
    u8 b1fc;
    u8 pad1FD[0x11];
    u16 h20e;
    u8 b210;
    u8 pad211[0x1F7];
    s32 w408;
    u8 pad40D[0x23];
    f32 f430;
} P_j;

void func_0031C020(P_j *p, s32 x, s32 y) {
    extern void func_001E3710(P_j *, u8);
    extern void func_001757E0(P_j *, s32, u8);
    s32 z;
    s8 v;
    switch (p->b1fc) {
    case 0:
        x = 0xF;
        z = 0;
        p->w408 = (s32)&data_s8_004C174C;
        y = 0x14;
        p->b1bb = 0;
        break;
    case 1:
        x = 0x10;
        z = 1;
        p->w408 = (s32)&D_004C1750;
        y = 0x15;
        p->b1bb = 1;
        break;
    case 2:
        if ((p->h20e & 0x1000) != 0 && !(p->f38 - p->f430 <= 240.0f)) {
            p->b6 = 1;
            x = 0x13;
            z = 5;
            v = p->b1ea;
            p->b1ea = v & 0xF;
            y = 0x16;
            p->b210 = 0;
            p->w408 = (s32)&D_004C1754;
            *(u32 *)&p->f5c = 0;
            *(u32 *)&p->f60 = 0;
            *(u32 *)&p->f68 = 0;
            *(u32 *)&p->f6c = 0;
        } else {
            p->b6 = 0;
            z = 2;
            p->w408 = (s32)&D_004C1754;
            x = 0x11;
            y = 0x16;
            p->b1bb = z;
        }
        break;
    }
    p->b1b5 = x;
    p->b1b2 = p->h1c0 = 0;
    p->w1d8 = 0;
    D_004C2794->h7c[p->b2] += 1;
    func_001E3710(p, y);
    func_001757E0(p, 0xC, z);
    v = p->b1ea;
    if ((v & 0xF0) != 0) p->b1ea = v - 0x10;
}
