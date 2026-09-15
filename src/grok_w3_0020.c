typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef signed int s32;
typedef float f32;

#define I(p, o) (*(s32 *)((u8 *)(p) + (o)))
#define S(p, o) (*(s16 *)((u8 *)(p) + (o)))
#define H(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define F(p, o) (*(f32 *)((u8 *)(p) + (o)))

extern int func_00175700(u8 *);
extern void func_001757E0(u8 *, int, int);
extern void func_00212080(u8 *);
extern void func_00212DE0(u8 *, u8 *);
extern void func_00178F20(u8 *, u8 *);
extern void func_00179150(u8 *, u8 *);
extern void func_001820A0(u8 *);
extern void func_00182300(u8 *);
extern void func_002174F0(u8 *);
extern void func_00217650(u8 *);
extern void func_001E3210(u8 *, int);
extern int func_001864A0(u8 *);
extern void func_001865B0(u8 *);
extern void func_001843A0(u8 *);
extern void func_00184540(u8 *);
extern void func_00182C30(u8 *, int);
extern void func_00182DB0(u8 *, int);
extern void func_001266A0(u8 *, int, int);
extern void func_001E3710(u8 *, int);
extern void func_00126400(void);
extern void func_0021C770(u8 *, u8 *);
extern void func_00204D50(u8 *);
extern void func_00204AB0(u8 *);
extern void func_00209BB0(u8 *);
extern void func_00209B70(u8 *);

void func_00203040(u8 *p) {
    u8 *q = *(u8 **)(p + 476);
    if (!*(s8 *)(q + 336))
        func_00178F20(q, p);
    else
        func_00179150(q, p);
}

void func_0020A7A0(u8 *p) {
    if (--S(p, 28) == 0) {
        p[7]++;
        func_001757E0(p, 21, 2);
    }
}

void func_0020A880(u8 *p) {
    if ((s8)func_00175700(p) < 0) {
        p[7]++;
        func_001757E0(p, 1, 3);
    }
}

void func_002174A0(u8 *p) {
    func_001820A0(p);
    func_00182300(p);
    if (!p[530])
        func_002174F0(p);
    else
        func_00217650(p);
}

void func_0021F6F0(u8 *p) {
    p[6]++;
    if (H(p, 730) == 1)
        func_001E3210(p, 21);
    func_001E3210(p, 33);
}

void func_00210C70(u8 *p) {
    if (!*(s8 *)(p + 436) || p[5])
        p[700] = 0;
}

void func_00207C30(u8 *p) {
    F(p, 100) += F(p, 112);
    if (--S(p, 28) == 0) {
        p[6]++;
        *(s16 *)(p + 28) = 4;
    }
}

void func_0021B980(u8 *p, u8 *q) {
    func_00182C30(q, 56);
    func_00182DB0(p, 2);
    func_001266A0(p, 6, 6);
    func_001757E0(p, 15, 0);
}

void func_0021BA50(u8 *p, u8 *q) {
    func_00182C30(q, 56);
    func_00182DB0(p, 2);
    func_001266A0(p, 5, 5);
    func_001757E0(p, 15, 4);
}

void func_0021C840(u8 *p, u8 *q) {
    p[337] = 10;
    func_001E3710(p, 5);
    func_00126400();
    func_0021C770(p, q);
}

void func_0020A620(u8 *p) {
    func_00175700(p);
    if (--S(p, 28) == 0) {
        p[7]++;
        func_001757E0(p, 18, 3);
    }
}

void func_00200B60(u8 *p) {
    if (*(s8 *)(p + 709)) {
        p[7]++;
        func_001757E0(p, 22, 16);
    } else if ((s8)func_00175700(p) < 0)
        func_001843A0(p);
}

void func_00204A40(u8 *p) {
    func_001820A0(p);
    func_00182300(p);
    if (p[530] == 1)
        func_00204D50(p);
    else
        func_00204AB0(p);
    if (func_001864A0(p))
        func_001865B0(p);
}

void func_00209B00(u8 *p) {
    func_001820A0(p);
    func_00182300(p);
    if (p[530] == 1)
        func_00209BB0(p);
    else
        func_00209B70(p);
    if (func_001864A0(p))
        func_001865B0(p);
}

void func_00204C00(u8 *p) {
    if ((s8)func_00175700(p) < 0) {
        p[6] = 5;
        I(p, 96) = 0;
        I(p, 104) = 0;
        I(p, 92) = 0;
        I(p, 108) = 0xBF4DB6DB;
        func_001757E0(p, 1, 9);
    }
}

void func_00204CD0(u8 *p) {
    if ((s8)func_00175700(p) < 0) {
        p[6]++;
        I(p, 96) = 0;
        I(p, 104) = 0;
        I(p, 92) = 0;
        I(p, 108) = 0xBF4DB6DB;
        func_001757E0(p, 1, 9);
    }
}

void func_00206570(u8 *p) {
    if ((s8)func_00175700(p) < 0) {
        func_001E3210(p, 43);
        if (p[525] == 2)
            func_00184540(p);
        else
            func_001843A0(p);
    }
}

void func_0020D740(u8 *p) {
    func_00175700(p);
    if (--S(p, 28) <= 0) {
        p[6]++;
        func_001757E0(p, 22, 33);
    }
}

void func_00211F80(u8 *p) {
    func_00212080(p);
    if ((s8)func_00175700(p) < 0) {
        p[6]++;
        func_001757E0(p, 18, 1);
        p[703] = 0;
        p[702] = 0;
    }
}

void func_002158B0(u8 *p) {
    p[700] = 255;
    func_00212DE0(p, p + 696);
    func_00175700(p);
    if (--S(p, 28) < 0) {
        p[6]++;
        func_001757E0(p, 15, 9);
    }
}

