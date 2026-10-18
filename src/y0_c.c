typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_001D1160(u8 *p, u8 *q)
{
    extern s32 func_00175670();
    u32 t;
    if (*(s32 *)(p + 0xD0) == *(u16 *)(q + 0x168) && p[1] == q[1]) {
        *(s8 *)(p + 0x24) = *(s8 *)(q + 0x24) + *(s8 *)(p + 0x31);
        *(f32 *)(p + 0x34) = *(f32 *)(q + 0x34);
        if (p[0x20] == 0) {
            *(f32 *)(p + 0x38) = *(f32 *)(q + 0x430);
            *(s16 *)(p + 0x140) = *(s16 *)(q + 0x140);
        } else {
            *(f32 *)(p + 0x38) = *(f32 *)(q + 0x38);
        }
        if ((s8)func_00175670(p) >= 0) return;
        if (p[0x20] != 0) return;
    }
    t = p[4];
    p[4] = t + 1;
    p[0x13C] = 0;
}
