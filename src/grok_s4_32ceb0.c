typedef unsigned char u8;
typedef signed char s8;

extern u8 D_00583B9B;
extern u8 *D_004CB5D0;
extern int func_0032C180(int);
extern void func_00123760(void);
extern void func_001E3CE0(int);

void func_0032CEB0(void)
{
    if (func_0032C180(1) == 0 && D_00583B9B == 2) {
        D_004CB5D0[4]++;
        func_00123760();
        func_001E3CE0(0x49);
    }
}
