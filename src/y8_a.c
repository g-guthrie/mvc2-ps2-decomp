typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;
typedef signed int s32;
extern u8 *D_004C2794;
extern u8 *D_004C2840;
extern f32 D_004643BC[];

extern u8 *D_004C2794;
extern u8 *D_004C2840;

u8 *func_00368FD0(u8 *p) {
    extern u8 *func_003DA750();
    extern void func_00369070();
    u8 *o;
    u8 *q;
    if ((o = func_003DA750(0, 1, 0)) != 0) {
        *(void (**)())(o + 0x10) = func_00369070;
        *(u8 **)(o + 0x18) = p;
        o[0x20] = 0;
        *(s16 *)(o + 0x26) = 0x1103;
    }
    if ((q = func_003DA750(o, 1, 2)) != 0) {
        *(void (**)())(q + 0x10) = func_00369070;
        *(u8 **)(q + 0x18) = p;
        *(u8 **)(q + 0x14) = o;
        q[0x20] = 1;
        *(s16 *)(q + 0x26) = 0x1103;
    }
    return o;
}

extern void (*D_00463DB0[])(u8 *, u8 *, u8 *);


void func_002422A0(u8 *p) {
    extern void func_00175700();
    extern void func_001757E0();
    s8 c;
    u32 t;
    s16 h;
    p[0x40C] = 2;
    p[0x33C] = 5;
    func_00175700(p);
    c = *(s8 *)(p + 0x2BC);
    if (c < 0) {
        p[0x40D] = 0;
        p[0x40C] = 0;
        p[0x33B] = 0;
        p[0x33C] = 0;
        t = p[6];
        p[6] = t + 1;
        p[7] = 0;
        func_001757E0(p, 0x16, 8);
        return;
    }
    if (c != 0) {
        h = *(s16 *)(p + 0x1C) - 1;
        *(s16 *)(p + 0x1C) = h;
        if (h == 0) {
        p[0x40D] = 0;
        p[0x40C] = 0;
        p[0x33B] = 0;
        p[0x33C] = 0;
        t = p[6];
        p[6] = t + 1;
        p[7] = 0;
        func_001757E0(p, 0x16, 8);
        }
    }
}

extern u8 D_004C1BA0[4];
void func_0035F8B0(u8 *p, u8 *q) {
    extern void func_00175700();
    extern s32 func_00174240();
    extern void func_001E7F60();
    extern void func_001757E0();
    u8 *s1 = q + 0x2B8;
    func_00175700(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (func_00174240(p) == 0) {
        p[4] = 2;
        p[0x13C] = 0;
    } else if (*(s8 *)(p + 0x1B2) != 0) {
        p[5] = 2;
        *(s8 *)(s1 + 6) = -1;
        func_001757E0(p, 0x17, (u8)(D_004C1BA0[p[0x1B7]] + *(s8 *)(p + 0x151)));
    } else {
        func_001E7F60(p);
    }
}

void func_00128420(void) {
    extern void func_0016F040();
    extern void func_0016CDA0();
    extern void func_00170160(int);
    extern void func_00122860();
    extern void func_003D6AC0();
    extern void func_001E4480();
    extern void func_001E3F50();
    extern void func_001E4340();
    extern void func_001E3FE0();
    extern void func_001E3CE0();
    extern void func_00144D50();
    extern void func_001453B0();
    extern void func_00122840();
    extern void func_0012E6B0();
    extern void func_0012E780();
    u8 *g;
    func_0016F040();
    func_0016CDA0();
    func_00170160(0xF);
    func_00122860(0xFF000000, 0xFF000000);
    func_003D6AC0();
    *(s16 *)(D_004C2840 + 0x108) = 0;
    *(s16 *)(D_004C2840 + 0x106) = 0;
    g = D_004C2840;
    if (*(s8 *)(g + 0x2A) != 0) {
        *(s8 *)(g + 3) = 2;
    } else {
        s8 t = *(s8 *)(g + 3);
        *(s8 *)(g + 3) = t + 1;
        D_004C2840[0x19] = 0;
        *(s16 *)(D_004C2840 + 0xC) = 9;
        *(s16 *)(D_004C2840 + 0xE) = 0x78;
        func_001E4480(6, 1, 9);
        func_001E3F50(0x17);
        func_001E4340(1);
        func_001E3FE0();
        func_001E3CE0(0x3C);
        func_00144D50();
        func_001453B0();
        func_00122840(-1);
        func_0012E6B0();
        func_0012E780(8);
    }
}
