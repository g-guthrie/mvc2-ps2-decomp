typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s32 func_00118FA8(f32);
extern int func_00175700(u8 *);

typedef struct { s16 x; s16 y; } Pair;
extern Pair D_0044ED20[];

void func_001DE790(u8 *p, u8 *q)
{
    s16 v;
    u32 b1 = 0x3FD55555;
    u32 b2 = 0x40092492;
    if (*(u16 *)(q + 0x168) != *(u16 *)(p + 0xD0)) {
        p[4]++;
        return;
    }
    p[0x24] = q[0x24];
    *(f32 *)(p + 0x34) = *(f32 *)(q + 0x34);
    *(f32 *)(p + 0x38) = *(f32 *)(q + 0x38);
    v = (s16)func_00118FA8(*(f32 *)&b1 * (f32)D_0044ED20[p[0x21]].x);
    if (*(s16 *)(q + 0x140))
        v = -v;
    *(f32 *)(p + 0x34) += (f32)v;
    *(f32 *)(p + 0x38) += *(f32 *)&b2 * (f32)D_0044ED20[p[0x21]].y;
    func_00175700(p);
}
