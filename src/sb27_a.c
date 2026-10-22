typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_00219040(u8 *p)
{
    extern s8 func_00175700();
    extern void func_001865B0();
    extern void func_00184540();
    u8 *q;
    u32 *v0, *v1, *a1, *a2;
    s32 b;
    q = p + 0x2B8;
    v0 = (u32 *)(p + 0x5C);
    a1 = (u32 *)(p + 0x68);
    v1 = (u32 *)(p + 0x60);
    a2 = (u32 *)(p + 0x6C);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (*(f32 *)(p + 0x38) < *(f32 *)(p + 0x430)) {
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        p[0x20D] = 0;
        *v0 = 0;
        *v1 = 0;
        *a1 = 0;
        *a2 = 0;
        func_001865B0(p);
        return;
    }
    if (p[7] == 0) {
        if (func_00175700(p) < 0) {
            p[0x20D] = 2;
            q[0] = 1;
            b = *(s8 *)(p + 0x1B2);
            if (b != 0 && ((s8)b & 1) == 0) {
                p[0x1E8] = 0;
                p[0x1EA] = 0x11;
                *(s8 *)(p + 0x1E7) = -1;
                func_00184540(p);
            } else {
                p[7]++;
                p[0x1E8] = 1;
                p[0x1E9] = 1;
                p[0x210] = 0;
                p[0x1EA] = 0;
            }
        }
    } else {
        func_00175700(p);
    }
}
