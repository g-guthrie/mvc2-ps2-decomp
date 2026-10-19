typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef float f32;

extern u8 *D_004C2A08 __attribute__((section(".sdata")));
extern void func_0039BBF0(u8 *);
extern void func_00175700(u8 *);
extern void func_001E7F60(u8 *);

void residual_0039BA40(u8 *p)
{
    f32 add;
    p[0x1B0] = 0x42;
    p[0x1B1] = 0x42;
    p[0x24] = 0;
    *(f32 *)(p + 0x34) = *(f32 *)(*(u8 **)(p + 0x18) + 0x34);
    *(f32 *)(p + 0x38) = *(f32 *)(*(u8 **)(p + 0x18) + 0x38);
    if ((*(u8 **)(p + 0x18))[0x1E6])
        add = 120.0f;
    else
        add = -120.0f;
    *(f32 *)(p + 0x34) += add;
    if (*(u16 *)D_004C2A08 != *(u16 *)(*(u8 **)(p + 0x18) + 0x168))
        func_0039BBF0(p);
    else {
        func_00175700(p);
        func_001E7F60(p);
    }
}
