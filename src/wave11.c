typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern u8 D_00443E78[];
extern u16 D_004F7F92;
extern s32 D_004F1CB4;
extern s32 D_004F1CB8;
extern s32 D_004F1CBC;
extern u8 D_004C2840[];
extern void func_0014A700(float, float, float, float, u16, s32, u8 *, s32);

void func_001DEEF0(u8 *p) {
    s16 *q = (s16 *)(p + 0xD8);
    s16 a = q[0];
    if (*(s16 *)(p + 0x140) == 0) a = -a;
    *(float *)(p + 0x34) = (float)(a + q[1]);
}

extern s32 func_0011C458(u8 *);
typedef struct { float a, b, c, d; } V4;
void func_00133140(u8 *p) {
    u8 *q = *(u8 **)(p + 0x14);
    *(V4 *)(p + 0x74) = *(V4 *)(q + 0x74);
    *(float *)(p + 0x50) = (float)*(s16 *)(*(u8 **)(p + 0x18) + 0x438) / 144.0f;
}

extern void func_001757E0(u8 *, s32, s32);
void func_0017C790(u8 *p) {
    *(float *)(p + 0x38) = *(float *)(p + 0x430);
    *(float *)(p + 0x5C) = 16.66666603088378906250f;
    *(float *)(p + 0x68) = 0.0f;
    if (p[0x1E6]) *(float *)(p + 0x5C) = -*(float *)(p + 0x5C);
    *(float *)(p + 0x60) = 17.14285659790039062500f;
    *(float *)(p + 0x6C) = -0.80357140302658081055f;
    p[0x20D] = 2;
    func_001757E0(p, 0x18, 2);
}

void func_001DB0D0(u8 *p) {
    float c;
    p[0x24] = 0xB;
    c = 236.66665649414062500000f;
    if (*(s16 *)(p + 0x140) == 0) c = -c;
    *(float *)(p + 0x34) += c;
    *(float *)(p + 0x38) += 160.71427917480468750000f;
    func_001757E0(p, 0x17, 8);
}

void func_00336360(u8 *p) {
    s16 n = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = n;
    if (n == 0) {
        p[7] = 0;
        p[5] = 0;
    } else {
        s32 d = 0x444;
        if (*(s16 *)(p + 0x1E) != 0) d = -0x444;
        *(s32 *)(p + 0x44) += d;
    }
}

extern void func_0015D370(u8 *);
extern void func_0015D420(u8 *);
extern void func_0015D4C0(u8 *);
extern void func_0015D570(u8 *);
void func_0015D310(u8 *p) {
    s32 i;
    for (i = 0; i < 1; i++) {
        func_0015D370(p);
        func_0015D420(p);
        func_0015D4C0(p);
        func_0015D570(p);
    }
}
void func_00173FF0(u8 *p) {
    u32 v; u32 hi; s32 n;
    p[0x543] = 0;
    v = *(u32 *)(p + 0x54C);
    hi = v & ~0xF;
    n = v & 0xF;
    n++;
    if (n > 9) n = 9;
    *(u32 *)(p + 0x54C) = hi | n;
}
