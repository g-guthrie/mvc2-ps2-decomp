typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z, w; } V4;

void func_002D5A70(u8 *p) {
    extern s32 func_00175700(u8 *);
    extern s32 func_00182E20(u8 *);
    extern s32 func_00182D30(u8 *);
    extern void func_0018FDB0(u8 *);
    extern void func_00154790(V4 *, s32, s32, s32);
    extern void func_001E3B70(u8 *, s32);
    extern void func_001E3210(u8 *, s32);
    extern void func_001264D0(void);
    V4 v;
    u8 *o;
    s32 t;
    func_00175700(p);
    *(s16 *)(p + 0x1C) -= 1;
    if (*(s16 *)(p + 0x1C) <= 0) goto retry;
    if (func_00182E20(p) != 0) p[0x152] = 1;
    if (func_00182D30(*(u8 **)(p + 0x1DC)) != 0) goto retry;
    t = *(s8 *)(p + 0x151);
    if (t == 0) return;
    if ((s8)t >= 0) goto blockA;
    p[0x151] = 0;
    *(u8 **)(*(u8 **)(p + 0x1DC) + 0x1C8) = p;
    *(s8 *)(*(u8 **)(p + 0x1DC) + 0x1B5) = 0x23;
    func_0018FDB0(p);
    v.y = 17.14285659790039f + *(f32 *)(p + 0x38);
    if (*(s16 *)(p + 0x140) != 0) v.x = 26.66666603088379f;
    else v.x = -26.66666603088379f;
    v.x += *(f32 *)(p + 0x34);
    v.z = *(f32 *)(p + 0x3C);
    func_00154790(&v, *(s16 *)(p + 0x140), 1, 0);
    func_001E3B70(*(u8 **)(p + 0x1DC), 0);
    func_001E3210(p, 3);
    return;
retry:
    p[0x152] = 1;
    func_00175700(p);
    if (*(s8 *)(p + 0x151) <= 0) goto retry;
blockA:
    p[6]++;
    func_001264D0();
    p[0x151] = 0;
    *(u8 **)(*(u8 **)(p + 0x1DC) + 0x1C8) = p;
    (*(u8 **)(p + 0x1DC))[0x20A] = 3;
    (*(u8 **)(p + 0x1DC))[0x1B5] = 0x21;
    if (p[1] == 0x1C || p[1] == 0x31) {
        o = *(u8 **)(p + 0x1DC);
        o[0x1E6] ^= 1;
    }
}
