typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct G_003D2CF0 {
    u8 b0, b1, b2, b3, b4, b5, b6, b7;
    s16 h8, hA, hC, hE;
    u8 pad10[4];
    s32 w14;
    u8 pad18[0x2C - 0x18];
    u8 b2C;
    u8 pad2D[0x4C - 0x2D];
    s8 b4C;
} G_003D2CF0;
extern G_003D2CF0 * volatile D_004C2840;
void func_003D2CF0(void) {
    extern void func_003DA410(void);
    extern void func_0016CDA0(void);
    extern void func_0016D160(void);
    extern void func_00329890(void);
    extern void func_00122840(s32);
    D_004C2840->w14 = 0x40;
    D_004C2840->b0 = 1;
    D_004C2840->b1 = 0;
    D_004C2840->b2 = 0;
    D_004C2840->b3 = 0;
    D_004C2840->b4 = 0;
    D_004C2840->b5 = 0;
    D_004C2840->b6 = 0;
    D_004C2840->b7 = 0;
    D_004C2840->h8 = 0;
    D_004C2840->hA = 0;
    D_004C2840->hC = 0;
    D_004C2840->hE = 0;
    {
        G_003D2CF0 *g = D_004C2840;
        if (g->b4C == 7) {
            g->b2C = 2;
        }
    }
    func_003DA410();
    func_0016CDA0();
    func_0016D160();
    func_00329890();
    func_00122840(0);
}
