typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern u8 D_004BAD68[];
extern u8 D_004BAD88[];

s32 func_003F7D98(u8 *p, u8 *a, s32 b)
{
    s8 *p0c = (s8 *)(p + 0xC);
    s8 *p0d = (s8 *)(p + 0xD);
    s8 *p0e = (s8 *)(p + 0xE);
    s8 *p10 = (s8 *)(p + 0x10);
    s8 *p0f = (s8 *)(p + 0xF);
    s8 *p14 = (s8 *)(p + 0x14);
    s16 v10[8];
    s16 v20[8];
    s16 v30[8];
    extern s32 func_003F99F0();
    extern s32 func_003F9B70();
    extern s32 func_003F8260();
    extern void func_004043B0();
    extern s32 func_003F9AF0();
    extern s32 func_003F9BE8();
    extern void func_00404360();
    extern void func_00404388();
    extern void func_003F9D20();
    extern void func_003FB178();

    *(s16 *)(p + 2) = 1;
    if (func_003F99F0(a, b, v30, p0c, p0d, p0f, p0e, p14, p + 0x18, p10) < 0)
        return 0;
    if (*p0c >= 5) {
        if (*(s32 *)(p + 0xA4) == 0) {
            func_003FB178(D_004BAD68, D_004BAD88);
            return 0;
        }
        *p0d = 8;
        *p0f = *p0e * 192;
        *(s32 *)p10 = 0x60;
        *(s16 *)(p + 0x98) = 10;
    } else {
        s8 *p1c;
        if (func_003F9B70(a, b, (u8 *)v30 + 2, (u8 *)v30 + 3) < 0)
            return 0;
        if (func_003F8260(p, ((u8 *)v30)[2], ((u8 *)v30)[3], v30 + 2, v30 + 3, v30 + 4) < 0)
            return 0;
        p1c = (s8 *)(p + 0x1C);
        func_004043B0(*(s32 *)(p + 8), v30[2], v30[3], v30[4]);
        if (func_003F9AF0(a, b, p1c) < 0)
            return 0;
        if (func_003F9BE8(a, b, v10, v20) < 0)
            return 0;
        func_00404360(*(s32 *)(p + 8), *(s32 *)p14, *(s16 *)p1c);
        func_00404388(*(s32 *)(p + 8), v10, v20);
        func_003F9D20(a, b, p + 0x20, p + 0x24, p + 0x26, p + 0x28, p + 0x2C, p + 0x30, p + 0x34);
        *(s16 *)(p + 0x98) = 0;
    }
    *(s32 *)(p + 0x50) = ((s8 *)p)[0xE];
    *(s32 *)(p + 0x54) = ((s8 *)p)[0xF];
    *(s32 *)(p + 0x58) = *(s32 *)(p + 0x10);
    *(s32 *)(p + 0x5C) = *(s32 *)(p + 0x3C);
    *(s32 *)(p + 0x60) = *(s32 *)(p + 0x40);
    *(s32 *)(p + 0x64) = *(s32 *)(p + 0x44);
    *(s32 *)(p + 0x8C) = 0;
    return v30[0];
}
