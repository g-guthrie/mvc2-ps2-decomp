typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x7C]; s16 h7c[1]; } G9F;
extern G9F *D_004C2794;
extern s8 D_00472870[][8];
extern s16 D_00472880[];
typedef struct { f32 x, y, z; } V9F;
typedef struct { u8 pad[0x1C]; s16 h1C; s16 h1E; } P9F;

void func_0039F190(u8 *p, u8 *q) {
    extern s32 func_00175700(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_003DAA40(u8 *);
    extern void func_001E7F60(u8 *);
    extern void func_001E2490(s32, s32);
    s32 i;
    s32 *d;
    s32 *sp;
    u8 *r2;
    s32 h;
    f32 f;
    if (p[4] == 0) {
        u32 t = p[4];
        p[4] = t + 1;
        sp = (s32 *)(q + 0xEC);
        d = (s32 *)(p + 0xEC);
        i = 0x31;
        do {
            *d = *sp;
            i--;
            sp++;
            d++;
        } while (i > 0);
        r2 = p + 2;
        p[0x13C] = 1;
        *r2 = q[2];
        p[1] = q[1];
        *(f32 *)(p + 0x50) = *(f32 *)(q + 0x50);
        *(f32 *)(p + 0x54) = *(f32 *)(q + 0x54);
        p[0x1B7] = q[0x1B7];
        p[0x1B8] = q[0x1B8];
        *(s8 *)(p + 0x30) = *(s8 *)(q + 0x30);
        *(V9F *)(p + 0x50) = *(V9F *)(q + 0x50);
        *(s8 *)(p + 0x24) = *(s8 *)(q + 0x24);
        p[0x1B0] = 0x42;
        p[0x1B1] = 0x42;
        *(s8 *)(p + 0x31) = -8;
        *(s32 *)(p + 0xD0) = q[0x1B7] ? 4 : 2;
        h = D_00472870[q[0x1B7]][p[0x21]];
        *(s16 *)(p + 0x1C) = h;
        *(s16 *)(p + 0x1E) = h;
        *(s16 *)(p + 0x1E) = *(s16 *)(p + 0x1E) - 4;
        f = 1.6666666269302368f * (f32)D_00472880[q[0x1B7] * 5 + p[0x21]];
        if (*(s16 *)(p + 0x140) != 0) f = -f;
        *(f32 *)(p + 0x34) += f;
        p[0x1B5] = *(s8 *)(q + 0x1B7) * 2 + 0x35;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(s32 *)(p + 0x1D8) = 0;
        D_004C2794->h7c[*r2]++;
        func_001757E0(p, 0x16, 2);
        p[0x13C] = 0;
    } else {
        *(s8 *)(p + 0x24) = *(s8 *)(q + 0x24);
        h = *(s16 *)(p + 0x1E);
        if (h > 0) {
            ((P9F *)p)->h1E = h - 1;
        } else if (h == 0) {
            ((P9F *)p)->h1E = -1;
            if (p[0x21] == *(s32 *)(p + 0xD0)) func_001E2490(6, 0x4D);
        }
        h = *(s16 *)(p + 0x1C);
        if (h != 0) {
            ((P9F *)p)->h1C = h - 1;
        } else {
            s32 r;
            p[0x13C] = 1;
            r = (s8)func_00175700(p);
            if (r < 0) {
                func_003DAA40(p);
            } else {
                func_001E7F60(p);
            }
        }
    }
}
