typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 *func_003DA750(void *, int, int);
extern void func_00154400(u8 *);

void func_00154470(u8 *owner, u32 dx, u32 dy, f32 sx, f32 sy)
{
    u8 *p = func_003DA750(0, 0x13, 1);
    if (p) {
        s32 v;
        p[0x13C] = 1;
        *(void (**)(u8 *))(p + 0x10) = func_00154400;
        *(u32 *)(p + 0xD0) = 0x800011;
        *(f32 *)(p + 0x34) = *(f32 *)(owner + 0x34);
        *(f32 *)(p + 0x38) = *(f32 *)(owner + 0x38);
        *(u32 *)(p + 0x3C) = 0;
        v = (s32)(dx & 0xFF);
        if (*(s16 *)(owner + 0x140) == 0)
            v = -v;
        *(f32 *)(p + 0x34) += (f32)v;
        *(f32 *)(p + 0x38) += (f32)(u32)dy;
        *(f32 *)(p + 0x50) = sx;
        *(f32 *)(p + 0x54) = sy;
        *(u32 *)(p + 0x58) = 0;
    }
}
