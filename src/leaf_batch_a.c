typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef signed char s8;
typedef signed int s32;
typedef unsigned int u32;
typedef long long s64;

/* ---- func_00102C58 ---- */

/* ---- func_001037B8 ---- */

/* ---- func_00104598 ---- */

/* ---- func_00105020 ---- */
typedef struct SG105020 {
    void *f0;
    s32 f4;
    void *f8;
    void *f12;
    u8 data[1];
} SG105020;


/* ---- func_00105EE0 ---- */

/* ---- func_00105F10 / func_00105F28 ---- */

/* ---- func_00106210 / func_00106228 ---- */
typedef struct T4C3AD8 {
    char pad[12];
    s32 f12;
    s32 f16;
    s32 f20;
    s32 f24;
} T4C3AD8;


/* ---- func_00106898 ---- */
typedef struct T898 {
    char pad[16];
    s32 f16;
    char pad2[4];
    s32 f24;
} T898;

/* ---- func_0010FF88 ---- */


/* ---- func_00122840 ---- */
extern s32 D_004F1CF4;
extern s32 D_004F1CF0;
void func_00122840(s32 a0) {
    D_004F1CF4 = a0;
    D_004F1CF0 = 0;
}

/* ---- func_00122860 ---- */
extern s32 D_004F1CF8;
void func_00122860(s32 a0, s32 a1) {
    D_004F1CF4 = a0;
    D_004F1CF8 = a1;
    D_004F1CF0 = 2;
}

/* ---- func_00123760 ---- */
extern u8 D_004F1F48;
extern u8 D_004F1F49;
extern u8 D_004F1F47;
extern u8 D_004F2034;
extern u8 D_004F2035;
extern u8 D_004F2036;
extern u8 D_004F2037;
void func_00123760(u8 a0) {
    D_004F1F48 = a0;
    D_004F1F49 = 0;
    D_004F1F47 = 1;
    D_004F2034 = 0;
    D_004F2035 = 0;
    D_004F2036 = 0;
    D_004F2037 = 0;
}

/* ---- func_00126000 ---- */
extern s32 D_004F1FEC;
extern s32 D_004F1FF8;
extern s32 D_004C9F50;
extern s32 D_004C9F40;
extern s32 D_004F1F4C;
extern s32 D_004F1F94;
void func_00126000(void) {
    D_004F1FEC = 0;
    D_004F1FF8 = 0;
    D_004C9F50 = 0;
    D_004C9F40 = 0;
    D_004F1F4C = 0;
    D_004F1F94 = 0;
}

/* ---- func_00126040 ---- */
extern s32 D_004F1FF0;
extern s32 D_004F1FFC;
extern s32 D_004C9F54;
extern s32 D_004C9F44;
extern s32 D_004F1F50;
extern s32 D_004F1F98;
void func_00126040(void) {
    D_004F1FF0 = 0x42BE0000;
    D_004F1FFC = 0x42BE0000;
    D_004C9F54 = 0x42BE0000;
    D_004C9F44 = 0x42BE0000;
    D_004F1F50 = 0x42BE0000;
    D_004F1F98 = 0x42BE0000;
}

/* ---- func_00127970 ---- */
extern u8 D_004AD070[];
u8 func_00127970(u8 a0) {
    return D_004AD070[a0];
}

/* ---- func_00129060 ---- */
extern s32 D_0043CC90[];
void func_00129060(s32 a0, s32 a1) {
    D_0043CC90[a0] = a1;
}

/* ---- func_00129110 ---- */
typedef struct S129110 {
    u16 f0;
    u8 pad[18];
} S129110;
extern S129110 D_004F4484[];
s32 func_00129110(u16 a0) {
    return (D_004F4484[a0].f0 & 64) != 0;
}

/* ---- func_0012AC70 ---- */
extern s32 D_0043CC70[];
void func_0012AC70(s32 a0, s32 a1) {
    D_0043CC70[a0] = a1;
}

/* ---- func_0012F6F0 ---- */
extern s8 D_0043DD00[];
s32 func_0012F6F0(s32 a0) {
    return D_0043DD00[a0];
}

/* ---- func_00132F70 ---- */
typedef struct GameState {
    char pad[20];
    struct GameState *f20;
    char pad2[92];
    float f116, f120, f124, f128;
    char pad3[184];
    s8 f316;
} GameState;

/* ---- func_00137F90 ---- */

/* ---- func_0013A2A0 ---- */
extern u8 D_00583B90[];
void func_0013A2A0(u8 *a0) {
    a0[4]++;
    D_00583B90[a0[32]] = 2;
}

/* ---- func_0013BCE0 ---- */
typedef struct Inner1BCE0 {
    char pad[1245];
    s8 f1245;
} Inner1BCE0;
typedef struct Outer1BCE0 {
    char pad[20];
    Inner1BCE0 *f20;
    char pad2[9];
    u8 f33;
} Outer1BCE0;

/* ---- func_0014C0E0 ---- */
extern u8 D_0014C0D0;
typedef struct S14C0E0 {
    char pad[4];
    u8 f4, f5, f6;
    char pad2[9];
    void *f16;
    char pad3[32];
    float f52;
} S14C0E0;
void func_0014C0E0(S14C0E0 *a0, float t4) {
    a0->f52 = t4;
    a0->f16 = &D_0014C0D0;
    a0->f4 = 0;
    a0->f5 = 0;
    a0->f6 = 0;
}

/* ---- func_0014C390 ---- */
typedef struct InnerP390 {
    char pad[6];
    u8 f6;
} InnerP390;
extern InnerP390 *D_004CAE80[][20];
s32 func_0014C390(s32 a0, s32 a1) {
    return !D_004CAE80[a0][a1]->f6;
}

/* ---- func_00161370 ---- */
typedef struct Sx316 {
    char pad[316];
    s8 f316;
} Sx316;
typedef struct Outer3 {
    char pad[24];
    Sx316 *f24;
    char pad2[288];
    s8 f316;
} Outer3;
void func_00161370(Outer3 *a0) {
    a0->f316 = a0->f24->f316;
}

/* ---- func_00162610 ---- */
typedef struct Vec2 {
    float x, y;
} Vec2;
typedef struct OuterV {
    char pad[28];
    s16 f28;
    char pad2[194];
    float f224, f228;
} OuterV;

/* ---- func_0016A1F0 ---- */
typedef struct Sbits {
    char pad[1220];
    s32 f1220;
} Sbits;

/* ---- func_0016CA10 ---- */
typedef struct SFloat {
    char pad[260];
    float f260, f264, f268, f272;
    char pad2[4];
    float f280;
} SFloat;
void func_0016CA10(SFloat *a0) {
    a0->f260 = 0.0f;
    a0->f268 = 1.0f;
    a0->f264 = 0.0f;
    a0->f272 = 1.0f;
    a0->f280 = 0.0f;
}

/* ---- func_0016CDF0 ---- */
extern float D_004F1D14, D_004F1D10, D_004F1D0C;
void func_0016CDF0(float t4) {
    D_004F1D14 = t4;
    D_004F1D10 = t4;
    D_004F1D0C = t4;
}

/* ---- func_0016CE60 ---- */
extern s32 D_004F1CB4, D_004F1CB8, D_004F1CBC, D_004F1CB0;
void func_0016CE60(void) {
    D_004F1CB4 = 1;
    D_004F1CB8 = 16;
    D_004F1CBC = 0x00FFFFFF;
}

/* ---- func_0016CED0 ---- */
void func_0016CED0(void) {
    D_004F1CB4 = 0;
    D_004F1CBC = 0;
    D_004F1CB8 = 120;
}

/* ---- func_0016CEF0 ---- */
void func_0016CEF0(void) {
    D_004F1CB4 = 0;
    D_004F1CBC = 0;
    D_004F1CB8 = 30;
}

/* ---- func_0016CF10 ---- */
void func_0016CF10(void) {
    D_004F1CBC = 0;
    D_004F1CB4 = 8;
    D_004F1CB8 = 185;
}

/* ---- func_0016CF80 ---- */

/* ---- func_0016CFB0 ---- */
void func_0016CFB0(void) {
    D_004F1CB8 = D_004F1CB8 - 1;
    D_004F1CB0 = D_004F1CB8 & 1;
}

/* ---- func_0016CFE0 ---- */
void func_0016CFE0(void) {
    D_004F1CB8 = D_004F1CB8 - 1;
    D_004F1CB0 = (D_004F1CB8 >> 1) & 1;
}

/* ---- func_0016D010 ---- */

/* ---- func_0016D040 ---- */

/* ---- func_001734D0 ---- */
typedef struct S1734D0 {
    char pad[1235];
    u8 f1235;
    char pad2[6];
    s16 f1242;
} S1734D0;
void func_001734D0(S1734D0 *a0) {
    a0->f1242 = 40;
    a0->f1235 = 1;
}
