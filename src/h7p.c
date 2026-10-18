typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_00353060(u8 *d, u8 *s) {
    *(f32 *)(d + 0x38) = 23.571428299f + *(f32 *)(s + 0x38);
    if (*(s16 *)(s + 0x140) != 0) {
        *(f32 *)(d + 0x34) = 225.0f + *(f32 *)(s + 0x34);
    } else {
        *(f32 *)(d + 0x34) = *(f32 *)(s + 0x34) - 225.0f;
    }
}

typedef struct { f32 x, y, z; } V3;
void func_00156480(u8 *d) {
    u8 *s = *(u8 **)(d + 0x18);
    f32 x;
    *(V3 *)(d + 0x34) = *(V3 *)(s + 0x34);
    x = 40.0f * *(f32 *)(s + 0x50);
    if (*(s16 *)(s + 0x140) == 0) x = -x;
    *(f32 *)(d + 0x34) += x;
    *(f32 *)(d + 0x38) += 205.7142792f * *(f32 *)(s + 0x54);
}
void func_003B68E0(u8 *d, u8 *s) {
    u32 t;
    *(f32 *)(d + 0x34) = *(f32 *)(s + 0x34) + *(f32 *)(d + 0x88);
    *(f32 *)(d + 0x38) = *(f32 *)(s + 0x38) + *(f32 *)(d + 0x8C);
    *(f32 *)(d + 0x5C) = 3.3333332539f;
    *(f32 *)(d + 0x68) = 0.0f;
    *(f32 *)(d + 0x60) = -2.1428570747f;
    *(f32 *)(d + 0x6C) = -0.2678571343f;
    if (*(s16 *)(s + 0x140) == 0) {
        *(f32 *)(d + 0x5C) = -*(f32 *)(d + 0x5C);
    }
    t = d[5];
    d[5] = t + 1;
}
extern f32 D_004F1F4C;
extern void func_00160B80(void *p);
extern void func_003DAA40(void *p);
void func_00160AF0(u8 *p) {
    *(f32 *)(p + 0x34) = D_004F1F4C;
    if (*(s16 *)(p + 0x1C) >= 0x50) {
        *(f32 *)(p + 0x74) -= 0.014285714365f;
    }
    if (*(s16 *)(p + 0x1C) >= 0x96) {
        func_003DAA40(p);
    } else {
        func_00160B80(p);
        *(s16 *)(p + 0x1C) += 1;
    }
}
