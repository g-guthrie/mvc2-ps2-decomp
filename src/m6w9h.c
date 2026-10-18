typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;


typedef struct { u8 p0[5]; u8 b5; u8 p1[0x2E]; f32 f34; f32 f38; u8 p3[0x20]; f32 f5c; f32 f60; u8 p4[4]; f32 f68; f32 f6c; } S34;
typedef struct { u8 p0[0x430]; f32 f430; } Q34;
extern void func_00175700(void *);
void func_0034AAA0(S34 *p, Q34 *q) {
    p->f34 += p->f5c;
    p->f5c += p->f68;
    p->f38 += p->f60;
    p->f60 += p->f6c;
    if (p->f38 > 548.5714111328125f + q->f430) {
        p->f38 = 548.5714111328125f + q->f430;
        p->b5++;
    }
    func_00175700(p);
}
