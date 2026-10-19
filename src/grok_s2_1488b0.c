typedef unsigned char u8;
typedef signed short s16;
typedef float f32;

extern u8 *D_004CB5D0;
extern void func_0012AD00(u8 *);

void func_001488B0(u8 *p)
{
    u8 *g;
    f32 *v;
    if (p[0x23] == 0)
        p[0x13C] = 1;
    else if (p[0x23] == 1) {
        g = D_004CB5D0;
        v = (f32 *)(0x00442AB0 + (*(s16 *)(g + 8) << 4));
        *(f32 *)(p + 0x34) = v[0];
        *(f32 *)(p + 0x38) = v[1];
        *(f32 *)(p + 0x3C) = v[2];
        *(f32 *)(p + 0x3C) = v[2] + 0.01f;
        if (*(int *)(p + 0xD8) != *(s16 *)(D_004CB5D0 + 8)) {
            *(int *)(p + 0xD8) = *(s16 *)(D_004CB5D0 + 8);
            *(s16 *)(p + 0x1E) = 0;
        }
        func_0012AD00(p);
    }
}
