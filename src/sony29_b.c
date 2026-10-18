extern int func_0010EF40(int);
extern int func_00106E68(void *, int, int, int, int, void *, int, int, int);
extern void func_00103E00(int);

extern unsigned char D_00439A00[];
extern unsigned char D_0043AB50[];
extern int D_004399A8;

int func_0010F0B0(void) {
    int r;

    if (!func_0010EF40(2)) {
        return 0;
    }

    r = func_00106E68(D_0043AB50, 0xE, 0, 0, 0, D_00439A00, 4, 0, 0);
    if (r < 0) {
        func_00103E00(D_004399A8);
        return 0;
    }

    {
        int val = *(int *) ((unsigned int) D_00439A00 | 0x20000000);
        func_00103E00(D_004399A8);
        return val;
    }
}
