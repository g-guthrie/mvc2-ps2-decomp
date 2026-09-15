typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef signed int s32;

#define I(p, o) (*(s32 *)((u8 *)(p) + (o)))
#define S(p, o) (*(s16 *)((u8 *)(p) + (o)))

extern int func_00175700(u8 *);
extern void func_001757E0(u8 *, int, int);
extern void func_00175C00(u8 *, int);
extern void func_00178F20(u8 *, u8 *);
extern void func_001843A0(u8 *);
extern void func_00186A60(u8 *, int);
extern void func_00318CF0(u8 *);
extern void func_00325620(u8 *);
extern void func_003C1250(u8 *, int, int);

extern u8 D_004C1660;
extern u8 D_004C1664;
extern u8 D_004C1838;
extern u8 D_004C183C;
extern u8 D_004C27D0;
extern u8 *D_004C2794;
extern u8 *D_004C2840;
extern u8 *D_004C28DC;
extern u8 D_00583B90[];

void func_0030F6A0(u8 *p) {
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    p[509] = (&D_004C1660)[(s8)p[1245]];
    func_00186A60(p, 29);
}

void func_0030F6D0(u8 *p) {
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    p[509] = (&D_004C1664)[(s8)p[1245]];
    func_00186A60(p, 29);
}

void func_00326590(u8 *p) {
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    p[509] = (&D_004C1838)[(s8)p[1245]];
    func_00186A60(p, 29);
}

void func_003265C0(u8 *p) {
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    p[509] = (&D_004C183C)[(s8)p[1245]];
    func_00186A60(p, 29);
}

void func_0032AD90(u8 *p) {
    if (D_00583B90[(s8)p[1336]] == 1)
        p[4] = 3;
}

void func_0032EE50(u8 *p) {
    if (D_004C27D0 == 0)
        I(p, 68) += 512;
    else
        I(p, 68) += 256;
}

void func_0032C140(void) {
    S(D_004C2840, 8)--;
    if (S(D_004C2840, 8) <= 0) {
        D_004C2840[4] = 0;
        D_004C2840[3] = 6;
    }
}

void func_003282F0(u8 *p) {
    if (--S(p, 28) < 0) {
        p[4]++;
        S(D_004C2794, 60) = 0;
    }
}

void func_0030F670(u8 *p) {
    if ((p[523] & 63) < 2)
        func_00178F20(*(u8 **)(p + 476), p);
}

void func_00327190(u8 *p) {
    ((void (*)(u8 *))I(*(u8 **)(p + 1084), 64))(p);
    p[617] = p[616];
}

void func_003085F0(u8 *p) {
    if (p[700]) {
        p[6]++;
        func_001757E0(p, 21, 1);
    }
    func_00175700(p);
}

void func_00308770(u8 *p) {
    if (p[700]) {
        p[6]++;
        func_001757E0(p, 21, 15);
    }
    func_00175700(p);
}

void func_0030C120(u8 *p) {
    u8 *q = *(u8 **)(p + 476);
    if (I(D_004C2840, 28) & 1)
        func_00175C00(q, 1);
    else
        func_00175C00(q, 8);
}

void func_0030C290(u8 *p) {
    u8 *q = *(u8 **)(p + 476);
    if (I(D_004C2840, 28) & 1)
        func_00175C00(q, 5);
    else
        func_00175C00(q, 4);
}

void func_0030A4B0(u8 *p) {
    if ((s16)(*(u16 *)(p + 862) & *(u16 *)(p + 864)) != 2048)
        D_004C28DC[8] = 1;
}

void func_0030A4F0(u8 *p) {
    if ((s16)(*(u16 *)(p + 862) & *(u16 *)(p + 864)) != 1024)
        D_004C28DC[8] = 1;
}

void func_00319810(u8 *p) {
    p[1036] = 2;
    p[828] = 5;
    func_00175700(p);
    func_00318CF0(p);
}

void func_003255E0(u8 *p) {
    p[6]++;
    func_001757E0(p, 22, 17);
    func_00325620(p);
}

void func_00314B40(u8 *p) {
    p[828] = 5;
    func_00175700(p);
    if (S(p, 28)-- == 0)
        func_001843A0(p);
}

void func_00313C70(u8 *p, u8 *q) {
    if ((S(p, 28) & 7) == 0) {
        func_003C1250(p, 7, q[30]);
        q[30] ^= 1;
    }
}
