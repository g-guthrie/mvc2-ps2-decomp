typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern void func_00175700(u8 *);
extern s32 func_001864a0(u8 *);
extern void func_0018F730(u8 *);
extern void func_001E3A10(u8 *);
extern void func_00158C70(f32 *, s32);
extern void func_00186CE0(u8 *, s32);
extern u8 D_004F1F46;
extern u8 D_004F1F45;

void func_00180090(u8 *p)
{
    func_00175700(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (func_001864a0(p) != 0) {
        u32 idx = p[0x1B5] & 0x7F;
        *(u32 *)(p + 0x1D0) = *(u32 *)(*(u8 **)(p + 0x1DC) + 0x184) + idx * 28;
        func_0018F730(p);
        *(s16 *)(p + 0x140) = p[0x1E6];
        func_001E3A10(p);
        func_00158C70((f32 *)(p + 0x34), p[2]);
        D_004F1F46 = 1;
        D_004F1F45 = 3;
        p[0x20D] = 3;
        {
            s32 forty = 0x40;
            p[0x209] = (u8)forty;
            *(s16 *)(p + 0x1FA) = (s16)forty;
        }
        p[0x1F7] = 0x64;
        func_00186CE0(p, 0x17);
    }
}
