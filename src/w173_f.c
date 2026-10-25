typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_001D8000(u8 *p,void *owner_context_unused)
{
    extern int func_00175670(u8 *);
    extern int func_001754A0(u8 *, s32, s32);
    u8 *o;
    f32 a, b;
    u32 k, c, d;
    s16 t;
    func_00175670(p);
    o = *(u8 **)(p + 0xD8);
    a = *(f32 *)(p + 0x68);
    if (*(s16 *)(o + 0x140) != 0) a = -a;
    *(f32 *)(p + 0x34) = *(f32 *)(o + 0x34) + a;
    k = o[0x20D];
    b = *(f32 *)(p + 0x6C);
    if (k == 1) b /= 2.0f;
    if (k == 3) b /= 4.0f;
    *(f32 *)(p + 0x38) = *(f32 *)(o + 0x38) + b;
    p[0x24] = *(s8 *)(o + 0x24);
    c = o[0x247];
    if (c == 9) {
        d = o[0x23E];
        if (d == 1 || d == 0) {
            if (c != 3) {
                t = *(s16 *)(p + 0x1C) - 1;
                *(s16 *)(p + 0x1C) = t;
                if (t > 0) return;
            }
        }
    }
    p[5]++;
    func_001754A0(p, 0x1B, (u8)(p[0x168] + 4));
}
