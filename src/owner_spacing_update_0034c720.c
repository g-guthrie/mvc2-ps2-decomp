/* Stop near the target; otherwise follow the owner and select its prior frame. */
typedef unsigned char u8;
typedef signed char s8;
typedef signed int s32;
typedef float f32;

extern f32 func_00117078(f32);
extern s32 func_00175910(u8 *, s32, s32, s32);
extern void func_001E7F60(u8 *);

void func_0034C720(u8 *p)
{
    u8 *o;
    u8 *q;
    q = *(u8 **)(p + 0x18);
    o = *(u8 **)(p + 0x14);
    if (o[6] == 2) {
        f32 d = *(f32 *)(q + 0x34) - *(f32 *)(p + 0x34);
        if (func_00117078(d) < 26.66666603088379f) {
            p[4]++;
            p[0x13C] = 0;
            return;
        }
    }
    *(f32 *)(p + 0x34) = *(f32 *)(o + 0x34) + *(f32 *)(p + 0x5C) * (f32)p[0x22];
    *(f32 *)(p + 0x38) = *(f32 *)(o + 0x38);
    func_00175910(p, 22, 19, *(s8 *)(o + 0x151) - 1);
    func_001E7F60(p);
}
