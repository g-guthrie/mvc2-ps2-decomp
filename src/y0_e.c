typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_0034D240(u8 *p)
{
    extern void func_0034CF60();
    u8 *q;
    s32 *r;
    u32 t;
    s16 v;
    q = *(u8 **)(p + 0x18);
    r = (s32 *)(p + 0xD0);
    func_0034CF60(p);
    v = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = v;
    if (v != 0) {
        *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
        *(s32 *)(p + 0x48) += *r;
    } else {
        t = p[5];
        p[5] = t + 1;
        *(f32 *)(p + 0x34) = *(f32 *)(q + 0x34) + *(f32 *)(p + 0x64);
        *(f32 *)(p + 0x38) = *(f32 *)(q + 0x38) + *(f32 *)(p + 0x70);
        *(s32 *)(p + 0x48) = 0;
    }
}
