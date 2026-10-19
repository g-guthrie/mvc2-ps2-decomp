typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u16 D_004C1C88[2] __attribute__((section(".sdata")));
extern void func_0036C050(u8 *, int);
extern void func_001757E0(u8 *, int, int);

void func_0036C2A0(u8 *p)
{
    u8 eleven = 0xB;
    f32 twenty = 20.0f;
    u8 one = 1;
    u8 *saved = *(u8 **)(p + 0x18);
    s32 pos = 0x60;
    s32 neg = -0x60;
    u16 *tbl = D_004C1C88;
    s32 mode = 0x18;
    s32 off;
    p[0x13C] = one;
    *(f32 *)(p + 0x34) = *(f32 *)(*(u8 **)(p + 0x18) + 0x34);
    *(f32 *)(p + 0x38) = *(f32 *)(*(u8 **)(p + 0x18) + 0x38);
    *(f32 *)(p + 0x3C) = *(f32 *)(*(u8 **)(p + 0x18) + 0x3C);
    off = pos;
    off = (*(s16 *)(*(u8 **)(p + 0x18) + 0x140) == 0) ? neg : off;
    *(f32 *)(p + 0x34) += (f32)off;
    *(f32 *)(p + 0x38) += twenty;
    p[0x24] = eleven;
    saved[0x2B8] = one;
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x6C) = 0;
    *(s16 *)(p + 0x1C) = tbl[(*(u8 **)(p + 0x18))[0x1B7]];
    func_0036C050(p, mode);
    p[0x169] = 0x17;
    func_001757E0(p, p[0x169], 0x1C);
}
