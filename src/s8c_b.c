/* func_00149380: MW 3.0.3 (MWCCPS2) -O3 -sdatathreshold 0; switch table @N -> jtbl_004B3860 (objcopy --redefine-sym).
   'old' is reused for the second saved/compare value, which gives retail's v0/v1 split. */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern u16 D_004F4484[];
extern u16 D_004F4490[];

s32 func_00149380(s8 *a)
{
    extern void func_001E3CE0(), func_003D4B70(), func_003D47E0();
    extern void func_0016EDA0(s32, s32);
    extern s32 func_001315E0();
    s8 old;
    s16 s0;
    s8 *s1;
    u32 r;
    old = a[0];
    if (((D_004F4484[a[1] * 10] | D_004F4490[a[1] * 10]) & 0x2000) != 0) a[0] = old - 1;
    if (((D_004F4484[a[1] * 10] | D_004F4490[a[1] * 10]) & 0x1000) != 0) a[0] = a[0] + 1;
    a[0] = (a[0] + 12) % 12;
    if (old != a[0]) func_001E3CE0(1);
    switch (a[0]) {
    case 0: case 1: case 2: case 3: case 4: case 5: case 6: case 7:
        s1 = a + a[0] + 4;
        s0 = 12;
        break;
    case 8:
        s1 = a + 2;
        s0 = 2;
        break;
    case 9:
        s1 = a + 3;
        s0 = 2;
        break;
    case 10:
        r = (u16)func_001315E0(a[1]);
        if (r & D_004F4484[a[1] * 10]) {
            func_003D4B70(a);
            func_001E3CE0(2);
        }
        s0 = -1;
        break;
    case 11:
        r = (u16)func_001315E0(a[1]);
        if (r & D_004F4484[a[1] * 10]) {
            func_001E3CE0(2);
            return 1;
        }
        s0 = -1;
        break;
    }
    if (s0 > 0) {
        old = *s1;
        if (((D_004F4484[a[1] * 10] | D_004F4490[a[1] * 10]) & 0x800) != 0) *s1 = old - 1;
        if (((D_004F4484[a[1] * 10] | D_004F4490[a[1] * 10]) & 0x400) != 0) *s1 = *s1 + 1;
        *s1 = (*s1 + s0) % s0;
        if (old != *s1) {
            func_003D47E0();
            func_001E3CE0(4);
            if (a[0] == 8 && *s1 != 0) func_0016EDA0(a[1], 8);
        }
        a[0xC] = a[0xC] + *s1;
    }
    return 0;
}
