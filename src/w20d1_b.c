extern int func_00106E68(void *, int, int, void *, int, void *, int, int, int);
extern char D_004C7080[];
extern void func_00103E00(int);
extern volatile int D_004399A8;
extern char D_004C6E80[];
extern void func_0010E9A8(void);
typedef struct {
    char pad[0x24];
    int f24;
} S7080;
typedef struct {
    char b[4];
} U4;
extern int D_00438320;
extern U4 D_004C70A8;
extern int func_00106C98(void *, unsigned, int);

int func_0010B198(void) {
    int r;
    int i;

    if (D_00438320 < 0) {
        for (;;) {
            r = func_00106C98(D_004C7080, 0x80000006, 0);
            if (r < 0) {
                return -1;
            }
            if (((S7080 *)D_004C7080)->f24 != 0) {
                D_00438320 = 0;
                r = func_00106E68(D_004C7080, 0xFF, 0, 0, 0, D_004C6E80, 4, 0, 0);
                if (r < 0) {
                    return 0xFFFEFFFF;
                }
                D_004C70A8 = *(U4 *)D_004C6E80;
                return 0;
            }
            i = 0x100000;
            do {
                i--;
                asm volatile ("nop");
            } while (i != -1);
        }
    }
    return 0;
}

extern int D_00439990;
extern int D_0043999C;
extern int D_004399B8;
extern int D_004C8650;
extern char D_004C8658[];
extern char D_004AB458[];
extern char D_004AB480[];
extern char D_0043AB50[];
extern int func_00103E30(int);
extern void func_00103CE0(int, void *);
extern int func_0010F148(int);
extern void func_00106628(int);

int func_0010EF40(int a0) {
    int i;
    char *p;
    int r;

    func_0010E9A8();
    if (D_004399A8 != func_00103E30(D_004399A8)) {
        if (D_00439990 > 0) {
            func_00105E80(D_004AB458, a0, D_0043999C);
        }
        return 0;
    }
    D_0043999C = a0;
    func_00103CE0(D_004C8650, D_004C8658);
    if (func_0010F148(1) != 0) {
        func_00103E00(D_004399A8);
        return 0;
    }
    func_00106628(0);
    if (D_004399B8 < 0) {
        for (;;) {
            p = D_0043AB50;
            r = func_00106C98(p, 0x80000595, 0);
            if (r < 0) {
                if (D_00439990 > 0) {
                    func_00105E80(D_004AB480);
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
        D_004399B8 = 0;
    }
    return 1;
}
