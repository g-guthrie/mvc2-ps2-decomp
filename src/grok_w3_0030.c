typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef unsigned int u32;
typedef float f32;

extern s8 func_00175700(u8 *);
extern void func_001757E0(u8 *, int, int);
extern void func_001843A0(u8 *);
extern void func_00184540(u8 *);
extern void func_001266A0(u8 *, int, int);
extern void func_00182380(u8 *);
extern void func_001821D0(u8 *);
extern void func_001D9D80(u8 *, int, int);
extern void func_003039A0(u8 *);
extern void func_00301380(u8 *);
extern void func_00301200(u8 *);
extern void func_00301C40(u8 *);
extern int func_003052D0(u8 *);
extern int func_00305330(u8 *);
extern void func_00176160(u8 *, int, int, int);
extern void func_001E3710(u8 *, int);
extern void func_0030C470(u8 *);
extern void func_003BA230(u8 *, int, int);
extern void func_00309310();
extern void func_0030A450();
extern void func_00175C00(u8 *, int);
extern void func_0030D080(u8 *);
extern void func_001E3210(u8 *, int);
extern void func_0030E6B0(u8 *);
extern void func_0030F450(u8 *);
extern void func_0030F560(u8 *);
extern void func_00178F20(u8 *, u8 *);
extern void func_003B38F0(u8 *, int, int);
extern void func_00318CF0(u8 *);
extern void func_00313120(u8 *);
extern void func_00183D90(u8 *);
extern void func_0030C120(u8 *);
extern void func_003031B0(u8 *p);

void func_003011B0(u8 *p) {
    func_003039A0(p);
    if (p[0x212] == 1)
        func_00301380(p);
    else
        func_00301200(p);
}

void func_00301BF0(u8 *p) {
    if (p[0x215])
        func_00301C40(p);
    else {
        func_00182380(p);
        func_001821D0(p);
        func_00301C40(p);
    }
}

void residual_00301CF0(u8 *p) {
    if (func_00175700(p) < 0)
        func_00184540(p);
    else if (*(s8 *)(p + 0x151))
        p[0x151] = 0;
}

void func_00302D80(u8 *p) {
    func_00175700(p);
    if (*(s8 *)(p + 0x151)) {
        p[7]++;
        *(s16 *)(p + 0x1C) = 10;
        func_001D9D80(p, 2, 0);
    }
}

void func_00303140(u8 *p) {
    s16 v;
    func_003031B0(p);
    func_00175700(p);
    v = *(s16 *)(p + 0x1C);
    *(s16 *)(p + 0x1C) = v - 1;
    if (v == 0)
        func_00184540(p);
}

void func_00303340(u8 *p) {
    if (func_00175700(p) < 0) {
        p[6]++;
        func_001757E0(p, 0x15, 8);
    }
}

s32 func_00305390(u8 *p) {
    if (func_003052D0(p))
        return 1;
    return func_00305330(p) != 0;
}

void func_00307250(u8 *p, u8 *q) {
    q[10] = 3;
    if (func_00175700(p) < 0)
        func_001843A0(p);
}

void func_003085F0(u8 *p) {
    if (p[0x2BC]) {
        p[6]++;
        func_001757E0(p, 0x15, 1);
    }
    func_00175700(p);
}

void func_00308680(u8 *p) {
    if (func_00175700(p) < 0) {
        func_001266A0(p, 0, 0);
        func_001843A0(p);
    }
}

void func_00308770(u8 *p) {
    if (p[0x2BC]) {
        p[6]++;
        func_001757E0(p, 0x15, 0xF);
    }
    func_00175700(p);
}

void func_00308800(u8 *p) {
    if (func_00175700(p) < 0) {
        func_001266A0(p, 0, 0);
        func_00184540(p);
    }
}

void func_003092C0(u8 *p) {
    if (!(p[0x25] & 1))
        func_00176160(p, 3, 4, 1);
    else
        func_00176160(p, 3, 0x10, 1);
}

void func_00309F00(u8 *p) {
    if (p[0x1FC] == 2 && *(s8 *)(p + 0x151)) {
        p[0x151] = 0;
        func_0030C470(p);
        func_003BA230(p, 4, 0);
    }
    func_00309310(p);
}

void func_0030A680(u8 *p) {
    func_0030A450();
    func_00309310();
}

void func_0030B3A0(u8 *p) {
    if (p[6])
        func_00309310(p);
    else {
        p[6]++;
        *(u32 *)(p + 0x5C) = 0;
        *(u32 *)(p + 0x60) = 0;
        *(u32 *)(p + 0x68) = 0;
        *(u32 *)(p + 0x6C) = 0;
        p[0x20D] = 0;
        func_001757E0(p, 0x14, 4);
    }
}

void func_0030C030(u8 *p) {
    func_0030C120(p);
    if (func_00175700(p) < 0) {
        p[6]++;
        func_001757E0(p, 0xF, 1);
    }
}

void func_0030C240(u8 *p) {
    if (func_00175700(p) < 0) {
        p[6]++;
        func_001757E0(p, 0xF, 3);
    }
}

void func_0030C3A0(u8 *p) {
    if (func_00175700(p) < 0) {
        p[6]++;
        func_001757E0(p, 0xF, 5);
    }
}

void func_0030D2D0(u8 *p) {
    if (!p[0x212]) {
        if (*(s8 *)(p + 0x1EA) & 0xF)
            func_0030D080(p);
    } else if (*(s8 *)(p + 0x1EA) & 0xF0)
        func_0030D080(p);
}

void func_0030E660(u8 *p) {
    p[6]++;
    func_001E3210(p, 0x25);
    func_001E3710(p, 0x4D);
    func_0030E6B0(p);
}

void func_0030F400(u8 *p) {
    p[0x1FE] = 1;
    if ((p[0x20B] & 0x3F) == 0)
        func_0030F450(p);
    else
        func_0030F560(p);
}

void func_0030F670(u8 *p) {
    if ((p[0x20B] & 0x3F) < 2)
        func_00178F20(*(u8 **)(p + 0x1DC), p);
}

void func_003018E0(u8 *p) {
    if ((s8)func_00175700(p) < 0)
        func_001843A0(p);
    else if (*(s8 *)(p + 0x151)) {
        p[0x151] = 0;
        func_003B38F0(p, 2, 0);
    }
}

void func_003041B0(u8 *p) {
    if ((s8)func_00175700(p) < 0)
        func_001843A0(p);
    else if (*(s8 *)(p + 0x151)) {
        p[0x151] = 0;
        func_003B38F0(p, 1, 4);
    }
}

void func_0030A3C0(u8 *p) {
    if ((s8)func_00175700(p) < 0) {
        p[6]++;
        func_001757E0(p, 2, 2);
    }
    func_0030A450(p);
}

void func_00312210(u8 *p, u8 *q) {
    if ((s8)func_00175700(p) < 0) {
        q[6] = 0;
        p[5]++;
    }
}

void func_00319810(u8 *p) {
    p[1036] = 2;
    p[828] = 5;
    func_00175700(p);
    func_00318CF0(p);
}

void func_00314B40(u8 *p) {
    s16 v;
    p[828] = 5;
    func_00175700(p);
    v = *(s16 *)(p + 0x1C);
    *(s16 *)(p + 0x1C) = v - 1;
    if (v == 0)
        func_001843A0(p);
}

void func_00314EF0(u8 *p) {
    func_00313120(p);
    if ((s8)func_00175700(p) < 0) {
        func_00175C00(p, 0);
        func_001843A0(p);
    }
}

void func_003111F0(u8 *p) {
    s16 v;
    func_00183D90(p);
    func_00175700(p);
    v = *(s16 *)(p + 0x1C);
    *(s16 *)(p + 0x1C) = v - 1;
    if (v == 0) {
        p[6]++;
        func_001757E0(p, 10, 3);
    }
}

