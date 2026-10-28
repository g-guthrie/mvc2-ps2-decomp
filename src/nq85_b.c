typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef unsigned int u32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;

extern u8 D_004F1F45;
extern u8 D_004F1F46;

void residual_0017DA20(u8 *p)
{
    extern void func_00191430(u8 *);
    extern void func_0018F730(u8 *);
    extern void func_001E3A10(u8 *);
    extern void func_00158C70(V3 *, s32);
    extern void func_0018EF20(u8 *);
    V3 v;
    u32 t;
    t = p[6];
    p[6] = t + 1;
    *(s8 *)(p + 0x24E) += 1;
    func_00191430(p);
    *(u8 **)(p + 0x1D0) = (u8 *)((u32)*(u8 **)(*(u8 **)(p + 0x1DC) + 0x184) + (p[0x1B5] & 0x7F) * 28);
    func_0018F730(p);
    if (((*(u8 **)(p + 0x1D0))[1] & 0x20) != 0)
        p[0x249] = 1;
    p[0x20D] = 2;
    if (p[1] == 1) {
        if ((*(s32 (**)(u8 *))(*(u8 **)(p + 0x43C) + 0x60))(p) == 0)
            func_001E3A10(p);
    }
    v = *(V3 *)(p + 0x34);
    v.y = *(f32 *)(p + 0x430);
    func_00158C70(&v, p[2]);
    D_004F1F45 = (p[0x21B] < 5) ? 1 : 3;
    D_004F1F46 = 1;
    t = (*(u8 **)(p + 0x1D0))[5];
    (*(u8 **)(p + 0x1DC))[0x1B4] = t;
    p[0x1B4] = t;
    func_0018EF20(p);
    *(u32 *)(p + 0x6C) = 0xBF9A4924;
    *(f32 *)(p + 0x5C) = *(f32 *)(p + 0x22C);
    *(f32 *)(p + 0x60) = *(f32 *)(p + 0x230);
}

