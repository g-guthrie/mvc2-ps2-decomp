typedef unsigned char u8;
typedef unsigned int u32;
typedef signed int s32;

extern s32 func_00174170(void);
extern void func_001757E0(u8 *, s32, s32);
extern void func_001266A0(u8 *, s32, s32);

void residual_00235180(u8 *p, u8 *q)
{
    u32 t = p[6];
    (void)q;
    p[6] = t + 1;
    switch (p[0x20]) {
    case 0:
        p[0x21] = (u8)(func_00174170() & 1);
        if (p[0x21] != 0) {
            func_001757E0(p, 0x13, 1);
            p[0x39] = 0;
            func_001266A0(p, 1, 0xD);
        } else {
            func_001757E0(p, 0x13, 0);
        }
        break;
    case 2:
        func_001757E0(p, 0x13, 2);
        break;
    case 1:
    case 3:
    case 4:
        func_001757E0(p, 0x13, 3);
        break;
    }
}
