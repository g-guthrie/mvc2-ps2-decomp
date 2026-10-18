typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3_7570;
typedef struct { u8 *v[3]; } Row7570;
extern Row7570 D_004D18B8[];
extern u8 D_004D18E2[];

void func_00327570(u8 *p)
{
    extern void func_00186A60(u8 *, s32);
    u8 *q;
    s16 v;
    q = D_004D18B8[p[2]].v[p[0x26B]];
    if (*(s16 *)(q + 0x434) > 0 && *(s16 *)(q + 0x2B4) == 0) {
        q[0] = 1;
        q[0x13C] = 0;
        q[4] = 1;
        q[5] = 0;
        q[7] = 0;
        q[6] = 0;
        func_00186A60(q, 0x1C);
        q[0x26A] = 7;
        q[0x269] = 8;
        v = p[0x1E6];
        *(s16 *)(q + 0x140) = v;
        q[0x1E6] = v;
        *(V3_7570 *)(q + 0x34) = *(V3_7570 *)(p + 0x34);
        q[0x159] = 0xFF;
        *(s16 *)(q + 0x356) = 0;
        *(s16 *)(q + 0x35C) = 0;
        *(s16 *)(q + 0x354) = 0;
        *(s16 *)(q + 0x360) = 0;
        *(s16 *)(q + 0x362) = 0;
        *(s16 *)(q + 0x35E) = 0;
        D_004D18E2[p[2]] |= 1 << *(s8 *)(q + 0x425);
        p[0x26D] = 1;
    }
}
