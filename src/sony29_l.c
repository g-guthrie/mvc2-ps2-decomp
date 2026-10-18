extern int func_0010CA20(void);
extern void func_0010CA68(void);

int func_00102BC0(volatile int *a0) {
    int status;
    int a2val;
    int s0;

    status = func_0010CA20();
    a2val = *(volatile int *) 0x1000F520;
    if (!(a2val & 0x10000)) {
        *(volatile int *) 0x1000F590 = a2val | 0x10000;
    }
    (void) *(volatile int *) 0x1000E000;
    s0 = *a0;
    *a0 = s0 & 0xFFFFFEFF;
    *(volatile int *) 0x1000F590 = a2val;
    if (status) {
        func_0010CA68();
    }
    return s0;
}
