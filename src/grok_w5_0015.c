typedef unsigned char u8;
typedef signed short s16;
typedef signed int s32;

extern void func_00122FE0(void);
extern void func_00123090(void);
extern void func_00151A20(s32);
extern void func_001520E0(s32);
extern void func_00153350(s32);
extern void func_003ED1C0(s32, s32);
extern void func_00159F50(u8 *, u8 *);
extern void func_0015A0D0(u8 *, u8 *);
extern void func_0015A290(u8 *, u8 *);
extern void func_0015A400(u8 *, u8 *);
extern void func_0015D100(u8 *, s32);
extern u8 *func_003DA750(s32, s32, s32);

extern char D_001516A0[];
extern char D_00151630[];
extern char D_0015F780[];

void func_00153310(void) {
    func_00122FE0();
    func_00151A20(6);
    func_001520E0(6);
    func_00153350(0x5B);
}

void func_001527F0(void) {
    func_00122FE0();
    func_00151A20(6);
    func_001520E0(6);
    func_003ED1C0(0, 0);
    func_00123090();
    func_00151A20(13);
    func_001520E0(13);
}

void func_0015A4A0(u8 *p, u8 *q) {
    func_00159F50(p, q);
    func_0015A0D0(p, q);
    func_0015A290(p, q);
    func_0015A400(p, q);
}

void func_0015D090(u8 *p) {
    s32 i = 0;
    s32 j;
    do {
        j = 0;
        do {
            func_0015D100(p, j);
            j++;
        } while (j < 3);
        i++;
    } while (i < 5);
}

void func_00151720(u8 *p) {
    *(s16 *)(p + 28) = (s16)(*(s16 *)(p + 28) + 1);
    if (*(signed char *)(p + 316) != 0) {
        if (*(s16 *)(p + 28) == 60) {
            p[316] = 0;
            *(s16 *)(p + 28) = 0;
        }
    } else if (*(s16 *)(p + 28) == 30) {
        p[316] = 1;
        *(s16 *)(p + 28) = 0;
    }
}

void func_00151650(u8 *a0) {
    u8 *p = func_003DA750(0, 13, 1);
    if (p) {
        p[316] = 0;
        *(char **)(p + 16) = D_001516A0;
        p[32] = (u8)(s32)a0;
    }
}

void func_0015F840(u8 *a0) {
    u8 *p = func_003DA750(0, 8, 1);
    if (p) {
        *(char **)(p + 16) = D_0015F780;
        *(u8 **)(p + 24) = a0;
        *(s16 *)(p + 28) = 8;
        *(s16 *)(p + 30) = 120;
    }
}

void func_001515D0(s32 a0, void *a1) {
    u8 *p = func_003DA750(0, 13, 1);
    if (p) {
        p[316] = 1;
        *(char **)(p + 16) = D_00151630;
        *(s16 *)(p + 204) = (s16)a0;
        *(void **)(p + 132) = a1;
    }
}

s32 func_0015BA00(u8 *a0, u8 *a1) {
    s16 v = *(s16 *)(a1 + 320);
    s32 ret;
    if (v != a0[7]) {
        a0[5] = (u8)v;
        ret = 1;
        a0[7] = (u8) *(signed char *)(a1 + 320);
    } else {
        a0[7] = (u8)v;
        ret = 0;
    }
    return ret;
}
