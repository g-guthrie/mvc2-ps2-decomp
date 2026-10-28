typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x7C]; s16 f7c[4]; } G25;
extern G25 *D_004C2794;
extern f32 D_004535C0[];


void func_002C9930(u8 *p, u8 *q)
{
    extern void func_00175700(u8 *);
    s16 v;
    f32 a;
    f32 b;
    u32 t;
    p[0x40C] = 2;
    p[0x33C] = 5;
    v = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = v;
    if (v < 0) {
    func_00175700(p);
    if (*(s8 *)(p + 0x161) != 0) {
    t = p[6];
    p[6] = t + 1;
    p[0x20D] = 2;
    q[2] = 0;
    a = p[0x1E6] ? 13.333333015441895f : -13.333333015441895f;
    *(f32 *)(p + 0x5C) = a;
    b = p[0x1E6] ? -0.3125f : 0.3125f;
    *(f32 *)(p + 0x68) = b;
    *(u32 *)(p + 0x60) = 0x40CDB6DB;
    *(u32 *)(p + 0x6C) = 0xBF4DB6DB;
    return;
    }
    return;
    }
}
