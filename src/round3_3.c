typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef float f32;

#define F(p, o) (*(f32 *)((u8 *)(p) + (o)))
#define I(p, o) (*(s32 *)((u8 *)(p) + (o)))
#define S(p, o) (*(s16 *)((u8 *)(p) + (o)))
#define PHYS \
    F(p, 52) += F(p, 92); \
    F(p, 92) += F(p, 104); \
    F(p, 56) += F(p, 96); \
    F(p, 96) += F(p, 108);

extern s8 func_00175670(u8 *);
extern s8 func_00175700(u8 *);
extern void func_001757E0(u8 *, int, int);
extern int func_001864A0(u8 *);
extern void func_00183D50(u8 *);
extern void func_0022C5D0(u8 *);
extern void func_001E7F60(u8 *);
extern void func_001AFCB0(u8 *, int);
extern u8 D_004D18A6;

void func_001C5B50(u8 *p, u8 *q) {
    if (!(D_004D18A6 & (1 << (q[2] ^ 1)))) {
        if (--S(p, 28) == 0)
            p[7]++;
        func_00175700(p);
    }
}
void func_001C5FC0(u8 *p, u8 *q) {
    if (!(D_004D18A6 & (1 << (q[2] ^ 1)))) {
        if (--S(p, 28) == 0)
            p[7]++;
        func_00175700(p);
    }
}
void func_001C6440(u8 *p, u8 *q) {
    if (!(D_004D18A6 & (1 << (q[2] ^ 1)))) {
        if (--S(p, 28) == 0)
            p[7]++;
        func_00175700(p);
    }
}

void func_00201020(u8 *p) {
    func_00175700(p);
    PHYS
    if (func_001864A0(p)) {
        p[7]++;
        func_00183D50(p);
        func_001757E0(p, 22, 20);
    }
}
void func_00201B90(u8 *p) {
    func_00175700(p);
    PHYS
    if (func_001864A0(p)) {
        p[7]++;
        func_00183D50(p);
        func_001757E0(p, 22, 20);
    }
}

void func_002276A0(u8 *p) {
    if ((s8)func_00175700(p) < 0) {
        func_0022C5D0(p);
        return;
    }
    if ((s8)p[337] == 0) {
        PHYS
    }
}
void func_00227890(u8 *p) {
    if ((s8)func_00175700(p) < 0) {
        func_0022C5D0(p);
        return;
    }
    if ((s8)p[337] == 0) {
        PHYS
    }
}

void func_001D58A0(u8 *p) {
    if ((s8)func_00175700(p) < 0) {
        p[5]++;
        S(p, 28) = 16;
        I(p, 96) = 0x40092492;
        func_001757E0(p, 18, 6);
    }
}
void func_001D9FB0(u8 *p) {
    if ((s8)func_00175700(p) < 0) {
        p[5]++;
        S(p, 28) = 16;
        I(p, 96) = 0x40092492;
        func_001757E0(p, 18, 6);
    }
}

void func_0038D710(u8 *p) {
    func_00175700(p);
    if ((s8)p[337] == 0) {
        p[5]++;
        F(p, 52) += F(p, 92);
        F(p, 92) += F(p, 104);
    }
    func_001E7F60(p);
}
void func_0041A3C0(u8 *p) {
    func_00175700(p);
    if ((s8)p[337] == 0) {
        p[5]++;
        F(p, 52) += F(p, 92);
        F(p, 92) += F(p, 104);
    }
    func_001E7F60(p);
}

void func_001B2720(u8 *p) {
    u8 *q;
    func_00175670(p);
    q = *(u8 **)(p + 24);
    if (q[6] != 3) {
        p[4]++;
        p[316] = 0;
    } else {
        F(p, 52) = F(q, 52);
        q = *(u8 **)(p + 24);
        F(p, 56) = F(q, 56);
    }
}
void func_001B27E0(u8 *p) {
    u8 *q;
    func_00175670(p);
    q = *(u8 **)(p + 24);
    if (q[6] != 3) {
        p[4]++;
        p[316] = 0;
    } else {
        F(p, 52) = F(q, 52);
        q = *(u8 **)(p + 24);
        F(p, 56) = F(q, 56);
    }
}

void func_00258A90(u8 *p) {
    if ((s8)p[337] == 1) {
        p[337] = 0;
        func_001AFCB0(p, 5);
    }
    if ((s8)func_00175700(p) < 0)
        p[5]++;
}
void func_00258B30(u8 *p) {
    if ((s8)p[337] == 1) {
        p[337] = 0;
        func_001AFCB0(p, 5);
    }
    if ((s8)func_00175700(p) < 0)
        p[5]++;
}
