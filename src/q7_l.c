typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;


typedef struct { f32 x, y, z; } V3;
typedef struct { s32 w[0x31]; } Blk;

void func_003AE5F0(u8 *p) {
    extern void func_001757E0();
    u32 t = p[4];
    p[4] = t + 1;
    *(Blk *)(p + 0xEC) = *(Blk *)(*(u8 **)(p + 0x18) + 0xEC);
    p[0x13C] = 1;
    p[2] = (*(u8 **)(p + 0x18))[2];
    p[1] = (*(u8 **)(p + 0x18))[1];
    *(f32 *)(p + 0x50) = *(f32 *)(*(u8 **)(p + 0x18) + 0x50);
    *(f32 *)(p + 0x54) = *(f32 *)(*(u8 **)(p + 0x18) + 0x54);
    p[0x1B7] = (*(u8 **)(p + 0x18))[0x1B7];
    p[0x1B8] = (*(u8 **)(p + 0x18))[0x1B8];
    *(s8 *)(p + 0x30) = *(s8 *)(*(u8 **)(p + 0x18) + 0x30);
    *(V3 *)(p + 0x50) = *(V3 *)(*(u8 **)(p + 0x18) + 0x50);
    *(s8 *)(p + 0x24) = *(s8 *)(*(u8 **)(p + 0x18) + 0x24);
    p[0x24] = 0;
    *(s16 *)(p + 0x1E) = 8;
    if (p[0x21] == 0) {
        p[0x168] = 3;
    } else {
        p[0x168] = 5;
    }
    func_001757E0(p, 0x13, p[0x168]);
}

void func_001B07F0(u8 *p) {
    extern void func_001754A0();
    u8 *q;
    f32 v;
    u32 t = p[4];
    p[4] = t + 1;
    q = *(u8 **)(p + 0x18);
    *(Blk *)(p + 0xEC) = *(Blk *)(q + 0xEC);
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
    *(f32 *)(p + 0x118) = 1.0f;
    *(f32 *)(p + 0x34) = *(f32 *)(*(u8 **)(p + 0x18) + 0x34);
    *(f32 *)(p + 0x38) = *(f32 *)(*(u8 **)(p + 0x18) + 0x38);
    *(f32 *)(p + 0x3C) = *(f32 *)(*(u8 **)(p + 0x18) + 0x3C);
    if (*(s16 *)(*(u8 **)(p + 0x18) + 0x140) != 0) {
        v = 160.0f;
    } else {
        v = -160.0f;
    }
    *(f32 *)(p + 0x34) += v;
    *(f32 *)(p + 0x50) = 0.800000011920929f;
    *(f32 *)(p + 0x54) = 0.800000011920929f;
    func_001754A0(p, 0x1B, 0xE);
}
