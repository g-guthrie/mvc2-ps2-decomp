typedef unsigned char u8;
typedef signed char s8;

extern u8 *D_004C2840;
extern void func_001E46C0(int);
extern void func_001E24E0(u8 *, int);
extern void func_001E2420(u8 *, int);
extern void func_001E3710(u8 *, int);
extern void func_001E3240(u8 *, int);
extern u8 D_004B6A68[];

extern u8 *func_00416180(u8 *, int);
extern void func_00176230(u8 *, u8 *);
extern void func_001E5F40(int, u8 *);
extern u8 *D_004C28B0;
extern void func_001E56C0(int);
extern void func_00402BC0(int);
extern u8 D_004BFAE0;
extern void func_001E4EB0(int, int, int);
extern void func_001E5070(int, int, int);
extern u8 D_004CD183[];
extern int func_00175700(u8 *);
extern void func_001843A0(u8 *);

void func_001E2130(void) {
    int a0 = 127;
    if (((s8 *)D_004C2840)[67] == 2)
        a0 = 95;
    func_001E46C0(a0);
}

void func_001E3210(u8 *p, int a1) {
    if ((u8)a1 < 64)
        func_001E24E0(p, a1);
}

void func_001E3240(u8 *p, int a1) {
    if ((u8)a1 < 64)
        func_001E2420(p, a1);
}

void func_001E31D0(u8 *p) {
    u8 v = p[1];
    if (v == 46 || v == 51)
        func_001E3240(p, 34);
}

void func_001E3C00(u8 *p) {
    func_001E3710(p, 50);
    func_001E24E0(p, 43);
}

void func_001E3BB0(u8 *p, int a1) {
    func_001E3710(p, D_004B6A68[(u8)a1]);
    func_001E24E0(p, 43);
}

void func_001E7470(u8 *p) {
    u8 *r = func_00416180(*(u8 **)(p + 404), 1);
    func_00176230(r, D_004C28B0);
    func_001E5F40(((int)p[440] >> 1) + 3238, D_004C28B0);
}

void func_001E3270(u8 *p, int a1) {
    if ((u8)a1 < 64)
        func_001E4EB0(D_004CD183[p[440] * 20], a1, 128);
}

void func_001E3320(u8 *p, int a1) {
    if ((u8)a1 < 64)
        func_001E5070(D_004CD183[p[440] * 20], a1, 128);
}

void func_001FD3F0(u8 *p) {
    if ((s8)func_00175700(p) < 0) {
        func_001843A0(p);
        return;
    }
}

void func_001E7430(u8 *p) {
    u8 *r = func_00416180(*(u8 **)(p + 404), 0);
    func_00176230(r, D_004C28B0);
    func_001E5F40(3225, D_004C28B0);
}

void func_001E4260(int a0) {
    if (a0)
        D_004BFAE0 = 1;
    else
        D_004BFAE0 = 0;
    func_001E56C0(D_004BFAE0);
    func_00402BC0(D_004BFAE0 ^ 1);
}
