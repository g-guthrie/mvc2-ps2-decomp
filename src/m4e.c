typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_00371B00(u8 *p) {
    u8 *q = *(u8 **)(p + 0x18) + 0x2B8;
    s16 old;
    *(f32 *)(p + 0x118) -= 0.05999999866f;
    if (*(f32 *)(p + 0x118) < 0.0f) *(f32 *)(p + 0x118) = 0.0f;
    old = *(s16 *)(p + 0x1C);
    *(s16 *)(p + 0x1C) = old - 1;
    if (old < 0) {
        u32 t = p[4];
        p[4] = t + 1;
        p[0x13C] = 0;
        q[1] = 0;
    }
}

extern void func_00137DF0(void);
void func_00137D50(u8 *p) {
    *(f32 *)(p + 0x50) += 0.00999999978f;
    *(f32 *)(p + 0x54) += 0.00999999978f;
    *(f32 *)(p + 0x74) -= 0.0500000007f;
    if (*(f32 *)(p + 0x74) <= 0.0f) {
        *(f32 *)(p + 0x74) = 0.0f;
        p[4]++;
        p[0x13C] = 0;
    } else {
        func_00137DF0();
    }
}

extern u8 *func_003DA750(s32 a, s32 b, s32 c);
extern void func_0039F8A0(void);
void func_0039F750(u8 *p) {
    s16 i;
    for (i = 1; i >= 0; i--) {
        u8 *o = func_003DA750(0, 1, 0);
        if (o != 0) {
            *(void **)(o + 0x10) = (void *)func_0039F8A0;
            *(u8 **)(o + 0x18) = p;
            *(u8 **)(o + 0xD8) = p;
            o[1] = p[1];
            o[0x21] = 0;
            o[0x20] = i;
            *(s16 *)(o + 0x26) = 0x2A01;
        }
    }
}
