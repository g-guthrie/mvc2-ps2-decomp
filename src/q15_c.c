typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;
typedef struct {
    u8 p0[0x34];
    f32 f34, f38, f3c;
    u8 p1[0x5C - 0x40];
    f32 f5c, f60, f64, f68, f6c;
    u8 p2[0x430 - 0x70];
    f32 f430;
} Obj;
extern s8 func_00175700();
extern void func_001757E0();

typedef struct { u8 p0[0x50]; f32 f50, f54; } O50;
void func_0036DCC0(O50 *o) {
    u8 *p = (u8 *)o;
    if (o->f50 > 1.0f) {
        *(f32 *)(p + 0x50) = 1.0f;
        *(f32 *)(p + 0x54) = 1.0f;
    } else {
        *(f32 *)(p + 0x50) += 0.039999999f;
        *(f32 *)(p + 0x54) += 0.039999999f;
    }
    func_00175700(p);
    if (*(s8 *)(p + 0x153) < 0) {
        u32 t = p[5];
        p[5] = t + 1;
        func_001757E0(p, 0x17, 0x1E);
    }
}
