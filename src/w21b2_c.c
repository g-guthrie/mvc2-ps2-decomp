typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern s32 D_004C24E4;
extern u32 D_004C24E8;
extern u8 *D_004C24EC;
extern u32 D_004C24F0;
extern s32 D_004C24F4;
extern s32 D_004C24F8;
extern u8 D_00495E38[];
extern char D_004BEA90[];
extern char D_004BEAC0[];

void func_00410F80(void)
{
    extern void func_0011D8F8(u8 *, s32, s32);
    extern void func_004095C8();
    extern u8 *func_0010ACD0(s32);
    extern s32 func_0011EB60();
    extern s32 func_00409250(s32, u32, u32, s32);
    extern void func_00409450(s32, void *, s32);
    extern void func_00409460(s32, void *, s32);
    extern void func_00409708(s32, s32, s32, s32, s32);
    extern void func_00410C18();
    extern void func_00410CB8();
    u8 *buf;
    u32 sz;
    if (D_004C24E4 == 0) {
        buf = D_00495E38;
        func_0011D8F8(buf, 0, 0x8D0);
        buf += 0x40;
        func_004095C8();
        D_004C24E8 = (u32)buf & -0x40;
        D_004C24F8 = 0x880;
        if (D_004C24EC == 0) {
            D_004C24EC = func_0010ACD0(0x8D0);
            if (D_004C24EC == 0) {
                func_0011EB60(D_004BEA90);
                for (;;) __asm__ volatile("nop");
            }
        }
        sz = ((u32)D_004C24EC + 0x40) & -0x40;
        D_004C24F0 = sz;
        D_004C24F4 = func_00409250(0, D_004C24E8, sz, D_004C24F8);
        if (D_004C24F4 == 0) {
            func_0011EB60(D_004BEAC0);
            for (;;) __asm__ volatile("nop");
        }
        func_00409450(D_004C24F4, func_00410C18, 0);
        func_00409460(D_004C24F4, func_00410CB8, 0);
        func_00409708(3, 0, 0, 0, 0);
    }
    D_004C24E4++;
}
