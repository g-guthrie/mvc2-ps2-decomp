typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
extern u8 D_004F1F45, D_004F1F46;
extern s32 func_00175700(u8 *);
extern void func_001E3A10(u8 *);
extern void func_00163D70(u8 *);
extern s32 func_001757E0(u8 *, s32, s32);
extern s32 func_001864A0(u8 *);
extern void func_0017D840(u8 *);
void func_0017F750(u8 *p)
{
    func_00175700(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (*(s8 *)(p + 0x211) != 0 && p[0x24C] == 0) {
        p[0x24C] = 1;
        func_001E3A10(p);
        func_00163D70(p);
        if (p[0x249] != 0) {
            D_004F1F45 = p[0x21B] < 5 ? 1 : 3;
            D_004F1F46 = 1;
        }
    }
    if (*(s16 *)(p + 0x1C) == 0 && *(f32 *)(p + 0x60) <= 0.0f) {
        func_001757E0(p, 13, 29);
        *(s16 *)(p + 0x1C) = 1;
    }
    if (p[0x247] != 2) {
        s8 timer = *(s8 *)(p + 0x24D) - 1;
        *(s8 *)(p + 0x24D) = timer;
        if (timer < 0 && *(s16 *)(p + 0x434) != 0) {
            p[6] = 3;
            *(s8 *)(p + 0x1EA) = -1;
            p[0x210] = 1;
            func_001757E0(p, 13, 30);
            func_0017D840(p);
            return;
        }
    }
    if (*(f32 *)(p + 0x60) <= 0.0f && func_001864A0(p) != 0) {
        p[0x1FF] = 2;
        *(s16 *)(p + 0x28C) = 5;
        p[6]++;
        p[0x20D] = 3;
        func_001757E0(p, 13, 26);
    }
}
