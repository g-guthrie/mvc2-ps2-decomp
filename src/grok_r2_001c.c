typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef signed int s32;
typedef float f32;

#define F(p, o) (*(f32 *)((u8 *)(p) + (o)))
#define S(p, o) (*(s16 *)((u8 *)(p) + (o)))
#define H(p, o) (*(u16 *)((u8 *)(p) + (o)))

extern void func_001CDEF0(u8 *);
extern void func_001EA840(u8 *);
extern void func_001E1430(u8 *);
extern void func_001CADD0(u8 *, int);
extern void func_00423990(void *, int);
extern void func_003DAA40(u8 *);
extern int func_001C3E60(u8 *);
extern int func_001C8570(u8 *);
extern void func_001754A0(u8 *, int, int);
extern void func_001CB5D0(u8 *);
extern void func_001E7750(int);
extern void func_001E46E0(void);
extern void func_001E5230(void);
extern void func_003FEAD0(void);
extern void func_004236C0(int);
extern void func_001E16E0(u8 *, u8 *);
extern void func_001E1C40(u8 *, u8 *);
extern int func_00175700(u8 *);
extern void func_001EAB70(u8 *);
extern s8 D_004B5990[];
extern u8 D_004B5988[];
extern void func_001CB180(u8 *);

void residual_001CDEE0(u8 *p) {
    p[4]++;
    func_001CDEF0(p);
}

void residual_001EA830(u8 *p) {
    p[6]++;
    func_001EA840(p);
}

void residual_001E1410(u8 *p) {
    p[4]++;
    p[316] = 0;
    func_001E1430(p);
}

void func_001CADB0(u8 *p) {
    u8 *q = *(u8 **)(p + 24);
    func_001CADD0(p, (u8)(q[347] >> 1));
}

void func_001CAD90(u8 *p) {
    u8 *q = *(u8 **)(p + 24);
    func_001CADD0(p, (u8)((q[347] + 2) >> 1));
}

void func_001E5700(void) {
    func_00423990((void *)0x8000000C, 1);
}

void func_001CE030(u8 *p) {
    u8 *q = *(u8 **)(p + 24);
    if (H(p, 208) != H(q, 360))
        p[4] = 2;
}

void func_001CB5A0(u8 *p, int a1, int a2) {
    func_001754A0(p, a1, a2);
    p[345] = 224;
}

void func_001D4FB0(u8 *p, u8 *q) {
    F(p, 52) = F(q, 52);
    F(p, 56) = F(*(u8 **)(p + 8), 56) + F(*(u8 **)(p + 20), 108);
}

void func_001E7720(void) {
    func_001E7750(0);
    func_001E7750(1);
}

void func_001EE9E0(u8 *p) {
    u8 v = p[484];
    if (v != 21 && v != 29)
        p[537] = 0;
}

void func_001C0970(u8 *p) {
    if (p[32] == 1) {
        s8 *q = *(s8 **)(p + 24);
        q[698]--;
    }
    func_003DAA40(p);
}

void func_001C2180(u8 *p) {
    if (!func_001C3E60(p))
        p[7]++;
}

void func_001C7400(u8 *p) {
    if (!func_001C8570(p))
        p[7]++;
}

void func_001CB490(u8 *p) {
    if (p[5] == 0) {
        p[5]++;
        func_001CB180(p);
    }
    func_001CB5D0(p);
}

void func_001E42A0(void) {
    func_001E46E0();
    func_001E5230();
    func_003FEAD0();
}

void func_001E56C0(int a0) {
    if (a0 == 1)
        func_004236C0(1);
    else
        func_004236C0(0);
}

void func_001C8C80(u8 *p) {
    if (--S(p, 28) <= 0)
        p[4]++;
}

void func_001C9650(u8 *p) {
    p[49] = D_004B5990[p[34]];
    func_001754A0(p, 27, D_004B5988[p[34]]);
}

void func_001E16A0(u8 *p) {
    if (p[32] == 0)
        func_001E16E0(p, *(u8 **)(p + 24));
    else
        func_001E1C40(p, *(u8 **)(p + 24));
}

void func_001EAB30(u8 *p) {
    p[6]++;
    func_00175700(p);
    func_001EAB70(p);
}
