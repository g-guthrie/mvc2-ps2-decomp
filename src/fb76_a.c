typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct {
    u8 pad0[4];
    s8 b4;
    u8 b5;
    u8 pad6[2];
    s16 h8;
    s16 hA;
    s16 hC;
    s16 hE;
    u8 pad10[4];
    s32 w14;
    u8 pad18[0x12];
    s8 b2A;
    u8 pad2B[0x74];
    s8 b9F;
    u8 pad9F[0x11];
    s8 bB1;
} GA;

extern GA *D_004C2840;
extern u8 D_0043CBE8[];
extern u32 D_004F1F4C[];
extern u8 D_004F1F40[];
extern u8 D_004F1F48[];
extern u32 D_004F1FAC[];
extern u32 D_004F1F9C[];
extern u32 D_004F1F50[];
extern u32 D_004F1F54[];
extern u32 D_004F1F94[];
extern u32 D_004F1F98[];
extern u32 D_004F1FC4[];
extern u32 D_004F1FC0[];
extern s16 D_004F7F7C[];
extern s8 D_004D18DE[];
extern s8 D_004D18A6[];
extern u8 D_004F2601[];
extern u8 D_004F2602[];
extern u8 D_004F1D20[];
extern u32 D_004F1D24[];
extern u32 D_004F1D2C[];
extern u8 D_004F1D29[];
extern u8 D_004F1D2A[];
extern u8 D_004F1D2B[];
extern u8 D_004C27C4[2];
extern u8 D_004C27C0[2];

void func_00126D10(void)
{
    extern void func_003DA410();
    extern void func_0016F040();
    extern void func_0016F090(void *);
    extern void func_0016F0C0(f32);
    extern void func_0016CDA0();
    extern void func_003D6D50();
    extern void func_003D6E20();
    extern void func_00170160(int);
    extern void func_00122DA0();
    extern void func_003D6AC0();
    extern void func_0013EAD0(s32);
    extern void func_0013F100(s32);
    extern void func_0013F400(s32, s32);
    extern void func_0013F880(s32, s32);
    extern void func_00122840(s32);
    extern void func_0016D160();
    extern void func_0016D190();
    extern void func_001E6D80(s32, s32);
    extern void func_0012E780(s32);
    s32 v;
    s32 t;
    s8 k;

    D_004C2840->b4 = D_004C2840->b4 + 1;
    D_004C2840->b5 = 0x14;
    D_004C2840->h8 = 0x21C;
    D_004C2840->hA = 7;
    D_004C2840->hC = 0;
    D_004C2840->hE = 0;
    func_003DA410();
    func_0016F040();
    func_0016F090(D_0043CBE8);
    func_0016F0C0(1.0f);
    func_0016CDA0();
    func_003D6D50();
    func_003D6E20();
    func_00170160(0xA);
    func_00122DA0();
    D_004F1F4C[0] = 0;
    D_004F1F40[0] = 1;
    D_004F1F48[0] = 3;
    D_004F1FAC[0] = 0x42B40000;
    D_004F1F9C[0] = 0xBF800000;
    D_004F1F50[0] = 0;
    D_004F1F54[0] = 0;
    D_004F1F94[0] = 0;
    D_004F1F98[0] = 0;
    D_004F1FC4[0] = 0;
    D_004F1FC0[0] = 0;
    if (D_004C2840->b9F != D_004F7F7C[0] - 1) {
        func_003D6AC0();
    }
    func_0013EAD0(0);
    func_0013EAD0(2);
    func_0013F100(0);
    func_0013F100(1);
    func_0013F100(2);
    if (D_004C2840->w14 == 0x60 && D_004C2840->b2A != 0) {
        k = D_004D18DE[0] + 1;
        func_0013F400(k + 5, k + 10);
    } else {
        switch (D_004C2840->bB1) {
        case 0:
            func_0013F400(0, 0);
            func_0013F400(1, 1);
            func_0013F400(2, 2);
            func_0013F400(4, 4);
            func_0013F400(3, 3);
            v = D_004F2601[D_004C2840->b9F * 0x5B8];
            break;
        case 1:
            func_0013F400(0, 5);
            func_0013F400(1, 6);
            func_0013F400(2, 7);
            func_0013F400(3, 8);
            v = D_004F2602[D_004C2840->b9F * 0x5B8];
            break;
        case 2:
            func_0013F400(0, 0);
            func_0013F400(1, 1);
            func_0013F400(2, 2);
            func_0013F400(4, 4);
            func_0013F400(3, 3);
            v = D_004F2601[D_004C2840->b9F * 0x5B8];
            break;
        }
        if (v < 0x14) {
            if (v == 0) {
                func_0013F880(3, 0);
            } else {
                func_0013F880(0, v % 5);
            }
            func_0013F880(1, v % 5);
        } else {
            func_0013F880(2, 0);
        }
    }
    D_004D18A6[0] = 0;
    func_00122840(-1);
    func_0016D160();
    D_004F1D20[0] = 1;
    D_004F1D24[0] = 0x80;
    D_004F1D2C[0] = 0x460CA000;
    D_004F1D29[0] = 0xFF;
    D_004F1D2A[0] = 0xFF;
    D_004F1D2B[0] = 0xFF;
    func_0016D190();
    D_004C27C4[0] = 1;
    D_004C27C0[0] = 0xB;
    func_001E6D80(-1, 0);
    func_001E6D80(-1, 1);
    func_001E6D80(-1, 2);
    func_001E6D80(-1, 3);
    func_001E6D80(-1, 4);
    func_001E6D80(-1, 5);
    func_001E6D80(-1, 6);
    func_001E6D80(-1, 7);
    func_0012E780(8);
}
