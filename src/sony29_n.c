typedef struct {
    char pad[0x24];
    int f24;
} S8900;

extern S8900 D_004C8900;
extern int D_0043B404;
extern int D_0043B400;
extern int D_004C8980;
extern int D_004C9EC0;
extern int func_00103E30(int);
extern int func_00106E68(void *, int, int, void *, int, void *, int, int, int);
extern void func_00103E00(int);

int func_00110FD8(int a0) {
    int s0 = a0;
    int v0;

    if (D_004C8900.f24 == 0) {
        return -0x64;
    }

    v0 = func_00103E30(D_0043B404);
    if (v0 < 0) {
        return -0xC8;
    }

    D_004C8980 = s0;
    s0 = func_00106E68(&D_004C8900, 0xA, 1, &D_004C8980, 0x30, &D_004C9EC0, 4, 0, 0);
    if (s0 == 0) {
        D_0043B400 = 0xA;
    } else {
        func_00103E00(D_0043B404);
    }
    return s0;
}

int func_00110298(int a0) {
    int s0 = a0;
    int v0;

    if (D_004C8900.f24 == 0) {
        return -0x64;
    }

    v0 = func_00103E30(D_0043B404);
    if (v0 < 0) {
        return -0xC8;
    }

    D_004C8980 = s0;
    s0 = func_00106E68(&D_004C8900, 3, 1, &D_004C8980, 0x30, &D_004C9EC0, 4, 0, 0);
    if (s0 == 0) {
        D_0043B400 = 3;
    } else {
        func_00103E00(D_0043B404);
    }
    return s0;
}
