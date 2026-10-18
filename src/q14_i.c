typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_00370660(u8 *a, s32 b, s32 *c) {
    u8 *t = *(u8**)(a + 0x1C4);
    if (t[3] == 0 && t[5] == 3 && t[5] != 2 && t[0x425] == 0 && t[0x20D] != 3 &&
        *(s16*)(t + 0x434) != 0 && (*(u32*)(t + 0x428) & 0x7000000) == 0 && t[5] == 3 && t[0x20D] < 2) {
        { f32 f = *(f32*)(a + 0x34); s32 one = 1; *(f32*)(t + 0x34) = f; c[2] = one; }
    }
}
