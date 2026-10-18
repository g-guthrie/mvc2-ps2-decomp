typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_0021C1E0(u8 *a, u8 *b) {
    extern void func_001266A0(u8 *, s32, s32);
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_0018FDB0(u8 *);
    extern void func_001E3710(u8 *, s32);
    extern void func_001E3210(u8 *, s32);
    extern void func_001548D0(u8 *, u32 *, s32);
    u32 v[4];
    func_001266A0(a, 6, 6);
    a[0x151] = 6;
    *(s16 *)(b + 0x1C) = 1;
    *(f32 *)(b + 0x38) = *(f32 *)(b + 0x430);
    func_001757E0(b, 0xD, 9);
    if ((*(u32 *)(b + 0x428) & 0x90001010) | (*(u32 *)(b + 0x42C) & 1)) {
        b[0x1E6] ^= 1;
        *(s16 *)(b + 0x140) = b[0x1E6];
    }
    *(u8 **)(b + 0x1C8) = a;
    b[0x1B5] = 0x23;
    func_0018FDB0(a);
    func_001E3710(a, 5);
    func_001E3210(a, 3);
    v[0] = 0xC3200000;
    v[1] = 0x42092492;
    func_001548D0(a, v, 2);
}
