typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

extern s32 func_00175700(u8 *);
extern void func_001843A0(u8 *);
extern void func_00385A20(u8 *);
extern void func_001C09A0(u8 *, s32);

void func_002876B0(u8 *p)
{
    if ((s8)func_00175700(p) < 0) {
        func_001843A0(p);
        return;
    }
    if (p[0x1FC] != 0) {
        if (p[0x1FC] == 1) {
            if (*(s8 *)(p + 0x151)) {
                p[0x151] = 0;
                func_00385A20(p);
                func_001C09A0(p, 1);
            }
        } else if (p[0x1FC] == 2) {
            if (*(s8 *)(p + 0x151)) {
                p[0x151] = 0;
                if (*(s16 *)(p + 0x140) == 0) {
                    *(s32 *)(p + 0x5C) = 0xC0A00000;
                    *(s32 *)(p + 0x68) = 0x3EA00000;
                } else {
                    *(s32 *)(p + 0x5C) = 0x40A00000;
                    *(s32 *)(p + 0x68) = 0xBEA00000;
                }
            }
        }
    }
}
