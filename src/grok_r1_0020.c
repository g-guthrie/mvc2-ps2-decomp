typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef signed int s32;

#define I(p, o) (*(s32 *)((u8 *)(p) + (o)))
#define S(p, o) (*(s16 *)((u8 *)(p) + (o)))
#define H(p, o) (*(u16 *)((u8 *)(p) + (o)))

extern int func_00175700(u8 *);
extern void func_001757E0(u8 *, int, int);
extern void func_00178F20(u8 *, u8 *);
extern void func_001843A0(u8 *);
extern void func_00184540(u8 *);
extern void func_00186CE0(u8 *, int);
extern void func_0019A3D0(u8 *, int);
extern void func_00358480(u8 *);
extern void func_0022C5C0(u8 *);
extern void func_0022C5D0(u8 *);
extern void func_00232B80(u8 *);
extern void func_00232C70(u8 *);
extern void func_00232D50(u8 *);
extern void func_00202D80(u8 *);
extern void func_0023A440(u8 *);
extern void func_0027C340(u8 *);
extern void func_00279270(u8 *);
extern void func_0027BD50(u8 *);
extern void func_002482C0(u8 *);

void func_00227F90(u8 *p) {
    if (*(s8 *)(p + 337) == 0)
        p[6]++;
    func_00175700(p);
}

void func_00232C30(u8 *p) {
    p[6]++;
    I(p, 92) = 0;
    I(p, 96) = 0;
    I(p, 104) = 0;
    I(p, 108) = 0;
    func_00232B80(p);
}

void func_00232D10(u8 *p) {
    p[6]++;
    I(p, 92) = 0;
    I(p, 96) = 0;
    I(p, 104) = 0;
    I(p, 108) = 0;
    func_00232C70(p);
}

void func_00232E20(u8 *p) {
    p[6]++;
    I(p, 92) = 0;
    I(p, 96) = 0;
    I(p, 104) = 0;
    I(p, 108) = 0;
    func_00232D50(p);
}

void func_00277790(u8 *p) {
    if (H(p, 860) & 2)
        I(p, 704)++;
}

void func_00202E10(u8 *p) {
    p[6]++;
    I(p, 96) = 0xC1092492;
    I(p, 108) = 0xBF892492;
    func_00202D80(p);
}

void func_00223130(u8 *p) {
    if (p[696])
        func_00358480(p);
}

void func_00203000(u8 *p) {
    u8 *q = *(u8 **)(p + 476);
    if (!*(s8 *)(q + 336))
        func_00178F20(q, p);
}

void func_00213970(u8 *p) {
    if (--S(p, 28) <= 0)
        p[6]++;
}

void func_00215A40(u8 *p) {
    u8 *q = *(u8 **)(p + 476);
    if (*(s8 *)(q + 337))
        func_00178F20(q, p);
}

void func_0022EC20(u8 *p) {
    p[7]++;
    p[710] = 1;
    p[711] = 8;
    S(p, 28) = 64;
    func_001757E0(p, 18, 0);
}

void func_00231BE0(u8 *p) {
    p[7]++;
    I(p, 96) = 0x424DB6DB;
    I(p, 108) = 0xBF4DB6DB;
    func_001757E0(p, 22, 6);
}

void func_0023A580(u8 *p) {
    u8 *q = p + 696;
    if (p[509] == 3 && q[2]) {
        q[2]--;
        p[520] = 2;
    }
}

void func_00260F70(u8 *p) {
    p[1036] = 2;
    p[828] = 5;
    if (*(s8 *)(p + 339) < 0)
        p[6]++;
    func_00175700(p);
}

void func_0023A400(u8 *p) {
    S(p, 1016) = 2;
    func_0023A440(p);
    func_0023A580(p);
}

void func_0024D460(u8 *p) {
    if ((p[523] & 63) != 3)
        func_00178F20(*(u8 **)(p + 476), p);
}

void func_002555E0(u8 *p) {
    if (S(p, 696) > 0) {
        p[1037] = 0;
        p[1036] = 0;
        p[828] = 5;
    } else {
        p[1036] = 2;
        p[828] = 5;
    }
}

void func_002610C0(u8 *p) {
    p[1036] = 2;
    p[828] = 5;
    if (S(p, 28)-- == 0)
        p[6]++;
}

void func_00212DA0(u8 *p, s8 *q) {
    if (p[525] == 2)
        p[360] = *q + 28;
    else
        p[360] = *q + 10;
    func_001757E0(p, 21, p[360]);
}

void func_00255620(u8 *p) {
    if (S(p, 696) > 0) {
        p[1037] = 0;
        p[1036] = 0;
        p[828] = 5;
    } else {
        p[1037] = 0;
        p[1036] = 0;
        p[827] = 0;
        p[828] = 0;
    }
}

void func_0027B9B0(u8 *p) {
    if (--S(p, 28) <= 0) {
        p[7]++;
        S(p, 30) = 30;
    }
}

void func_00212240(u8 *p) {
    func_00175700(p);
    if (*(s8 *)(p + 337)) {
        p[337] = 0;
        func_0019A3D0(p, 4);
    }
}

void func_0027CCC0(u8 *p) {
    if ((s8)func_00175700(p) < 0)
        p[6]++;
}

void func_0027C300(u8 *p) {
    p[6]++;
    func_001757E0(p, 21, 4);
    func_0027C340(p);
}

void func_00229DE0(u8 *p) {
    func_0022C5C0(p);
    if ((s8)func_00175700(p) < 0)
        func_0022C5D0(p);
}

void func_00229F80(u8 *p) {
    func_00175700(p);
    if (!*(s8 *)(p + 337)) {
        p[6]++;
        p[525] = 2;
    }
}

void func_002460E0(u8 *p) {
    func_002482C0(p);
    if ((s8)func_00175700(p) < 0)
        func_00184540(p);
}

void func_00279230(u8 *p) {
    func_00186CE0(p, 21);
    p[509] = 4;
    func_00279270(p);
}

void func_0027BC10(u8 *p) {
    func_00186CE0(p, 21);
    p[509] = 4;
    func_0027BD50(p);
}

void func_00247470(u8 *p) {
    func_00175700(p);
    if (S(p, 28)-- == 0)
        func_001843A0(p);
}

void func_00269B40(u8 *p) {
    if ((s8)func_00175700(p) < 0) {
        p[6] = 8;
        p[7] = 0;
    }
}
