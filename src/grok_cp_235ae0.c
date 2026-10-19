typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern void func_00175700(u8 *);
extern void func_001757E0(u8 *, s32, u8);
extern void func_00183d50(u8 *);

void func_00235AE0(u8 *p)
{
    f32 *vx = (f32 *)(p + 0x5C);
    f32 *ax = (f32 *)(p + 0x68);
    f32 *vy = (f32 *)(p + 0x60);
    f32 *ay = (f32 *)(p + 0x6C);
    s32 v0;

    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_00175700(p);
    if (*(f32 *)(p + 0x38) < *(f32 *)(p + 0x430)) {
        p[6]++;
        p[7] = 0;
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        p[0x20D] = 0;
        *vx = 0.0f;
        *vy = 0.0f;
        *ax = 0.0f;
        *ay = 0.0f;
        v0 = 6;
        if (!((s8)p[0x1B2] & 1)) {
            v0 = 1;
            if (p[0x1B7] != v0)
                v0 = 5;
            else
                v0 = 6;
        }
        func_001757E0(p, 0x15, (u8)v0);
        func_00183d50(p);
    }
}
