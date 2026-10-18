typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { s32 x[0x31]; } S31;
typedef struct { f32 x, y, z; } V3;

void func_001B2380(u8 *p) {
    extern void func_001754A0();
    u8 *q;
    u32 t;
    f32 c, d;
    f32 a0, a1, a2;
    t = p[4];
    p[4] = t + 1;
    q = *(u8 **)(p + 0x18);
    *(S31 *)(p + 0xEC) = *(S31 *)(q + 0xEC);
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
    p[0x24] = 0;
    *(s16 *)(p + 0x140) = *(s16 *)(*(u8 **)(p + 0x18) + 0x140);
    *(f32 *)(p + 0x34) = *(f32 *)(*(u8 **)(p + 0x18) + 0x34);
    *(f32 *)(p + 0x38) = *(f32 *)(*(u8 **)(p + 0x18) + 0x38);
    *(f32 *)(p + 0x3C) = *(f32 *)(*(u8 **)(p + 0x18) + 0x3C);
    if (*(s16 *)(p + 0x140) != 0) {
        c = 116.66666412353516f;
    } else {
        c = -116.66666412353516f;
    }
    d = 12.857142448425293f;
    *(f32 *)(p + 0x34) += c;
    *(f32 *)(p + 0x38) += d;
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x6C) = 0;
    func_001754A0(p, 0x1B, 0xE);
}
