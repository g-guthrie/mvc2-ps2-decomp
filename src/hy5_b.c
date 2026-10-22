typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;

void func_002F5660(u8 *p)
{
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_00175700();
    extern s32 func_00185980();
    s16 v;
    p[0x40C] = 2;
    p[0x33C] = 5;
    if (*(s8 *)(p + 0x1B2) == 0) {
        v = *(s16 *)(p + 0x1C) - 1;
        *(s16 *)(p + 0x1C) = v;
        if (v < 0) {
            p[6] = 0xD;
            func_001757E0(p, 0x16, 3);
            return;
        }
        func_00175700(p);
        *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
        *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
        *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    } else {
        if (func_00185980(p) == 0) {
            p[6] = 0xD;
            *(u32 *)(p + 0x60) = 0x414DB6DB;
            *(u32 *)(p + 0x6C) = 0xBF4DB6DB;
            *(u32 *)(p + 0x5C) = 0x3FD55555;
            if (*(s16 *)(p + 0x140) != 0) {
                *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
            }
            func_001757E0(p, 0x16, 3);
        } else {
            u8 *q;
            f32 k;
            u32 t = p[6];
            p[6] = t + 1;
            func_001757E0(p, 0x16, 1);
            q = *(u8 **)(p + 0x1C4);
            *(V3 *)(q + 0x34) = *(V3 *)(p + 0x34);
            *(f32 *)(q + 0x38) += 17.14285659790039f;
            k = -106.66666412353516f;
            if (*(s16 *)(p + 0x140) != 0) {
                k = -k;
            }
            *(f32 *)(q + 0x34) += k;
            *(V3 *)(p + 0x5C) = *(V3 *)(q + 0x34);
        }
    }
}
