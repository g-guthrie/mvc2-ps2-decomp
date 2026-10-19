typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s32 func_0018E970(u8 *, u8 *);
extern void func_0018ED90(u8 *);
extern void func_0018EE50(u8 *);
extern void func_0018ED20(u8 *);
extern void func_0018EB00(u8 *);
extern s16 D_00446C40[];

void func_0018EA00(u8 *p, u8 *q)
{
    u8 idx;
    u16 flags;
    f32 scale;
    idx = (u8)func_0018E970(p, q);
    *(u16 *)(p + 0x1C2) = *(u16 *)(q + 0x1C0);
    scale = 1.666666627f * (f32)D_00446C40[idx] / 256.0f;
    *(f32 *)(p + 0x234) = scale;
    *(u32 *)(p + 0x238) = 0x3FFD5555;
    if (p[0x1E6] == 0) {
        *(f32 *)(p + 0x234) = -*(f32 *)(p + 0x234);
        *(f32 *)(p + 0x238) = -*(f32 *)(p + 0x238);
    }
    flags = *(u16 *)(p + 0x1C2);
    if (flags & 0x10)
        func_0018ED90(p);
    else if (flags & 0x1000)
        func_0018EE50(p);
    else if ((*(u8 **)(p + 0x1D0))[1] & 0x40)
        func_0018ED20(p);
    else
        func_0018EB00(p);
}
