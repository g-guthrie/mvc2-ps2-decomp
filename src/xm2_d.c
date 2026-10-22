extern void func_00105E80(void *context, ...);
extern int func_00106E68(void *, int, int, void *, int, void *, int, int, int);
extern void func_00103E00(int);
extern volatile int D_004399A8;
extern void func_0010E9A8(void);
typedef struct {
    char pad[0x24];
    int f24;
} S8840;
typedef struct {
    char b[0x24];
} S24;
typedef struct {
    char pad[0x24];
    char name[0x100];
    int f124;
    int f128;
} S86C0;

extern int D_00439990;
extern int D_0043999C;
extern int D_004399C0;
extern int D_004C8650;
extern char D_004C8658[];
extern char D_004AB3E8[];
extern char D_004AB408[];
extern char D_004C86E4[];
extern char D_004AB420[];
extern char D_004AB430[];
extern char D_004AB440[];
extern S8840 D_004C8840;
extern S86C0 D_004C86C0;
extern char D_004C8800[];
extern int func_00103E30(int);
extern void func_00103CE0(int, void *);
extern int func_0010F148(int);
extern void func_00106628(int);
extern int func_00106C98(void *, unsigned, int);
extern void func_00106578(void *, int);

int func_0010EC08(S24 *out, unsigned char *name, int arg)
{
    int i;
    int d;
    int r;
    S86C0 *b;
    S8840 *p;
    int res;

    func_0010E9A8();
    if (D_004399A8 != func_00103E30(D_004399A8)) {
        return 0;
    }
    D_0043999C = 1;
    func_00103CE0(D_004C8650, D_004C8658);
    if (func_0010F148(1) != 0) {
        func_00103E00(D_004399A8);
        return 0;
    }
    func_00106628(0);
    if (D_004399C0 < 0) {
        for (;;) {
            p = &D_004C8840;
            r = func_00106C98(p, 0x80000597, 0);
            if (r < 0) {
                if (D_00439990 > 0) {
                    func_00105E80(D_004AB3E8);
                }
                d = 0x100000;
                do {
                    d--;
                    asm volatile ("nop");
                } while (d != -1);
            } else {
                if (p->f24 != 0) {
                    D_004399C0 = 0;
                    break;
                }
                d = 0x100000;
                do {
                    d--;
                    asm volatile ("nop");
                } while (d != -1);
            }
        }
    }
    for (i = 0; i < 0x100; i++) {
        if ((D_004C86C0.name[i] = name[i]) == 0) break;
    }
    if (i == 0x100) {
        D_004C86C0.name[0xFF] = 0;
    }
    if (D_00439990 > 0) {
        func_00105E80(D_004AB408, D_004C86E4);
    }
    b = &D_004C86C0;
    b->f124 = (int)b;
    b->f128 = arg;
    func_00106578(b, 0x12C);
    r = func_00106E68(&D_004C8840, 0, 0, b, 0x12C, D_004C8800, 4, 0, 0);
    if (r < 0) {
        func_00103E00(D_004399A8);
        return 0;
    }
    *out = *(S24 *)((unsigned)b | 0x20000000);
    if (D_00439990 > 0) {
        func_00105E80(D_004AB420, (char *)out + 8);
        if (D_00439990 > 0) {
            func_00105E80(D_004AB430, *(int *)((char *)out + 4));
            if (D_00439990 > 0) {
                func_00105E80(D_004AB440, *(int *)out);
            }
        }
    }
    res = *(int *)((unsigned)D_004C8800 | 0x20000000);
    func_00103E00(D_004399A8);
    return res;
}
