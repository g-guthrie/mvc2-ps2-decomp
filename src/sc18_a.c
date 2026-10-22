extern char D_004C8658[];
extern char D_004AB4B8[];
extern char D_004AB4E0[];
extern char D_0043B3C8[];
extern volatile int D_004399AC;
extern int D_00439990;
extern int D_00439998;
extern int D_004399C8;
extern int D_004C8650;
typedef struct {
    char pad[0x24];
    int f24;
} S7080;
extern void func_0010E9A8(void);
extern void func_00103E00(int);
extern int func_00103E30(int);
extern void func_00103CE0(int, void *);
extern int func_0010F1E8(int);
extern void func_00106628(int);
extern int func_00106C98(void *, unsigned, int);

int func_0010F258(int a0) {
    int i;
    char *p;
    int r;

    func_0010E9A8();
    if (D_004399AC != func_00103E30(D_004399AC)) {
        if (D_00439990 > 0) {
            func_00105E80(D_004AB4B8, a0, D_00439998);
        }
        return 0;
    }
    D_00439998 = a0;
    func_00103CE0(D_004C8650, D_004C8658);
    if (func_0010F1E8(1) != 0) {
        func_00103E00(D_004399AC);
        return 0;
    }
    func_00106628(0);
    if (D_004399C8 < 0) {
        for (;;) {
            p = D_0043B3C8;
            r = func_00106C98(p, 0x80000593, 0);
            if (r < 0) {
                if (D_00439990 > 0) {
                    func_00105E80(D_004AB4E0);
                }
                i = 0x100000;
                do {
                    i--;
                    asm volatile ("nop");
                } while (i != -1);
            } else {
                if (((S7080 *)p)->f24 != 0) {
                    break;
                }
                i = 0x100000;
                do {
                    i--;
                    asm volatile ("nop");
                } while (i != -1);
            }
        }
        D_004399C8 = 0;
    }
    return 1;
}
