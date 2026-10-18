typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct {
    u8 p0[5]; u8 b5; u8 pad6[0x1C - 6]; s16 s1c; u8 pad1e[0x34 - 0x1E];
    f32 f34; f32 f38; u8 pad3c[0x5C - 0x3C];
    f32 f5c; f32 f60; u8 pad64[4]; f32 f68; f32 f6c;
    u8 pad70[0x13C - 0x70]; u8 b13c;
} C1;

void func_003513B0(C1 *p) {
    extern s32 func_00174240();
    extern void func_001E7F60();
    p->b13c = 1;
    p->f34 += p->f5c;
    p->f5c += p->f68;
    p->f38 += p->f60;
    p->f60 += p->f6c;
    {
        s16 v = p->s1c - 1;
        p->s1c = v;
        if (v == 0) {
            u32 t = p->b5;
            p->b5 = t + 1;
            p->s1c = 16;
        }
    }
    if (func_00174240(p) == 0) p->b13c = 0;
    else func_001E7F60(p);
}

typedef struct { f32 x, y, z; } V3;

void func_001D35F0(u8 *p) {
    extern void func_001754A0();
    extern void func_00175670();
    u8 *q = *(u8 **)(p + 0x18);
    s8 t; u8 n, m;
    p[0x13C] = 0;
    p[0x24] = q[0x24] + 1;
    if (p[1] != q[1]) {
        p[4] = 2;
    } else if (*(s8 *)(q + 0x13C) != 0) {
        *(V3 *)(p + 0x34) = *(V3 *)(q + 0x34);
        *(s16 *)(p + 0x140) = *(s16 *)(q + 0x140);
        t = *(s8 *)(q + 0x161);
        n = t;
        if (t != 0) {
            m = n;
            p[0x13C] = 1;
            if (*(s16 *)(p + 0x1C) != m) {
                *(s16 *)(p + 0x1C) = m;
                func_001754A0(p, 0x1B, m - 1);
                return;
            }
            func_00175670();
        } else {
            *(s16 *)(p + 0x1C) = -1;
        }
    }
}
