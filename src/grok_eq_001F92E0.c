typedef unsigned char u8;
typedef signed short s16;

extern int func_00174170(void);
extern int func_001757E0(u8 *, int, int);

void func_001F92E0(u8 *p)
{
    p[6]++;
    if (p[0x20] == 2) {
        func_001757E0(p, 19, 4);
        return;
    }
    *(s16 *)(p + 0x1C) = (s16)(func_00174170() & 3);
    switch (*(s16 *)(p + 0x1C)) {
    case 0:
        func_001757E0(p, 19, 0);
        break;
    case 1:
        func_001757E0(p, 19, 1);
        break;
    case 2:
        func_001757E0(p, 19, 2);
        break;
    case 3:
        func_001757E0(p, 19, 3);
        break;
    }
}
