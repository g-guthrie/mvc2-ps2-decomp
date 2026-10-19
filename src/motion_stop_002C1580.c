typedef unsigned char u8;
typedef signed int s32;
typedef float f32;

extern void func_00175700(u8 *);
extern void func_001757E0(u8 *, s32, s32);

void func_002C1580(u8 *p)
{
    func_00175700(p);
    if (!*(f32 *)(p + 0x5C)) {
        p[7]++;
        *(f32 *)(p + 0x5C) = 0.0f;
        *(f32 *)(p + 0x68) = 0.0f;
        func_001757E0(p, 0xA, (u8)(p[0x1B7] + 6));
    }
}
