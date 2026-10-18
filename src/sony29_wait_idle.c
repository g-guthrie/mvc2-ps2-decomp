extern volatile int D_00439990, D_004399B0;
extern char D_0043AB50[];
extern char gCdDvdDiagnostic_004AB498[];
extern void func_00105E80(void *, ...);
extern int func_00107058(void *);
extern void func_0010E608(unsigned short);

int func_0010F148(int mode)
{
    if (mode == 0) {
        if (D_00439990 > 0)
            func_00105E80(gCdDvdDiagnostic_004AB498);
        while (D_004399B0 || func_00107058(D_0043AB50))
            func_0010E608(60);
        return 0;
    }
    if (D_004399B0 || func_00107058(D_0043AB50))
        return 1;
    return 0;
}
