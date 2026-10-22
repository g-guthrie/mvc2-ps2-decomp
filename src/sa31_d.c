typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern u8 *D_004C2840;
extern u8 D_004F20B0[];
extern u8 D_004F2C20[];
extern u8 D_004F3790[];
extern u8 D_004F2668[];
extern u8 D_004F31D8[];
extern u8 D_004F3D48[];
extern u8 *D_004D18B8[];
extern u8 *D_004D18BC[];
extern u8 *D_004D18C0[];
extern u8 *D_004D18C4[];
extern u8 *D_004D18C8[];
extern u8 *D_004D18CC[];
extern s8 D_004D1570[];
extern s8 D_004D1370[];
extern s8 D_004F7D30[];
extern s8 D_004F25F0[];
extern s8 D_004F3160[];
extern s8 D_004F3CD0[];
extern s32 D_004F25F8[];
extern s32 D_004F25FC[];
extern u8 D_004F25EB[];
extern u8 D_004F2601[];
extern u8 D_004F2602[];
extern void func_00126D10(void);
extern void func_001E4480(s32, s32);
extern void func_001E3F50(s32);
extern void func_001E4340(s32);
extern void func_001E3FE0(void);
extern void func_003298B0(s32, s32, s32);
extern void func_0012E780(s32);

void func_001275F0(void) {
    s8 *p;
    D_004C2840[3] = 4;
    D_004C2840[0x9F] = 0;
    D_004C2840[0xB1] = (D_004C2840[0x2C] + 3) % 3;
    D_004C2840[0x8F] = (s8)D_004C2840[0xB1] & 1;
    D_004D18B8[0] = D_004F20B0;
    D_004D18BC[0] = D_004F2C20;
    D_004D18C0[0] = D_004F3790;
    D_004D18C4[0] = D_004F2668;
    D_004D18C8[0] = D_004F31D8;
    D_004D18CC[0] = D_004F3D48;
    switch ((s8)D_004C2840[0xB1]) {
    case 0:
        p = D_004D1570;
        break;
    case 1:
        p = D_004D1370;
        break;
    case 2:
        p = D_004F7D30;
        break;
    }
    D_004F25F0[0] = p[1];
    D_004F3160[0] = p[2];
    D_004F3CD0[0] = p[3];
    D_004F25F8[0] = *(s32 *)(p + 0x14);
    D_004F25FC[0] = *(s32 *)(p + 0x10);
    D_004F25EB[0] = ((u8 *)p)[8];
    D_004F2601[0] = 0;
    D_004F2602[0] = 0;
    D_004C2840[0x93] = p[1];
    func_00126D10();
    func_001E4480(6, 1);
    func_001E3F50(0x1A);
    func_001E4340(1);
    func_001E3FE0();
    func_003298B0(0xFF000000, 0x14, 0);
    func_0012E780(6);
}
