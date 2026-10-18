typedef struct {
    int f00, f04, f08, f0c, f10, f14;
} Msg85C0;

extern Msg85C0 D_004C85C0;
extern unsigned char D_004C8380[];
extern int func_00106E68(void *, int, int, int, int, void *, int, int, int);
extern int func_0010DA40(int, int, int);

int func_0010DEA8(int a0, int a1, int a2, int a3) {
    int r;
    int ret;

    D_004C85C0.f04 = a0;
    D_004C85C0.f08 = a1;
    D_004C85C0.f0c = a2;
    D_004C85C0.f10 = a3;
    D_004C85C0.f00 = 6;
    r = func_00106E68(D_004C8380, 1, 0, &D_004C85C0, 0x80, &D_004C85C0, 0x80, 0, 0);
    if (r < 0) {
        return 0;
    }
    ret = D_004C85C0.f14;
    if (ret == 1) {
        func_0010DA40(a0, a1, 2);
        ret = D_004C85C0.f14;
    }
    return ret;
}
