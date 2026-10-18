typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct GG {
    u8 pad0[0x7C];
    s16 f7c[2];
    s16 f80[1];
} GG;

typedef struct O {
    u8 pad0[2];
    u8 b2;
    u8 pad3[0x30 - 3];
    s8 b30;
    u8 pad31[3];
    f32 f34;
    f32 f38;
    f32 f3C;
    u8 pad40[0xFC - 0x40];
    u32 wFC;
    u32 w100;
    u8 pad104[0x118 - 0x104];
    u32 w118;
    u8 pad11C[0x13D - 0x11C];
    s8 b13D;
    s16 h13E;
    u8 pad140[0x1B8 - 0x140];
    u8 b1B8;
    u8 pad1B9[0x1F0 - 0x1B9];
    u8 b1F0;
    u8 pad1F1[4];
    u8 b1F5;
    u8 pad1F6;
    u8 b1F7;
    u8 pad1F8[0x226 - 0x1F8];
    u8 b226;
    u8 pad227[0x425 - 0x227];
    u8 b425;
    u8 pad426[2];
    u32 w428;
    u8 pad42C[4];
    f32 f430;
    s16 h434;
    u8 pad436[2];
    s16 h438;
    u8 pad43A[0x540 - 0x43A];
    s8 b540;
} O;

extern s8 D_004ACD08[];
extern s8 D_004ACD90[];
extern u8 D_004D18E5[];
extern f32 D_004ACD30[];
extern f32 D_004ACD34[];
extern f32 D_004ACD38[];
extern GG *D_004C2794;

void func_001804F0(O *p) {
    p->b13D = -1;
    p->h13E = D_004ACD08[p->b1B8];
    p->b30 = D_004ACD90[p->b540];
    if (D_004D18E5[0] == 0) {
        p->f34 = D_004ACD30[p->b2 * 3];
        p->f38 = D_004ACD34[p->b2 * 3];
        p->f3C = D_004ACD38[p->b2 * 3];
        p->f430 = p->f38;
    }
    p->wFC = 0x3FD55555;
    p->w100 = 0x40092492;
    p->w118 = 0x3F800000;
    p->h434 = 0x90;
    p->h438 = 0x90;
    p->b1F0 = 0;
    if (p->b425 != 0 && (p->w428 & 0x7000000) != 0) {
        p->h434 = 0;
        p->h438 = 0;
    }
    D_004C2794->f7c[p->b2] = 0;
    D_004C2794->f80[p->b2] = 0;
    p->b1F5 = 0x50;
    p->b1F7 = 0;
    p->b226 = 0;
}
