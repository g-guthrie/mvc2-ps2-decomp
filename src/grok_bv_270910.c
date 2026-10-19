typedef unsigned char u8;
typedef signed short s16;
typedef signed int s32;

extern u8 D_004D18E6;
extern s32 func_00174170(void);
extern s32 func_001841C0(u8 *);
extern void func_001757E0(u8 *, s32, s32);

void residual_00270910(u8 *p)
{
    p[6]++;
    if (p[0x20] == 2) {
        p[6] = 2;
        func_001757E0(p, 0x13, 1);
        return;
    }
    if (D_004D18E6)
        *(s16 *)(p + 0x1C) = func_00174170() & 1;
    else
        *(s16 *)(p + 0x1C) = 1;
    if (func_001841C0(p) >= 2)
        *(s16 *)(p + 0x1C) = 1;
    switch (*(s16 *)(p + 0x1C)) {
    case 0:
        p[6] = 1;
        func_001757E0(p, 0x13, 0);
        break;
    case 1:
        p[6] = 2;
        func_001757E0(p, 0x13, 1);
        break;
    case 2:
        break;
    }
}
