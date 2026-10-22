typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef void (*FN)(s32);
extern u8 *D_004C25D4;
extern u8 *D_004C25D0;
extern s8 D_004F1F41[];
extern s8 D_004F1F42[];
extern s8 D_004F1F43[];
extern s8 D_004F1F44[];
extern FN D_0043CB70[];
extern FN D_0043CBB0[];

void func_00126780(void)
{
    extern void func_001258A0(s32);
    extern void func_00125A80(s32);
    extern void func_00125AF0(s32);
    extern void func_00125C20(s32);
    extern void func_00125C90(s32);
    u32 x;
    if ((D_004C25D4[0x25C] | D_004C25D0[0x25C]) != 0) {
        if (D_004F1F41[0] == 1) {
            D_0043CB70[1](8);
        } else {
            D_0043CB70[D_004F1F43[0]](8);
        }
        D_0043CBB0[D_004F1F44[0]](8);
        return;
    }
    if (D_004C25D4[0x2B3] != 0) {
        func_001258A0(2);
        D_0043CBB0[0](2);
        return;
    }
    if (D_004C25D0[0x2B3] != 0) {
        func_001258A0(2);
        D_0043CBB0[0](2);
        return;
    }
    x = D_004C25D4[0x249];
    if ((x | D_004C25D0[0x249]) != 0) {
        s32 p = *(s8 *)(D_004C25D4 + 0x1B4);
        s32 q = *(s8 *)(D_004C25D0 + 0x1B4);
        if (p != q) {
            if (x != 0) {
                func_00125A80(2);
                func_00125AF0(4);
            } else {
                func_00125C20(2);
                func_00125C90(4);
            }
            return;
        }
        if (p == 0 && q == 0) {
            if (x != 0) {
                func_00125A80(2);
                func_00125AF0(4);
            } else {
                func_00125C20(2);
                func_00125C90(4);
            }
            return;
        }
    }
    D_0043CB70[D_004F1F41[0]](8);
    D_0043CBB0[D_004F1F42[0]](8);
}
