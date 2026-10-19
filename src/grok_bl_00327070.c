typedef unsigned char u8;
typedef signed short s16;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;
typedef struct { u8 *v[3]; } Row;
extern Row D_004D18B8[];
extern void func_00186A60(u8 *, s32);
extern void func_00185490(u8 *);
extern void func_00186800(u8 *);
extern void func_00180D20(u8 *, u8 *);
extern void func_001833C0(u8 *);

void func_00327070(u8 *p)
{
    u8 *q;
    s16 v;

    q = D_004D18B8[p[2]].v[p[0x26B]];
    if (*(s16 *)(q + 0x434) > 0 && *(s16 *)(q + 0x2B4) == 0) {
        q[0] = 1;
        q[0x13C] = 0;
        q[4] = 1;
        q[5] = 0;
        q[6] = 0;
        q[7] = 0;
        func_00186A60(q, 0x1C);
        q[0x26A] = 5;
        q[0x269] = 3;
        q[0x404] = 0xFF;
        q[0x405] = 0x10;
        q[0x425] = 0;
        p[0x425] = p[0x26B];
        v = p[0x1E6];
        *(s16 *)(q + 0x140) = v;
        q[0x1E6] = (u8)v;
        *(V3 *)(q + 0x34) = *(V3 *)(p + 0x34);
        q[0x159] = 0xFF;
        func_00185490(q);
        func_00186800(q);
        func_00180D20(q, p);
        func_001833C0(q);
    }
}
