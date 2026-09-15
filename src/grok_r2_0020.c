typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef signed int s32;

#define I(p, o) (*(s32 *)((u8 *)(p) + (o)))
#define S(p, o) (*(s16 *)((u8 *)(p) + (o)))

extern void func_00178F20(u8 *, u8 *);
extern void func_00179150(u8 *, u8 *);
extern void func_00179160(u8 *, u8 *);
extern int func_00175700(u8 *);
extern void func_001757E0(u8 *, int, int);
extern void func_00186A20(u8 *);
extern void func_0022E7E0(u8 *);
extern void func_0022EB50(u8 *);
extern void func_0015F4B0(u8 *, int);
extern u8 D_004D18A0;
extern s8 D_00451C60[];

void func_00239C80(u8 *p, u8 *q) {
    if (p[6] == 0)
        p[520] = 2;
    func_00178F20(q, p);
}

void func_00203040(u8 *p) {
    u8 *q = *(u8 **)(p + 476);
    if (*(s8 *)(q + 336) == 0)
        func_00178F20(q, p);
    else
        func_00179150(q, p);
}

void func_002101B0(u8 *p) {
    u8 *q = *(u8 **)(p + 476);
    if (q[6] == 0)
        func_00179160(q, p);
    else
        func_00178F20(q, p);
}

void func_00225CE0(u8 *p) {
    u8 *q = *(u8 **)(p + 476);
    if (*(s8 *)(q + 336))
        func_00179150(q, p);
    else
        func_00178F20(q, p);
}

void func_00231800(u8 *p) {
    p[7]++;
    p[525] = 2;
    I(p, 92) = 0;
    I(p, 104) = 0;
    I(p, 96) = 0x424DB6DB;
    I(p, 108) = 0xBF4DB6DB;
    func_001757E0(p, 22, 6);
}

void func_0020A7A0(u8 *p) {
    if (--S(p, 28) == 0) {
        p[7]++;
        func_001757E0(p, 21, 2);
    }
}

void func_00211EE0(u8 *p) {
    func_00175700(p);
    if (*(s8 *)(p + 336)) {
        p[336] = 0;
        p[6]++;
        p[703] = 0;
        p[702] = 0;
    }
}

void func_00224560(u8 *p) {
    if ((s8)func_00175700(p) < 0) {
        p[5]++;
        S(p, 320) = p[486];
    }
}

void func_00228AF0(u8 *p) {
    if (*(s8 *)(p + 337) == 0) {
        p[6]++;
        func_00186A20(p);
    }
    func_00175700(p);
}

void func_00202FB0(u8 *p) {
    u8 *q = *(u8 **)(p + 476);
    if (*(s8 *)(q + 353)) {
        if (*(s8 *)(q + 336))
            func_00178F20(q, p);
        else
            func_00179150(q, p);
    }
}

void func_0022E8C0(u8 *p) {
    if (D_004D18A0 < 2)
        p[316] = 0;
    else {
        p[7]++;
        p[316] = 1;
        func_0022E7E0(p);
    }
}

void func_0022EBD0(u8 *p) {
    if (D_004D18A0 != 2)
        func_00175700(p);
    else {
        p[7]++;
        func_0022EB50(p);
    }
}

void func_0022C580(u8 *p) {
    s32 idx = I(p, 208);
    if (idx && p[1061] == 0)
        func_0015F4B0(p, D_00451C60[idx]);
}

extern void func_00183D50(u8 *);
extern u8 D_004F1F45;
extern u8 D_004F1F46;

void func_0022C6B0(u8 *p) {
    func_00183D50(p);
    if (p[534] == 0x80) {
        D_004F1F45 = 1;
        D_004F1F46 = 1;
    }
}

void func_002221E0(u8 *p) {
    func_00175700(p);
    if (*(s8 *)(p + 337) == 2) {
        p[6]++;
        p[486] ^= 1;
    }
}
