typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 *D_004C2840;
void func_0014DFD0(u8 *p)
{
    extern void func_0014E0E0(u8 *);
    s32 x;
    s32 v;
    if (p[4] == 0) {
        x = *(s8 *)(D_004C2840 + 7);
        if (x != 0) {
            if ((s8)x == 1) p[4] = 1;
            else p[4] = 2;
        }
    }
    if (p[4] != 0) func_0014E0E0(p);
    v = *(s8 *)(D_004C2840 + 6) + *(s16 *)(p + 0x1E);
    switch (v) {
    case 0:
        *(f32 *)(p + 0x78) = 1.0f;
        *(f32 *)(p + 0x7C) = 0.8999999761581421f;
        *(f32 *)(p + 0x80) = 0.30000001192092896f;
        break;
    case 1:
        *(f32 *)(p + 0x78) = 0.8999999761581421f;
        *(f32 *)(p + 0x7C) = 0.8999999761581421f;
        *(f32 *)(p + 0x80) = 0.8999999761581421f;
        break;
    case 2:
        *(f32 *)(p + 0x78) = 1.0f;
        *(f32 *)(p + 0x7C) = 0.6000000238418579f;
        *(f32 *)(p + 0x80) = 0.15000000596046448f;
        break;
    default:
        *(f32 *)(p + 0x78) = 0.5f;
        *(f32 *)(p + 0x7C) = 0.5f;
        *(f32 *)(p + 0x80) = 0.5f;
        break;
    }
}
