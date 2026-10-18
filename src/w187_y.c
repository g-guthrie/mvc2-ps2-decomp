typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;
typedef struct { u8 p0[0x34]; f32 f34; f32 f38; f32 f3C; u8 p1[0x100]; s16 h140; } PF;
extern void func_00176160(u8 *, s32, s32, s32);
extern void func_001754A0(u8 *, s32, s32);
extern void func_0015E630(u8 *);

void func_001B0510(u8 *p) {
    s32 n;
    s32 *d;
    s32 *s;
    u32 t;
    u8 *q;
    f32 k;
    n = 0x31;
    d = (s32 *)(p + 0xEC);
    t = p[4]; p[4] = t + 1;
    q = *(u8 **)(p + 0x18);
    s = (s32 *)(q + 0xEC);
    do {
        *d++ = *s++;
    } while (--n > 0);
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
    p[0x24] = 7;
    *(u32 *)(p + 0x118) = 0x3F800000;
    ((PF *)p)->f34 = ((PF *)(*(u8 **)(p + 0x18)))->f34;
    ((PF *)p)->f38 = ((PF *)(*(u8 **)(p + 0x18)))->f38;
    ((PF *)p)->f3C = ((PF *)(*(u8 **)(p + 0x18)))->f3C;
    k = (((PF *)(*(u8 **)(p + 0x18)))->h140 != 0) ? 160.0f : -160.0f;
    *(f32 *)((s32)p + 0x34) += k;
    *(u32 *)(p + 0x54) = 0x3F800000;
    func_00176160(q, 3, 3, 1);
    func_00176160(q, 5, 5, 1);
    func_001754A0(p, 0x1B, 0xC);
    func_0015E630(p);
    p[0] = 1;
}
