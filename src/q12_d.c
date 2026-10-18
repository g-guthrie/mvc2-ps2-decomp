typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef float f32;
extern s32 func_00175700(void *p);
typedef struct { f32 x, y, z; } V3;
extern u8 *D_004D18C4;
extern u8 D_004D18A0;
extern f32 D_004F1F50;
extern s32 func_00174810(void *p);
void func_0015BF10(u8 *p)
{
    u8 *o = D_004D18C4;
    p[0x13C] = 0;
    if (D_004D18A0 > 3) {
        if (func_00174810(o) == 0) {
            p[0x13C] = 1;
        }
    }
    *(V3 *)(p + 0x34) = *(V3 *)(o + 0x34);
    *(f32 *)(p + 0x38) = D_004F1F50 - 50.0f;
    *(f32 *)(p + 0x3C) += 5.0f;
}

extern void func_0013B3C0(void *p, s32 a);
extern void func_0013B7D0(void *p);
extern void func_0013D0F0(void *p);
void func_0013AA10(u8 *p)
{
    u8 a = p[5];
    switch (a) {
    case 0:
        p[5] = a + 1;
        func_0013B3C0(p, 0);
        func_0013B7D0(p);
        func_0013D0F0(p);
    case 1:
        *(f32 *)(p + 0x54) += 0.1f;
        if (*(f32 *)(p + 0x54) >= 1.0f) {
            { u32 c = p[5]; p[5] = c + 1; }
            *(f32 *)(p + 0x54) = 1.0f;
        }
    case 2:
        break;
    default:
        break;
    }
}

typedef struct { u8 p0[5]; u8 b5; u8 p6[0x2E]; f32 f34; u8 p38[0x38]; f32 f70; } S8;
void func_00134500(S8 *p)
{
    f32 z = 0.0f;
    f32 d = p->f70 - p->f34;
    if (d == z) {
        u32 c = p->b5;
        p->b5 = c + 1;
        d = 4.0f * (p->f70 - p->f34);
    }
    d /= 4.0f;
    if (d < 0.03125f && d > -0.03125f) {
        d = p->f70 - p->f34;
    }
    p->f34 += d;
}

extern f32 D_00451980[];
extern f32 D_0045198C[];
extern void func_00186A20(void *p);
void func_00228EA0(u8 *p)
{
    f32 v;
    func_00175700(p);
    if (*(s8 *)(p + 0x151) != 0) {
        u32 c = p[6];
        p[6] = c + 1;
        func_00186A20(p);
        *(f32 *)(p + 0x38) += 34.285713195800781f;
        v = D_00451980[p[0x1B7]];
        if (*(s16 *)(p + 0x140) != 0) v = -v;
        *(f32 *)(p + 0x5C) = v;
        *(u32 *)(p + 0x60) = 0;
        *(u32 *)(p + 0x68) = 0;
        *(f32 *)(p + 0x6C) = D_0045198C[p[0x1B7]];
    }
}
