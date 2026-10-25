/* Follow the linked actor according to its phase and clamp its ground position. */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_002BF790(u8 *a) {
    extern void func_00179150(u8 *, u8 *);
    extern void func_00178F20(u8 *, u8 *);
    u8 *o = *(u8 **)(a + 0x1DC);
    switch (o[0x15B]) {
    case 1: func_00179150(o, a); return;
    case 2: {
        if (*(f32 *)(o + 0x38) <= *(f32 *)(o + 0x430)) *(f32 *)(o + 0x38) = *(f32 *)(o + 0x430);
    }
    }
    func_00178F20(*(u8 **)(a + 0x1DC), a);
}
