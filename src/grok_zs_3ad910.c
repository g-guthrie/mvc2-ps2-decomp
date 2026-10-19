typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;

extern void func_001757E0(u8 *, s32, s32);
extern int func_00175700(u8 *);
extern void func_003AE8A0(u8 *);
extern void func_001E7F60(u8 *);

void func_003AD910(u8 *p)
{
    u8 *o = *(u8 **)(p + 0x18);
    if (!p[5]) {
        if ((s8)o[0x151] == 0)
            return;
        p[5]++;
        func_001757E0(p, 20, 0);
        p[0x13C] = 1;
    }
    *(V3 *)(p + 0x34) = *(V3 *)(o + 0x34);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    if ((s8)o[0x1B4] == 0) {
        if ((s8)func_00175700(p) < 0) {
            *(s16 *)(o + 0x1C) = 0;
            func_003AE8A0(p);
            return;
        }
        if (o[0x214]) {
            if ((s8)func_00175700(p) < 0) {
                *(s16 *)(o + 0x1C) = 0;
                func_003AE8A0(p);
                return;
            }
        }
        func_001E7F60(p);
    }
}
