typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { s16 v[6]; } E6c;
typedef struct { E6c e[3]; } R3c;

extern R3c D_00473BA0[];
extern u8 D_004C1F5C[8];

void func_003AF770(u8 *a, u8 *o, u8 *p)
{
    extern void func_00175580();
    u16 *q = (u16 *)(p + 0x2B8);
    u8 i;
    E6c *e;
    f32 k1, k3, x, y, z;

    i = 0;
    if (*(s8 *)(p + 0x151) < 0) i = 1;
    e = &D_00473BA0[i].e[*q];
    k1 = 2.142857074737549f;
    k3 = 1.6666666269302368f;
    *(f32 *)(o + 0x10) = k1 * (f32)e->v[1];
    *(f32 *)(o + 0x18) = k1 * (f32)e->v[3];
    *(f32 *)(o + 0x20) = k1 * (f32)e->v[5];
    x = k3 * (f32)e->v[0];
    y = k3 * (f32)e->v[2];
    z = k3 * (f32)e->v[4];
    if (*(s16 *)(p + 0x140) != 0) {
        x = -x;
        y = -y;
        z = -z;
    }
    *(f32 *)(o + 0xC) = x;
    *(f32 *)(o + 0x14) = y;
    *(f32 *)(o + 0x1C) = z;
    func_00175580(a, 0x1B, D_004C1F5C[*q], i);
}
