typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x1C]; s8 f1c; } G_i;
extern G_i *D_004C2840;

void func_00391C80(u8 *p)
{
    extern void func_00175700(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_003928B0(u8 *);
    s16 h;
    u32 t;
    if (p[6] == 0) {
        func_00175700(p);
        *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
        *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
        *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
        if (*(f32 *)(p + 0x38) <= *(f32 *)(*(u8 **)(p + 0x18) + 0x430)) {
            t = p[6];
            p[6] = t + 1;
            *(f32 *)(p + 0x38) = *(f32 *)(*(u8 **)(p + 0x18) + 0x430);
            func_001757E0(p, 0x17, 1);
        }
    } else {
        func_00175700(p);
        if (*(s8 *)(p + 0x151) == 0) {
            p[6] = 0;
            *(f32 *)(p + 0x60) *= -1.0f;
            func_001757E0(p, 0x17, 0);
        }
    }
    h = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = h;
    if (h == 0) {
        func_003928B0(p);
        return;
    }
    p[0x13C] = D_004C2840->f1c & 1;
}
