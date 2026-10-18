typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { s32 w0; s8 b4; s8 b5; s16 h6; s16 h8; s16 hA; s16 hC; s16 hE; } G_s;
extern G_s *D_004C2840;
extern s8 D_004C27C0[2];
extern s8 D_004C27C4[2];

void func_001277A0(void)
{
    extern void func_001E6D80(s32, s32);
    extern void func_001237A0(void);
    extern void func_0016F0D0(void);
    extern void func_0016D190(void);
    s16 v = D_004C2840->h8 - 1;
    D_004C2840->h8 = v;
    if (v == 0) {
        D_004C2840->b4 = D_004C2840->b4 + 1;
    }
    if (D_004C2840->h8 == 0x168) D_004C2840->hE = 1;
    if (D_004C2840->h8 == 0x14A) D_004C2840->hE = 2;
    if (D_004C2840->hE == 2) {
        D_004C2840->hC++;
        if (D_004C2840->hC >= 8) {
            D_004C2840->hC = 0;
            D_004C2840->hA++;
            if (D_004C2840->hA >= 8) D_004C2840->hA = 0;
            D_004C2840->b5 = D_004C2840->b5 - 1;
            if (D_004C2840->b5 == -2) D_004C2840->hE = 3;
            D_004C27C4[0] = 1;
            D_004C27C0[0] = 0xB;
            func_001E6D80(D_004C2840->b5, 7 - D_004C2840->hA);
        }
    }
    func_001237A0();
    func_0016F0D0();
    func_0016D190();
}
