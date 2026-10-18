typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
extern s32 D_00632140[3];
extern s32 D_00632240[];
extern void func_00409708(s32, s32 *, s32, s32 *, s32);
s32 func_004107F0(s32 a, s32 b, s32 c) {
    D_00632140[0] = a;
    D_00632140[1] = b;
    D_00632140[2] = c;
    func_00409708(0x20, D_00632140, 3, D_00632240, 1);
    return D_00632240[0];
}
