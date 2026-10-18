typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s8 *D_004C2840;
extern u16 D_004C291C;
extern u16 D_004C291E;
extern u16 D_004F25B8[];
extern u16 D_004F2B70[];
extern s8 D_00583BC8[];
extern void (*D_0045E310[])(void);

void func_0032C880(void)
{
    extern void func_0016E960(void);
    extern void func_003DA6F0(s32);
    extern void func_003D7310(void (*)(void));
    extern void func_00152570(void);
    extern void func_00152660(void);
    s8 *g;
    s8 *q;
    D_004C291C = D_004F25B8[0];
    D_004C291E = D_004F2B70[0];
    if (D_00583BC8[0] != 0) {
        func_0016E960();
    } else {
        g = D_004C2840;
        q = g + 0x90;
        if (*q != 0) {
            D_00583BC8[0] = 1;
            g[0x88] = *q ^ 3;
            D_004C2840[0x91] = 0;
            D_004C2840[0x92] = 0;
        } else {
            D_0045E310[g[4]]();
        }
        func_003DA6F0(6);
        func_003DA6F0(8);
        func_003DA6F0(1);
    }
    if (D_004C2840[0x90] != 0) {
        if (D_004C2840[0x92] < 2) {
            func_003D7310(func_00152570);
        }
        func_003D7310(func_00152660);
    } else {
        func_003D7310(func_00152570);
    }
}
