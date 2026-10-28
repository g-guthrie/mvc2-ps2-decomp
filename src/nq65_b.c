typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s8 D_004F7F50[];
extern s8 D_004F7F30[];
extern u8 D_004F7D10[];

s32 func_003D69A0(void)
{
    extern void func_003D3E10(s8 *);
    extern void func_003D5090(s8 *);
    extern void func_003D6530(s8 *, u8 *);
    extern void func_003CE560();
    extern void func_003CE6D0();
    extern void func_003CE780();
    extern void func_003D6340(s8 *, s8 *);
    extern void func_003DA6F0(s32);
    extern s32 func_003D44E0(s8 *);
    s8 *a = D_004F7F50;
    s8 *b = D_004F7F30;

    if (D_004F7F50[0] & 4) {
        func_003D3E10(a);
        return;
    }
    if (a[0x19] == 1) {
        func_003D5090(a);
        return;
    }
    if (a[0x19] == 2) {
        func_003D6530(a, D_004F7D10);
        return;
    }
    if (b[0xE] != 0) {
        switch (b[0x1C]) {
        case 0:
            b[0x1C] = 1;
            func_003CE560();
            b[0x1B] = 0;
            b[0x1A] = 0;
            break;
        case 1:
            b[0x1C] = 2;
            func_003CE6D0();
            func_003CE780();
            break;
        }
        func_003D6340(a, b);
        func_003DA6F0(0x10);
        return;
    }
    if (a[0] & 3) {
        return func_003D44E0(a);
    }
}
