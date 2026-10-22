typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s16 D_0044ECF0[];

typedef struct { f32 x, y, z; } V3;

void func_001DD660(u8 *p, u8 *q)
{
    extern s32 func_00175670();
    extern void func_00176090(u8 *, s32, s32, s32);
    extern void func_00176160(u8 *, s32, s32, s32);
    extern void func_00174A40(u8 *, s32);
    extern void func_001DD890(u8 *, u8 *);
    s32 tv;
    s16 t;
    f32 c;

    if (p[0x20] >= 3) goto A7A0;
    if (p[0x20] == 2) goto L73C;
    if (p[0x20] != 1) {
        if ((s8)func_00175670(p) < 0) goto L85C;
        return;
    }
    if (*(s32 *)(p + 0xD0) != *(u16 *)(q + 0x168)) goto L85C;
    func_00175670(p);
    {
        s32 idx = *(s8 *)(p + 0x150);
        if (idx != 0) {
            tv = D_0044ECF0[(s8)idx];
            if (tv < 0) {
                func_00176090(q, 1, 0, 1);
                p[0x150] = 0;
            } else {
                func_00176160(q, 1, tv, 1);
                p[0x150] = 0;
            }
        }
    }
    return;
L73C:
    if (*(s32 *)(p + 0xD0) != *(u16 *)(q + 0x168)) goto L85C;
    p[0x13C] = 0;
    if (q[0x15B] == 0) return;
    p[0x13C] = 1;
    *(s8 *)(p + 0x24) = *(s8 *)(q + 0x24);
    *(V3 *)(p + 0x34) = *(V3 *)(q + 0x34);
    if ((s8)func_00175670(p) < 0) goto L85C;
    return;
A7A0:
    if (*(s32 *)(p + 0xD0) != *(u16 *)(q + 0x168)) goto L85C;
    {
        u32 b = p[5];
        if (b == 0) {
            p[5] = b + 1;
            *(s16 *)(p + 0x1C) = 0x3C;
            *(s16 *)(p + 0x1E) = 0;
        }
    }
    *(s16 *)(p + 0x1E) = *(s16 *)(p + 0x1E) + 0x78;
    c = 40.0f;
    if (*(s16 *)(q + 0x140) != 0) c = -c;
    *(f32 *)(p + 0x34) = *(f32 *)(q + 0x34) + c;
    *(f32 *)(p + 0x38) = 342.857117f + *(f32 *)(q + 0x38);
    func_00174A40(p, *(s16 *)(p + 0x1E));
    {
        u32 u = p[0x22];
        p[0x22] = u + 9;
        u = p[0x22];
        p[0x22] = u & 0x1F;
    }
    t = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = t;
    if (t > 0) return;
L85C:
    func_001DD890(p, q);
}
