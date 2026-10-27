typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct GG {
    u8 pad0[0x7C];
    s16 f7c[1];
} GG;

typedef struct O {
    u8 pad0[2];
    u8 b2;
    u8 pad3[0x34 - 3];
    f32 f34;
    u8 pad38[0x168 - 0x38];
    u8 b168;
    u8 pad169[0x1B2 - 0x169];
    u8 b1B2;
    u8 pad1B3[2];
    u8 b1B5;
    u8 pad1B6[5];
    u8 b1BB;
    u8 pad1BC[4];
    u16 s1C0;
    u8 pad1C2[0x1D8 - 0x1C2];
    s32 w1D8;
    u8 pad1DC[0x1E6 - 0x1DC];
    u8 b1E6;
    u8 pad1E7[0x1FC - 0x1E7];
    u8 b1FC;
    u8 pad1FD[0x408 - 0x1FD];
    s32 *w408;
} O;

extern s32 D_004C08A4, D_004C08A8, D_004C08AC;
extern GG *D_004C2794;

void func_00281C80(O *p) {
    extern void func_001757E0(O *, s32, s32);
    extern void func_001E3710(O *, s32);
    extern u8 *func_00383B80(void *, u8, u8);
    u32 t;
    f32 k;
    switch (p->b1FC) {
    case 0:
        p->b168 = 0;
        p->b1B5 = 3;
        func_001E3710(p, 0x14);
        p->w408 = &D_004C08A4;
        p->b1BB = 0;
        break;
    case 1:
        p->b168 = 1;
        p->b1B5 = 4;
        func_001E3710(p, 0x15);
        p->w408 = &D_004C08A8;
        p->b1BB = 1;
        break;
    case 2:
        if (p->b1E6 != 0) {
            k = 26.66666603088379f;
        } else {
            k = -26.66666603088379f;
        }
        p->f34 += k;
        p->b168 = 2;
        p->b1B5 = 5;
        func_001E3710(p, 0x16);
        p->w408 = &D_004C08AC;
        p->b1BB = 2;
        func_00383B80(p, 4, 0);
        break;
    }
    t = p->b1B5;
    p->b1B5 = t;
    p->b1B2 = p->s1C0 = 0;
    p->w1D8 = 0;
    D_004C2794->f7c[p->b2]++;
    func_001757E0(p, 8, p->b168);
}
