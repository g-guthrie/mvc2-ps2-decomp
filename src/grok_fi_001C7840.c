typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

extern f32 D_004F1FC8[];
extern f32 D_004F1FCC[];
extern int func_001757E0(u8 *, int, int);
extern void func_0015E630(u8 *);
extern void func_001C7960(u8 *, u8 *);

void func_001C7840(u8 *p, u8 *q)
{
    s16 face;
    p[7]++;
    p[0x14C] = 0x10;
    p[0x14D] = 0x10;
    p[0x14E] = 0x18;
    p[0x14F] = 0x18;
    p[0x13D] = 1;
    if (q[2] != 0)
        *(s16 *)(p + 0x13E) += 0xA;
    else
        *(s16 *)(p + 0x13E) += 2;
    face = *(s16 *)(q + 0x140) ^ 1;
    *(s16 *)(p + 0x140) = face;
    if (face == 0) {
        *(f32 *)(p + 0x34) = 80.0f + D_004F1FCC[0];
        *(u32 *)(p + 0x5C) = 0xC0BAAAAA;
    } else {
        *(f32 *)(p + 0x34) = D_004F1FC8[0] - 80.0f;
        *(u32 *)(p + 0x5C) = 0x40BAAAAA;
    }
    *(f32 *)(p + 0x38) = *(f32 *)(q + 0x430);
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x60) = 0;
    *(u32 *)(p + 0x6C) = 0;
    func_001757E0(p, 0x19, 0x1C);
    p[0] = 1;
    func_0015E630(p);
    func_001C7960(p, q);
}
