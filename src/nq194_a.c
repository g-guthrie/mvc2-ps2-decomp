typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { s32 w[0x31]; } W31a;
typedef struct { f32 x, y, z; } V3a;
typedef struct { s32 i0; s32 i4; s16 s8; s16 sA; s8 c; s8 d; u8 e; u8 f; } T16a;
typedef struct { u8 pad[0x7C]; s16 f7c[1]; } G3a;
typedef struct { u8 pad[0x34]; f32 f34; } PAa;
extern G3a *D_004C2794;
extern T16a D_004635A0[];

void residual_003624E0(u8 *p)
{
    extern void func_001757E0(u8 *, s32, u8);
    extern void func_0015E630(u8 *);
    extern void func_00362760(u8 *);
    u8 *q;
    u32 k;
    T16a *t;
    u8 *b2;
    q = *(u8 **)(p + 0x18);
    k = p[4]; p[4] = k + 1;
    *(u16 *)(p + 0x26) = 0x1001;
    *(W31a *)(p + 0xEC) = *(W31a *)(q + 0xEC);
    p[0x13C] = 1;
    p[2] = q[2];
    p[1] = q[1];
    *(f32 *)(p + 0x50) = *(f32 *)(q + 0x50);
    *(f32 *)(p + 0x54) = *(f32 *)(q + 0x54);
    p[0x1B7] = q[0x1B7];
    p[0x1B8] = q[0x1B8];
    *(s8 *)(p + 0x30) = *(s8 *)(q + 0x30);
    *(V3a *)(p + 0x50) = *(V3a *)(q + 0x50);
    *(s8 *)(p + 0x24) = *(s8 *)(q + 0x24);
    p[0x14C] = 0x20;
    p[0x14D] = 0x20;
    p[0x14E] = 0x20;
    p[0x14F] = 0x20;
    t = &D_004635A0[p[0x20]];
    *(s8 *)(p + 0x24) = t->c;
    *(s16 *)(p + 0x1C) = t->d;
    *(V3a *)(p + 0x34) = *(V3a *)(q + 0x34);
    b2 = p + 2;
    if (*(s16 *)(q + 0x140) == 0) {
        ((PAa *)p)->f34 += 1.6666666269302368f * (f32)t->s8;
        *(f32 *)(p + 0x5C) = 1.6666666269302368f * (f32)t->i0 / 65536.0f;
    } else {
        ((PAa *)p)->f34 -= 1.6666666269302368f * (f32)t->s8;
        *(f32 *)(p + 0x5C) = -(1.6666666269302368f * (f32)t->i0 / 65536.0f);
    }
    *(f32 *)(p + 0x38) += 2.142857074737549f * (f32)t->sA;
    *(s32 *)(p + 0x68) = 0;
    *(f32 *)(p + 0x60) = 2.142857074737549f * (f32)t->i4 / 65536.0f;
    *(s32 *)(p + 0x6C) = 0;
    p[0x1B0] = 0x44;
    p[0x1B1] = 0x44;
    p[0x1B5] = t->f;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(s32 *)(p + 0x1D8) = 0;
    D_004C2794->f7c[*b2]++;
    func_001757E0(p, 0x17, t->e);
    p[0] = 1;
    func_0015E630(p);
    func_00362760(p);
}
