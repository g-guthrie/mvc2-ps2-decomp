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

void func_002F85F0(u8 *p) {
    PHYS
    func_00175700(p);
    if (--S(p, 28) == 0) func_001843A0(p);
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

void func_0023B8D0(u8 *p) {
    f32 f;
    I(p, 92) = 0;
    I(p, 96) = 0;
    I(p, 104) = 0;
    I(p, 108) = 0;
    p[6]++;
    if (p[486] != 0) f = -12.5f;
    else f = 12.5f;
    *(f32 *)(p + 92) = f;
    func_0023B920(p);
}

void func_0023BA80(u8 *p) {
    p[6]++;
    p[316] = 1;
    *(f32 *)(p + 56) += 480.0f;
    I(p, 92) = 0;
    I(p, 104) = 0;
    I(p, 96) = 0xC1092492;
    I(p, 108) = 0xBF092492;
    p[361] = 18;
    p[360] = 0;
    func_001757E0(p, p[361], p[360]);
}

void func_002FD9A0(u8 *p) {
    p[6]++;
    p[316] = 1;
    *(f32 *)(p + 56) += 480.0f;
    I(p, 92) = 0;
    I(p, 104) = 0;
    I(p, 96) = 0xC1092492;
    I(p, 108) = 0xBF092492;
    func_001757E0(p, 18, 0);
}

extern void func_00185490(u8 *);
extern void func_002CE990(u8 *);
void func_002CE920(u8 *p) {
    p[6]++;
    func_00185490(p);
    p[525] = 0;
    *(f32 *)(p + 56) = *(f32 *)(p + 1072);
    I(p, 92) = 0;
    I(p, 96) = 0;
    I(p, 104) = 0;
    I(p, 108) = 0;
    func_001757E0(p, 2, 0);
    func_002CE990(p);
}

extern void func_00288520(u8 *);
void func_002884D0(u8 *p) {
    p[7]++;
    *(s16 *)(p + 28) = 1;
    *(s16 *)(p + 30) = 0;
    func_001757E0(p, 0, 0);
    func_00288520(p);
}

extern void func_00175C00(u8 *, int);
extern void func_00183D10(u8 *);
void func_002E6E60(u8 *p) {
    p[6]++;
    func_00175C00(p, 0);
    func_00185490(p);
    func_00183D10(p);
    func_001757E0(p, 22, 0);
}

extern void func_001C57B0(u8 *, int);
void func_0028FE50(u8 *p) {
    p[7]++;
    *(s16 *)(p + 28) = 64;
    func_001C57B0(p, 13);
    func_001757E0(p, 0, 0);
}

extern void func_00290180(u8 *);
void func_00290120(u8 *p) {
    p[7]++;
    *(s16 *)(p + 28) = 1;
    func_00175C00(p, 0);
    func_001C57B0(p, 6);
    func_001757E0(p, 0, 0);
    func_00290180(p);
}

void func_002A6400(u8 *p) {
    func_00175700(p);
    if (*(s8 *)(p + 337)) {
        p[6]++;
        p[337] = 0;
        if ((p[34] & 1) == 0) {
            p[486] ^= 1;
            *(s16 *)(p + 320) = p[486];
        }
    }
}

extern void func_001E3210(u8 *, int);
extern void func_002F0C50(u8 *);
void func_002F0BE0(u8 *p) {
    p[6]++;
    p[525] = 0;
    *(f32 *)(p + 56) = *(f32 *)(p + 1072);
    *(s16 *)(p + 28) = 32;
    func_001757E0(p, 21, 40);
    func_001E3210(p, 21);
    func_00183D10(p);
    func_002F0C50(p);
}

extern void func_0018C4B0(u8 *, int);
void func_002E6950(u8 *p) {
    p[6]++;
    *(f32 *)(p + 56) = *(f32 *)(p + 1072);
    p[525] = 0;
    I(p, 92) = 0;
    I(p, 96) = 0;
    I(p, 104) = 0;
    I(p, 108) = 0;
    func_0018C4B0(p, 5);
    func_00185490(p);
    func_00183D10(p);
    func_001757E0(p, 21, 12);
}

extern void func_00176160(u8 *, int, int, int);
void func_002F39C0(u8 *p) {
    p[6]++;
    p[316] = 1;
    func_00176160(p, 0, p[37] * 4, 1);
    func_00176160(p, 1, 24, 1);
    func_001757E0(p, 18, 0);
}

extern void func_001266A0(u8 *, int, int);
void func_002A66F0(u8 *p) {
    func_00175700(p);
    if (*(s8 *)(p + 337)) {
        u8 *q;
        p[6]++;
        p[337] = 0;
        q = *(u8 **)(p + 476);
        *(u8 **)(q + 456) = p;
        q[522] = 1;
        q[437] = 36;
        func_001266A0(p, 0, 0);
    }
}
extern void func_00290290(u8 *);
void func_00290240(u8 *p) {
    p[7]++;
    func_00175C00(p, 0);
    func_001757E0(p, 19, 7);
    func_00290290(p);
}

extern void func_00383B80(u8 *, int, int);
void func_00282490(u8 *p) {
    func_00175700(p);
    if (*(s8 *)(p + 337)) {
        p[7]++;
        *(s16 *)(p + 28) = 240;
        func_00383B80(p, 6, 0);
    }
}

void func_002288E0(u8 *p) {
    p[6]++;
    func_00185490(p);
    p[525] = 0;
    func_00183D10(p);
    func_0018C4B0(p, 5);
    I(p, 92) = 0;
    I(p, 96) = 0;
    I(p, 104) = 0;
    I(p, 108) = 0;
    func_001757E0(p, 21, 26);
}

extern void func_00277650(u8 *);
void func_002775E0(u8 *p) {
    p[6]++;
    func_00185490(p);
    I(p, 92) = 0;
    I(p, 96) = 0;
    I(p, 104) = 0;
    I(p, 108) = 0;
    *(f32 *)(p + 56) = *(f32 *)(p + 1072);
    p[528] = 0;
    p[525] = 0;
    func_001757E0(p, 20, 2);
    func_00277650(p);
}

extern s32 func_00417A40(u8 *);
extern void func_0022EA40(u8 *), func_0022EC50(u8 *);
void func_0022E650(u8 *p) {
    p[6]++;
    p[7] = 0;
    p[316] = 1;
    if (func_00417A40(p) & 1) func_0022EA40(p);
    else {
        p[6]++;
        func_0022EC50(p);
    }
}

void func_002B72E0(u8 *p) {
    p[6]++;
    if (p[617] == 6) {
        p[1028] = 255;
        p[1029] = 16;
    }
    func_00175C00(p, 0);
    p[525] = 0;
    func_00185490(p);
    func_00183D10(p);
    func_001757E0(p, 22, 6);
}

