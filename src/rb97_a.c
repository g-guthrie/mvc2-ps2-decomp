typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3e;
typedef struct { u8 pad[0x1E]; s16 h1E; } S1E;
typedef struct { u8 pad[0x34]; f32 x, y; } OF;

void func_00215170(u8 *p) {
    extern s32 func_00175700(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_00352670(u8 *, s32, s32, s32);
    extern void func_00212DE0(u8 *, u8 *);
    extern void func_00175C00(u8 *, s32);
    extern void func_001E3240(u8 *, s32);
    extern void func_001843A0(u8 *);
    u8 *q;
    u8 *o;
    u32 t;
    s32 h;
    s32 t2;
    u16 hh;
    struct { f32 a, b; } tt;
    f32 c;
    f32 c2;
    s8 r;
    q = p + 0x2B8;
    if (p[6] == 0) {
        r = func_00175700(p);
        if (r >= 0) {
            if (*(s8 *)(p + 0x151) == 2) {
                p[0x151] = 1;
                hh = *(u16 *)(p + 0x35E);
                if (*(s8 *)(p + 0x539) != 0) {
                    q[0] = 0;
                    p[0x22] = 0;
                    *(s16 *)(p + 0x1C) = 5;
                } else {
                    if (hh & 0x800) {
                        q[0] = 0xE;
                        p[0x22] = 0x1C;
                        *(s16 *)(p + 0x1C) = 4;
                    } else if ((hh & 0x400) == 0) {
                        q[0] = 0;
                        p[0x22] = 0;
                        *(s16 *)(p + 0x1C) = 5;
                    } else {
                        q[0] = 0xE;
                        p[0x22] = 0x1C;
                        *(s16 *)(p + 0x1C) = 4;
                        t2 = *(s8 *)(p + 0x1E6) ^ 1;
                        p[0x1E6] = t2;
                        *(s16 *)(p + 0x140) = (u8)t2;
                    }
                }
            }
        } else {
            t = p[6];
            p[6] = t + 1;
            func_001757E0(p, 0xF, p[0x1C]);
            q[1] = 0x40;
            *(s16 *)(q + 2) = 0xD;
            q[4] = 0xFF;
            *(s16 *)(p + 0x1C) = 0x1E;
            *(s16 *)(p + 0x1E) = 1;
            func_00352670(p, 1, 2, 0);
            o = *(u8 **)(p + 0x1DC);
            *(V3e *)(o + 0x34) = *(V3e *)(p + 0x34);
            c = 0.0f;
            if (p[0x22] != 0) {
                c = -160.0f;
                if (p[0x1E6] != 0) c = -c;
            }
            *(f32 *)(o + 0x34) += c;
            *(f32 *)(o + 0x38) += 205.71427917480469f;
        }
    } else {
        q[4] = 0xFF;
        o = *(u8 **)(p + 0x1DC);
        if (*(s8 *)(o + 0x211) != 0) *(s16 *)(q + 2) = 0;
        h = *(s16 *)(p + 0x1C) - 1;
        *(s16 *)(p + 0x1C) = h;
        if ((s16)h >= 0) {
            func_00212DE0(p, q);
            func_00175700(p);
            if (*(s16 *)(q + 2) != 0) {
                h = *(s16 *)(p + 0x1E) - 1;
                *(s16 *)(p + 0x1E) = h;
                if ((s16)h == 0) {
                    ((S1E *)p)->h1E = 1;
                    tt.a = 19.28571319580078f;
                    tt.b = 0.0f;
                    if (p[0x22] != 0) {
                        tt.b = -10.0f;
                        tt.a = 12.857142448425293f;
                        if (p[0x1E6] != 0) tt.b = -tt.b;
                    }
                    ((OF *)o)->x += tt.b;
                    ((OF *)o)->y += tt.a;
                }
            }
        } else {
            *(s16 *)(q + 2) = 0;
            q[4] = 0;
            *(u8 **)(o + 0x1C8) = p;
            o[0x20A] = 1;
            o[0x1B5] = 0xA3;
            if (p[0x1E6] != 0) {
                p[0x22] = (0x20 - *(s8 *)(p + 0x22)) & 0x1F;
            }
            func_00175C00(p, 0);
            func_001E3240(p, 0x1F);
            func_001E3240(p, 0x20);
            func_001843A0(p);
        }
    }
}
