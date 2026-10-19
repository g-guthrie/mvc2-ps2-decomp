typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef float f32;

extern s8 *D_004C2840;
extern u8 D_004F2294;
extern u8 D_004F284C;
extern void func_003D3080(s32);
extern void func_001E4140(void);
extern void func_001E3CE0(s32);
extern void func_0016EE50(void);

void func_003D31A0(u8 *s0)
{
    if (D_004C2840[0xAA]) {
        if (D_004F2294 == 0x1D || D_004F284C == 0x1D)
            return;
        if (D_004C2840[0x9C])
            return;
    }
    s0[2] = 0;
    s0[3] = 0;
    s0[0xC] = 0;
    s0[0xD] = 0;
    s0[0xE] = 0;
    s0[0xF] = 0;
    s0[0x18] = 0;
    s0[0x19] = 0;
    s0[0x1A] = 0;
    *(s16 *)(s0 + 0x2A) = 0;
    if (D_004C2840[0x5C] == 0) {
        func_003D3080(1);
        func_001E4140();
    }
    func_001E3CE0(0x39);
    *(s16 *)(s0 + 8) = 0x4650;
    *(s16 *)(s0 + 0xA) = 10;
    *(f32 *)(s0 + 0x10) = 80.0f;
    *(f32 *)(s0 + 0x14) = 88.0f;
    func_0016EE50();
    if (D_004C2840[0x4C] == 2)
        s0[0xD] = 2;
}
