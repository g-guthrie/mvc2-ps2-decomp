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

#define PHYSXY \
    F(p, 52) += F(p, 92); \
    F(p, 92) += F(p, 104);

extern int func_00175700(u8 *);
extern void func_001757E0(u8 *, int, int);
extern int func_001864A0(u8 *);
extern void func_001843A0(u8 *);
extern void func_00186A20(u8 *);

void func_0021B740(u8 *p) {
    func_00175700(p);
    PHYS
    if (func_001864A0(p)) {
        p[6]++;
        func_001757E0(p, 21, 35);
    }
}
void func_00320FF0(u8 *p) {
    func_00175700(p);
    PHYS
    if (func_001864A0(p)) {
        p[6]++;
        func_001757E0(p, 21, 35);
    }
}

void func_00204F80(u8 *p) {
    PHYS
    func_00175700(p);
    if (--S(p, 28) == 0) p[6]++;
}
void func_002051F0(u8 *p) {
    PHYS
    func_00175700(p);
    if (--S(p, 28) == 0) p[6]++;
}

void func_0026C690(u8 *p) {
    PHYSXY
    if ((s8)func_00175700(p) < 0) {
        I(p, 92) = 0;
        I(p, 96) = 0;
        I(p, 104) = 0;
        I(p, 108) = 0;
        func_001843A0(p);
    }
}
void func_002B40A0(u8 *p) {
    PHYSXY
    if ((s8)func_00175700(p) < 0) {
        I(p, 92) = 0;
        I(p, 96) = 0;
        I(p, 104) = 0;
        I(p, 108) = 0;
        func_001843A0(p);
    }
}

void func_003A2770(u8 *p) {
    p[316] = 1;
    func_00175700(p);
    if (--S(p, 28) < 0) {
        p[5]++;
        func_001757E0(p, 22, 4);
    }
}
void func_003A2C70(u8 *p) {
    p[316] = 1;
    func_00175700(p);
    if (--S(p, 28) < 0) {
        p[5]++;
        func_001757E0(p, 22, 4);
    }
}

void func_001D5840(u8 *p) {
    func_00175700(p);
    if (--S(p, 28) == 0) {
        p[5]++;
        func_001757E0(p, 18, 5);
    }
}
void func_001D9F50(u8 *p) {
    func_00175700(p);
    if (--S(p, 28) == 0) {
        p[5]++;
        func_001757E0(p, 18, 5);
    }
}

void func_002C7120(u8 *p) {
    PHYSXY
    if ((s8)func_00175700(p) < 0) func_001843A0(p);
}
void func_00311BF0(u8 *p) {
    PHYSXY
    if ((s8)func_00175700(p) < 0) func_001843A0(p);
}

void func_002C88D0(u8 *p) {
    if (--S(p, 28) < 0) {
        p[6]++;
        if (p[525] != 2) func_00186A20(p);
    }
}
void func_002C91C0(u8 *p) {
    if (--S(p, 28) < 0) {
        p[6]++;
        if (p[525] != 2) func_00186A20(p);
    }
}
