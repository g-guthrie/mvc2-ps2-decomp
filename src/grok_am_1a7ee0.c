typedef unsigned char u8;
typedef signed short s16;
typedef signed int s32;
typedef unsigned int u32;
typedef float f32;

extern u8 *func_003DA750(u8 *, s32, s32);
extern f32 func_001A8CB0(u8 *);
extern void func_001A7FA0(u8 *, u8 *);
extern void func_001A7990(void);

void residual_001A7EE0(u8 *p, u8 *q)
{
    u8 *o;
    p[5]++;
    *(s16 *)(p + 0x1E) = 10;
    if ((o = func_003DA750(p, 3, 2)) != 0) {
        *(u32 *)(o + 0x10) = (u32)func_001A7990;
        *(u8 **)(o + 0x18) = q;
        *(s16 *)(o + 0x1E) = *(s16 *)(p + 0x1E) - 1;
        if (!(func_001A8CB0(p) < 80.0f))
            o[0x20] = 5;
        else
            o[0x20] = 6;
    }
    func_001A7FA0(p, q);
}
