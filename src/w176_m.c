typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0xAF]; s8 bAF; } G2840;
extern G2840 *D_004C2840;
extern u16 D_004F25A0[];
extern s16 D_004F2B58[];
extern u16 D_004F2406[], D_004F2404[], D_004F29BE[], D_004F29BC[];

void func_003D82A0(u8 *p) {
    extern void func_00135150(s32);
    extern void func_00126400(void);
    extern void func_001E4150(void);
    extern void func_001E4340(s32);
    extern void func_001E3F50(s32);
    extern void func_001E3FE0(void);
    s16 h;
    u16 a3, a2;
    if (*(s16 *)(p + 0x12) == 0x3C) func_00135150(1);
    h = *(s16 *)(p + 0x12) - 1;
    *(s16 *)(p + 0x12) = h;
    if (h > 0) return;
    func_00126400();
    a3 = D_004F25A0[0] & 0xBFF0;
    a2 = D_004F2B58[0] & 0xBFF0;
    D_004F2406[0] = a3;
    D_004F2404[0] = a3;
    D_004F29BE[0] = a2;
    D_004F29BC[0] = a2;
    p[1] = 9;
    *(s16 *)(p + 0x12) = 0x3C;
    p[0x3F] = 0;
    p[0] = 4;
    if (p[0x45] != 0 && p[0x48] == 8 && D_004C2840->bAF != 0) {
        func_001E4150();
        func_001E4340(1);
        if (p[0x45] == 1) {
            func_001E3F50(0x11);
        } else {
            func_001E3F50(0x12);
        }
        func_001E3FE0();
    }
}
