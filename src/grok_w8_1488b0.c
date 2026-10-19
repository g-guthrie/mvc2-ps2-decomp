typedef unsigned char u8;
typedef signed short s16;
typedef float f32;

extern u8 *D_004C2840;
extern f32 D_00442AB0[];
extern void func_0012AD00(u8 *);

void func_001488B0(u8 *p)
{
    u8 *g;
    f32 *vec;
    u8 st = p[0x23];

    if (st == 0)
        p[0x13C] = 1;
    else if (st == 1) {
        g = D_004C2840;
        vec = D_00442AB0 + (*(s16 *)(g + 8) * 4);
        *(f32 *)(p + 0x34) = vec[0];
        *(f32 *)(p + 0x38) = vec[1];
        *(f32 *)(p + 0x3C) = vec[2] + 0.01f;
        if (*(int *)(p + 0xD8) != *(s16 *)(D_004C2840 + 8)) {
            *(int *)(p + 0xD8) = *(s16 *)(D_004C2840 + 8);
            *(s16 *)(p + 0x1E) = 0;
        }
        func_0012AD00(p);
    }
}
