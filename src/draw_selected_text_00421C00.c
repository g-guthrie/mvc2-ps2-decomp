typedef signed char s8;
typedef signed int s32;
typedef unsigned char u8;

extern s32 D_004C2B84;
extern s32 D_004D17CC __attribute__((section(".bss")));
extern u8 D_004AA160[];
extern u8 D_004AA1C8[];
extern u8 D_004AA240[];
extern u8 D_004AA2A8[];
extern int func_004220B0(float scale, void *data, s32 zero, s32 mode);
extern void func_004212D0(s32 value);

void func_00421C00(void)
{
    if (D_004C2B84 < 100) {
        D_004AA1C8[0] = *(s8 *)&D_004D17CC + 17;
        func_004220B0(0.090000003576278687f, D_004AA160, 0, 2);
    } else {
        D_004AA2A8[0] = *(s8 *)&D_004D17CC + 17;
        func_004220B0(0.090000003576278687f, D_004AA240, 0, 2);
    }
    func_004212D0(0x15C);
}
