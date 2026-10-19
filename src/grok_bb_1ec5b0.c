typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s32 func_00175700(u8 *);
extern void func_001757E0(u8 *, s32, s32);
extern void func_001EC280(u8 *);

void func_001EC5B0(u8 *p)
{
    s16 v;
    union { u32 i; f32 f; } u;
    p[0x40C] = 2;
    p[0x33C] = 5;
    if ((s8)func_00175700(p) < 0) {
        v = *(s16 *)(p + 0x1C) - 1;
        *(s16 *)(p + 0x1C) = v;
        if (v <= 0) {
            p[6] = p[6] + 1;
            func_001757E0(p, 0x16, 8);
            return;
        }
        return;
    }
    u.i = 0xBE092492;
    *(f32 *)(p + 0x38) = *(f32 *)(p + 0x38) + u.f;
    func_001EC280(p);
}
