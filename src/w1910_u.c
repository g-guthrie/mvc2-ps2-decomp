typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3_u;
typedef struct { s32 a, b, c; } T3_u;
extern T3_u D_004D18B8[];
extern T3_u D_004D18BC[];
extern T3_u D_004D18C0[];

void func_00183920(u8 *p, f32 *q)
{
    extern void func_0018C6B0(u8 *, s32);
    extern s32 func_00327CF0(u8 *, s32);
    extern void func_00160C40(V3_u *, s32, s32, s32);
    extern void func_001E3710(u8 *, s32);
    extern void func_00183A70(u8 *);
    extern void func_00175C00(s32, s32);
    V3_u v;
    func_0018C6B0(p, 1);
    if (func_00327CF0(p, 6) != 0) {
        v = *(V3_u *)(p + 0x34);
        v.y += q[1];
        if (*(s16 *)(p + 0x140) == 0) {
            v.x += q[0];
        } else {
            v.x -= q[0];
        }
        func_00160C40(&v, *(s16 *)(p + 0x140), 0, 0);
        func_001E3710(p, 0x40);
        func_00183A70(p);
        func_00175C00(D_004D18B8[p[2] ^ 1].a, 2);
        func_00175C00(D_004D18BC[p[2] ^ 1].a, 2);
        func_00175C00(D_004D18C0[p[2] ^ 1].a, 2);
    }
}
