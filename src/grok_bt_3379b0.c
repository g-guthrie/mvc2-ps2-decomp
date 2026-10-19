typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u32 func_00174170(void);
extern void func_00337A90(u8 *);
extern f32 D_004B8008[];

void residual_003379B0(u8 *p)
{
    u32 i;
    f32 cur;
    f32 nxt;

    i = p[5];
    cur = D_004B8008[i];
    *(f32 *)(p + 0x38) = cur;
    i = p[5];
    p[5] = i + 1;
    i = p[5];
    p[5] = i & 1;
    i = p[5];
    nxt = D_004B8008[i];
    *(f32 *)(p + 0x60) = (nxt - *(f32 *)(p + 0x38)) / 600.0f;
    *(s16 *)(p + 0x1C) = 0x258;
    p[6] = 1;
    *(u32 *)(p + 0xDC) = func_00174170();
    *(u32 *)(p + 0xDC) = *(u32 *)(p + 0xDC) << 2;
    *(s32 *)(p + 0xDC) = *(s32 *)(p + 0xDC) % 0x3E9;
    *(s32 *)(p + 0xDC) = *(s32 *)(p + 0xDC) + 0x1F4;
    p[4] = 1;
    func_00337A90(p);
}
