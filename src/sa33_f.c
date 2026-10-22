typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef unsigned long long u64;
typedef struct G3FE0 { u8 pad0[0x14]; s32 i14; u8 pad18[0x15]; s8 b2D; u8 pad2E[0x15]; s8 b43; } G3FE0;
extern G3FE0 *D_004C2840;
extern s32 D_004BFAE4;
extern s32 D_004C2B50;
extern u8 D_004C272A;
extern u8 D_004C2726;
extern s32 func_003CE510(s32, s32);
extern void func_004026B0(s32, s32);
extern s32 func_001E1FF0(s32);
extern void func_004020D8(s32, s16);

void func_001E3FE0(void)
{
    double k;
    if (D_004C2840->b43 == 0 && D_004C2840->i14 == 0x40) return;
    if (func_003CE510(3, 6) != 0) return;
    if (D_004C2840->b2D != 0) return;
    if (D_004BFAE4 < 0) return;
    if (D_004C2B50 == 0) return;
    func_004026B0(D_004C2B50, 0);
    if (D_004BFAE4 >= 0 && D_004BFAE4 < 11) {
        k = 0.8;
        D_004C2726 = (u32)(k *= (double)(u32)D_004C272A);
    } else {
        D_004C2726 = D_004C272A;
    }
    func_004020D8(D_004C2B50, (s16)func_001E1FF0(D_004C2726));
    D_004BFAE4 = -1;
}
