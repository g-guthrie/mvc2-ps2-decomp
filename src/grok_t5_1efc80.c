typedef unsigned char u8;
typedef signed char s8;
typedef signed int s32;

extern s8 func_00175700(u8 *);
extern void func_00184540(u8 *);
extern void func_001E3710(u8 *, s32);
extern s32 func_001864A0(u8 *);
extern void func_001865B0(u8 *);

void func_001EFC80(u8 *p)
{
    u8 s = p[0x1FC];
    if (s != 2) {
        if (s != 1) {
            if (s != 0) {
                goto tail;
            }
            if (p[6] != 0) {
                func_00175700(p);
            } else if ((s8)func_00175700(p) < 0) {
                func_00184540(p);
            }
            goto tail;
        }
    }
    if ((s8)func_00175700(p) < 0) {
        func_00184540(p);
    }
    if (p[0x1FC] == 2) {
        if (p[0x15B] != 0) {
            func_001E3710(p, 22);
            p[0x15B] = 0;
        }
    }
tail:
    if (func_001864A0(p) != 0) {
        func_001865B0(p);
    }
}
