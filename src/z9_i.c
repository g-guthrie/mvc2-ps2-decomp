typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;
typedef struct { s32 x[49]; } S49;

void func_001DE180(u8 *p, u8 *q) {
    extern void func_001757E0();
    extern void func_001DE270();
    u32 t = p[4];
    p[4] = t + 1;
    *(S49 *)(p + 0xEC) = *(S49 *)(q + 0xEC);
    p[0x13C] = 1;
    p[2] = q[2];
    p[1] = q[1];
    *(f32 *)(p + 0x50) = *(f32 *)(q + 0x50);
    *(f32 *)(p + 0x54) = *(f32 *)(q + 0x54);
    p[0x1B7] = q[0x1B7];
    p[0x1B8] = q[0x1B8];
    *(s8 *)(p + 0x30) = *(s8 *)(q + 0x30);
    *(V3 *)(p + 0x50) = *(V3 *)(q + 0x50);
    *(s8 *)(p + 0x24) = *(s8 *)(q + 0x24);
    p[0x13C] = 1;
    p[0x31] = 1;
    *(f32 *)(p + 0x3C) = *(f32 *)(q + 0x3C);
    func_001757E0(p, 0x17, 8);
    func_001DE270(p, q);
}

#define Q (*(u8 **)(p + 0x18))

void func_00379070(u8 *p) {
    extern void func_00379350();
    f32 k = 548.5714111328125f;
    u32 t = p[4];
    p[4] = t + 1;
    *(S49 *)(p + 0xEC) = *(S49 *)(Q + 0xEC);
    p[0x13C] = 1;
    p[2] = Q[2];
    p[1] = Q[1];
    *(f32 *)(p + 0x50) = *(f32 *)(Q + 0x50);
    *(f32 *)(p + 0x54) = *(f32 *)(Q + 0x54);
    p[0x1B7] = Q[0x1B7];
    p[0x1B8] = Q[0x1B8];
    *(s8 *)(p + 0x30) = *(s8 *)(Q + 0x30);
    *(V3 *)(p + 0x50) = *(V3 *)(Q + 0x50);
    *(s8 *)(p + 0x24) = *(s8 *)(Q + 0x24);
    p[0x24] = 10;
    *(f32 *)(p + 0x34) = *(f32 *)(Q + 0x34);
    {
        f32 v = *(f32 *)(Q + 0x38);
        *(f32 *)(p + 0x38) = v;
        *(f32 *)(p + 0x38) = v + k;
    }
    func_00379350(p);
}
