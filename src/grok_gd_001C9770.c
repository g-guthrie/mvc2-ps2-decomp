typedef unsigned char u8;
typedef signed short s16;
typedef signed int s32;
typedef float f32;

extern f32 D_004B59A0[];
extern f32 D_004B59A4[];
extern f32 D_004B59F0[];
extern f32 D_004B59F4[];
extern f32 D_004B59F8[];
extern f32 D_004B59FC[];
extern void func_001754A0(u8 *, s32, s32);
extern void func_001E3710(u8 *, s32);

void func_001C9770(u8 *p)
{
    u8 *q;
    q = *(u8 **)(p + 0x18);
    *(f32 *)(p + 0x34) = *(f32 *)((u8 *)D_004B59A0 + (p[0x22] << 3));
    *(f32 *)(p + 0x38) = *(f32 *)((u8 *)D_004B59A4 + (p[0x22] << 3));
    *(f32 *)(p + 0x5C) = *(f32 *)((u8 *)D_004B59F0 + (p[0x22] << 4));
    *(f32 *)(p + 0x68) = *(f32 *)((u8 *)D_004B59F4 + (p[0x22] << 4));
    *(f32 *)(p + 0x60) = *(f32 *)((u8 *)D_004B59F8 + (p[0x22] << 4));
    *(f32 *)(p + 0x6C) = *(f32 *)((u8 *)D_004B59FC + (p[0x22] << 4));
    {
        s16 face = *(s16 *)(q + 0x140);
        *(s16 *)(p + 0x140) = face;
        if (face != 0) {
        *(f32 *)(p + 0x34) = -*(f32 *)(p + 0x34);
        *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x68) = -*(f32 *)(p + 0x68);
        }
    }
    *(f32 *)(p + 0x34) += *(f32 *)(q + 0x34);
    *(f32 *)(p + 0x38) += *(f32 *)(q + 0x38);
    if (p[0x20] == 9)
        func_001754A0(p, 0x1B, 0x7A);
    else
        func_001754A0(p, 0x1B, 0xA);
    func_001E3710(q, 0x4B);
}
