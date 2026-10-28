typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;
typedef struct { s32 w[0x31]; } B4a;
typedef struct { u8 pad[0x7C]; s16 f7c[1]; } G4a;
typedef struct { s32 a, b; s16 c, d; u8 e, f; } T4a;
typedef struct { u8 pad[0x34]; f32 f34, f38; } O4a;
extern G4a *D_004C2794;
extern T4a D_004719A0[];


void residual_0038D410(u8 *o) {
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_0038D660(u8 *);
    T4a *t;
    u8 *q;
    u8 *p2;
    u32 v;
    f32 k;
    v = o[4];
    o[4] = v + 1;
    *(s16 *)(o + 0x26) = 0x1D06;
    q = *(u8 **)(o + 0x18);
    *(B4a *)(o + 0xEC) = *(B4a *)(q + 0xEC);
    o[0x13C] = 1;
    o[2] = q[2];
    o[1] = q[1];
    *(f32 *)(o + 0x50) = *(f32 *)(q + 0x50);
    *(f32 *)(o + 0x54) = *(f32 *)(q + 0x54);
    o[0x1B7] = q[0x1B7];
    o[0x1B8] = q[0x1B8];
    *(s8 *)(o + 0x30) = *(s8 *)(q + 0x30);
    *(V3 *)(o + 0x50) = *(V3 *)(q + 0x50);
    *(s8 *)(o + 0x24) = *(s8 *)(q + 0x24);
    o[0x24] = 8;
    o[0x13C] = 1;
    t = &D_004719A0[o[0x20]];
    *(V3 *)(o + 0x34) = *(V3 *)(q + 0x34);
    p2 = o + 2;
    if (*(s16 *)(o + 0x140) == 0) {
        k = 1.6666666269302368f;
        ((O4a *)o)->f34 += k * (f32)t->c;
        *(f32 *)(o + 0x5C) = k * (f32)t->a / 65536.0f;
    } else {
        k = 1.6666666269302368f;
        ((O4a *)o)->f34 -= k * (f32)t->c;
        *(f32 *)(o + 0x5C) = -(k * (f32)t->a / 65536.0f);
    }
    k = 2.142857074737549f;
    ((O4a *)o)->f38 += k * (f32)t->d;
    *(f32 *)(o + 0x60) = k * (f32)t->b / 65536.0f;
    *(s32 *)(o + 0x68) = 0;
    *(s32 *)(o + 0x6C) = 0;
    o[0x1B0] = 0x44;
    o[0x1B1] = 0x44;
    o[0x1B5] = t->f;
    o[0x1B2] = *(u16 *)(o + 0x1C0) = 0;
    *(s32 *)(o + 0x1D8) = 0;
    D_004C2794->f7c[*p2]++;
    func_001757E0(o, 0x17, t->e);
    func_0038D660(o);
}
