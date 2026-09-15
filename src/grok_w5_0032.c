typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
typedef float f32;

#define F(p, o) (*(f32 *)((u8 *)(p) + (o)))
#define S(p, o) (*(s16 *)((u8 *)(p) + (o)))
#define I(p, o) (*(s32 *)((u8 *)(p) + (o)))

extern u8 *func_003DA750(s32, s32, s32);
extern void *D_004C283C;
extern void func_00170DF0(void *);
extern s8 func_00175700(u8 *);
extern void func_001843A0(u8 *);
extern void func_0019B110(u8 *, s32);
extern void func_00182C30(u8 *, s32);
extern void func_00182DB0(u8 *, s32);
extern void func_001266A0(u8 *, s32, s32);
extern void func_001757E0(u8 *, s32, s32);
extern void func_0032EEC0(void);
extern void func_0032F1B0(void);
extern void func_0033D360(void);
extern void func_0033DC60(void);
extern void func_0033E090(void);
extern void func_0033E380(void);
extern void func_0033E8E0(void);
extern void func_0033EDB0(void);
extern void func_0033EB00(void);
extern void func_0033C9D0(void);
extern void func_0032FF00(void);
extern void func_00337D40(void);
extern void func_0033F630(void);
extern void func_0032F790(void);
extern void func_003287A0(void);
extern void func_003288F0(void);
extern void func_0032FAF0(void);

void func_0032EE80(void)
{
    u8 *p = func_003DA750(0, 6, 1);
    if (p) {
        p[316] = 0;
        *(void **)(p + 16) = func_0032EEC0;
        I(p, 208) = 0xC0D;
    }
}

void func_0032F160(void)
{
    u8 *p = func_003DA750(0, 6, 1);
    if (p) {
        p[316] = 0;
        *(void **)(p + 16) = func_0032F1B0;
        I(p, 208) = 0x800B21;
    }
}

void func_0033D320(void)
{
    u8 *p = func_003DA750(0, 6, 1);
    if (p) {
        p[316] = 0;
        *(void **)(p + 16) = func_0033D360;
    }
}

void func_0033ED60(void)
{
    u8 *p = func_003DA750(0, 6, 1);
    if (p) {
        p[316] = 1;
        *(void **)(p + 16) = func_0033EDB0;
        I(p, 208) = 0x801;
    }
}

void func_0033DC00(void)
{
    u8 *p = func_003DA750(0, 5, 1);
    if (p) {
        p[316] = 1;
        *(void **)(p + 16) = func_0033DC60;
        S(p, 204) = 36;
        *(void **)(p + 132) = D_004C283C;
        I(p, 208) = 0x80F;
        S(p, 30) = 1;
    }
}

void func_0033E030(void)
{
    u8 *p = func_003DA750(0, 6, 1);
    if (p) {
        p[316] = 1;
        *(void **)(p + 16) = func_0033E090;
        S(p, 204) = 1;
        *(void **)(p + 132) = D_004C283C;
        I(p, 208) = 0x801;
        func_00170DF0(*(void **)(p + 132));
    }
}

void func_0033E320(void)
{
    u8 *p = func_003DA750(0, 6, 1);
    if (p) {
        p[316] = 1;
        *(void **)(p + 16) = func_0033E380;
        S(p, 204) = 3;
        *(void **)(p + 132) = D_004C283C;
        I(p, 208) = 0x801;
    }
}

void func_0033EAA0(void)
{
    u8 *p = func_003DA750(0, 6, 1);
    if (p) {
        p[316] = 1;
        *(void **)(p + 16) = func_0033E8E0;
        S(p, 204) = 17;
        *(void **)(p + 132) = D_004C283C;
        I(p, 208) = 0xC01;
    }
}

void func_0033ECB0(s32 a0)
{
    u8 *p = func_003DA750(0, 6, 1);
    if (p) {
        p[316] = 1;
        *(void **)(p + 16) = func_0033EB00;
        S(p, 204) = 18;
        *(void **)(p + 132) = D_004C283C;
        I(p, 208) = 0x801;
        p[32] = (u8)a0;
        S(p, 30) = 1;
    }
}

void func_0033C9E0(void)
{
    u8 *p = func_003DA750(0, 5, 1);
    if (p) {
        p[316] = 1;
        *(void **)(p + 16) = func_0033C9D0;
        S(p, 204) = 38;
        *(void **)(p + 132) = D_004C283C;
        I(p, 208) = 0x800;
    }
}

void func_00330320(void)
{
    u8 *p = func_003DA750(0, 6, 1);
    if (p) {
        p[316] = 1;
        *(void **)(p + 16) = func_0032FF00;
        S(p, 204) = 14;
        *(void **)(p + 132) = D_004C283C;
        I(p, 208) = 0x80F;
        S(p, 30) = 1;
    }
}

void func_00337ED0(void)
{
    u8 *p = func_003DA750(0, 6, 1);
    if (p) {
        p[316] = 1;
        *(void **)(p + 16) = func_00337D40;
        S(p, 204) = 49;
        *(void **)(p + 132) = D_004C283C;
        I(p, 208) = 0x800800;
    }
}

void func_0033F720(u8 *a0)
{
    u8 *p = func_003DA750(0, 6, 0);
    if (p) {
        p[316] = 1;
        *(void **)(p + 16) = func_0033F630;
        S(p, 204) = 7;
        *(void **)(p + 132) = D_004C283C;
        I(p, 208) = 0x803;
        *(void **)(p + 200) = a0 + 136;
    }
}

void func_0032F730(void)
{
    u8 *p = func_003DA750(0, 6, 1);
    if (p) {
        p[316] = 0;
        S(p, 204) = 15;
        *(void **)(p + 132) = D_004C283C;
        *(void **)(p + 16) = func_0032F790;
        I(p, 208) = 0x800C01;
    }
}

void func_00328740(u8 *a0)
{
    u8 *p = func_003DA750(0, 12, 0);
    if (p) {
        *(void **)(p + 16) = func_003287A0;
        *(void **)(p + 24) = a0;
        p[1] = a0[1];
        p[32] = 0;
        S(p, 38) = 0x500;
    }
}

void func_003288A0(u8 *a0)
{
    u8 *p = func_003DA750(0, 12, 1);
    if (p) {
        S(p, 38) = 1;
        *(void **)(p + 16) = func_003288F0;
        *(void **)(p + 24) = a0;
    }
}

void func_0032FBA0(void)
{
    u8 *p = func_003DA750(0, 5, 1);
    if (p) {
        p[316] = 1;
        *(void **)(p + 16) = func_0032FAF0;
        S(p, 204) = 1;
        *(void **)(p + 132) = D_004C283C;
        I(p, 208) = 0x821;
        I(p, 116) = 0x3E99999A;
    }
}

void func_00320920(u8 *p)
{
    if ((s8)func_00175700(p) < 0)
        func_001843A0(p);
    else if (*(s8 *)(p + 0x151)) {
        p[0x151] = 0;
        func_0019B110(p, 6);
    }
}

void func_00320A50(u8 *p)
{
    if ((s8)func_00175700(p) < 0)
        func_001843A0(p);
    else if (*(s8 *)(p + 0x151)) {
        p[0x151] = 0;
        func_0019B110(p, 1);
    }
}

void func_00321230(u8 *p, u8 *q)
{
    func_00182C30(q, 0x38);
    func_00182DB0(p, 2);
    func_001266A0(p, 6, 6);
    func_001757E0(p, 15, 0);
}

void func_00321300(u8 *p, u8 *q)
{
    func_00182C30(q, 0x38);
    func_00182DB0(p, 2);
    func_001266A0(p, 5, 5);
    func_001757E0(p, 15, 4);
}

void func_00321290(u8 *p, u8 *q)
{
    func_00182C30(q, 0x38);
    func_00182DB0(p, 2);
    S(q, 0x1c) = 0;
    func_001266A0(p, 5, 5);
    func_001757E0(p, 15, 2);
}
