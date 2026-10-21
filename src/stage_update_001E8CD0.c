typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;
typedef float f32;

extern void func_00326700(void);
extern void func_0016CDF0(f32);
extern void func_003DA6F0(u8);
extern void func_001237A0(void);
extern void func_001E87D0(void);
extern void func_001E8890(void);
extern void func_003D0F70(void);
extern void func_003268B0(void);
extern void func_00128380(void);
extern s32 func_001E8EB0(void);
extern void func_0016D190(void);
extern u8 D_004D18A6 __attribute__((section(".bss")));
extern u16 D_004D18DC __attribute__((section(".bss")));
extern u8 D_004D18DB __attribute__((section(".bss")));

void func_001E8CD0(void)
{
    func_00326700();
    if (D_004D18A6 == 0) {
        func_0016CDF0(1.0f);
        if ((D_004D18DC & (1u << D_004D18DB)) == 0) {
            func_003DA6F0(3);
            func_003DA6F0(4);
            func_003DA6F0(1);
            func_003DA6F0(2);
        }
    } else {
        func_0016CDF0(0.5f);
        if ((D_004D18DC & (1u << D_004D18DB)) == 0) {
            func_003DA6F0(4);
            func_003DA6F0(2);
        }
    }
    if ((D_004D18DC & (1u << D_004D18DB)) == 0)
        func_001237A0();
    if (D_004D18A6 == 0) {
        func_003DA6F0(6);
        func_003DA6F0(7);
        func_003DA6F0(12);
        func_003DA6F0(8);
        func_003DA6F0(9);
        func_003DA6F0(10);
        func_003DA6F0(0x5B);
        func_003DA6F0(11);
        func_003DA6F0(5);
        func_003DA6F0(17);
        func_001E87D0();
        func_001E8890();
        func_003D0F70();
    } else {
        func_003DA6F0(7);
        func_003DA6F0(9);
        func_003DA6F0(10);
        func_001E8890();
    }
    func_003268B0();
    func_00128380();
    D_004D18A6 = (u8)func_001E8EB0();
    func_003DA6F0(13);
    func_003DA6F0(15);
    func_003DA6F0(14);
    func_003DA6F0(18);
    func_0016D190();
}
