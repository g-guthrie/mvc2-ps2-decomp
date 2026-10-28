typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x38]; f32 f38; } F38;

void func_003A7280(u8 *p, u8 *q) {
    extern s32 func_001745B0(u8 *);
    extern void func_00175700(u8 *);
    extern void func_001E7F60(u8 *);
    if (func_001745B0(p) == 0) { p[0x13C] = 0; } else { p[0x13C] = 1; }
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_00175700(p);
    if (*(f32 *)(p + 0x38) < *(f32 *)(q + 0x430)) {
        ((F38 *)p)->f38 = *(f32 *)(q + 0x430);
        { u32 t = p[4]; p[4] = t + 1; }
    } else {
        switch ((s8)p[0x1B3]) { default: { u32 t = p[4]; p[4] = t + 1; } break;
        case 0:
            func_001E7F60(p);
            if ((s8)p[0x1B2] != 0) { u32 t = p[4]; p[4] = t + 1; }
            break; }
    }
}
