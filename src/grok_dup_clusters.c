typedef unsigned char u8;
typedef unsigned short u16;
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

extern s8 func_00175700(u8 *);
extern int func_00174240(u8 *);
extern int func_001864A0(u8 *);
extern void func_001757E0(u8 *, int, int);
extern void func_00183D50(u8 *);
extern void func_001843A0(u8 *);
extern void func_00184540(u8 *);
extern void func_001846B0(u8 *);
extern void func_00185490(u8 *);
extern void func_001AC3F0(u8 *, u8 *);
extern void func_001C3A80(u8 *, u8 *);
extern void func_001E7F60(u8 *);
extern void func_0022C5C0(u8 *);
extern void func_0022C5D0(u8 *);
extern void func_0022C6B0(u8 *);
extern void func_002482C0(u8 *);
extern void func_00267E20(u8 *);
extern void func_00269D10(u8 *);
extern void func_00294BC0(u8 *);
extern void func_0029B130(u8 *);
extern void func_002EBB00(u8 *);
extern void func_003266E0(u8 *);
extern void func_00359140(u8 *, u8 *);
extern void func_00359260(u8 *, u8 *);
extern void func_00359350(u8 *, u8 *);
extern void func_003670B0(u8 *);
extern void func_003888B0(u8 *, int);
extern void func_0039FC70(u8 *, u8 *);
extern int func_00406128(void);

void func_00229DE0(u8 *p) {
    func_0022C5C0(p);
    if ((s8)func_00175700(p) < 0)
        func_0022C5D0(p);
}
void func_002460E0(u8 *p) {
    func_002482C0(p);
    if ((s8)func_00175700(p) < 0)
        func_00184540(p);
}
void func_00290C00(u8 *p) {
    func_00294BC0(p);
    if ((s8)func_00175700(p) < 0)
        func_001843A0(p);
}
void func_002EBA90(u8 *p) {
    func_002EBB00(p);
    if ((s8)func_00175700(p) < 0)
        func_00184540(p);
}

void func_001ABDF0(u8 *p, u8 *q) {
    func_00175700(p);
    F(p, 52) += F(p, 92);
    F(p, 92) += F(p, 104);
    if (--S(p, 30) == 0)
        func_001AC3F0(p, q);
}
void func_001ABF50(u8 *p, u8 *q) {
    func_00175700(p);
    F(p, 52) += F(p, 92);
    F(p, 92) += F(p, 104);
    if (--S(p, 30) == 0)
        func_001AC3F0(p, q);
}

void func_001C3970(u8 *p, u8 *q) {
    if (func_00175700(p) < 0)
        func_001C3A80(p, q);
}
void func_0039FC20(u8 *p, u8 *q) {
    if (func_00175700(p) < 0)
        func_0039FC70(p, q);
}

void func_00267050(u8 *p) {
    if ((s8)func_00175700(p) < 0) {
        func_00267E20(p);
        func_00185490(p);
    }
}
void func_002694E0(u8 *p) {
    if ((s8)func_00175700(p) < 0) {
        func_00269D10(p);
        func_00185490(p);
    }
}

void func_00359310(u8 *p, u8 *q) {
    p[5]++;
    *(u16 *)(q + 8) = 0xFFFF;
    func_00359260(p, q);
}
void func_003593B0(u8 *p, u8 *q) {
    p[5]++;
    *(u16 *)(q + 8) = 0xFFFF;
    func_00359350(p, q);
}

void func_0024A250(u8 *p) {
    int *a = (int *)(p + 92);
    int *c = (int *)(p + 104);
    PHYS
    if ((s8)func_00175700(p) < 0)
        func_00184540(p);
    if ((s8)p[337] != 0) {
        p[337] = 0;
        *a = 0;
        *c = 0;
    }
}

void func_002323D0(u8 *p) {
    if ((s8)func_00175700(p) < 0) {
        func_001843A0(p);
        return;
    }
    if ((s8)p[337] == 0) {
        PHYS
    }
}

void func_0038DA40(u8 *p) {
    PHYS
    if (!func_00174240(p)) {
        p[4]++;
        p[316] = 0;
    } else {
        func_001E7F60(p);
    }
}

void func_0029F9A0(u8 *p) {
    if ((s8)func_00175700(p) < 0) {
        if (p[525] == 2)
            func_00184540(p);
        else
            func_0029B130(p);
    }
}

void func_002C35D0(u8 *p) {
    if (func_00175700(p) < 0) {
        p[1037] = 0;
        p[1036] = 0;
        p[827] = 0;
        p[828] = 0;
        func_00184540(p);
    }
}

void func_002F16A0(u8 *p) {
    func_00175700(p);
    if (--*(s16 *)(p + 28) == 0)
        func_001846B0(p);
}

int func_00407BA0(void) { return func_00406128() != 0; }

void func_00231310(u8 *p) {
    func_00175700(p);
    PHYS
    if (func_001864A0(p)) {
        p[7]++;
        func_00183D50(p);
        func_001757E0(p, 22, 8);
    }
}
void func_002859C0(u8 *p) {
    func_00175700(p);
    PHYS
    if (func_001864A0(p)) {
        p[6]++;
        func_00183D50(p);
        func_001757E0(p, 20, 6);
    }
}
void func_002AAF30(u8 *p) {
    func_00175700(p);
    PHYS
    if (func_001864A0(p)) {
        p[6]++;
        func_00183D50(p);
        func_001757E0(p, 20, 4);
    }
}
void func_002DBC40(u8 *p) {
    func_00175700(p);
    PHYS
    if (func_001864A0(p)) {
        p[6]++;
        func_00183D50(p);
        func_001757E0(p, 21, 25);
    }
}

void func_00214790(u8 *p) {
    func_00175700(p);
    PHYS
    if (func_001864A0(p)) {
        p[6]++;
        func_001757E0(p, 20, 8);
        func_00183D50(p);
    }
}
void func_0021EC70(u8 *p) {
    func_00175700(p);
    PHYS
    if (func_001864A0(p)) {
        p[6]++;
        func_001757E0(p, 20, 4);
        func_00183D50(p);
    }
}
void func_002C43A0(u8 *p) {
    func_00175700(p);
    PHYS
    if (func_001864A0(p)) {
        p[6]++;
        func_001757E0(p, 20, 14);
        func_00183D50(p);
    }
}

void func_002B1A80(u8 *p) {
    func_00175700(p);
    PHYS
    if (func_001864A0(p)) {
        func_00183D50(p);
        p[6]++;
        func_001757E0(p, 20, 2);
    }
}
void func_002E3650(u8 *p) {
    func_00175700(p);
    PHYS
    if (func_001864A0(p)) {
        func_00183D50(p);
        p[6]++;
        func_001757E0(p, 20, 6);
    }
}

void func_00225F90(u8 *p) {
    func_00175700(p);
    PHYS
    if (func_001864A0(p)) {
        p[6]++;
        func_001757E0(p, 20, 6);
    }
}
void func_002D1190(u8 *p) {
    func_00175700(p);
    PHYS
    if (func_001864A0(p)) {
        p[6]++;
        func_001757E0(p, 20, 7);
    }
}

void func_0028A840(u8 *p, u8 *q) {
    if (--S(p, 28) == 0) {
        q[24]++;
        I(p, 96) = 0x41892492;
        I(p, 108) = 0xBF4DB6DB;
        func_003888B0(p, 5);
        func_003888B0(p, 6);
        func_003888B0(p, 7);
    }
}
void func_0028AA50(u8 *p, u8 *q) {
    if (--S(p, 28) == 0) {
        q[24]++;
        I(p, 96) = 0x41892492;
        I(p, 108) = 0xBF4DB6DB;
        func_003888B0(p, 11);
        func_003888B0(p, 12);
        func_003888B0(p, 13);
    }
}
void func_00291BB0(u8 *p, u8 *q) {
    if (--S(p, 28) == 0) {
        q[24]++;
        I(p, 96) = 0x41892492;
        I(p, 108) = 0xBF4DB6DB;
        func_003888B0(p, 5);
        func_003888B0(p, 6);
        func_003888B0(p, 7);
    }
}
void func_00291DC0(u8 *p, u8 *q) {
    if (--S(p, 28) == 0) {
        q[24]++;
        I(p, 96) = 0x41892492;
        I(p, 108) = 0xBF4DB6DB;
        func_003888B0(p, 11);
        func_003888B0(p, 12);
        func_003888B0(p, 13);
    }
}

void func_003253F0(u8 *p) {
    if (func_00175700(p) < 0) {
        p[316] = 1;
        func_003266E0(p);
    }
}
void func_003668A0(u8 *p) {
    if (func_00175700(p) < 0) {
        p[5] = 9;
        func_003670B0(p);
    }
}

void func_0022B540(u8 *p) {
    func_00175700(p);
    PHYS
    if (func_001864A0(p)) {
        p[6]++;
        func_0022C6B0(p);
        func_001757E0(p, 20, 1);
    }
}
