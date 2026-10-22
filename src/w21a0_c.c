typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;

void func_0017BA10(u8 *p)
{
    extern void func_0015A4A0(V3 *, s32);
    extern void func_001E3710(u8 *, s32);
    extern void func_001820A0(u8 *);
    extern void func_00182300(u8 *);
    extern void func_00175700(u8 *);
    extern void func_0018D0C0(u8 *);
    extern s32 func_00184720(u8 *);
    extern s32 func_00185EC0(u8 *);
    extern void func_00186A60(u8 *, s32);
    extern void func_001757E0(u8 *, s32, s32);
    extern s32 func_001864a0(u8 *);
    extern s32 func_00185A90(u8 *);
    extern s32 func_00186030(u8 *);
    extern void func_001865B0(u8 *);
    V3 v;
    s32 t;

    if (*(s8 *)(p + 0x1F1) < 0 && *(s8 *)(p + 0x1F2) != 0) {
        p[6] = 2;
        *(s16 *)(p + 0x1C) = 0x1C;
        p[0x1F1] = 0;
        v.x = *(f32 *)(p + 0x260);
        v.y = *(f32 *)(p + 0x264);
        v.z = *(f32 *)(p + 0x3C);
        func_0015A4A0(&v, *(s16 *)(p + 0x140));
        func_001E3710(p, 0x44);
        return;
    }
    func_001820A0(p);
    func_00182300(p);
    func_00175700(p);
    t = *(s8 *)(p + 0x1F2);
    if (t != 0) {
        p[0x1F2] = t - 1;
        func_0018D0C0(p);
        goto L64;
    }
    p[0x225] = 0;
    if (func_00184720(p) != 0) return;
    if (func_00185EC0(p) == 0) {
        if (*(f32 *)(p + 0x6C) > -0.0669642836f) *(u32 *)(p + 0x6C) = 0xBF4DB6DB;
        *(u32 *)(p + 0x68) = 0;
        if (p[0x210] == 0) {
            p[6] = 1;
            func_00186A60(p, 3);
        } else {
            p[6] = 1;
            func_00186A60(p, 0xE);
        }
        func_001757E0(p, 1, 9);
        return;
    }
L64:
    if (func_001864a0(p) == 0) return;
    if (*(s8 *)(p + 0x1F2) != 0) p[0x203] = 8;
    if (func_00185A90(p) != 0) return;
    if (func_00186030(p) != 0) return;
    func_001865B0(p);
}
