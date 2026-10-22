typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_002D4DE0(u8 *p)
{
    extern void func_00175700(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    extern u8 *func_0039C5B0(u8 *, s32);
    f32 *a3, *t0, *t1, *t2;
    s32 a;
    s16 h;
    u32 t;
    u8 *r;
    p[0x40C] = 2;
    p[0x33C] = 5;
    p[0x405] = (p[0x269] == 6) ? 2 : 0;
    func_00175700(p);
    a3 = (f32 *)(p + 0x5C);
    t1 = (f32 *)(p + 0x68);
    t0 = (f32 *)(p + 0x60);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    t2 = (f32 *)(p + 0x6C);
    if (!(*(f32 *)(p + 0x430) <= *(f32 *)(p + 0x38))) {
        p[6] = 5;
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        p[0x20D] = 0;
        *(s32 *)a3 = 0;
        *(s32 *)t0 = 0;
        *(s32 *)t1 = 0;
        *(s32 *)t2 = 0;
        func_001757E0(p, 1, 4);
        return;
    }
    h = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = h;
    if (*(s16 *)(p + 0x1C) < 0) {
        a = *(s8 *)(p + 0x211);
        if (a != 0) {
            if (p[0x1E6] != 0) {
                if (((s8)a & 1) == 0) return;
            } else {
                if (((s8)a & 2) == 0) return;
            }
            t = p[6];
            p[6] = t + 1;
            p[0x1E6] ^= 1;
            *(s16 *)(p + 0x140) = p[0x1E6];
            *(s32 *)a3 = 0;
            *(s32 *)t0 = 0;
            *(s32 *)t1 = 0;
            *(s32 *)t2 = 0;
            if (p[0x1FD] == 0xE) func_001757E0(p, 0x16, 0xE);
            else func_001757E0(p, 0x16, 7);
            r = func_0039C5B0(p, 2);
            if (r != 0) r[0x95] = 1;
        }
    }
}
