typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

extern u8 *D_004C2840;
extern u8 D_004C2AF8;
extern u8 D_004C2AF9;
extern u8 D_004C2AFA;
extern u8 D_004C2AFB;
extern u8 D_004C2AFC;
extern s32 D_004C23AC;
extern s32 D_004C23A8;
extern s32 D_004C2410;
extern s32 D_004C2B3C;
extern s32 D_004C2B48;
extern s32 D_004C2B38;
extern s32 D_004C2B44;

s32 func_00131980(void) { return *(s32 *)(D_004C2840 + 268); }

void func_00131960(s32 v) {
    *(s32 *)(D_004C2840 + 268) = v;
    *(s16 *)(D_004C2840 + 276) = 1;
}

void func_003ED2E0(u8 v) {
    D_004C2AF8 = v;
    D_004C2AF9 = v;
    D_004C2AFA = v;
    D_004C2AFB = v;
    D_004C2AFC = v;
}

s32 func_004000E0(s32 v) { D_004C23AC = v; return D_004C23A8 = 40 - v; }

s32 func_004044D0(void) { return D_004C2410 = 1; }

s32 func_00416AC0(s32 a, s32 b) {
    D_004C2B3C = b;
    D_004C2B48 = a;
    D_004C2B38 = 0;
    D_004C2B44 = 0;
    return a;
}
