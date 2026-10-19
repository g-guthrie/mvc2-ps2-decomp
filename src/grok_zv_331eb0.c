typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern void func_00416AE0(void);
extern void func_00416F80(u8 *);
extern void func_00416CC0(s32);

void func_00331EB0(u8 *p)
{
    u8 *owner = *(u8 **)(p + 0x14);
    s32 mode = *(s32 *)(owner + 0xDC);
    *(s32 *)(p + 0xDC) = mode;
    if (mode != 0) {
        mode = *(s32 *)(*(u8 **)(p + 0x14) + 0xD8);
        *(s32 *)(p + 0xDC) = mode;
        if (mode == 2)
            *(f32 *)(p + 0x38) -= 1.0f;
        else if (mode == 1)
            *(f32 *)(p + 0x38) += 1.0f;
        else if (mode == 0)
            ;
        if (*(s32 *)(p + 0xC8) == 0) {
            *(u8 **)(p + 0xC8) = *(u8 **)(p + 0x14) + 0x88;
            *(f32 *)(p + 0x34) = *(f32 *)(p + 0x5C);
            *(f32 *)(p + 0x38) = *(f32 *)(p + 0x60);
            *(f32 *)(p + 0x3C) = *(f32 *)(p + 0x64);
            *(s32 *)(p + 0x44) = 0;
            return;
        }
    }
    if (*(s32 *)(p + 0xC8) != 0) {
        *(s32 *)(p + 0xC8) = 0;
        *(f32 *)(p + 0x5C) = *(f32 *)(p + 0x34);
        *(f32 *)(p + 0x60) = *(f32 *)(p + 0x38);
        *(f32 *)(p + 0x64) = *(f32 *)(p + 0x3C);
        func_00416AE0();
        func_00416F80(p + 0x88);
        func_00416CC0(1);
        *(s32 *)(p + 0x44) = *(s32 *)(*(u8 **)(*(u8 **)(*(u8 **)(p + 0x14) + 0x14) + 0x14) + 0x44);
    }
}
