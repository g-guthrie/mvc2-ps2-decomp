typedef unsigned char u8;
typedef signed int s32;
extern s32 D_004C253C;
extern volatile u8 D_00630000[0x4380];
#define STATE_VALUE (*(volatile s32 *)(D_00630000 + 0x40c0))
extern s32 func_00103E00(s32 state);
extern s32 func_00103E20(s32 state);
extern s32 func_00103E30(s32 state);
s32 func_00423930(s32 enabled)
{
    s32 result;
    s32 saved;

    if (enabled != 0) {
        result = func_00103E30(D_004C253C);
        if (result < 0)
            return -1;
    } else {
        func_00103E20(D_004C253C);
    }
    saved = STATE_VALUE;
    func_00103E00(D_004C253C);
    return saved;
}
