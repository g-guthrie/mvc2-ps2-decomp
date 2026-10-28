typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef signed int s32;

extern u8 D_004D18E6;

void func_002DDBB0(u8 *p)
{
    extern s32 func_00174170(void);
    extern s32 func_001841C0(u8 *);
    extern void func_001D2C00(u8 *, s32);
    extern void func_001757E0(u8 *, s32, u8);
    u32 r;
    u32 t = p[6];
    p[6] = t + 1;
    switch (p[0x20]) {
    case 0:
        p[0x21] = ((u32)func_00174170() & 0xF) % 3;
        if (D_004D18E6 == 0) {
            p[0x20] = 2;
            r = 0;
            p[0x21] = 0;
        } else if (func_001841C0(p) > 1) {
            r = 0;
            p[0x20] = 2;
            p[0x21] = 0;
        } else {
            r = p[0x21] & 1;
            if (p[0x21] != 2) {
                p[0x33A] = 0xFF;
                func_001D2C00(p, p[0x21]);
            }
        }
        break;
    case 2:
        p[0x21] = 0;
        r = 0;
        break;
    case 1:
    case 3:
    case 4:
        r = 3;
        break;
    default:
        break;
    }
    func_001757E0(p, 0x13, (u8)r);
}
