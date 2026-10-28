#pragma opt_propagation off

typedef unsigned char u8;
typedef signed int s32;
typedef float f32;

extern void func_00422150(u8 *, s32 *, s32, s32, f32);

s32 func_004220B0(u8 *p, s32 a, s32 b, f32 f)
{
    s32 n;
    s32 i;
    s32 local;
    u8 *q = p;
    local = 1;
    n = q[0];
    i = 0;
    if (0 < n) {
        do {
            func_00422150(q, &local, a, b, f);
            i++;
        } while (i < n);
    }
    return 0;
}
