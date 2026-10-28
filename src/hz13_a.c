typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 *D_004CAE64;
extern f32 func_00417500(u32);
extern void func_0012AD00(u8 *);

void func_0014B470(u8 *p) {
    if (p[0x23] != 0) {
        u32 angle;
        s16 v;
        *(s16 *)(p + 0x1E) = *(s16 *)(p + 0x1E) + 3;
        if (*(s16 *)(p + 0x1E) >= 0x168) *(s16 *)(p + 0x1E) = 0;
        angle = (u32)(s32)(0.5 + 65536.0 * (double)((s32)*(s16 *)(p + 0x1E)) / 360.0) & 0xFFFFu;
        *(f32 *)(p + 0x74) = 0.3000000119f + 0.5f * func_00417500(angle);
        *(s8 *)(p + 0x13C) = *(s8 *)(*(u8 **)(D_004CAE64 + 0xD8) + 0x13C);
        if (!(*(f32 *)(p + 0x74) <= 1.0f)) *(f32 *)(p + 0x74) = 1.0f;
        if (!(*(f32 *)(p + 0x78) <= 1.0f)) *(f32 *)(p + 0x78) = 1.0f;
        if (!(*(f32 *)(p + 0x7C) <= 1.0f)) *(f32 *)(p + 0x7C) = 1.0f;
        if (!(*(f32 *)(p + 0x80) <= 1.0f)) *(f32 *)(p + 0x80) = 1.0f;
        if (*(f32 *)(p + 0x74) < 0.0f) *(f32 *)(p + 0x74) = 0.0f;
        if (*(f32 *)(p + 0x78) < 0.0f) *(f32 *)(p + 0x78) = 0.0f;
        if (*(f32 *)(p + 0x7C) < 0.0f) *(f32 *)(p + 0x7C) = 0.0f;
        if (*(f32 *)(p + 0x80) < 0.0f) *(f32 *)(p + 0x80) = 0.0f;
    } else {
        func_0012AD00(p);
    }
}
