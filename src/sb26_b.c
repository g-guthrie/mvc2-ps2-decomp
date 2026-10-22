typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern u8 D_0047B180[];
extern s32 D_0047C5AC, D_0047C5B0, D_0047C5B4, D_0047C5B8;

s32 func_003FBCF0(s32 a0, u8 *a1, s32 a2, u8 *a3, s32 a4, s32 a5)
{
    extern s32 func_003FB5F0();
    extern void func_003FB128();
    extern s32 func_003FCA60();
    extern s32 func_0011D8F8();
    extern void func_00120440();
    extern s32 func_003FCF88();
    extern void func_003FCCF0();
    extern s32 D_0062F900, D_0062F904;
    extern u8 D_004BAF28[], D_004BAF58[], D_004BAF88[], D_004BAFB8[];
    s32 r;
    s32 v;
    if (a4 == 0) {
        func_003FB128(D_004BAF28);
        return -3;
    }
    if (a5 <= 0) {
        func_003FB128(D_004BAF58);
        return -3;
    }
    r = func_003FB5F0(a0, a3);
    if (r < 0) return r;
    if (D_0047C5B4 >= 0) {
        func_003FB128(D_004BAF88);
        return -1;
    }
    D_0047C5B0 = func_003FCA60(a1, a2);
    if (D_0047C5B0 == 0) {
        func_003FB128(D_004BAFB8);
        return -1;
    }
    D_0047C5B4 = a0;
    D_0047C5AC = 0;
    func_0011D8F8(a3, 0, 0x118);
    *(s32 *)(D_0047B180 + a0 * 4) = (s32)a3;
    *(s32 *)a3 = 0;
    func_00120440(a3 + 0x10, a1, 0x100);
    *(s32 *)(a3 + 0x110) = a2;
    a3[0xE] = 0;
    v = a5 >> 11;
    D_0062F900 = a4;
    D_0047C5B8 = v;
    D_0062F904 = a4;
    r = func_003FCF88(D_0047C5B0, v, a4);
    if (r < 0) {
        func_003FCCF0(D_0047C5B0);
        return r;
    }
    *(s32 *)(a3 + 8) = 0;
    return 0;
}
