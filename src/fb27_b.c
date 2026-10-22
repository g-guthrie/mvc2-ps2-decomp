typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s8 func_00175700();
extern void func_001843A0(u8 *p);
extern void func_00154580(u8 *p, f32 *v, f32 a, f32 b);

void func_002749C0(u8 *p) {
    s32 t;
    f32 v;
    f32 loc[4];
    switch (p[0x1FC]) {
    case 0:
        if (func_00175700(p) < 0) func_001843A0(p);
        break;
    case 1:
        if (func_00175700(p) < 0) func_001843A0(p);
        break;
    case 2:
        if (func_00175700(p) < 0) {
            func_001843A0(p);
            break;
        }
        if (p[0x168] != 3) break;
        t = (s8)p[0x151];
        switch (t) {
        case 1:
            *(u32 *)(p + 0x5C) = 0;
            *(u32 *)(p + 0x60) = 0;
            *(u32 *)(p + 0x68) = 0;
            *(u32 *)(p + 0x6C) = 0;
            break;
        case 2:
            v = (*(s16 *)(p + 0x140) != 0) ? 2.0f : -2.0f;
            *(f32 *)(p + 0x5C) = v;
            p[0x151] = 0;
            break;
        case 3:
            loc[0] = 52.0f;
            v = (*(s16 *)(p + 0x140) != 0) ? 0.4000000059604645f : -0.4000000059604645f;
            *(f32 *)(p + 0x5C) = v;
            p[0x151] = 0;
            func_00154580(p, loc, 1.0f, 1.0f);
            break;
        case 4:
            *(u32 *)(p + 0x5C) = 0;
            *(u32 *)(p + 0x60) = 0;
            *(u32 *)(p + 0x68) = 0;
            *(u32 *)(p + 0x6C) = 0;
            break;
        }
        *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
        break;
    }
}
