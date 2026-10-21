extern int func_0010EF40(int);
extern int func_0010F258(int);
extern int func_00106E68(void *, int, int, void *, int, void *, int, void (*)(void *), void *);
extern void func_00103E00(int);

extern unsigned char D_00439A00[];
struct SonyRpcClient;
extern struct SonyRpcClient D_0043AB50;
extern unsigned char D_0043B3C8[];
extern unsigned char D_0043AB80[];
extern int D_004399A8;
extern int D_004399AC;

int func_0010F0B0(void) {
    int r;

    if (!func_0010EF40(2)) {
        return 0;
    }

    r = func_00106E68(&D_0043AB50, 0xE, 0, 0, 0, D_00439A00, 4, 0, 0);
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

int func_0010FB48(void) {
    int r;

    if (!func_0010F258(3)) {
        return -1;
    }

    r = func_00106E68(D_0043B3C8, 4, 0, 0, 0, D_0043AB80, 4, 0, 0);
    if (r < 0) {
        func_00103E00(D_004399AC);
        return -1;
    }

    {
        int value = *(int *)((unsigned int)D_0043AB80 | 0x20000000);
        func_00103E00(D_004399AC);
        return value;
    }
}
