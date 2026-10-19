typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s32 D_00473F70[];
extern s32 D_00473F74[];
extern void func_003B5530(u8 *, u8 *);

void func_003B4E50(u8 *p, u8 *q)
{
    s16 h = *(s16 *)(p + 0x1C);
    u32 t;
    *(s16 *)(p + 0x1C) = h - 1;
    if (h == 0) {
        *(f32 *)(p + 0x5C) = 1.6666666f * (f32)D_00473F70[p[0x23] * 2] / 65536.0f;
        *(f32 *)(p + 0x68) = 1.6666666f * (f32)D_00473F74[p[0x23] * 2] / 65536.0f;
        if (*(s16 *)(p + 0x140) != 0) {
            *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
            *(f32 *)(p + 0x68) = -*(f32 *)(p + 0x68);
        }
        p[0x1B0] = 0;
        t = p[5];
        p[5] = t + 1;
    }
    func_003B5530(p, q);
}
