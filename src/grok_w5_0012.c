typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed int s32;
typedef void (*VoidFn)(void);

extern u8 *D_004C2840;
extern u8 D_0043CD08[];

extern VoidFn jtbl_004CA000[];

extern s32 func_003299D0(void);
extern void func_003298B0(s32, s32, s32);
extern void func_0012E5E0(s32, u16, VoidFn);
extern void func_0012CB90(void);
extern void func_0012C8E0(void);
extern void func_0012D4F0(void);
void func_0012D4A0(void);
extern void func_00129060(s32, void *);
extern void func_00129080(s32);
extern void func_0012DBF0(s32, s32);
extern void func_0012DA40(s32, s32, s32);
extern void func_003D6D50(void);
extern void func_003D6E20(void);
extern void func_00170160(s32);


void func_00129870(void) {
    D_004C2840[2] = 0;
    D_004C2840[3] = 0;
    func_003298B0(0xFF000000, 10, 1);
}

void func_0012EF50(u8 *p) {
    func_0012E5E0(2, (u16)(((s8 *)p)[0x540] + 209), jtbl_004CA000[p[0x570]]);
}

void func_0012EF80(u8 *p) {
    func_0012E5E0(2, (u16)(((s8 *)p)[0x540] + 209), jtbl_004CA000[p[0x570]]);
}

void func_0012CB50(void) {
    if (func_003299D0() == 0) {
        D_004C2840[5] = 2;
        *(VoidFn *)D_0043CD08 = func_0012CB90;
    }
}

void func_0012D2B0(void) {
    if (func_003299D0() == 0) {
        *(VoidFn *)D_0043CD08 = func_0012C8E0;
        D_004C2840[3] = 1;
        D_004C2840[5] = 0;
    }
}

void func_0012D670(void) {
    if (func_003299D0() == 0) {
        D_004C2840[1] = 0;
        func_00129060(8, func_0012D4A0);
    }
}

void func_0012DA00(void) {
    if (func_003299D0() == 0) {
        D_004C2840[3] = 1;
        func_00129060(8, func_0012D4F0);
    }
}

void func_0012DBA0(s32 a0, s32 a1) {
    func_0012DBF0(a0, a1);
    func_0012DA40(a0, a1, 2);
}

void func_0012D4A0(void) {
    D_004C2840[4] = 0;
    func_003D6D50();
    func_003D6E20();
    func_00170160(18);
    func_00170160(27);
    func_00129060(8, func_0012D4F0);
    func_00129080(8);
}

