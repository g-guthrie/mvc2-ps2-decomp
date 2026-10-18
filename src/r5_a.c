typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern void func_003DAC50(void *, s32);
extern char D_0062C530[], D_0062C700[], D_0062C660[], D_0062C640[];

void func_003ED880(void) {
    func_003DAC50(D_0062C530, 0x104);
    func_003DAC50(D_0062C700, 0xA0);
    func_003DAC50(D_0062C660, 0xA0);
    func_003DAC50(D_0062C640, 0x20);
}
