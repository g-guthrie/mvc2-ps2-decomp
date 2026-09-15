typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef float f32;

#define F(p, o) (*(f32 *)((u8 *)(p) + (o)))
#define I(p, o) (*(s32 *)((u8 *)(p) + (o)))
#define S(p, o) (*(s16 *)((u8 *)(p) + (o)))

extern int func_00175700(u8 *);
extern int func_00175670(u8 *);
extern void func_001757E0(u8 *, int, int);
extern void func_00175C00(u8 *, int);
extern void func_001843A0(u8 *);
extern int func_001864A0(u8 *);
extern void func_001E3210(u8 *, int);
extern void func_001AC3F0(u8 *, u8 *);
extern void func_00183D90(u8 *);
extern void func_003888B0(u8 *, int);

void func_0023B9C0(u8 *p) {
    F(p, 52) += F(p, 92);
    F(p, 92) += F(p, 104);
    F(p, 56) += F(p, 96);
    F(p, 96) += F(p, 108);
    if (*(s8 *)(p + 337) != 0) I(p, 92) = 0;
    I(p, 104) = 0;
    if ((s8)func_00175700(p) < 0) func_001843A0(p);
}
void func_0023C2A0(u8 *p) {
    F(p, 52) += F(p, 92);
    F(p, 92) += F(p, 104);
    F(p, 56) += F(p, 96);
    F(p, 96) += F(p, 108);
    if (*(s8 *)(p + 337) != 0) I(p, 92) = 0;
    I(p, 104) = 0;
    if ((s8)func_00175700(p) < 0) func_001843A0(p);
}

void func_001EDAF0(u8 *p) {
    func_00175700(p);
    F(p, 52) += F(p, 92);
    F(p, 92) += F(p, 104);
    F(p, 56) += F(p, 96);
    F(p, 96) += F(p, 108);
    if (func_001864A0(p)) {
        p[6]++;
        func_001757E0(p, 20, 9);
    }
}
void func_0029AF90(u8 *p) {
    func_00175700(p);
    F(p, 52) += F(p, 92);
    F(p, 92) += F(p, 104);
    F(p, 56) += F(p, 96);
    F(p, 96) += F(p, 108);
    if (func_001864A0(p)) {
        p[6]++;
        func_001757E0(p, 20, 9);
    }
}

void func_002AADB0(u8 *p) {
    if (p[6] == 0) {
        p[6]++;
        p[525] = 0;
        F(p, 56) = F(p, 1072);
        func_001757E0(p, 20, 2);
    } else if ((s8)func_00175700(p) < 0) {
        func_00175C00(p, 0);
        I(p, 92) = 0;
        I(p, 96) = 0;
        I(p, 104) = 0;
        I(p, 108) = 0;
        func_001843A0(p);
    }
}
void func_002BDD90(u8 *p) {
    if (p[6] == 0) {
        p[6]++;
        p[525] = 0;
        F(p, 56) = F(p, 1072);
        func_001757E0(p, 20, 2);
    } else if ((s8)func_00175700(p) < 0) {
        func_00175C00(p, 0);
        I(p, 92) = 0;
        I(p, 96) = 0;
        I(p, 104) = 0;
        I(p, 108) = 0;
        func_001843A0(p);
    }
}

void func_00247710(u8 *p) {
    F(p, 56) += F(p, 96);
    F(p, 96) += F(p, 108);
    if ((s8)func_00175700(p) < 0) {
        I(p, 96) = 0;
        I(p, 108) = 0;
        func_001843A0(p);
    }
}
void func_003038D0(u8 *p) {
    F(p, 56) += F(p, 96);
    F(p, 96) += F(p, 108);
    if ((s8)func_00175700(p) < 0) {
        I(p, 96) = 0;
        I(p, 108) = 0;
        func_001843A0(p);
    }
}

void func_0028A940(u8 *p, u8 *q) {
    if (--S(p, 28) == 0) {
        q[24]++;
        I(p, 96) = 0x41892492;
        I(p, 108) = 0xBF4DB6DB;
        func_003888B0(p, 8);
        func_003888B0(p, 9);
        func_003888B0(p, 10);
    }
}
void func_00291CB0(u8 *p, u8 *q) {
    if (--S(p, 28) == 0) {
        q[24]++;
        I(p, 96) = 0x41892492;
        I(p, 108) = 0xBF4DB6DB;
        func_003888B0(p, 8);
        func_003888B0(p, 9);
        func_003888B0(p, 10);
    }
}

void func_001D9450(u8 *p, u8 *q) {
    F(p, 52) = F(q, 52);
    F(p, 56) = F(q, 56);
    F(p, 52) += F(p, 92);
    F(p, 56) += F(p, 96);
    if ((s8)func_00175670(p) < 0) {
        p[316] = 0;
        p[4]++;
    }
}
void func_001D9680(u8 *p, u8 *q) {
    F(p, 52) = F(q, 52);
    F(p, 56) = F(q, 56);
    F(p, 52) += F(p, 92);
    F(p, 56) += F(p, 96);
    if ((s8)func_00175670(p) < 0) {
        p[316] = 0;
        p[4]++;
    }
}

void func_002EAEB0(u8 *p) {
    p[6]++;
    p[316] = 1;
    p[697] = 0;
    F(p, 56) += 480.0f;
    I(p, 96) = 0xC1092492;
    func_001757E0(p, 18, 0);
    func_001E3210(p, 34);
}
void func_00302530(u8 *p) {
    p[6]++;
    p[316] = 1;
    p[697] = 0;
    F(p, 56) += 480.0f;
    I(p, 96) = 0xC1092492;
    func_001757E0(p, 18, 0);
    func_001E3210(p, 34);
}

void func_001D5A90(u8 *p) {
    F(p, 56) += F(p, 96);
    F(p, 96) += F(p, 108);
    func_00175700(p);
    if (--S(p, 28) == 0) p[4]++;
}
void func_001DA1A0(u8 *p) {
    F(p, 56) += F(p, 96);
    F(p, 96) += F(p, 108);
    func_00175700(p);
    if (--S(p, 28) == 0) p[4]++;
}

void func_0024FCA0(u8 *p) {
    if ((s8)p[337] == 0) func_00175700(p);
    if (--S(p, 28) == 0) p[6]++;
}
void func_00250050(u8 *p) {
    if ((s8)p[337] == 0) func_00175700(p);
    if (--S(p, 28) == 0) p[6]++;
}

void func_001A9FE0(u8 *p, u8 *q) {
    func_00175700(p);
    if (--S(p, 30) == 0) func_001AC3F0(p, q);
}
void func_001ABC40(u8 *p, u8 *q) {
    func_00175700(p);
    if (--S(p, 30) == 0) func_001AC3F0(p, q);
}

void func_00310EE0(u8 *p) {
    func_00183D90(p);
    if ((s8)func_00175700(p) < 0) {
        I(p, 92) = 0;
        I(p, 96) = 0;
        I(p, 104) = 0;
        I(p, 108) = 0;
        func_001843A0(p);
    }
}
void func_00311250(u8 *p) {
    func_00183D90(p);
    if ((s8)func_00175700(p) < 0) {
        I(p, 92) = 0;
        I(p, 96) = 0;
        I(p, 104) = 0;
        I(p, 108) = 0;
        func_001843A0(p);
    }
}
