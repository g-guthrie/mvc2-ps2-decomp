typedef unsigned char u8;

extern int func_001841C0(u8 *);
extern int func_00174170(void);
extern int func_001757E0(u8 *, int, int);
extern void func_001B3E30(u8 *, int, int);

void func_002648F0(u8 *p)
{
    p[6] = 1;
    if (func_001841C0(p) >= 2) {
        if (func_00174170() & 1)
            func_001757E0(p, 0x13, 4);
        else
            func_001757E0(p, 0x13, 5);
    } else {
        switch (func_00174170() & 3) {
        case 0:
            func_001757E0(p, 0x13, 0);
            func_001B3E30(p, 0x13, 5);
            break;
        case 1:
            func_001757E0(p, 0x13, 2);
            func_001B3E30(p, 0x14, 0xA);
            break;
        case 2:
            func_001757E0(p, 0x13, 4);
            break;
        case 3:
            func_001757E0(p, 0x13, 5);
            break;
        }
    }
}
