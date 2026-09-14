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

/* ---- func_00122860 ---- */

/* ---- func_00123760 ---- */

/* ---- func_00126000 ---- */

/* ---- func_00126040 ---- */

/* ---- func_00127970 ---- */

/* ---- func_00129060 ---- */

/* ---- func_00129110 ---- */
typedef struct S129110 {
    u16 f0;
    u8 pad[18];
} S129110;

/* ---- func_0012AC70 ---- */

/* ---- func_0012F6F0 ---- */

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
typedef struct S14C0E0 {
    char pad[4];
    u8 f4, f5, f6;
    char pad2[9];
    void *f16;
    char pad3[32];
    float f52;
} S14C0E0;

/* ---- func_0014C390 ---- */
typedef struct InnerP390 {
    char pad[6];
    u8 f6;
} InnerP390;

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

/* ---- func_0016CE60 ---- */

/* ---- func_0016CED0 ---- */

/* ---- func_0016CEF0 ---- */

/* ---- func_0016CF10 ---- */

/* ---- func_0016CF80 ---- */

/* ---- func_0016CFB0 ---- */

/* ---- func_0016CFE0 ---- */

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
