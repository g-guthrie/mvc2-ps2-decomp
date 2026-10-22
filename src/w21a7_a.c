typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x1C]; s16 f1C; s16 f1E; } H;
extern u16 D_004D18DC;
extern u8 D_004D18DB;
extern u8 D_004D18A6;

void func_003C8FC0(u8 *p)
{
    extern s32 func_00174240();
    extern void func_001E7F60();
    extern void func_003DAA40();
    u8 *r, *q;
    s16 v;
    s32 t;
    u32 u;

    if (D_004D18DC & (1 << D_004D18DB)) return;
    t = *(s8 *)(p + 0x1B4);
    if (t != 0) {
        p[0x1B4] = t - 1;
        return;
    }
    if (D_004D18A6 & (1 << (*(u8 **)(p + 0x18))[2])) return;
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    v = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = v;
    if (v >= 0) goto pos;
    ((H *)p)->f1C = 0;
    if (func_00174240(p) == 0) {
        q = *(u8 **)(p + 0x18);
        r = *(u8 **)(p + 0xD0);
        if (q[0x425] == 0 && r[0x425] == 0) {
            v = *(s16 *)(p + 0x1E) - 1;
            *(s16 *)(p + 0x1E) = v;
            if (v < 0) {
                u = p[7];
                p[7] = u + 1;
                *(s8 *)(q + 0x2BC) += 1;
                return;
            } else {
                *(s16 *)(p + 0x1C) = 2;
                u = p[7];
                p[7] = u - 1;
                *(s16 *)(p + 0x140) ^= 1;
                return;
            }
        } else {
            func_003DAA40(p);
            return;
        }
    } else {
        func_001E7F60(p);
    }
    return;
pos:
    if (func_00174240(p) != 0) {
        func_001E7F60(p);
        p[0x13C] = 1;
    } else {
        p[0x13C] = 0;
    }
}
