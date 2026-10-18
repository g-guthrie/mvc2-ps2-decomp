typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;

void func_003C0240(u8 *p, u8 *q)
{
    extern s32 func_001748C0(u8 *, f32 *);
    extern void func_00175700(u8 *);
    extern void func_00178F20(u8 *, u8 *);
    extern void func_003C09C0(u8 *);
    extern void func_0018F9E0(u8 *, s32);
    extern void func_0018FCA0(u8 *, s32);
    extern void func_001757E0(u8 *, s32, s32);
    u8 *o;
    f32 v[3];
    s32 r;
    s16 h;
    o = *(u8 **)(p + 0xD4);
    q[0x1FE] = 1;
    q[0x201] = 2;
    p[0x24] = *(s8 *)(o + 0x24);
    v[0] = -320.0f;
    if (*(s16 *)(q + 0x140) != 0)
        v[0] = -v[0];
    v[0] += *(f32 *)(q + 0x34);
    v[1] = 360.0f + *(f32 *)(q + 0x38);
    *(f32 *)(p + 0x34) = (v[0] + 7.0f * *(f32 *)(p + 0x34)) / 8.0f;
    *(f32 *)(p + 0x38) = (v[1] + 7.0f * *(f32 *)(p + 0x38)) / 8.0f;
    *(V3 *)v = *(V3 *)(q + 0x34);
    v[0] = 40.0f;
    if (*(s16 *)(q + 0x140) != 0)
        v[0] = -v[0];
    v[0] += *(f32 *)(q + 0x34);
    v[1] = 342.85711669921875f + *(f32 *)(q + 0x38);
    r = func_001748C0(p + 0x34, v);
    p[0x22] = ((u8)r + 4) >> 3;
    *(s16 *)(p + 0x140) = p[0x22] >> 4;
    func_00175700(p);
    func_00178F20(p, o);
    *(s16 *)(p + 0x140) = 0;
    p[0x15D] = ((p[0x22] - 8) & 0x1F) >> 1;
    h = *(s16 *)(p + 0x1E) + 0x1000;
    *(s16 *)(p + 0x1E) = h;
    if (h == 0) {
        func_003C09C0(p);
        func_0018F9E0(q, 1);
        func_0018FCA0(o, -2);
        if (*(s16 *)(o + 0x434) == 0)
            *(s16 *)(p + 0x1C) = 0;
    }
    h = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = h;
    if (h < 0) {
        p[5]++;
        *(s16 *)(p + 0x1E) = 0;
        q[0x1FE] = 0;
        *(u8 **)(o + 0x1C8) = q;
        o[0x1B5] = 0x22;
        o[0x20D] = 2;
        o[0x1E6] = q[0x1E6] ^ 1;
        o[0x20A] = 1;
        func_001757E0(p, 0x16, 0x18);
        *(s16 *)(p + 0x140) = 0;
        p[0x15D] = ((p[0x22] + 8) & 0x1F) >> 1;
    }
}
