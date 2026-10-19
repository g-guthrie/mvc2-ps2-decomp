typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;

extern void func_00175670(u8 *);
extern void func_003DAA40(u8 *);

void func_003C06A0(u8 *p)
{
    u8 *o;
    u8 *q;
    f32 dx;
    f32 dy;
    f32 t;
    f32 k;
    func_00175670(p);
    o = *(u8 **)(p + 0x18);
    q = *(u8 **)(p + 0xD8);
    *(V3 *)(p + 0x34) = *(V3 *)(o + 0x34);
    t = 40.0f;
    if (*(s16 *)(q + 0x140) != 0)
        t = -t;
    dx = (t + *(f32 *)(q + 0x34) - *(f32 *)(p + 0x34)) / 8.0f;
    dy = (342.85711669921875f + *(f32 *)(q + 0x38) - *(f32 *)(p + 0x38)) / 8.0f;
    k = (f32)p[0x20];
    *(f32 *)(p + 0x34) += dx * k;
    k = (f32)p[0x20];
    *(f32 *)(p + 0x38) += dy * k;
    p[0x15D] = (u8)((o[0x22] & 0x1F) >> 1);
    if (o[4] >= 2) {
        p[0x13C] = 0;
        func_003DAA40(p);
    }
}
