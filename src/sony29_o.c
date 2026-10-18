typedef struct {
    char pad[0x24];
    int f24;
} S8900;

typedef struct {
    int f0;
    int f4;
    char pad2[0xC];
    char name[0x400];
} S89B0;

extern S8900 D_004C8900;
extern S89B0 D_004C89B0;
extern int D_0043B404;
extern int D_0043B400;
extern int D_004C9EC0;
extern int func_00103E30(int);
extern void func_00103E00(int);
extern void func_00120440(void *, const char *, int);
extern int func_00106E68(void *, int, int, void *, int, void *, int, int, int);

int func_00111480(int a0, int a1, char *a2) {
    int v0;
    int res;

    if (D_004C8900.f24 == 0) {
        return -0x64;
    }

    v0 = func_00103E30(D_0043B404);
    if (v0 < 0) {
        return -0xC8;
    }

    if (a2 == 0 || *a2 == 0) {
        func_00103E00(D_0043B404);
        return -0xD2;
    }

    D_004C89B0.f0 = a0;
    D_004C89B0.f4 = a1;
    func_00120440(D_004C89B0.name, a2, 0x3FF);
    D_004C89B0.name[0x3FF] = 0;

    res = func_00106E68(&D_004C8900, 0x12, 1, &D_004C89B0, 0x414, &D_004C9EC0, 4, 0, 0);
    if (res == 0) {
        D_0043B400 = 0x12;
    } else {
        func_00103E00(D_0043B404);
    }
    return res;
}
