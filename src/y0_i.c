typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_0034C840(u8 *p)
{
    extern u8 *func_003DA750();
    extern void func_0034C920();
    extern void func_001E3430();
    extern void func_00154470(u8 *, s32, s32, f32, f32);
    u8 *o;
    u8 *q;
    if ((o = func_003DA750(0, 1, 0)) != 0) {
        *(u32 *)(o + 0x10) = (u32)func_0034C920;
        *(u8 **)(o + 0x18) = p;
        *(u32 *)(o + 0x14) = *(u32 *)(p + 0x1C8);
        *(s16 *)(o + 0x26) = 0x404;
        o[0] = 1;
        q = *(u8 **)(p + 0x1C8);
        if (q[1] == 4) {
            func_001E3430(p, q, 0x2D);
            func_001E3430(p, *(u8 **)(p + 0x1C8), 0x30);
        }
        func_00154470(p, 0, 0, 2.0f, 2.0f);
        func_00154470(p, 0x10, 0, 2.0f, 2.0f);
        func_00154470(p, 0xF0, 0, 2.0f, 2.0f);
    }
}
