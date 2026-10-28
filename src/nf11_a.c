typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x1C]; s8 f1c; } G_a;
extern G_a *D_004C2840;

void residual_00234CE0(u8 *p)
{
    extern s32 func_00175700(u8 *);
    extern void func_00175C00(u8 *, s32);
    extern void func_00176160(u8 *, s32, s32, s32);
    extern void func_001A0B20(u8 *, s32);
    extern void func_00235020(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    s32 r;
    s32 q;
    s16 v;

    r = func_00175700(p);
    if ((s8)r >= 0) {
        v = *(s16 *)(p + 0x1E) - 1;
        *(s16 *)(p + 0x1E) = v;
        if (v == 0) {
            *(s16 *)(p + 0x1E) = 3;
            func_00175C00(p, 1);
        } else {
            q = p[0x25] << 4;
            q += *(s16 *)(p + 0x1C) + 8;
            func_00176160(p, 1, q, 1);
        }
        *(s16 *)(p + 0x1C) = (*(s16 *)(p + 0x1C) + 1) % 3;
        p[0x13C] = D_004C2840->f1c & 1;
    } else {
        u32 t = p[7];
        p[7] = t + 1;
        p[0x13C] = 1;
        *(s16 *)(p + 0x1C) = 0;
        *(s16 *)(p + 0x1E) = 1;
        *(f32 *)(p + 0x38) += 308.5714111328125f;
        func_001A0B20(p, 0);
        func_00235020(p);
        func_001757E0(p, 0x12, 1);
    }
}
