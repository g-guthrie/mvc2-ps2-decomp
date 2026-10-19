typedef unsigned char u8;
typedef signed char s8;
typedef signed int s32;

extern s8 D_004F7F50[];
extern s8 D_004F7F30[];
extern s8 D_004F7D10[];
extern void func_003D3E10(s8 *);
extern void func_003D5090(s8 *);
extern void func_003D6530(s8 *, s8 *);
extern void func_003CE560(void);
extern void func_003CE6D0(void);
extern void func_003CE780(void);
extern void func_003D6340(s8 *, s8 *);
extern void func_003DA6F0(s32);
extern void func_003D44E0(s8 *);

void func_003D69A0(void)
{
    s8 *s0 = D_004F7F50;
    s8 *s1 = D_004F7F30;
    if (s0[0] & 4) {
        func_003D3E10(s0);
        return;
    }
    if (s0[0x19] == 1) {
        func_003D5090(s0);
        return;
    }
    if (s0[0x19] == 2) {
        func_003D6530(s0, D_004F7D10);
        return;
    }
    if (s1[0xE]) {
        if (s1[0x1C] == 1) {
            s1[0x1C] = 2;
            func_003CE6D0();
            func_003CE780();
        } else if (s1[0x1C] == 0) {
            s1[0x1C] = 1;
            func_003CE560();
            s1[0x1B] = 0;
            s1[0x1A] = 0;
        }
        func_003D6340(s0, s1);
        func_003DA6F0(0x10);
        return;
    }
    if (s0[0] & 3)
        func_003D44E0(s0);
}
