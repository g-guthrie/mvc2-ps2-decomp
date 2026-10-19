typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

extern f32 D_004F1FD0;
extern int func_00174470(u8 *);
extern void func_001E3210(u8 *, int);
extern int func_001757E0(u8 *, int, int);
extern void func_0015E630(u8 *);
extern void func_001C4220(u8 *, u8 *);

void func_001C40D0(u8 *p, u8 *q)
{
    s16 face;
    f32 off;
    p[7]++;
    face = *(s16 *)(q + 0x140) ^ 1;
    *(s16 *)(p + 0x140) = face;
    off = 160.0f;
    if (*(s16 *)(q + 0x140) == 0)
        *(f32 *)(p + 0x34) = *(f32 *)(q + 0x34) - off;
    else
        *(f32 *)(p + 0x34) = off + *(f32 *)(q + 0x34);
    {
        u32 b = 0xC1892492;
        u32 c = 0xBF4DB6DB;
        *(f32 *)(p + 0x38) = 68.57143f + D_004F1FD0;
        *(u32 *)(p + 0x5C) = 0;
        *(u32 *)(p + 0x68) = 0;
        *(u32 *)(p + 0x60) = b;
        *(u32 *)(p + 0x6C) = c;
    }
    if (func_00174470(p) == 0) {
        *(s16 *)(p + 0x140) = 0;
        if (*(s16 *)(q + 0x140) == 0)
            *(f32 *)(p + 0x34) = off + *(f32 *)(q + 0x34);
        else
            *(f32 *)(p + 0x34) = *(f32 *)(q + 0x34) - off;
    }
    func_001E3210(p, 0x21);
    func_001757E0(p, 0x19, 0x17);
    p[0] = 1;
    func_0015E630(p);
    func_001C4220(p, q);
}
