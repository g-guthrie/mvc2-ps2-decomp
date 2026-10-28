typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_00219F60(u8 *p, u8 *q)
{
    extern void func_00175700(u8 *);
    extern s32 func_00185980(u8 *);
    extern void func_001266A0(u8 *, s32, s32);
    extern void func_001757E0(u8 *, s32, s32);
    u32 *r5c, *r68;
    u8 *o;
    s32 sel;
    f32 f;
    u32 t;

    r68 = (u32 *)(p + 0x68);
    p[0x40C] = 2;
    r5c = (u32 *)(p + 0x5C);
    p[0x33C] = 5;
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    func_00175700(p);
    sel = *(s8 *)(p + 0x211);
    if (sel != 0 && (s8)sel != (1 << p[0x1E6])) {
        p[0x40D] = 0;
        p[0x40C] = 0;
        p[0x33B] = 0;
        p[0x33C] = 0;
        t = p[6];
        p[6] = t + 1;
        p[7] = 0;
        func_001757E0(p, 0x16, 3);
        return;
    }
    if (*(s8 *)(p + 0x1B2) != 0) {
        if (func_00185980(p) != 0) {
            o = *(u8 **)(p + 0x1C4);
            f = -100.0f;
            t = p[7];
            p[7] = t + 1;
            *(u8 **)(q + 4) = o;
            *(s16 *)(q + 8) = 0;
            if (p[0x1E6] != 0) {
                f = -f;
            }
            *(f32 *)(o + 0x34) = *(f32 *)(p + 0x34) + f;
            *(f32 *)(o + 0x38) = *(f32 *)(p + 0x38);
            o[0x20D] = 0;
            *r5c = 0;
            *r68 = 0;
            func_001266A0(p, 8, 8);
            func_001757E0(p, 0x16, 1);
        } else {
            p[0x40D] = 0;
            p[0x40C] = 0;
            p[0x33B] = 0;
            p[0x33C] = 0;
            t = p[6];
            p[6] = t + 1;
            p[7] = 0;
            *r5c = 0;
            *(u32 *)(p + 0x60) = 0;
            *r68 = 0;
            *(u32 *)(p + 0x6C) = 0;
            func_001757E0(p, 0x16, 4);
        }
    }
}
