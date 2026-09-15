typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef float f32;

#define F(p, o) (*(f32 *)((u8 *)(p) + (o)))
#define I(p, o) (*(s32 *)((u8 *)(p) + (o)))
#define S(p, o) (*(s16 *)((u8 *)(p) + (o)))

extern int func_00175700(u8 *);
extern void func_001757E0(u8 *, int, int);
extern void func_001E3710(u8 *, int);
extern void func_001E7F60(u8 *);
extern void func_00386780(u8 *, u8 *);
extern void func_00386E40(u8 *, u8 *);
extern void func_0039E450(u8 *);
extern void func_00396EC0(u8 *, u8 *, u8 *);
extern void func_003A5000(u8 *, int, int, int);
extern void func_003B1130(u8 *, int, int, int);
extern void func_003BA140(u8 *);
extern void func_003BDA80(u8 *, u8 *);
extern void func_003BE240(u8 *);
extern void func_003BE300(u8 *, u8 *);

void func_00386740(u8 *p) {
    u8 *q = *(u8 **)(p + 24);
    if (p[32])
        func_00386E40(p, q);
    else
        func_00386780(p, q);
}

void func_00388F60(u8 *p, u8 *q) {
    if (q[7] != 1)
        p[6] = 0;
    else
        func_00175700(p);
}

void func_00389020(u8 *p, u8 *q) {
    if (q[7] != 2)
        p[6] = 0;
    else
        func_00175700(p);
}

void func_003890E0(u8 *p, u8 *q) {
    if (q[7] != 7)
        p[6] = 0;
    else
        func_00175700(p);
}

void func_00389660(u8 *p, u8 *q) {
    u8 *r = q + 696;
    if (q[708] & 1) {
        p[6]++;
        r[28] |= 1;
    }
}

void func_003897C0(u8 *p, u8 *q) {
    u8 *r = q + 696;
    if (q[708] & 2) {
        p[6]++;
        r[28] |= 2;
    }
}

void func_00395FF0(u8 *p, u8 *q) {
    p[316] = 1;
    F(p, 52) = F(q, 52);
    F(p, 56) = F(q, 56);
    S(p, 30) = 10;
    S(p, 28) = 2;
    *(s8 *)(p + 49) = -8;
    func_001757E0(p, 23, 10);
}

void func_00396EC0(u8 *p, u8 *q, u8 *r) {
    F(p, 52) = F(q, 52);
    F(p, 56) = F(q, 56);
    F(p, 52) += F(r, 8);
    F(p, 56) += F(r, 12);
}

void func_00397CD0(u8 *p) {
    p[36] = 0;
    if ((s8)func_00175700(p) < 0) {
        p[4] = 2;
        p[316] = 0;
    }
}

void func_0039D130(u8 *p) {
    if (*(s8 *)(p + 435) == 0)
        func_0039E450(p);
}

void func_0039D3B0(u8 *p) {
    if (S(p, 30) == 0)
        func_0039E450(p);
}

void func_003A53A0(u8 *p) {
    func_003A5000(p, 2, 0, 0);
    p[5]++;
}

void func_003B14F0(u8 *p) {
    func_003B1130(p, 2, 0, 0);
    p[5]++;
}

void func_003B9750(u8 *p) {
    func_003BA140(p);
    p[36] = 12;
    func_001757E0(p, 21, 13);
}

void func_003B9790(u8 *p) {
    func_003BA140(p);
    p[36] = 9;
    func_001757E0(p, 21, 19);
}

void func_003B9EC0(u8 *p) {
    if (--S(p, 30) == 0) {
        p[4]++;
        p[5] = 0;
        p[316] = 0;
    }
}

void func_003BA0F0(u8 *p) {
    p[4]++;
    p[316] = 0;
    if (p[32] == 3)
        func_001E3710(p, 58);
}

void func_003BDA40(u8 *p) {
    if (p[32] == 0)
        func_003BDA80(p, *(u8 **)(p + 24));
    else
        func_003BE300(p, *(u8 **)(p + 24));
}

void func_003BE2C0(u8 *p) {
    func_003BE240(p);
    if (I(p, 220) == 0)
        func_001E7F60(p);
}
