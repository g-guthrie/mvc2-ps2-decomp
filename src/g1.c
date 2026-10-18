typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern s32 func_00175700();
extern void func_001C0A00();
extern void func_001843A0();
extern void func_00296FB0();
extern void func_0013BE20();
extern void func_003DAA40();
extern void func_0027BB50();

void func_001C7440(u8 *p, u8 *q) {
    func_00175700(p, q);
    if (*(s8 *)(p + 0x151)) {
        u32 t = p[7];
        p[7] = t + 1;
        *(s16 *)(q + 0x1C) = 0;
        func_001C0A00(p, p, 7);
    }
}

extern u8 D_00583BC6;
void func_0013BDC0(u8 *p) {
    if (D_00583BC6 == 0) {
        u32 a1 = p[4];
        switch (a1) {
        case 0: func_0013BE20(p); break;
        case 2: func_003DAA40(p); break;
        }
    }
}

void func_0027BAC0(u8 *p) {
    *(float *)(p + 0x118) += (0.75f - *(float *)(p + 0x118)) / (float)*(s16 *)(p + 0x1C);
    {
        s16 v = *(s16 *)(p + 0x1C) - 1;
        *(s16 *)(p + 0x1C) = v;
        if (v <= 0) { u32 t = p[7]; p[7] = t + 1; }
    }
    func_0027BB50(p);
}
