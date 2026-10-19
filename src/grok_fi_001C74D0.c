typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

extern f32 D_004F1FD0;
extern void func_001757E0(u8 *, int, int);
extern void func_001C0A00(u8 *, u8 *, int);
extern void func_0015E630(u8 *);
extern void func_001C7640(u8 *, u8 *);

void residual_001C74D0(u8 *p, u8 *q)
{
    s16 face;
    f32 off;
    p[7]++;
    p[0x24] = 0xC;
    p[0x13D] = 1;
    if (q[2] != 0)
        *(s16 *)(p + 0x13E) += 9;
    else
        *(s16 *)(p + 0x13E) += 1;
    face = *(s16 *)(q + 0x140) ^ 1;
    *(s16 *)(p + 0x140) = face;
    off = 133.33333f;
    if (face == 0)
        *(f32 *)(p + 0x34) = off + *(f32 *)(q + 0x34);
    else
        *(f32 *)(p + 0x34) = *(f32 *)(q + 0x34) - off;
    {
        u32 b = 0xC1092492;
        *(f32 *)(p + 0x38) = 34.285713f + D_004F1FD0;
        *(u32 *)(p + 0x5C) = 0;
        *(u32 *)(p + 0x68) = 0;
        *(u32 *)(p + 0x60) = b;
        *(u32 *)(p + 0x6C) = 0;
    }
    func_001757E0(p, 0x16, 0x28);
    func_001C0A00(p, p, 0x35);
    func_001C0A00(p, p, 0x36);
    func_001C0A00(p, p, 0x37);
    func_001C0A00(p, p, 0x38);
    p[0] = 1;
    func_0015E630(p);
    func_001C7640(p, q);
}
