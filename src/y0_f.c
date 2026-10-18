typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_00198A80(u8 *p)
{
    extern void func_001754A0();
    extern void func_00175670();
    u8 *q;
    s16 v;
    u32 t;
    q = *(u8 **)(p + 0x14);
    if (q[4] == 2 || q[5] != 0) {
        p[5] = 3;
        func_001754A0(p, 0x1B, 4);
        return;
    }
    v = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = v;
    if (v != 0) {
        *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
        *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
        *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
        func_00175670(p);
    } else {
        t = p[5];
        p[5] = t + 1;
        p[0x22] = 0x60;
    }
}
