typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef float f32;

extern void func_001E3710(u8 *, s32);
extern void func_0015E620(u8 *);
extern void func_00328AA0(u8 *, u8 *);
extern void func_00328DD0(u8 *, u8 *);
extern void func_00328D30(u8 *, u8 *);
extern void func_00329020(u8 *, u8 *);
extern void func_00328F80(u8 *, u8 *);
extern void func_00329670(u8 *, u8 *);
extern void func_003295D0(u8 *, u8 *);

void residual_00328A20(u8 *p, u8 *q)
{
    unsigned t = p[4];
    p[4] = t + 1;
    p[1] = q[1];
    *(f32 *)(p + 0x34) = *(f32 *)(q + 0x34);
    *(f32 *)(p + 0x38) = *(f32 *)(q + 0x38);
    *(s8 *)(p + 0x24) = *(s8 *)(q + 0x24);
    *(s16 *)(p + 0x1C) = 0;
    *(s16 *)(p + 0x1E) = 0x96;
    func_001E3710(p, 0x50);
    func_0015E620(q);
    func_00328AA0(p, q);
}

void residual_00328CA0(u8 *p, u8 *q)
{
    unsigned t = p[4];
    p[4] = t + 1;
    p[1] = q[1];
    *(f32 *)(p + 0x34) = *(f32 *)(q + 0x34);
    *(f32 *)(p + 0x38) = *(f32 *)(q + 0x38);
    *(s8 *)(p + 0x24) = *(s8 *)(q + 0x24);
    func_001E3710(p, 0x4B);
    if (q[0])
        func_00328DD0(p, q);
    *(s16 *)(p + 0x1C) = 0x96;
    func_00328D30(p, q);
}

void residual_00328EF0(u8 *p, u8 *q)
{
    unsigned t = p[4];
    p[4] = t + 1;
    p[1] = q[1];
    *(f32 *)(p + 0x34) = *(f32 *)(q + 0x34);
    *(f32 *)(p + 0x38) = *(f32 *)(q + 0x38);
    *(s8 *)(p + 0x24) = *(s8 *)(q + 0x24);
    func_001E3710(p, 9);
    if (q[0])
        func_00329020(p, q);
    *(s16 *)(p + 0x1C) = 0x96;
    func_00328F80(p, q);
}

void residual_00329540(u8 *p, u8 *q)
{
    unsigned t = p[4];
    p[4] = t + 1;
    p[1] = q[1];
    *(f32 *)(p + 0x34) = *(f32 *)(q + 0x34);
    *(f32 *)(p + 0x38) = *(f32 *)(q + 0x38);
    *(s8 *)(p + 0x24) = *(s8 *)(q + 0x24);
    func_001E3710(p, 0x4B);
    if (q[0])
        func_00329670(p, q);
    *(s16 *)(p + 0x1C) = 0x96;
    func_003295D0(p, q);
}
