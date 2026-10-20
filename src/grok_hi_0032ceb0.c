/* ./try.sh src/grok_hi_0032ceb0.c "-O4,p -sdatathreshold 8" */
typedef unsigned char u8;
typedef signed char s8;
typedef signed int s32;

extern s32 func_0032C180(s32);
extern void func_00123760(s32);
extern void func_001E3CE0(s32);
extern u8 D_00583B9B[];
extern s8 *D_004C2840;

void func_0032CEB0(void)
{
    if (func_0032C180(1) == 0 && D_00583B9B[0] == 2) {
        D_004C2840[4]++;
        func_00123760(2);
        func_001E3CE0(0x49);
    }
}
