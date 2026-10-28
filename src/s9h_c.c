/* MW 3.0 (try30.sh) -O3 -Op -sdatathreshold 0 */
#pragma opt_propagation off
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;
typedef struct { u32 w[0x31]; } BIG;
typedef struct { u8 pad[0xD0]; u8 b[8]; } SD;

void func_001C1780(u8 *p)
{
    extern void *func_001C1DA0(u8 *);
    extern void func_001C18A0(u8 *);
    u8 *q;
    u32 t;
    u8 *b;
    u8 *c;
    u8 *e;
    s32 m;
    s32 k;

    q = *(u8 **)(p + 0x18);
    e = q + 0x2B8;
    t = p[4];
    p[4] = t + 1;
    *(s16 *)(p + 0x26) = 0x1C02;
    *(BIG *)(p + 0xEC) = *(BIG *)(q + 0xEC);
    k = 1;
    p[0x13C] = k;
    p[2] = q[2];
    p[1] = q[1];
    *(f32 *)(p + 0x50) = *(f32 *)(q + 0x50);
    *(f32 *)(p + 0x54) = *(f32 *)(q + 0x54);
    p[0x1B7] = q[0x1B7];
    p[0x1B8] = q[0x1B8];
    *(s8 *)(p + 0x30) = *(s8 *)(q + 0x30);
    *(V3 *)(p + 0x50) = *(V3 *)(q + 0x50);
    *(s8 *)(p + 0x24) = *(s8 *)(q + 0x24);
    p[0x13C] = 0;
    m = -1;
    *(s8 *)(p + 0x31) = m;
    e[0] = k;
    b = ((SD *)p)->b;
    c = b + 8;
    if (b[8] == 0) {
        e[10] = k;
        if (func_001C1DA0(q) != 0) *c = 1;
    }
    func_001C18A0(p);
}
