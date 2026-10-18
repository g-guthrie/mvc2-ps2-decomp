typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct {f32 x,y,z;} V3;

void func_0022AAF0(u8 *p) {
    extern void func_00175700(u8 *);
    extern void func_00183920(u8 *, f32 *);
    func_00175700(p);
    if (*(s8 *)(p + 0x151) != 0) {
        f32 v[4];
        u32 t = p[6];
        p[6] = t + 1;
        p[0x151] = 0;
        v[0] = 45.0f;
        v[1] = 205.7142792f;
        func_00183920(p, v);
    }
}

void func_00279C80(u8 *p) {
    extern void func_00175700(u8 *);
    extern void func_001830D0(u8 *, f32 *, s32);
    func_00175700(p);
    if (*(s8 *)(p + 0x151) != 0) {
        f32 v[4];
        u32 t = p[6];
        p[6] = t + 1;
        p[0x151] = 0;
        v[0] = -53.33333206f;
        v[1] = 214.28570556f;
        v[2] = 0.0f;
        func_001830D0(p, v, 1);
    }
}

void func_002C7830(u8 *p) {
    extern void func_001757E0(u8 *, s32, s32);
    s16 v;
    p[0x33A] = 0xFF;
    p[0x13C] = 0;
    p[0x209] = 1;
    v = *(s16 *)(p + 0x1E) - 1;
    *(s16 *)(p + 0x1E) = v;
    if (v < 0) {
        u32 t = p[6];
        p[6] = t + 1;
        p[0x13C] = 1;
        *(f32 *)(p + 0x38) = 137.14285278f + *(f32 *)(p + 0x430);
        func_001757E0(p, 0x15, 6);
    }
}
