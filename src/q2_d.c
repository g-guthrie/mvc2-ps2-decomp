typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;


typedef struct { f32 x, y, z; } V3d;
typedef struct {
    u8 f0; u8 p0[0x34 - 1]; V3d f34; u8 p1[0x54 - 0x40]; f32 f54;
    u8 p2[0x13C - 0x58]; s8 f13c; u8 p3[0x14C - 0x13D]; u8 f14c; u8 p4[0x269 - 0x14D]; u8 f269;
} Q15C;
typedef struct { u8 p0[0x34]; V3d f34; f32 p1; u8 p2[0x13C - 0x44]; s8 f13c; } P15C;
extern Q15C *D_004D18C0;
extern f32 D_004F1FD4;
extern u8 D_004D18A0[];

void func_0015C450(P15C *p)
{
    Q15C *q = D_004D18C0;
    f32 f;
    p->f13c = 0;
    if (q->f0 != 0 && q->f269 == 8 && D_004D18A0[0] == 4 && q->f13c != 0) p->f13c = 1;
    p->f34 = q->f34;
    f = (f32)(u32)q->f14c;
    p->f34.y += 2.142857074737549f * f * q->f54;
    p->f34.y += 100.0f;
    p->f34.z += 2.0f;
    if (p->f34.y <= 100.0f + D_004F1FD4) p->f34.y = 100.0f + D_004F1FD4;
}
