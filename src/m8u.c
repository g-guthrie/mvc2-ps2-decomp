typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u16 *D_004C26E0;
extern void func_001B8AC0(void *p);
extern void func_00175580(void *p, s32 a, s32 b, s32 c);

void func_001B8A20(u8 *p) {
    if (*D_004C26E0 != *(u16 *)(*(u8 **)(p + 0x18) + 0x168)) {
        func_001B8AC0(p);
        return;
    }
    func_00175580(p, 0x1B, 8, (s8)(*(s8 *)(*(u8 **)(p + 0x18) + 0x15B) - 1));
    if ((s32)*(s8 *)(*(u8 **)(p + 0x18) + 0x15B) - 1 < 0) {
        func_001B8AC0(p);
    } else {
        u8 *q = *(u8 **)(p + 0x18);
        *(f32 *)(p + 0x34) = *(f32 *)(q + 0x34);
        *(f32 *)(p + 0x38) = *(f32 *)(*(u8 **)(p + 0x18) + 0x38);
    }
}
