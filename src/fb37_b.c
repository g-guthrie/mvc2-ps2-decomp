typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 D_004404A0[];
extern u8 D_004404C0[];
extern s32 D_004C2830;

void func_0013C110(u8 *a)
{
    u8 *c;
    u8 *r;
    f32 *t;
    s8 i;
    extern u8 *func_003DA750(s32, s32, s32);
    extern void func_0013C7A0(void);
    extern void func_0013C7E0(void);
    extern void func_0032D390(u8 *, s32, int, int, f32, f32);
    extern void func_0032D4E0(u8 *, s32, f32, int);
    extern void func_001E3CE0(s32);

    if ((r = func_003DA750(0, 6, 1)) == 0)
        return;
    *(s32 *)(r + 0x18) = (s32)a;
    *(s32 *)(r + 0x10) = (s32)func_0013C7A0;
    *(s32 *)(r + 0x34) = 0;
    *(f32 *)(r + 0x38) = 190.0f;
    *(s32 *)(r + 0x3C) = 0;
    *(s32 *)(r + 0x40) = 0;
    *(s32 *)(r + 0x44) = 0;
    *(s32 *)(r + 0x48) = 0;
    *(s32 *)(r + 0xD0) = 0x809;
    *(s16 *)(r + 0xCC) = 0x82;
    *(s32 *)(r + 0x84) = D_004C2830;
    r[0x13C] = 0;
    for (i = 0; i < 3; i++) {
        if ((c = func_003DA750(0, 6, 1)) == 0)
            return;
        *(s32 *)(c + 0x18) = (s32)a;
        *(s32 *)(c + 0x14) = (s32)r;
        *(s32 *)(c + 0xC8) = (s32)(r + 0x88);
        c[0x13C] = 1;
        *(s32 *)(c + 0x10) = (s32)func_0013C7E0;
        c[0x20] = i;
        t = (f32 *)(D_004404A0 + i * 8);
        *(f32 *)(c + 0x34) = 5.0f * t[0];
        if (i & 1)
            *(s32 *)(c + 0x38) = 0;
        else
            *(f32 *)(c + 0x38) = 2.0f * t[1];
        *(f32 *)(c + 0x3C) = 1150.0f;
        *(s16 *)(c + 0x1C) = 30;
        func_0032D390(c, *(s16 *)(c + 0x1C), 2, 2, t[0], t[1]);
        func_0032D4E0(c, *(s16 *)(c + 0x1C), 230.0f, 2);
        *(s32 *)(c + 0x40) = *(s32 *)(D_004404C0 + i * 8);
        *(s32 *)(c + 0x48) = *(s32 *)(D_004404C0 + i * 8 + 4);
        *(s32 *)(c + 0x44) = 0;
        *(f32 *)(c + 0x74) = 0.2f;
        *(s16 *)(c + 0xCC) = 0x82;
        *(s32 *)(c + 0x84) = D_004C2830;
        *(s16 *)(c + 0x1E) = 4;
        c[0x22] = 0;
        c[0x23] = 0;
        *(f32 *)(c + 0x50) = 1.0f;
        *(f32 *)(c + 0x54) = 1.0f;
        *(f32 *)(c + 0x58) = 1.0f;
        *(s32 *)(c + 0xD0) = 0x83F;
    }
    func_001E3CE0(0x39);
}
