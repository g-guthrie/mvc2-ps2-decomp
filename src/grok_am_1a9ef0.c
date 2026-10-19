typedef unsigned char u8;
typedef signed short s16;
typedef signed int s32;
typedef float f32;

extern s32 func_00174170(void);
extern void func_001757E0(u8 *, s32, s32);
extern void func_001AA040(u8 *, u8 *);
extern void func_001A9FE0(u8 *, u8 *);

void residual_001A9EF0(u8 *p, u8 *q)
{
    s32 flag = 0;
    unsigned int r;
    p[7]++;
    *(s32 *)(p + 0x5C) = 0;
    *(s32 *)(p + 0x68) = 0;
    *(s32 *)(p + 0x60) = 0;
    *(s32 *)(p + 0x6C) = 0;
    if (*(f32 *)(p + 0x34) < *(f32 *)(q + 0x34))
        flag = 1;
    if ((u8)flag != *(s16 *)(p + 0x140)) {
        *(s32 *)(p + 0xD0) = p[6];
        *(s32 *)(p + 0xD4) = p[7];
        p[6] = 0xB;
        p[7] = 0;
        func_001AA040(p, q);
        return;
    }
    if (p[6] != *(s32 *)(p + 0xD0)) {
        r = (unsigned int)func_00174170();
        func_001757E0(p, 0x17, (u8)(r % 3u));
    }
    func_001A9FE0(p, q);
}
