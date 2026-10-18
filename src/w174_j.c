typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 D_004D18A6[];
extern u8 D_004D18EC[];
extern u8 D_004F20B0[];
extern u8 D_004F2668[];
extern u8 D_004F2C20[];
extern u8 D_004F31D8[];
extern u8 D_004F3790[];
extern u8 D_004F3D48[];

void func_00181150(void) {
    extern void func_00181280(u8 *, u8 *);
    u8 *e;
    u8 i;
    if (D_004D18A6[0] == 0) {
        D_004D18EC[0] = 0;
        func_00181280(D_004F20B0, D_004F2668);
        func_00181280(D_004F2C20, D_004F2668);
        func_00181280(D_004F3790, D_004F2668);
        func_00181280(D_004F20B0, D_004F31D8);
        func_00181280(D_004F2C20, D_004F31D8);
        func_00181280(D_004F3790, D_004F31D8);
        func_00181280(D_004F20B0, D_004F3D48);
        func_00181280(D_004F2C20, D_004F3D48);
        func_00181280(D_004F3790, D_004F3D48);
        for (i = 0; i < 6; i++) {
            e = D_004F20B0 + i * 0x5B8;
            if (e[0x209] != 0) {
                if (*(s8 *)(e + 0x1B4) == 0) {
                    e[0x209] = e[0x209] - 1;
                }
            }
        }
    }
}
