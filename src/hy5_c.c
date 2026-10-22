typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { s16 a; s16 b; } T4;
extern T4 D_0044E560[];

void func_001D5E90(u8 *p, u8 *q)
{
    extern void func_001D6B20(u8 *, u8 *);
    extern void func_00175700(u8 *);
    u8 *r;
    u16 *pd;
    s8 t;
    s8 a = q[0x24];
    r = q + 0x2B8;
    t = a + (s8)p[0x31];
    p[0x24] = t;
    pd = (u16 *)(p + 0xD0);
    if ((s8)p[0x24] > 7) {
        p[0x24] = 7;
    }
    if ((s8)p[0x24] < 0) {
        p[0x24] = 0;
    }
    if (*(u16 *)(q + 0x168) != *pd) {
        u32 c = p[4];
        p[4] = c + 1;
        func_001D6B20(p, q);
        return;
    }
    func_00175700(p);
    *(f32 *)(p + 0x34) = *(f32 *)(q + 0x34);
    *(f32 *)(p + 0x38) = *(f32 *)(q + 0x38);
    *(f32 *)(p + 0x3C) = *(f32 *)(q + 0x3C);
    if (*(s16 *)(p + 0x140) == 0) {
        *(f32 *)(p + 0x34) += 1.6666666269302368f * (f32)D_0044E560[p[0x21]].a;
    } else {
        *(f32 *)(p + 0x34) -= 1.6666666269302368f * (f32)D_0044E560[p[0x21]].a;
    }
    *(f32 *)(p + 0x38) += 2.142857074737549f * (f32)D_0044E560[p[0x21]].b;
    if (*r != 0) {
        u32 c = p[4];
        p[4] = c + 1;
    }
}
