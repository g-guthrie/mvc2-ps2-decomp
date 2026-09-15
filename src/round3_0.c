typedef unsigned char u8;
typedef signed char s8;
typedef short s16;
typedef int s32;
typedef float f32;

#define F(p, o) (*(f32 *)((u8 *)(p) + (o)))
#define I(p, o) (*(s32 *)((u8 *)(p) + (o)))
#define S(p, o) (*(s16 *)((u8 *)(p) + (o)))

extern s8 func_00175700(u8 *);
extern void func_001843A0(u8 *);
extern void func_00184540(u8 *);
extern void func_001757E0(u8 *, int, int);
extern void func_00183D50(u8 *);
extern int func_001864A0(u8 *);
extern void func_001865B0(u8 *);
extern void func_001C3A80(u8 *, u8 *);
extern void func_001E7F60(u8 *);
extern void func_00255620(u8 *);
extern void func_0034FA60(u8 *);
extern void func_003888B0(u8 *, int);

#define PHYS \
    F(p, 52) += F(p, 92); \
    F(p, 92) += F(p, 104); \
    F(p, 56) += F(p, 96); \
    F(p, 96) += F(p, 108);

int func_001AC360(s16 a, s16 b) { return (a & (1 << b)) != 0; }
int func_001C39F0(s16 a, s16 b) { return (a & (1 << b)) != 0; }

void func_001C2BD0(u8 *p, u8 *q) {
    func_00175700(p);
    F(p, 52) += F(p, 92);
    F(p, 92) += F(p, 104);
    if (--S(p, 30) == 0) func_001C3A80(p, q);
}
void func_001C2D30(u8 *p, u8 *q) {
    func_00175700(p);
    F(p, 52) += F(p, 92);
    F(p, 92) += F(p, 104);
    if (--S(p, 30) == 0) func_001C3A80(p, q);
}

void func_0029CEE0(u8 *p) {
    PHYS
    func_00175700(p);
    if (--S(p, 28) < 0) func_001843A0(p);
}
void func_0029D150(u8 *p) {
    PHYS
    func_00175700(p);
    if (--S(p, 28) < 0) func_001843A0(p);
}

void func_002F36B0(u8 *p) {
    PHYS
    func_00175700(p);
    if (--S(p, 28) <= 0) p[6]++;
}
void func_00317CA0(u8 *p) {
    PHYS
    func_00175700(p);
    if (--S(p, 28) <= 0) p[6]++;
}

void func_00192190(u8 *p) {
    F(p, 52) += F(p, 92);
    F(p, 92) += F(p, 104);
    if ((s8)func_00175700(p) < 0) func_00184540(p);
}
void func_001922E0(u8 *p) {
    F(p, 52) += F(p, 92);
    F(p, 92) += F(p, 104);
    if ((s8)func_00175700(p) < 0) func_00184540(p);
}

void func_0020A0B0(u8 *p) {
    PHYS
    if ((s8)func_00175700(p) < 0) {
        p[6]++;
        p[361] = 2;
        p[360] = 3;
        func_001757E0(p, p[361], p[360]);
    }
}
void func_0023B920(u8 *p) {
    PHYS
    if ((s8)func_00175700(p) < 0) {
        p[6]++;
        p[361] = 2;
        p[360] = 3;
        func_001757E0(p, p[361], p[360]);
    }
}

void func_0023C650(u8 *p) {
    func_00175700(p);
    PHYS
    if (--S(p, 28) == 0) {
        p[7]++;
        p[361] = 21;
        p[360] = 10;
        func_001757E0(p, p[361], p[360]);
    }
}
void func_0023D140(u8 *p) {
    func_00175700(p);
    PHYS
    if (--S(p, 28) == 0) {
        p[7]++;
        p[361] = 21;
        p[360] = 10;
        func_001757E0(p, p[361], p[360]);
    }
}

void func_0027A990(u8 *p) {
    func_00175700(p);
    PHYS
    if (func_001864A0(p)) {
        p[6]++;
        func_001757E0(p, 20, 1);
    }
}
void func_0027CE50(u8 *p) {
    func_00175700(p);
    PHYS
    if (func_001864A0(p)) {
        p[6]++;
        func_001757E0(p, 20, 1);
    }
}

void func_001F0820(u8 *p) {
    if (func_001864A0(p)) {
        func_001865B0(p);
        return;
    }
    PHYS
    func_00175700(p);
}
void func_001F0C10(u8 *p) {
    if (func_001864A0(p)) {
        func_001865B0(p);
        return;
    }
    PHYS
    func_00175700(p);
}

void func_001F1530(u8 *p) {
    p[510] = 1;
    p[513] = 2;
    p[521] = 2;
    PHYS
    if (func_001864A0(p)) {
        func_00183D50(p);
        p[7]++;
        func_001757E0(p, 15, 34);
    }
}
void func_001F1D20(u8 *p) {
    p[510] = 1;
    p[513] = 2;
    p[521] = 2;
    PHYS
    if (func_001864A0(p)) {
        func_00183D50(p);
        p[7]++;
        func_001757E0(p, 15, 34);
    }
}

void func_0038D850(u8 *p) {
    func_00175700(p);
    if ((s8)p[337] == 0) {
        p[5]++;
        PHYS
    }
    func_001E7F60(p);
}
void func_0041A6A0(u8 *p) {
    func_00175700(p);
    if ((s8)p[337] == 0) {
        p[5]++;
        PHYS
    }
    func_001E7F60(p);
}

void func_001F3850(u8 *p) {
    if ((s8)func_00175700(p) < 0) {
        p[7]++;
        I(p, 92) = 0;
        I(p, 104) = 0;
        I(p, 96) = 0xC0CDB6DB;
        I(p, 108) = 0xBF9A4924;
        func_001757E0(p, 15, 45);
    }
}
void func_001F5140(u8 *p) {
    if ((s8)func_00175700(p) < 0) {
        p[7]++;
        I(p, 92) = 0;
        I(p, 104) = 0;
        I(p, 96) = 0xC0CDB6DB;
        I(p, 108) = 0xBF9A4924;
        func_001757E0(p, 15, 45);
    }
}

void func_003498D0(u8 *p) {
    u8 *q = *(u8 **)(p + 20);
    if (q[32] == 0) F(p, 52) = F(q, 52) + F(p, 92);
    else F(p, 52) = F(q, 52) + F(p, 104);
    F(p, 56) = F(q, 56);
    if ((s8)func_00175700(p) < 0) {
        p[4]++;
        p[316] = 0;
    }
}
void func_00349AA0(u8 *p) {
    u8 *q = *(u8 **)(p + 20);
    if (q[32] == 0) F(p, 52) = F(q, 52) + F(p, 92);
    else F(p, 52) = F(q, 52) + F(p, 104);
    F(p, 56) = F(q, 56);
    if ((s8)func_00175700(p) < 0) {
        p[4]++;
        p[316] = 0;
    }
}

