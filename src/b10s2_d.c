typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern s32 D_004C22B4;
extern void func_003FDAA0(void);
extern void func_00103D00(void);
extern u32 func_001041F0(s32);

void func_003FDBA8(void) {
    D_004C22B4 = 0;
    func_003FDAA0();
}

void func_003FE170(void) {
    func_00103D00();
    __asm__ volatile("");
}



