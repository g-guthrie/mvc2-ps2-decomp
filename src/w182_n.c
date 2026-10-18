typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern volatile s32 D_00633E20;
extern u8 D_00633E30[];
extern u8 D_00633E34[];
extern u8 D_00633E35[];
extern u8 D_00633E36[];

s32 func_00422EA0(u32 id, s32 a1, s32 a2, s32 a3)
{
    s32 c1;
    s32 c2;
    s32 c3;
    s32 *e;
    s32 off;
    s32 t;
    s32 fl;
    off = D_00633E20 << 3;
    e = (s32 *)(D_00633E30 + off);
    if (*e >= 0) {
        return -1;
    }
    c2 = ((s8)a2 >= 0) ? 1 : 0;
    c1 = ((s8)a1 >= 0) ? 1 : 0;
    c3 = ((s16)a3 >= 0) ? 1 : 0;
    fl = ((c3 & 1) << 2) | ((c1 & 1) | ((c2 & 1) << 1));
    *e = ((s32)(s8)fl << 24) | (id & 0xFFFFFF);
    *(s8 *)(D_00633E34 + off) = a1;
    *(s8 *)(D_00633E35 + off) = a2;
    *(s16 *)(D_00633E36 + off) = a3;
    t = D_00633E20 + 1;
    D_00633E20 = t;
    D_00633E20 = t % 64;
    return 0;
}
