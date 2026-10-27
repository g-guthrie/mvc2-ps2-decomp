typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef signed int s32;
typedef unsigned int u32;

typedef struct GG { u8 pad0[0x7C]; s16 f7c[2]; } GG;
typedef struct O {
    u8 pad0[2]; u8 b2; u8 pad3[3]; u8 b6; u8 pad7[0x168 - 7]; u8 b168;
    u8 pad169[0x1B2 - 0x169]; u8 b1B2; u8 pad1B3[2]; u8 b1B5;
    u8 pad1B6[5]; u8 b1BB; u8 pad1BC[4]; u16 s1C0;
    u8 pad1C2[0x1D8 - 0x1C2]; s32 w1D8;
    u8 pad1DC[0x1FC - 0x1DC]; u8 b1FC;
    u8 pad1FD[0x20E - 0x1FD]; u16 s20E;
    u8 pad210[0x408 - 0x210]; s32 *w408;
} O;
extern s32 D_004C0898, D_004C089C, D_004C08A0;
extern GG *D_004C2794;
extern void func_001E3710(u8 *, s32);
extern s32 func_001757E0(u8 *, s32, s32);
extern u8 *func_00383B80(void *, u8, u8);

void func_00281A20(O *p)
{
    u32 t;
    switch (p->b1FC) {
    case 0:
        p->b168 = 0;
        p->b1B5 = 0;
        func_001E3710((u8 *)p, 20);
        p->w408 = &D_004C0898;
        p->b1BB = 0;
        break;
    case 1:
        p->b168 = 1;
        p->b1B5 = 1;
        func_001E3710((u8 *)p, 21);
        p->w408 = &D_004C089C;
        p->b1BB = 1;
        break;
    case 2:
        p->w408 = &D_004C08A0;
        p->b1BB = 2;
        if (p->s20E & 0x800) {
            p->b6 = 1;
            p->b1B5 = 0x57;
            p->b1B2 = p->s1C0 = 0;
            p->w1D8 = 0;
            D_004C2794->f7c[p->b2]++;
            func_001757E0((u8 *)p, 21, 21);
            func_00383B80((u8 *)p, 5, 0);
            return;
        }
        p->b168 = 2;
        p->b1B5 = 2;
        func_001E3710((u8 *)p, 22);
        break;
    }
    t = p->b1B5;
    p->b1B5 = t;
    p->b1B2 = p->s1C0 = 0;
    p->w1D8 = 0;
    D_004C2794->f7c[p->b2]++;
    func_001757E0((u8 *)p, 7, p->b168);
}
