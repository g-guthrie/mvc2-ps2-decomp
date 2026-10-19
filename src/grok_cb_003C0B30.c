typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef float f32;

extern s32 func_00175700(u8 *);
extern void func_003DAA40(u8 *);

void func_003C0B30(u8 *p)
{
    u8 *q = *(u8 **)(p + 0xD8);
    f32 s = 40.0f;
    if (*(s16 *)(q + 0x140) != 0)
        s = -s;
    *(f32 *)(p + 0x34) = (s + *(f32 *)(q + 0x34) + 3.0f * *(f32 *)(p + 0x34)) / 4.0f;
    *(f32 *)(p + 0x38) = (342.857147216796875f + *(f32 *)(q + 0x38) + 3.0f * *(f32 *)(p + 0x38)) / 4.0f;
    if ((s8)func_00175700(p) < 0) {
        p[0x13C] = 0;
        func_003DAA40(p);
    }
}
