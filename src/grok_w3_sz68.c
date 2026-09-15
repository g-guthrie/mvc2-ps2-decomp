typedef unsigned char u8;
typedef signed char s8;

extern s8 func_00175700(u8 *);
extern void func_001843A0(u8 *);

#define CHECK_012 \
    { \
        switch (p[508]) { \
        case 0: \
        case 1: \
        case 2: \
            if ((s8)func_00175700(p) < 0) { \
                func_001843A0(p); \
            } \
            break; \
        default: \
            break; \
        } \
    }

#define CHECK_201 \
    { \
        switch (p[508]) { \
        case 2: \
        case 0: \
        case 1: \
            if ((s8)func_00175700(p) < 0) { \
                func_001843A0(p); \
            } \
            break; \
        default: \
            break; \
        } \
    }

void func_00204990(u8 *p) { CHECK_012 }
void func_00209780(u8 *p) { CHECK_012 }
void func_0023AE90(u8 *p) { CHECK_012 }
void func_0023B070(u8 *p) { CHECK_012 }
void func_00244AD0(u8 *p) { CHECK_012 }
void func_0024EB50(u8 *p) { CHECK_012 }
void func_0024ECB0(u8 *p) { CHECK_012 }
void func_0025D6D0(u8 *p) { CHECK_012 }
void func_00274B90(u8 *p) { CHECK_012 }
void func_002825A0(u8 *p) { CHECK_012 }
void func_00282610(u8 *p) { CHECK_012 }
void func_0028EFE0(u8 *p) { CHECK_012 }
void func_0029C9A0(u8 *p) { CHECK_012 }
void func_002A1FA0(u8 *p) { CHECK_012 }
void func_002A20F0(u8 *p) { CHECK_012 }
void func_002A8270(u8 *p) { CHECK_012 }
void func_002A82E0(u8 *p) { CHECK_012 }
void func_002A85A0(u8 *p) { CHECK_012 }
void func_002B3C00(u8 *p) { CHECK_012 }
void func_002B94D0(u8 *p) { CHECK_012 }
void func_002B9540(u8 *p) { CHECK_012 }
void func_002B95B0(u8 *p) { CHECK_012 }
void func_002B9620(u8 *p) { CHECK_012 }
void func_002CCE00(u8 *p) { CHECK_012 }
void func_002F8100(u8 *p) { CHECK_012 }
void func_002F8170(u8 *p) { CHECK_012 }
void func_002FD2D0(u8 *p) { CHECK_012 }
void func_002FD340(u8 *p) { CHECK_012 }
void func_002FD3B0(u8 *p) { CHECK_012 }
void func_00310AE0(u8 *p) { CHECK_012 }

void func_0025D550(u8 *p) { CHECK_201 }
void func_0025D740(u8 *p) { CHECK_201 }
void func_002B3A40(u8 *p) { CHECK_201 }
void func_002B3AB0(u8 *p) { CHECK_201 }
