typedef unsigned char u8;
typedef signed short s16;
typedef signed int s32;

extern u8 D_00583B90[];
extern u8 D_00583B92[];
extern u8 D_00583BE2[];

extern void func_001319F0(s32, s32, s32);
extern void func_00134500(u8 *, u8 *);
extern void func_00133A70(u8 *, u8 *);
extern void func_00134790(u8 *);
extern void func_00133C10(u8 *, u8 *);
extern s32 func_00134480(u8 *, u8 *);
extern void func_001347D0(u8 *, u8 *);
extern void func_00133EE0(u8 *, u8 *);
extern void func_00133CE0(u8 *, u8 *);
extern void func_00134230(u8 *);
extern void func_001345B0(u8 *);
extern void func_001345C0(u8 *, u8 *, s32);
extern void func_00133FA0(u8 *, u8 *);
extern void func_00134710(u8 *, u8 *);
extern void func_00134040(u8 *, u8 *);

#define S(p, o) (*(s16 *)((u8 *)(p) + (o)))

void residual_001380C0(u8 *p) {
    if (D_00583B92[p[0x20]] & (1 << p[0x21])) {
        p[4]++;
    }
}

void func_00139620(u8 *p) {
    if (D_00583B92[p[0x20]] & (1 << p[0x21])) {
        p[4]++;
    }
}

void func_00139660(u8 *p) {
    if (D_00583B92[p[0x20]] & (0x10 << p[0x21])) {
        p[4]++;
    }
}

void func_0013A440(u8 *p) {
    if (D_00583BE2[p[0x20]]) {
        p[4]++;
        S(p, 0x1c) = 10;
    }
}

void func_00139590(u8 *p) {
    p[4]++;
    if (p[0x21] == 2) {
        D_00583B90[p[0x20]] = 1;
    }
}



void func_00131990(void) {
    func_001319F0(14, 0, 60);
    func_001319F0(13, 1, 130);
    func_001319F0(13, 0, 131);
}

void func_00133A30(u8 *p, u8 *q) {
    func_00134500(p, q);
    func_00133A70(p, q);
}

void residual_00133BC0(u8 *p, u8 *q) {
    p[5]++;
    S(p, 0x1c) = 0;
    p[0x14d] = 0;
    func_00134790(p);
    func_00133C10(p, q);
}

void func_00133C10(u8 *p, u8 *q) {
    func_00134500(p, q);
    func_00134480(p, q);
    func_001347D0(p, q);
    func_00133EE0(p, q);
}

void func_00133C70(u8 *p, u8 *q) {
    if (func_00134480(p, q)) {
        func_001347D0(p, q);
        func_00133EE0(p, q);
    } else {
        p[5]++;
        S(p, 0x1c) = 0;
        func_00133CE0(p, q);
    }
}

void residual_00133F40(u8 *p, u8 *q) {
    p[5]++;
    S(p, 0x1c) = 0;
    p[0x21] = 0;
    func_001345B0(p);
    func_001345C0(p, q, p[0x14c]);
    func_00133FA0(p, q);
}

void func_00133FA0(u8 *p, u8 *q) {
    func_00134500(p, q);
    func_00134710(p, q);
    func_00134040(p, q);
}

void func_00133FF0(u8 *p, u8 *q) {
    func_00134480(p, q);
    func_00134710(p, q);
    func_00134040(p, q);
}


