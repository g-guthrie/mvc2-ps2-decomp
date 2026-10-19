typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

extern void func_00175700(u8 *);
extern void func_00178F20(u8 *, u8 *);

void residual_0026A4B0(u8 *p)
{
    u8 *q;
    struct {
        union {
            f32 values[3];
            u32 bits[3];
        } position;
        u32 padding;
    } tmp __attribute__((aligned(16)));

    p[6]++;
    func_00175700(p);
    p[0x150] = 0;
    *(s16 *)(p + 0x1C) = 0x18;
    *(u8 **)(p + 0x1DC) = *(u8 **)(p + 0x1C4);
    q = *(u8 **)(p + 0x1DC);
    tmp.position.values[0] = *(f32 *)(q + 0x34);
    tmp.position.values[1] = *(f32 *)(q + 0x38);
    tmp.position.values[2] = *(f32 *)(q + 0x3C);
    func_00178F20(p, q);
    *(f32 *)(q + 0x5C) = (*(f32 *)(q + 0x34) - tmp.position.values[0]) / 24.0f;
    *(u32 *)(q + 0x68) = 0;
    *(u32 *)(q + 0x6C) = 0xBF892492;
    *(f32 *)(q + 0x60) = (*(f32 *)(q + 0x38) - tmp.position.values[1]) / 24.0f
        - (24.0f * *(f32 *)(q + 0x6C) / 2.0f);
    *(f32 *)(q + 0x34) = tmp.position.values[0];
    *(f32 *)(q + 0x38) = tmp.position.values[1];
    *(f32 *)(q + 0x3C) = tmp.position.values[2];
    *(s16 *)(q + 0x144) = 0;
    *(s16 *)(q + 0x146) = 0x66;
}
