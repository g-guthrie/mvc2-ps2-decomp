typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

static void func_002B5100(u8 *p) {
    *(float *)(p + 0x38) += *(float *)(p + 0x60);
    *(float *)(p + 0x60) += *(float *)(p + 0x6C);
    if (*(float *)(p + 0x60) * *(float *)(p + 0x6C) > 0.0f) *(float *)(p + 0x6C) = -1.607142806053161621f;
}

void func_002B5150(u8 *p)
{
    extern void func_00175700(u8 *);
    func_002B5100(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    if (*(f32 *)(p + 0x5C) * *(f32 *)(p + 0x68) > 0.0f) {
        u32 t = p[6];
        p[6] = t + 1;
    }
    func_00175700(p);
}

void func_002B62B0(u8 *p)
{
    extern void func_00175700(u8 *);
    p[0x40C] = 2;
    p[0x33C] = 5;
    func_002B5100(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    if (*(f32 *)(p + 0x5C) * *(f32 *)(p + 0x68) > 0.0f) {
        u32 t = p[6];
        p[6] = t + 1;
    }
    func_00175700(p);
}
