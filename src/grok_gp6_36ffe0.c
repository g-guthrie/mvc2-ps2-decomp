typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern void func_00370660(u8 *, s32, s32 *);
extern void func_003706F0(u8 *, u8 *, u8 **);
extern void func_001757E0(u8 *, s32, s32);
extern void func_001E7F60(u8 *);

void func_0036FFE0(u8 *p, u8 *q, u8 *r)
{
    f32 sum;
    u8 *owner;
    f32 y;
    u8 *s;
    owner = *(u8 **)(p + 0x18);
    y = *(f32 *)(p + 0x38);
    s = *(u8 **)(p + 0x1C4);
    sum = *(f32 *)(owner + 0x38);
    sum = 102.85713958740234f + sum;
    if (y <= sum) {
        owner[6] = 0xB;
        p[5] = 4;
        *(s16 *)(p + 0x1C) = 0x14;
    } else if (*(s8 *)(p + 0x1B2) < 0) {
        func_00370660(p, (s32)q, (s32 *)r);
        func_003706F0(p, q, (u8 **)r);
        if (*(s32 *)(r + 8)) {
            p[5]++;
            s[0x13C] = 0;
            *(s16 *)(p + 0x1C) = 0;
            p[0x23] = 0;
            func_001757E0(p, 0x17, 0x2F);
        } else {
            goto motion;
        }
    } else {
    motion:
        *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
        *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
        *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
        func_001E7F60(p);
    }
}
