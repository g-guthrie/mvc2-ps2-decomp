typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s32 D_004C28AC;
extern s32 D_004C28B8;
extern s32 D_004C280C;
extern s32 D_004C26A8;
extern s32 D_004C26A0;
extern s32 D_004C2694;
extern s32 D_004C2690;
extern s32 D_004C2698;
extern s32 D_004C26A4;
extern s32 D_004C269C;
extern u8 *D_004C2794;
extern s32 func_0018AB60(u8 *);
extern void func_003266E0(u8 *);
extern void func_00125A80(s32);
extern void func_00125C20(s32);
extern u8 *D_004C25D4;
extern u8 *D_004C25D0;
extern void (*D_004C1828[2])(u8 *);

s32 func_00170DA0(s32 a, s32 b, s32 c, s32 d) {
    D_004C26A8 = a;
    D_004C26A0 = c;
    D_004C2694 = b;
    D_004C2690 = d;
    D_004C2698 = 0;
    D_004C26A8 += 0x18;
    D_004C26A0 += 0x18;
    D_004C26A4 = D_004C26A8;
    D_004C269C = D_004C26A0;
    return 0;
}

void func_001259C0(void) {
    if (D_004C25D4[5] == 1 || D_004C25D0[5] == 2) {
        func_00125A80(0x10);
    } else {
        func_00125C20(0x10);
    }
}

void func_00325AF0(u8 *p) {
    if (func_0018AB60(p)) {
        func_003266E0(p);
    } else {
        D_004C1828[p[6]](p);
    }
}
