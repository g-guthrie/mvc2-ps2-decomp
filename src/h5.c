typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
extern u8 D_004F2603[];
extern void func_0012F060(s32);
void func_00172320(s32 i) {
    u8 *b = D_004F2603;
    u8 *p0 = b + i * 0x5B8;
    u8 *p1 = b + (i + 2) * 0x5B8;
    u8 *p2 = b + (i + 4) * 0x5B8;
    *p0 = 0;
    *p1 = 1;
    *p2 = 2;
    func_0012F060(i);
}
