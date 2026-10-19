typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern void func_001A7990(void);

void residual_001A8020(u8 *p, u8 *q)
{
    extern u8 *func_003DA750(u8 *, s32, s32);
    extern f32 func_001A8CB0(u8 *);
    extern void func_001A8140(u8 *, u8 *);
    u8 *a3;
    u8 *o;
    f32 c;
    a3 = *(u8 **)(p + 8);
    p[5]++;
    if (a3[0x20] == 4)
        c = -53.33333206f;
    else
        c = -80.0f;
    if (*(s16 *)(p + 0x140) != 0)
        c = -c;
    *(f32 *)(p + 0x34) = *(f32 *)(a3 + 0x34) + c;
    *(f32 *)(p + 0x38) = *(f32 *)(a3 + 0x38);
    if ((o = func_003DA750(p, 3, 2)) != 0) {
        *(u32 *)(o + 0x10) = (u32)func_001A7990;
        *(u8 **)(o + 0x18) = q;
        *(s16 *)(o + 0x1E) = *(s16 *)(p + 0x1E) - 1;
        if (*(s16 *)(p + 0x1E) == 0)
            goto l12;
        if (!(func_001A8CB0(p) < 53.33333206f))
            o[0x20] = 5;
        else {
        l12:
            o[0x20] = 6;
        }
    }
    func_001A8140(p, q);
}
