typedef unsigned char u8;
typedef signed short s16;
typedef signed int s32;
typedef float f32;

extern signed char *D_004C2840;
extern void *D_004C2814;

extern void func_00123090(void);
extern void func_001230C0(void);
extern void func_0012AC70(s32, void *);
extern void func_00143920(void);
extern void func_00143A60(void);
extern void func_00148FD0(void);
extern s32 func_003299D0(void);
extern void func_003D7350(s32, s32, s32, void *);
extern void func_00149690(void *);
extern void func_00151A20(s32);
extern void func_001520E0(s32);
extern void func_00152550(u8 *, s32);
extern void func_00153670(void);
extern void func_00157BF0(u8 *);
extern void func_00157970(u8 *);
extern void func_00157E60(u8 *);
extern void func_001580D0(u8 *);
extern void func_00158EE0(u8 *);
extern void func_001591A0(u8 *);
extern void func_00159460(u8 *);
extern void func_00159720(u8 *);
extern void func_001599F0(u8 *);
extern void func_00159B00(u8 *, u8 *);
extern void func_00159C30(u8 *, u8 *);
extern void func_00159D80(u8 *, u8 *);
extern void func_0015BB60(void);
extern void func_0015BFB0(void);
extern void func_0015C130(void);
extern void func_0015C280(void);
extern void func_0015C3F0(void);
extern void func_0015C560(void);
extern void func_003DAA40(u8 *);
extern u8 *func_003DA750(s32, s32, s32);
extern void func_003ED1C0(s32, s32);

extern char D_00148ED0[];
extern char D_0014A530[];
extern char D_00151710[];
extern char D_004B3450[];
extern char D_004F7D10[];
extern char D_004F7D20[];

void func_0015C5C0(void) {
    func_0015BB60();
    func_0015BFB0();
    func_0015C280();
    func_0015C130();
    func_0015C560();
    func_0015C3F0();
}

void func_00159A40(u8 *p) {
    func_00158EE0(p);
    func_001591A0(p);
    func_00159460(p);
    func_00159720(p);
    func_001599F0(p);
}

void func_00159E50(u8 *p, u8 *q) {
    func_00159B00(p, q);
    func_00159C30(p, q);
    func_00159D80(p, q);
}

void func_00158170(u8 *p) {
    func_001580D0(p + 52);
    func_00157E60(p + 52);
    func_00157BF0(p + 52);
    func_00157970(p + 52);
    func_003DAA40(p);
}

void func_001527C0(void) {
    func_001230C0();
    func_00151A20(6);
    func_001520E0(6);
}

void func_00152660(void) {
    func_00123090();
    func_003ED1C0(0, 0);
    func_00151A20(18);
    func_001520E0(18);
}

void func_00143C60(void) {
    if (D_004C2840[2] == 0) {
        func_00143920();
    }
    func_00143A60();
}

void func_0015EE10(u8 *p) {
    func_00152550(p, 0);
    p[316] = 0;
    p[4] += 1;
}

void func_00148E90(void) {
    func_00148FD0();
    if (func_003299D0() == 0) {
        func_0012AC70(1, D_00148ED0);
    }
}

void func_00148FD0(void) {
    func_003D7350(60, 30, 51, D_004B3450);
    func_00149690(D_004F7D10);
    func_00149690(D_004F7D20);
}

void func_001422E0(u8 *p, s32 a1) {
    s32 t;
    p[35] = (u8)(a1 + 55);
    t = a1 + 13;
    *(s16 *)(p + 204) = p[35];
    *(void **)(p + 132) = D_004C2814;
    p[32] = 0;
    *(s32 *)(p + 116) = 0;
    *(s32 *)(p + 208) = 0;
    p[49] = (u8)t;
    *(s32 *)(p + 64) = 0;
    *(s32 *)(p + 72) = 0;
}

void func_0014C080(u8 *p) {
    u8 *q = *(u8 **)(p + 24);
    if (q) {
        *(f32 *)(p + 52) = *(f32 *)(q + 52) + *(f32 *)(p + 92);
        *(f32 *)(p + 56) = *(f32 *)(q + 56) + *(f32 *)(p + 96);
        *(f32 *)(p + 60) = *(f32 *)(q + 60) + *(f32 *)(p + 100);
    }
}

void func_00151270(u8 *p) {
    if (p[33] == 3) {
        *(s32 *)(p + 208) |= 8;
        *(s32 *)(p + 72) = 0xAAB;
    }
}

void func_001536C0(void) {
    func_00123090();
    func_00151A20(13);
    func_001520E0(13);
    if (*(s32 *)((u8 *)D_004C2840 + 20) != 64) {
        func_00153670();
    }
}

void func_0014A4E0(void) {
    u8 *p = func_003DA750(0, 13, 1);
    if (p) {
        p[316] = 1;
        *(char **)(p + 16) = D_0014A530;
        p[32] = 0x8A;
    }
}

void func_00151780(void) {
    u8 *p = func_003DA750(0, 13, 1);
    if (p) {
        p[316] = 1;
        *(char **)(p + 16) = D_00151710;
        *(s32 *)(p + 208) = 1;
    }
}
