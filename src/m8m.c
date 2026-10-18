typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 D_004D18E4;
extern void func_001754A0(void *p, s32 a, s32 b);
extern void func_00175670(void *p);

void func_0019D680(u8 *a, u8 *b) {
    a[0x13C] = 0;
    if (*(s8 *)(b + 0x13C) != 0) {
        s32 v = *(s8 *)(b + 0x161);
        if (v != 0 && (u32)v < 0x20) {
            a[0x13C] = 1;
            *(f32 *)(a + 0x34) = *(f32 *)(b + 0x34);
            *(f32 *)(a + 0x38) = *(f32 *)(b + 0x38);
            *(s16 *)(a + 0x140) = *(s16 *)(b + 0x140);
            *(s8 *)(a + 0x24) = *(s8 *)(b + 0x24);
            if (*(s32 *)(a + 0xD4) != v) {
                *(s32 *)(a + 0xD4) = v;
                func_001754A0(a, 0x1B, v & 0xFF);
            } else if (D_004D18E4 == 0) {
                func_00175670(a);
            }
        }
    }
}
