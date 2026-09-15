typedef unsigned char u8;
typedef signed char s8;

extern int func_00175700(u8 *);
extern void func_001757E0(u8 *, int, int);

void func_00177B40(u8 *p) {
    if ((s8)func_00175700(p) < 0) {
        p[6]++;
        func_001757E0(p, 13, 34);
    }
}

void func_00177EE0(u8 *p) {
    if ((s8)func_00175700(p) < 0) {
        p[6]++;
        func_001757E0(p, 13, 31);
    }
}

void func_001CF5F0(u8 *p) {
    if ((s8)func_00175700(p) < 0) {
        p[5]++;
        func_001757E0(p, 21, 42);
    }
}

void func_001F3800(u8 *p) {
    if ((s8)func_00175700(p) < 0) {
        p[7]++;
        func_001757E0(p, 15, 44);
    }
}

void func_001F47B0(u8 *p) {
    if ((s8)func_00175700(p) < 0) {
        p[7]++;
        func_001757E0(p, 15, 30);
    }
}

void func_0020A880(u8 *p) {
    if ((s8)func_00175700(p) < 0) {
        p[7]++;
        func_001757E0(p, 1, 3);
    }
}

void func_00269960(u8 *p) {
    if ((s8)func_00175700(p) < 0) {
        p[7]++;
        func_001757E0(p, 22, 41);
    }
}

void func_002699B0(u8 *p) {
    if ((s8)func_00175700(p) < 0) {
        p[7]++;
        func_001757E0(p, 22, 43);
    }
}

void func_00269A00(u8 *p) {
    if ((s8)func_00175700(p) < 0) {
        p[7]++;
        func_001757E0(p, 22, 39);
    }
}

void func_00269A50(u8 *p) {
    if ((s8)func_00175700(p) < 0) {
        p[7]++;
        func_001757E0(p, 22, 44);
    }
}

void func_00269AA0(u8 *p) {
    if ((s8)func_00175700(p) < 0) {
        p[7]++;
        func_001757E0(p, 22, 38);
    }
}

void func_00277650(u8 *p) {
    if ((s8)func_00175700(p) < 0) {
        p[6]++;
        func_001757E0(p, 20, 3);
    }
}

void func_00303340(u8 *p) {
    if ((s8)func_00175700(p) < 0) {
        p[6]++;
        func_001757E0(p, 21, 8);
    }
}

void func_0030C240(u8 *p) {
    if ((s8)func_00175700(p) < 0) {
        p[6]++;
        func_001757E0(p, 15, 3);
    }
}

void func_0030C3A0(u8 *p) {
    if ((s8)func_00175700(p) < 0) {
        p[6]++;
        func_001757E0(p, 15, 5);
    }
}

void func_0038FFF0(u8 *p) {
    if ((s8)func_00175700(p) < 0) {
        p[5]++;
        func_001757E0(p, 23, 10);
    }
}

void residual_00272FF0(u8 *p) {
    func_00175700(p);
    if ((s8)p[337] != 0) {
        p[6]++;
        p[337] = 0;
    }
}
