typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_00335C50(u8 *p) {
    extern s32 func_003367F0(u8 *);
    extern s32 func_00336460(u8 *);
    extern s32 func_00336690(u8 *);
    extern s32 func_00335390(u8 *);
    f32 a, b, z;
    switch (func_003367F0(p)) { case 0: break; default: *(u32 *)(p + 0x5C) = 0; *(u32 *)(p + 0x60) = 0; *(u32 *)(p + 0x68) = 0; *(u32 *)(p + 0x6C) = 0; return; } switch (func_00336460(p)) { case 0: break; default: *(u32 *)(p + 0x5C) = 0; *(u32 *)(p + 0x60) = 0; *(u32 *)(p + 0x68) = 0; *(u32 *)(p + 0x6C) = 0; return; } if (*(s16 *)(p + 0x140) != 0) a = *(f32 *)(p + 0x68); else a = -*(f32 *)(p + 0x68);
    *(f32 *)(p + 0x5C) += a;
    if (*(s16 *)(p + 0x140) != 0) b = -*(f32 *)(p + 0x5C); else b = *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x34) += b;
    z = 0.0f; if (*(f32 *)(p + 0x5C) <= z) {
        *(f32 *)(p + 0x5C) = z; *(f32 *)(p + 0x60) = z; *(f32 *)(p + 0x68) = z; *(f32 *)(p + 0x6C) = z;
        p[7] = 0; p[5] = 0;
        return;
    }
    if (func_00336690(p) != 0) return;
    if (func_00335390(p) != 0) { *(u32 *)(p + 0x5C) = 0; *(u32 *)(p + 0x60) = 0; *(u32 *)(p + 0x68) = 0; *(u32 *)(p + 0x6C) = 0; p[7] = 0; p[5] = 0; }
}

void func_001F8D70(u8 *p) {
    extern s8 func_00175700(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    f32 c;
    u32 t;
    if (*(s8 *)(p + 0x151) == 0) {
        *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
        *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
        *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    }
    if (func_00175700(p) < 0) {
        t = p[6];
        p[6] = t + 1;
        func_001757E0(p, 2, 2);
        switch (p[0x1E6]) { default: c = -0.8333333134651184f; break; case 0: c = 0.8333333134651184f; break; } *(f32 *)(p + 0x68) = c;
    }
}

void func_003B1900(u8 *p, u8 *q) {
    extern void func_003B1AA0(u8 *, s32);
    extern void func_00175700(u8 *);
    extern void func_001E7F60(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    extern int func_00174470(const void *);
    extern void func_003B1A70(u8 *, u8 *);
    s32 x = *(s32 *)(p + 0x14);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    func_003B1AA0(p, x);
    func_00175700(p);
    func_001E7F60(p);
    switch (q[0x2B8]) { default: { u32 t = p[5]; p[5] = t + 1; if (p[0x20] == 2) { func_001757E0(p, 0x17, 1); } else { func_001757E0(p, 0x17, 4); } return; } break; case 0: { if (func_00174470(p) == 0) { u32 t = p[4]; p[4] = t + 1; func_003B1A70(p, q); } } break; }
}
