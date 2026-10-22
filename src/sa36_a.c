typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;
typedef struct { f32 a, b, c, d; } V4;
extern s32 D_004C2834;
extern u8 D_004F20B0[];
extern u8 D_004BF328[8];
extern V3 D_0043DD80[];
extern V4 D_0043E130;
extern s32 D_004CAB90[];

void func_00131B50(s32 n) {
    extern u8 *func_003DA750(s32, s32, s32);
    extern void func_00132810();
    extern void func_00131CE0(u8 *, s32);
    extern void func_00132120(u8 *, s32);
    extern void func_00132210(u8 *, s32);
    extern void func_00132400(u8 *, s32);
    u8 *o;
    u8 *e, *t, *q;
    s32 c;
    u32 m;
    u32 w;
    s32 *z;
    if ((o = func_003DA750(0, 0xE, 1)) != 0) {
        o[0x13C] = 1;
        *(void **)(o + 0x10) = func_00132810;
        c = 0x3D;
        if ((n & 1) != 0) {
            c = 0x46;
        }
        *(s16 *)(o + 0xCC) = c;
        *(s32 *)(o + 0x84) = D_004C2834;
        e = D_004F20B0 + n * 0x5B8;
        t = D_004BF328 + e[0x425];
        q = t + e[2] * 3;
        w = *q;
        if ((*(u32 *)(e + 0x428) & 0x7000000) != 0) {
            w = w + 0x12;
        }
        *(V3 *)(o + 0x34) = *(V3 *)((u8 *)D_0043DD80 + w * 12);
        *(u32 *)(o + 0xD0) = 0x10C21;
        o[2] = n & 1;
        o[0x20] = n;
        o[0x21] = e[0x425];
        *(u8 **)(o + 0x18) = e;
        *(V4 *)(o + 0x74) = D_0043E130;
        *(s16 *)(o + 0x1C) = 0;
        z = (s32 *)((u32)D_004CAB90 + 0);
        z[0] = 0;
        z[1] = 0;
        z[2] = 0;
        z[3] = 0;
        z[4] = 0;
        z[5] = 0;
        func_00131CE0(o, n);
        func_00132120(o, n);
        func_00132210(o, n);
        func_00132400(o, n);
    }
}
