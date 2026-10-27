typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x7C]; s16 f7c[1]; } G3a;
extern G3a *D_004C2794;
extern u8 D_004D18A0[];

void func_003A3F80(u8 *p, u8 *q, u8 *r)
{
    extern void func_003A4340(u8 *);
    extern void func_00175910(u8 *, s32, s32, s32);
    extern void func_001E7F60(u8 *);
    u8 *o;
    s16 v;
    u32 t;

    o = *(u8 **)(p + 0x1C4);
    func_003A4340(p);
    if (*(s8 *)(p + 0x1B3) == 0) {
        if (*(s16 *)(q + 0x434) != 0 && *(s16 *)(o + 0x434) != 0 && q[5] == 0 && D_004D18A0[0] != 5) goto cont;
    }
L3FEC:
    p[5] = 4;
    *(s8 *)(r + 3) = -1;
    func_00175910(p, 0x17, 5, *(s8 *)(p + 0x151));
    return;
cont:
    if (q[0x1E4] == 0x1C) {
        *(s16 *)(p + 0x1C) = 1;
        *(s16 *)(p + 0x1E) = 1;
    }
    p[0x13D] = 1;
    *(s16 *)(p + 0x13E) = p[0x23];
    v = *(s16 *)(p + 0x1E) - 1;
    *(s16 *)(p + 0x1E) = v;
    if (v == 0) {
        *(s16 *)(p + 0x1E) = (*(s16 *)(p + 0x1C) / 8) * 4;
        p[0x21] = 3;
    }
    if (p[0x21] != 0) {
        *(s16 *)(p + 0x13E) = p[0x23] + 1;
        t = p[0x21];
        p[0x21] = t - 1;
    }
    if (q[5] == 2) goto L3FEC;
    if (*(s8 *)(r + 9) != 0) goto L3FEC;
    if (q[5] == 1) return;
    v = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = v;
    if (v == 0) {
        t = p[5];
        p[5] = t + 1;
        *(s16 *)(p + 0x1C) = 8;
        p[0x1B5] = 0x31;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(s32 *)(p + 0x1D8) = 0;
        D_004C2794->f7c[p[2]]++;
        func_001E7F60(p);
    }
}
