typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef signed int s32;

extern u8 D_004C26B0;
extern u8 D_004C26AC;
extern s8 *D_004C2794;
extern s8 D_004C2798;
extern s8 D_004C2799;
extern s8 D_004C279C;
extern s8 D_004C279D;
extern u8 *D_004C2840;
extern s32 D_004C2928;
extern u8 *D_004C2978;
extern s32 D_004C2A4C;
extern s32 D_004C2A50;
extern s32 D_004C2A54;
extern s32 D_004C2A58;
extern s32 D_004C2A5C;

void func_00174150(void) { D_004C26B0 = 1; D_004C26AC = 195; }

s32 func_001841C0(u8 *p) { return D_004C2794[p[2] + 52]; }

void func_001E7F20(void) {
    D_004C279D = 0;
    D_004C2799 = 0;
    D_004C279C = 0;
    D_004C2798 = 0;
}

void func_0032A8E0(void) { D_004C2840[3] = 3; D_004C2840[4] = 0; D_004C2840[175] = 0; }

void func_0032BED0(s8 *p) { D_004C2928 |= p[1244]; }

void func_0032BFD0(void) { ((s8 *)D_004C2840)[4]++; *(s16 *)(D_004C2840 + 8) = 20; }

void func_00367F60(u8 *p) { p[4] = 3; p[316] = 0; D_004C2978[2] = 0; }

void func_003D6B30(void) {
    *(s32 *)(D_004C2840 + 20) = 64;
    D_004C2840[0] = 1;
    D_004C2840[1] = 0;
    D_004C2840[2] = 0;
}

void func_003D72F0(void) { D_004C2A4C++; }

void func_003D7300(void) { D_004C2A5C = 0; D_004C2A58 = 0; D_004C2A4C = 0; }

void func_003D7630(void) { D_004C2A50 = 0; D_004C2A54 = 0; }
