typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern void func_003DF850();

extern void func_00175C00();
extern void func_003DAA40();
void func_003296A0(u8 *a0, u8 *a1) {
    if (a1[0x23E] == 4) {
        s8 t = a1[0x23D] - 1;
        a1[0x23D] = t;
        if (t < 0) a1[0x23D] = 0;
    }
    func_00175C00(a1, 1);
    func_003DAA40(a0);
}

extern void func_003D92F0();
extern s8 func_00175700();
extern void func_00176160();
extern u32 D_0044FE20[];
void func_001FEBF0(u8 *p) {
    p[0x33A] = 0xFF;
    func_003D92F0();
    func_00175700(p);
    if (*(s8 *)(p + 0x151)) func_00176160(p, 0, D_0044FE20[p[0x25]], 1);
}

extern void func_001757E0();
extern void func_001861B0();
extern void func_0022F590();
void func_0022FB00(u8 *p, u8 *q) {
    u32 t = p[7];
    p[7] = t + 1;
    func_001861B0();
    *(s8 *)(q + 0x14) = -0x7F;
    p[0x169] = 0x15;
    p[0x168] = *(s8 *)(p + 0x1B7) + 9;
    func_001757E0(p, p[0x169], p[0x168]);
    func_0022F590(p, q);
}

extern void func_0022F190();
extern void func_00230500();
void func_002305E0(u8 *p, u8 *q) {
    u32 t;
    if (p[0x269] == 6) {
        p[0x404] = 0xFF;
        p[0x405] = 0x10;
    }
    t = p[7];
    p[7] = t + 1;
    func_0022F190(p);
    p[0x169] = 0x16;
    p[0x168] = 0xD;
    func_001757E0(p, p[0x169], p[0x168]);
    func_00230500(p, q);
}

extern u8 *func_003DA750();
extern void func_0035D470();
void func_0035D3F0(u8 *p, u32 a, u32 b) {
    u8 *o = func_003DA750(p, 1, 2);
    if (o) {
        *(void **)(o + 0x10) = func_0035D470;
        *(s16 *)(o + 0x26) = 0xD01;
        *(u32 *)(o + 0x18) = *(u32 *)(p + 0x18);
        *(u8 **)(o + 0x14) = p;
        o[1] = p[1];
        o[0x20] = a;
        o[0x21] = b;
    }
}

void func_0018A990(u8 *p, u8 *q) {
    if (*(s8 *)(p + 0x539)) {
        p[0x212] = p[0x4BF];
        p[0x1B7] = p[0x4BE];
        *(u16 *)(p + 0x20E) = *(u16 *)(p + 0x4C0);
    } else {
        if (*(u16 *)(q + 6) & 0x240) p[0x1B7] = 0;
        if (*(u16 *)(q + 6) & 0x120) p[0x1B7] = 1;
        if (*(u16 *)(q + 6) & 0x300) p[0x212] = 0;
        if (*(u16 *)(q + 6) & 0x60) p[0x212] = 1;
    }
}

#define F(o) (*(float *)(p + (o)))
#define INTEG() \
    F(0x34) += F(0x5C); \
    F(0x5C) += F(0x68); \
    F(0x38) += F(0x60); \
    F(0x60) += F(0x6C)

extern s32 func_00174470();
extern void func_001843A0();
void func_00388140(u8 *p, u8 *q) {
    if (func_00174470(p) == 0) {
        p[4] = 2;
        q[0x2BF] = 0;
    } else {
        INTEG();
    }
}

void func_0017B410(u8 *p) {
    p[0x201] = 1;
    p[0x1B1] = 0;
    p[0x1FF] = 4;
    p[0x209] = 1;
    if (func_00175700(p) < 0) {
        p[0x20D] = 0;
        func_001843A0(p);
    } else {
        INTEG();
    }
}

extern void func_001BAE10();
void func_0037D830(u8 *p, u8 *q) {
    INTEG();
    if (func_00175700(p) < 0) {
        func_001BAE10(p, q, 3);
        p[4] = 2;
        *(u32 *)(q + 0x2E0) = 0;
        *(u32 *)(q + 0x2E4) = 0;
    }
}

extern s8 func_00175670();
void func_0019BD20(u8 *p) {
    p[0x25] = (*(u8 **)(p + 0x18))[0x25];
    INTEG();
    if (func_00175670(p) < 0) {
        p[0x13C] = 0;
        p[4] = 3;
    }
}

void func_003980C0(u8 *p) {
    s16 t;
    F(0x38) += F(0x60);
    F(0x60) += F(0x6C);
    *(s16 *)(p + 0x1C) = *(s16 *)(p + 0x1C) - 1;
    if (*(s16 *)(p + 0x1C) <= 0) {
        p[4] = 2;
        p[0x13C] = 0;
    } else if (*(s16 *)(p + 0x1C) & 1) {
        p[0x13C] = 1;
        func_00175700(p);
    } else {
        p[0x13C] = 0;
    }
}

extern s32 func_00118FA8(float);
void func_00289E30(u8 *p) {
    s32 a = func_00118FA8(F(0x60));
    F(0x38) += F(0x60);
    F(0x60) += F(0x6C);
    if ((a ^ func_00118FA8(F(0x60))) < 0) *(u32 *)(p + 0x6C) = 0xBFCDB6DB;
}

extern void func_001845F0();
void func_002F8EB0(u8 *p) {
    if (p[0x20D] == 2) {
        *(s8 *)(p + 0x1E7) = -1;
        *(u32 *)(p + 0x5C) = 0;
        *(u32 *)(p + 0x68) = 0;
        *(u32 *)(p + 0x60) = 0xC0092492;
        *(u32 *)(p + 0x6C) = 0xBF4DB6DB;
        func_001845F0(p);
    } else {
        func_001843A0(p);
    }
}

extern void func_0035D340();
extern void func_0015ED10();
void func_0035D2A0(u8 *p, u8 *q) {
    if (q[0x2B8]) {
        u32 t = p[4];
        p[4] = t + 1;
        func_0035D340(p);
    } else {
        F(0x34) = *(float *)(q + 0x34);
        F(0x38) = *(float *)(q + 0x38);
        F(0x3C) = *(float *)(q + 0x3C);
        F(0x34) += F(0x5C);
        F(0x38) += F(0x60);
        if ((*(s16 *)(p + 0x1C) & 0xF) == 0) func_0015ED10(q);
        *(s16 *)(p + 0x1C) = *(s16 *)(p + 0x1C) + 1;
    }
}

extern float D_004F7FD4;
void func_0016C5F0(u8 *p) {
    s16 a, b;
    a = *(s16 *)(p + 0x1E) - 1;
    *(s16 *)(p + 0x1E) = a;
    if (a & 2) *(u32 *)(p + 0xF4) = 0;
    else *(u32 *)(p + 0xF4) = 0xC0000000;
    F(0xF4) += D_004F7FD4;
    b = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = b;
    if (b == 0) {
        u32 t = p[4];
        p[4] = t + 1;
        *(s16 *)(p + 0x1C) = 0x10;
    }
}

extern void func_001CFF70();
void func_001CFE00(u32 a, u32 b) {
    u8 *o = func_003DA750(0, 3, 0);
    if (o) {
        *(void **)(o + 0x10) = func_001CFF70;
        *(u32 *)(o + 0x18) = a;
        *(s16 *)(o + 0x26) = 0x2702;
        o[0x20] = b;
        *(s16 *)(o + 0x1C) = 0;
    }
    o = func_003DA750(0, 3, 0);
    if (o) {
        *(void **)(o + 0x10) = func_001CFF70;
        *(u32 *)(o + 0x18) = a;
        *(s16 *)(o + 0x26) = 0x2702;
        o[0x20] = b;
        *(s16 *)(o + 0x1C) = 1;
    }
}

extern void func_003CDC30();
void func_003CDB90(u8 *p, s32 n) {
    u8 *o;
    if (n < 0) o = func_003DA750(0, 1, 1);
    else o = func_003DA750(p, 1, 2);
    if (o) {
        *(void **)(o + 0x10) = func_003CDC30;
        *(u8 **)(o + 0x18) = p;
        *(u32 *)(o + 0x14) = *(u32 *)(p + 0x18);
        *(u32 *)(o + 0xD0) = *(u16 *)(p + 0x168);
        o[1] = p[1];
        *(s16 *)(o + 0x26) = 0x3A04;
        o[0x20] = n;
        o[0x21] = n >> 8;
        o[0x23] = n >> 16;
    }
}

void func_003769B0(u8 *p) {
    if (p[6] == 0) {
        u32 t = p[6];
        p[6] = t + 1;
        func_001757E0(p, 0x17, 0x10);
    } else {
        if (func_00175700(p) < 0) {
            u32 t = p[4];
            p[4] = t + 1;
            p[0x13C] = 0;
        }
    }
}
