typedef struct {
    int f00, f04, f08, f0c, f10, f14, f18;
} Inner;

extern Inner D_004C83D0[][4];
extern int func_0010E1B0(int, int, int);

int func_0010E318(int a0, int a1) {
    if (D_004C83D0[a0][a1].f10 == 0) {
        return 0;
    }
    return func_0010E1B0(a0, a1, 0);
}
