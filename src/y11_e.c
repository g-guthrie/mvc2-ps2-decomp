typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;


extern u8 D_0061BEE0[];
extern u8 D_0061C6E0[];
extern u8 D_0061BE20[];
extern u8 D_0061C760[];
extern u8 D_0061BE60[];
extern u8 D_0061BEA0[];
extern s32 D_0062BC00;
void func_003DD4E0(s32 idx, s32 a, s32 b, s32 c, s32 d) {
    extern void func_003DD5D0();
    extern void func_003DD440();
    extern void func_003DE160();
    extern void func_003E00D0();
    func_003DD5D0(D_0061BEE0 + idx * 64);
    func_003DD440(D_0061C6E0);
    func_003DE160(D_0061BE20, D_0061C6E0, D_0061C760);
    func_003DE160(D_0061BE60, D_0061C6E0, D_0061BEA0);
    if (D_0062BC00 == 0) {
        b = b / 2;
        d = d / 2;
    }
    func_003E00D0(a, b, c, d, 0);
}
