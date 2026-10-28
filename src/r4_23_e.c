typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { u8 pad[0x7C]; s16 f7c[1]; } Gc;
extern Gc *D_004C2794;

void func_00373130(u8 *p)
{
    extern void func_001757E0(u8 *, s32, s32);
    extern u8 *func_00372C60(u8 *, u8 *, u8);
    extern void func_00175700(u8 *);
    extern void func_001E7F60(u8 *);
    u8 *o;
    s32 *q;
    u8 *r;
    s16 v;
    s8 i;
    u32 t;
    u32 z;
    f32 a, b, c;
    v = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = v;
    if (v <= 0) {
        t = p[5];
        p[5] = t + 1;
        o = *(u8 **)(p + 0x18);
        a = 120.0f;
        c = -16.666666030883789f;
        b = 0.0f;
        if (*(s16 *)(o + 0x140) != 0) {
            a = -a;
            b = -b;
            c = -c;
        }
        *(f32 *)(p + 0x34) += a;
        *(f32 *)(p + 0x5C) = c;
        *(f32 *)(p + 0x68) = b;
        *(u32 *)(p + 0x60) = 0;
        *(u32 *)(p + 0x6C) = 0xC0AB6DB6;
        p[0x1B0] = 0x42;
        p[0x1B1] = 0x42;
        p[0x1B5] = 0x3A;
        z = p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(s32 *)(p + 0x1D8) = 0;
        D_004C2794->f7c[p[2]]++;
        o[0x1B5] = 0x3A;
        *(u16 *)(o + 0x1C0) = 0;
        o[0x1B2] = z;
        *(s32 *)(o + 0x1D8) = 0;
        D_004C2794->f7c[o[2]]++;
        func_001757E0(p, 0x16, 3);
        q = (s32 *)(o + 0x2B8);
        for (i = 1; i < 0xD; i++)
            (q + 8)[i] = 0;
        for (i = 1; i < 0xD; i++) {
            r = func_00372C60(o, p, i);
            *(u8 **)(q + 8 + i) = r;
            if (r == 0)
                return;
        }
    }
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_00175700(p);
    func_001E7F60(p);
    if (*(u16 *)(p + 0xD0) != *(u16 *)(*(u8 **)(p + 0x18) + 0x168))
    {
        p[4] = 2;
        return;
    }
}
