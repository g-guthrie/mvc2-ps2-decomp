typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

extern s32 func_00119AB8(void);
extern void func_0010D090(u8 *);
extern void func_00138350(u8 *, s32);
extern void func_00139380(u8 *);
extern s32 func_001315F0(void);
extern void func_00129870(void);
extern void func_003DAA40(u8 *);
extern s32 *func_0013AEA0(void);
extern void func_00122DA0(void);
extern u8 D_004D18A0;
extern u8 D_0013B010[];
extern s8 D_004F1F47;

s32 func_00100240(void) { return func_00119AB8() < 0; }
s32 func_00100290(void) { return func_00119AB8() > 0; }
s32 func_00100260(void) { return func_00119AB8() <= 0; }
s32 func_001002B0(void) { return func_00119AB8() >= 0; }

s32 func_0013BCE0(u8 *p) {
    return p[0x21] == *(s8 *)(*(u8 **)(p + 0x14) + 0x4DD);
}

void func_00134120(u8 *p) {
    if (D_004D18A0) {
        p[5] = 0;
        p[0x20] = 0;
        p[0x21] = 0;
    }
}

s32 func_001045B8(s32 a, u8 *p) {
    if (a == 1) func_0010D090(p);
    return 0;
}

void residual_001391D0(u8 *p) {
    p[4]++;
    func_00139380(p);
}

void residual_00138920(u8 *p) {
    p[4]++;
    func_00138350(p, 1);
}

void func_0012A2F0(void) {
    if (func_001315F0()) func_00129870();
}

void func_001331A0(u8 *p) {
    u8 *q = *(u8 **)(p + 0x18);
    *(s8 *)(p + 0x13C) = *(s8 *)(q + 0x13C);
    if (*(s16 *)(q + 0x1C) == 0) {
        *(s8 *)(p + 0x13C) = 0;
        func_003DAA40(p);
    }
}

void func_0013AF60(void) {
    s32 *p = func_0013AEA0();
    if (p) *(u8 **)(p + 4) = D_0013B010;
}

void func_001230F0(void) {
    func_00122DA0();
    D_004F1F47++;
}
