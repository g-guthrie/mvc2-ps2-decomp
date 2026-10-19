typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef float f32;

extern u8 *D_004C2840;
extern u8 D_004F2294;
extern u8 D_004F284C;
extern void func_003D3080(s32);
extern void func_001E4140(void);
extern void func_001E3CE0(s32);
extern void func_0016EE50(void);

void func_003D31A0(u8 *p)
{
    u8 *q = D_004C2840;
    if (*(s8 *)(q + 0xAA) != 0) {
        if (D_004F2294 == 0x1D || D_004F284C == 0x1D)
            return;
        if (*(s8 *)(q + 0x9C) != 0)
            return;
    }
    p[2] = 0;
    p[3] = 0;
    p[0xC] = 0;
    p[0xD] = 0;
    p[0xE] = 0;
    p[0xF] = 0;
    p[0x18] = 0;
    p[0x19] = 0;
    p[0x1A] = 0;
    *(s16 *)(p + 0x2A) = 0;
    if (*(s8 *)(D_004C2840 + 0x5C) == 0) {
        func_003D3080(1);
        func_001E4140();
    }
    func_001E3CE0(0x39);
    *(s16 *)(p + 8) = 0x4650;
    *(s16 *)(p + 0xA) = 10;
    *(f32 *)(p + 0x10) = 80.0f;
    *(f32 *)(p + 0x14) = 88.0f;
    func_0016EE50();
    if (*(s8 *)(D_004C2840 + 0x4C) == 2)
        p[0xD] = 2;
}
