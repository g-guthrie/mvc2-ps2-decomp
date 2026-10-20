typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern void func_00212DE0(u8 *, u8 *);
extern void func_001E3240(u8 *, int);
extern void func_00175C00(u8 *, int);
extern int func_001757E0(u8 *, int, int);

void func_00215650(u8 *p)
{
    u8 *q = p + 0x2B8;
    p[0x2BC] = 0xFF;
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (*(f32 *)(p + 0x38) < *(f32 *)(p + 0x430)) {
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430) - 15.0f / 7.0f;
    } else {
        s16 t;
        func_00212DE0(p, q);
        t = *(s16 *)(p + 0x1C) - 1;
        *(s16 *)(p + 0x1C) = t;
        if (t >= 0)
            return;
    }
    p[6]++;
    q[4] = 0;
    func_001E3240(p, 0x1F);
    func_001E3240(p, 0x20);
    *(f32 *)(p + 0x5C) = 10.0f / 3.0f;
    if (*(s16 *)(p + 0x140))
        *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x60) = 0x41AB6DB6;
    *(u32 *)(p + 0x6C) = 0xBF4DB6DB;
    func_00175C00(p, 0);
    func_001757E0(p, 0xF, 7);
}
