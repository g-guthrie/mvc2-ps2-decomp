typedef unsigned char u8;
typedef signed char s8;

extern void func_003FB128(char *s);
extern void func_00403A70(void);
extern void func_004035D8(void);
extern void func_00403900(void);
extern void func_00403B20(void);
extern void func_00403D28(void);
extern void func_004040F0(u8 *p);
extern void func_00404070(u8 *p);
extern char D_004BC818[];

void func_00404178(u8 *p)
{
    if (p == 0) {
        func_003FB128(D_004BC818);
        return;
    }
    switch ((s8)p[1]) {
    case 3:
        func_00403A70();
        break;
    case 1:
        func_004035D8();
        break;
    case 2:
        func_00403900();
        break;
    case 4:
        func_00403B20();
        break;
    case 5:
        func_00403D28();
        break;
    }
    func_004040F0(p);
    func_00404070(p);
}
