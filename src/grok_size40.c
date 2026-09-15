typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;

extern s8 func_00175700(u8 *);
extern void func_001843A0(u8 *);
extern void func_00184540(u8 *);
extern int func_00210B90(u8 *);
extern int func_00210BF0(u8 *);
extern int func_0023F4C0(u8 *);
extern int func_0023F520(u8 *);
extern int func_00248890(u8 *);
extern int func_002488F0(u8 *);
extern int func_0026B530(u8 *);
extern int func_0026B590(u8 *);
extern int func_0026F4A0(u8 *);
extern int func_0026F520(u8 *);
extern int func_00273CB0(u8 *);
extern int func_00273D10(u8 *);
extern int func_003052D0(u8 *);
extern int func_00305330(u8 *);
extern int func_0031B8A0(u8 *);
extern int func_0031B900(u8 *);
extern int func_00322870(u8 *);
extern int func_003228E0(u8 *);
extern void func_00347190(u8 *);
extern void func_0036A8B0(u8 *);
extern void func_0036A8A0(u8 *);
extern void func_0036A600(u8 *);
extern void func_00398540(u8 *);

int func_00210B50(u8 *p) {
    if (func_00210B90(p))
        return 1;
    return func_00210BF0(p) != 0;
}

int func_0023F480(u8 *p) {
    if (func_0023F4C0(p))
        return 1;
    return func_0023F520(p) != 0;
}

int func_00248850(u8 *p) {
    if (func_00248890(p))
        return 1;
    return func_002488F0(p) != 0;
}

int func_0026B4F0(u8 *p) {
    if (func_0026B590(p))
        return 1;
    return func_0026B530(p) != 0;
}

int func_0026F460(u8 *p) {
    if (func_0026F4A0(p))
        return 1;
    return func_0026F520(p) != 0;
}

int func_00273C70(u8 *p) {
    if (func_00273CB0(p))
        return 1;
    return func_00273D10(p) != 0;
}

int func_00305390(u8 *p) {
    if (func_003052D0(p))
        return 1;
    return func_00305330(p) != 0;
}

int func_0031B860(u8 *p) {
    if (func_0031B8A0(p))
        return 1;
    return func_0031B900(p) != 0;
}

int func_00322830(u8 *p) {
    if (func_00322870(p))
        return 1;
    return func_003228E0(p) != 0;
}

void func_001FD3F0(u8 *p) {
    if ((signed char)func_00175700(p) < 0) {
        func_001843A0(p);
        return;
    }
}

void func_0022DA10(u8 *p) {
    if ((signed char)func_00175700(p) < 0) {
        func_001843A0(p);
        return;
    }
}

void func_0022DA50(u8 *p) {
    if ((signed char)func_00175700(p) < 0) {
        func_001843A0(p);
        return;
    }
}

void func_00249BB0(u8 *p) {
    if ((signed char)func_00175700(p) < 0) {
        func_00184540(p);
        return;
    }
}

void func_002760B0(u8 *p) {
    if ((signed char)func_00175700(p) < 0) {
        func_001843A0(p);
        return;
    }
}

void func_0028EFA0(u8 *p) {
    if ((signed char)func_00175700(p) < 0) {
        func_001843A0(p);
        return;
    }
}

void func_0028F210(u8 *p) {
    if ((signed char)func_00175700(p) < 0) {
        func_00184540(p);
        return;
    }
}

void func_00294830(u8 *p) {
    if ((signed char)func_00175700(p) < 0) {
        func_001843A0(p);
        return;
    }
}

void func_00347150(u8 *p) {
    if ((signed char)func_00175700(p) < 0) {
        func_00347190(p);
        return;
    }
}

void func_003692E0(u8 *p) {
    if ((signed char)func_00175700(p) < 0) {
        func_0036A8B0(p);
        return;
    }
}

void func_003696F0(u8 *p) {
    if ((signed char)func_00175700(p) < 0) {
        func_0036A8A0(p);
        return;
    }
}

void func_0036A5B0(u8 *p) {
    if ((signed char)func_00175700(p) < 0) {
        func_0036A600(p);
        return;
    }
}

void func_00398500(u8 *p) {
    if ((signed char)func_00175700(p) < 0) {
        func_00398540(p);
        return;
    }
}

void func_001C4760(u8 *p) {
    if ((s8)func_00175700(p) < 0) {
        p[6] = 1;
        p[7] = 0;
    }
}

void func_00269B40(u8 *p) {
    if ((s8)func_00175700(p) < 0) {
        p[6] = 8;
        p[7] = 0;
    }
}

void func_0035BE30(u8 *p) {
    if ((s8)func_00175700(p) < 0) {
        p[4] = 3;
        p[316] = 0;
    }
}

void func_0016CA30(u8 *p) {
    if (--*(s16 *)(p + 28) == 0) {
        p[4]++;
        *(s16 *)(p + 28) = 120;
    }
}

void func_0016CA70(u8 *p) {
    if (--*(s16 *)(p + 28) == 0) {
        p[4]++;
        *(s16 *)(p + 28) = 16;
    }
}

void func_001BD9D0(u8 *p) {
    if (--*(s16 *)(p + 28) == 0) {
        p[5]++;
        *(s16 *)(p + 28) = 10;
    }
}
