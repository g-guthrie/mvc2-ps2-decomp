typedef unsigned char u8;
typedef signed short s16;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;

extern u8 *D_004C2840;
extern V3 D_00442AB0[];
extern void func_0012AD00(u8 *);

void func_001488B0(u8 *p)
{
    V3 *vec;
    f32 z;

    if (p[0x23] == 0)
        p[0x13C] = 1;
    else if (p[0x23] == 1) {
        vec = &D_00442AB0[*(s16 *)(D_004C2840 + 8)];
        z = vec->z;
        *(f32 *)(p + 0x34) = vec->x;
        *(f32 *)(p + 0x38) = vec->y;
        *(f32 *)(p + 0x3C) = z;
        *(f32 *)(p + 0x3C) = z + 0.009999999776482582f;
        if (*(s32 *)(p + 0xD8) != *(s16 *)(D_004C2840 + 8)) {
            *(s32 *)(p + 0xD8) = *(s16 *)(D_004C2840 + 8);
            *(s16 *)(p + 0x1E) = 0;
        }
        func_0012AD00(p);
    }
}
