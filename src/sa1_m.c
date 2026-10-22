typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_002DE490(u8 *p)
{
    extern void func_00175700(u8 *);
    extern s32 func_00185980(u8 *);
    extern void func_00185770(u8 *, s32);
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_001266A0(u8 *, s32, s32);
    extern void func_00183d50(u8 *);
    u32 *a3, *t0, *t1, *t2;
    u32 t;
    func_00175700(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    a3 = (u32 *)(p + 0x5C);
    t1 = (u32 *)(p + 0x68);
    t0 = (u32 *)(p + 0x60);
    t2 = (u32 *)(p + 0x6C);
    if (*(s8 *)(p + 0x1B2) != 0) {
        if (func_00185980(p) != 0) {
            t = p[7];
            p[7] = t + 1;
            p[0x1B1] = 0;
            p[0x20B] = 0xC2;
            *(s8 *)(p + 0x16A) = -1;
            p[0x1FE] = 1;
            p[0x206] = 3;
            func_00185770(p, *(s32 *)(p + 0x1C4));
            *(u32 *)(p + 0x5C) = 0xC0A00000;
            *(u32 *)(p + 0x68) = 0;
            *(u32 *)(p + 0x60) = 0x414DB6DB;
            *(u32 *)(p + 0x6C) = 0xBF892492;
            if (p[0x1E6] != 0) *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
            func_001757E0(p, 0xF, 5);
            func_001266A0(p, 5, 5);
        } else {
            t = p[6];
            p[6] = t + 1;
            p[7] = 1;
            *(f32 *)(p + 0x5C) = -(*(f32 *)(p + 0x5C) / 8.0f);
            *(u32 *)(p + 0x60) = 0x41892492;
            *(u32 *)(p + 0x68) = 0;
            *(u32 *)(p + 0x6C) = 0xBF892492;
            func_001757E0(p, 0x15, 0xA);
        }
        return;
    } else {
        if (*(f32 *)(p + 0x38) < *(f32 *)(p + 0x430)) {
            t = p[6];
            p[6] = t + 1;
            p[7] = 0;
            *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
            p[0x20D] = 0;
            *a3 = 0;
            *t0 = 0;
            *t1 = 0;
            *t2 = 0;
            func_001757E0(p, 1, 3);
            func_00183d50(p);
        }
    }
}
