extern void func_0010CA20(void);
extern int func_00103B20(int);
extern void func_0010CA68(void);

int func_00104928(int a0) {
    int status;
    int result;

    asm volatile ("mfc0 %0, $12" : "=r"(status));
    status = status & 0x10000;
    if (status) {
        func_0010CA20();
    }
    result = func_00103B20(a0);
    asm volatile ("sync");
    if (status) {
        func_0010CA68();
    }
    return result;
}

extern int func_00103B30(int);
extern int func_00103B40(int);
extern int func_00103B50(int);

int func_001048C0(int a0) {
    int status;
    int result;

    asm volatile ("mfc0 %0, $12" : "=r"(status));
    status = status & 0x10000;
    if (status) {
        func_0010CA20();
    }
    result = func_00103B30(a0);
    asm volatile ("sync");
    if (status) {
        func_0010CA68();
    }
    return result;
}

int func_00104990(int a0) {
    int status;
    int result;

    asm volatile ("mfc0 %0, $12" : "=r"(status));
    status = status & 0x10000;
    if (status) {
        func_0010CA20();
    }
    result = func_00103B50(a0);
    asm volatile ("sync");
    if (status) {
        func_0010CA68();
    }
    return result;
}

int func_001049F8(int a0) {
    int status;
    int result;

    asm volatile ("mfc0 %0, $12" : "=r"(status));
    status = status & 0x10000;
    if (status) {
        func_0010CA20();
    }
    result = func_00103B40(a0);
    asm volatile ("sync");
    if (status) {
        func_0010CA68();
    }
    return result;
}
