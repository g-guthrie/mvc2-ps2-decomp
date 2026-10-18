typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef signed long s64;
typedef float f32;

extern volatile s32 D_004C22C4;
extern volatile s32 D_004C238C;
extern s32 (* D_004C2390)(s32);
extern s32 D_004C22CC;
extern volatile s32 D_004C22DC;
extern volatile s32 D_004C2328;
extern volatile s32 D_004C22E0;
extern volatile s32 D_004C2324;
extern volatile s64 D_004C2318;

extern void func_003FE0D0(s32);
extern s32 func_003FE4F0(void);
extern void func_00411A18(void);

s32 func_003FE9E8(s32 a)
{
    s32 v;
    D_004C22C4++;
    if (D_004C238C == 0) {
        D_004C238C = 1;
        if (D_004C22CC > 0) {
            if (D_004C22DC != 1) {
                func_003FE0D0(D_004C2328);
            }
            v = func_003FE4F0();
            if (v == 1 && D_004C22E0 != v) {
                func_003FE0D0(D_004C2324);
            }
            D_004C2318++;
        }
        func_00411A18();
        D_004C238C = 0;
    }
    if (D_004C2390 != 0) {
        return D_004C2390(a);
    }
    return 0;
}
