typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x7C]; s16 f7c[1]; } H_d;
extern H_d *D_004C2794;
extern f32 D_00476380[];
extern f32 D_00476384[];
extern f32 D_00476410[];
extern f32 D_00476414[];
extern f32 D_004764A0[];
extern f32 D_004764A4[];

void func_003C9A20(u8 *p, u8 *q, u8 *r)
{
    extern void func_003DAA40(u8 *);
    extern void func_00175910(u8 *, s32, s32, s32);
    extern void func_001E7F60(u8 *);
    extern s32 func_00174240(u8 *);
    extern void func_003C9CA0(u8 *, s32);
    u8 *o;
    u32 v;
    s8 a;
    s32 i;
    f32 f2, f3, f4, f5, f6;

    if (p[4] != 0) {
        func_003DAA40(p);
        return;
    }
    o = *(u8 **)(p + 0xD4);
    if (o == 0) {
        func_003DAA40(p);
        return;
    }
    if (r[0x22] != p[0x22]) {
        p[0x22] = r[0x22];
        p[0x13C] = 1;
        func_00175910(p, 0x16, 4, p[0x22]);
        v = p[0x15B];
        a = v;
        if (v != 0) {
            if (a == 0x3C && q[0x269] > 3 && q[0x269] < 3) a = 0x2F;
            p[0x1B5] = a;
            p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
            *(s32 *)(p + 0x1D8) = 0;
            D_004C2794->f7c[p[2]] += 1;
        }
    }
    i = p[0x22];
    f2 = *(f32 *)((u8 *)D_00476380 + i * 8);
    f3 = *(f32 *)((u8 *)D_00476384 + i * 8);
    f4 = *(f32 *)((u8 *)D_00476410 + i * 8);
    f5 = *(f32 *)((u8 *)D_00476414 + i * 8);
    f6 = *(f32 *)((u8 *)D_004764A0 + i * 8);
    if (*(s16 *)(p + 0x140) != 0) {
        f2 = -f2;
        f4 = -f4;
        f6 = -f6;
    }
    if (*(s8 *)(p + 0xD8) == 6) {
        *(f32 *)(p + 0x34) = *(f32 *)(r + 0x34) + 0.9800000190734863f * f2;
        *(f32 *)(p + 0x38) = *(f32 *)(r + 0x38) + f3;
    } else {
        *(f32 *)(p + 0x34) = *(f32 *)(r + 0x34) + 0.9800000190734863f * f4;
        *(f32 *)(p + 0x38) = *(f32 *)(r + 0x38) + f5;
    }
    *(f32 *)(p + 0x34) += 0.9800000190734863f * f6;
    *(f32 *)(p + 0x38) += *(f32 *)((u8 *)D_004764A4 + p[0x22] * 8);
    if (*(s8 *)(o + 0xD9) != 0) {
        if (*(s8 *)(q + 0x1B2) == 0) func_001E7F60(p);
        if (func_00174240(p) != 0) {
            p[0x13C] = 1;
        } else {
            p[0x13C] = 0;
        }
    } else {
        p[0x13C] = 0;
    }
    if (*(s8 *)(p + 0x1B2) != 0) func_003C9CA0(p, *(s32 *)(p + 0x1C4));
}
